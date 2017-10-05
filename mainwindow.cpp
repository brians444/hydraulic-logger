/***************************************************************************
**  This file is part of Serial Port Plotter                              **
**                                                                        **
**                                                                        **
**  Serial Port Plotter is a program for plotting integer data from       **
**  serial port using Qt and QCustomPlot                                  **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
****************************************************************************/

#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/******************************************************************************************************************/
/* Constructor */
/******************************************************************************************************************/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    connected(false), plotting(false), dataPointNumber(0), numberOfAxes(1), STATE(WAIT_START), NUMBER_OF_POINTS(500)
{
    ui->setupUi(this);
    createUI();                                                                           // Create the UI
    ui->tabWidget->setCurrentIndex(0);

    crearGrafico1();                                                                          // Setup plot area
    crearGrafico2();                                                                          // Setup plot area
    ui->stopPlotButton->setEnabled(false);                                                // Plot button is disabled initially
    colourSetup();
                                                                                          // Slot for printing coordinates
    connect(ui->plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(onMouseMoveInPlot(QMouseEvent*)));

    h = 0;
    filtrar = true;
    ganancias = true;
    // Promediado
    n_promedio = 10;
    promedio_cont = 0;
    for(int i = 0; i < CANALES*2; i++)
    {
        promediados.append("");
    }


    serialPort = NULL;                                                                    // Set serial port pointer to NULL initially
    connect(&updateTimer, SIGNAL(timeout()), this, SLOT(replot()));                       // Connect update timer to replot slot
    ui->saveJPGButton->setEnabled(1);
    ui->comboAxes->setEnabled(1);

    colores[0] = QPen(Qt::red);
    colores[1] = QPen(Qt::blue);
    colores[2] = QPen(Qt::green);

    for(int i = 0; i < CANALES; i++)
    {
        habilitado[i] = true;
    }
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Destructor */
/******************************************************************************************************************/
MainWindow::~MainWindow()
{
    if(serialPort != NULL) delete serialPort;
    delete ui;
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Replot */
/******************************************************************************************************************/
void MainWindow::replot()
{
    qDebug() <<"Replot";
    if(connected) {
        ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
        ui->plot->replot();

        ui->plot2->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
        ui->plot2->replot();
    }
    qDebug() <<"END Replot";
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for new data from serial port . Data is comming in QStringList and needs to be parsed */
/******************************************************************************************************************/
void MainWindow::onNewDataArrived(QStringList newData)
{
    if(plotting)
    {
        int dataListSize = newData.size();
        for(int i = 0; i < dataListSize; i++)
        {
            promediados[i] = QString::number(newData[i].toLong() + promediados[i].toLong());
        }
        promedio_cont++;

        if(promedio_cont == n_promedio)
        {
            QStringList filtrados = signal.append(newData, CANALES);

            int dataListSize = newData.size();                                                    // Get size of received list
            dataPointNumber++;                                                                    // Increment data number
            qDebug() <<"Data Arrive. Tamaño = "<<dataListSize;
            qDebug() <<"Numero de ejes = "<<numberOfAxes;

            this->procesarSignals();

            qDebug() <<"Lista "<<newData;
            qDebug() <<"Adding data plot 1";
            double tmp;
            for(int i=0; i < 3; i++)
            {
                if(habilitado[i] == true)
                {
                    tmp = (double)newData[i].toDouble();
                    qDebug() <<"Señal["<<i<<"] = "<<tmp;
                    ui->plot->graph(i)->addData(dataPointNumber, tmp);
                    ui->plot->graph(i)->removeDataBefore(dataPointNumber - NUMBER_OF_POINTS);
                }
            }
            qDebug() << "Adding data plot 2";
            for(int i=0; i < 3; i++)
            {
                if(habilitado[i] == true)
                {
                    tmp = (double)filtrados[i].toDouble();
                    ui->plot2->graph(i)->addData(dataPointNumber, tmp);
                    ui->plot2->graph(i)->removeDataBefore(dataPointNumber - NUMBER_OF_POINTS);
                }
            }
            qDebug() <<"END Data Arrive";

            promedio_cont = 0;
            for(int i = 0; i< 8; i++)
            {
                promediados[i] = QString::number(0);
            }
        }
    }
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Read data for inside serial port */
/******************************************************************************************************************/
void MainWindow::readData()
{
    if(serialPort->bytesAvailable()) {                                                    // If any bytes are available
        QByteArray data = serialPort->readAll();                                          // Read all data in QByteArray

        if(!data.isEmpty()) {                                                             // If the byte array is not empty
            char *temp = data.data();                                                     // Get a '\0'-terminated char* to the data

            for(int i = 0; temp[i] != '\0'; i++) {                                        // Iterate over the char*
                switch(STATE) {                                                           // Switch the current state of the message
                case WAIT_START:                                                          // If waiting for start [$], examine each char
                    if(temp[i] == START_MSG) {                                            // If the char is $, change STATE to IN_MESSAGE
                        STATE = IN_MESSAGE;
                        receivedData.clear();                                             // Clear temporary QString that holds the message
                        break;                                                            // Break out of the switch
                    }
                    break;
                case IN_MESSAGE:                                                          // If state is IN_MESSAGE
                    if(temp[i] == END_MSG) {                                              // If char examined is ;, switch state to END_MSG
                        STATE = WAIT_START;
                        QStringList incomingData = receivedData.split(' ');               // Split string received from port and put it into list
                        emit newData(incomingData);                                       // Emit signal for data received with the list
                        break;
                    }
                    else if(isdigit(temp[i]) || isspace(temp[i]) ) {                      // If examined char is a digit, and not '$' or ';', append it to temporary string
                        receivedData.append(temp[i]);
                    }
                    break;
                default:
                {
                    STATE = WAIT_START;
                    break;
                }
                }
            }
        }
    }
}
/******************************************************************************************************************/




void MainWindow::generar()
{
    QStringList lista;
    int d = h*h;
    h++;
    dataPointNumber++;
    if(h>100)
    {
        h = 0;
    }
    lista.append(QString::number(d));
    for(int i = 1; i < CANALES; i++)
    {
        lista.append((QString::number(h*i*10)));
    }

    qDebug() << "Emitiendo "<<lista;

    emit(newData(lista));
}

void MainWindow::on_GraficoAleatorio_clicked()
{
    if(plotting == 0)
    {

        crearGrafico1();
        crearGrafico2();


        plotting = 1;
        connected = 1;
        updateTimer.setInterval(20);                                                                // Slot is refreshed 20 times per second
        generador.start(5);
        updateTimer.start();

        connect(this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
        connect(&generador, SIGNAL(timeout()), this, SLOT(generar()));                       // Connect update timer to replot slot

        qDebug() << "Generado";
    }
    else
    {
        plotting = 0;
        connected = 0;
        disconnect(this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
        disconnect(&generador, SIGNAL(timeout()),this, SLOT(generar()));

        updateTimer.stop();
        generador.stop();

    }

}


void MainWindow::LeerTemperatura()
{
    // Read temp continuously
    // Opening the device's file triggers new reading
    int fd = open(devPath, O_RDONLY);
    if(fd == -1)
    {
        perror ("Couldn't open the w1 device.");
        return;
    }
    if((numRead = read(fd, buf, 256)) > 0)
    {
        strncpy(tmpData, strstr(buf, "t=") + 2, 5);
        float tempC = strtof(tmpData, NULL);
        tempC /= 1000.0;
        qDebug() << "Device: " << dev;
        qDebug() << "Temp:  " << tempC << "C";
        last_temp = tempC;
    }
    //close(fd);

}

void MainWindow::TempSensorInit()
{
    connect(&tempLector, SIGNAL(timeout()), this, SLOT(LeerTemperatura()));

    strcpy(path, "/sys/bus/w1/devices");

     dir = opendir (path);
     if (dir != NULL)
     {
      while ((dirent = readdir (dir)))
       // 1-wire devices are links beginning with 28-
       if (dirent->d_type == DT_LNK &&
         strstr(dirent->d_name, "28-") != NULL) {
        strcpy(dev, dirent->d_name);
        printf("\nDevice: %s\n", dev);
       }
            (void) closedir (dir);
            }
     else
     {
      perror ("Couldn't open the w1 devices directory");
      return;
     }

            // Assemble path to OneWire device
     sprintf(devPath, "%s/%s/w1_slave", path, dev);
}
void MainWindow::on_graficarTempButton_clicked()
{
    tempLector.setInterval(1000);
    tempLector.start();
}
