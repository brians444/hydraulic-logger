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
    connected(false), plotting(false), numberOfAxes(1), STATE(WAIT_START)
{
    dataPointNumber = 0;
    dataPointNumber_temp = 0;
    NUMBER_OF_POINTS = 500;
    NUMBER_OF_POINTS_TEMP = 500;
    ui->setupUi(this);
    createUI();                                                                           // Create the UI
    ui->tabWidget->setCurrentIndex(0);

    crearGrafico1();                                                                          // Setup plot area
    crearGrafico2();                                                                          // Setup plot area
    ui->stopPlotButton->setEnabled(false);                                                // Plot button is disabled initially
    colourSetup();
                                                                                          // Slot for printing coordinates
    connect(ui->plot, SIGNAL(mouseRelease(QMouseEvent*)), this, SLOT(onMouseMoveInPlot(QMouseEvent*)));

    plotting_temp = 0;
    h = 0;
    filtrar = true;
    ganancias = true;
    // Promediado
    /*n_promedio = 10;
    promedio_cont = 0;
    for(int i = 0; i < CANALES*2; i++)
    {
        promediados.append("");
    }*/


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

    ui->p1_label->setText(" - bar");
    ui->t1_label->setText(" - ºC");
    ui->t2_label->setText(" - ºC");

    task_temp = new tempReader();
    //connect(task_temp, SIGNAL(plotTemps(float a,float b)), this, SLOT(graficarTemp(float a ,float b)) );
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Destructor */
/******************************************************************************************************************/
MainWindow::~MainWindow()
{
    updateTimer.stop();
    if(serialPort != NULL) delete serialPort;
    ui->plot->clearItems();
    ui->plot2->clearItems();
    delete ui;
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Replot */
/******************************************************************************************************************/
void MainWindow::replot()
{
    //qDebug() <<"Replot";
    if(connected) {
        ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
        ui->plot->replot();
    }
    //qDebug() <<"END Replot";
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for new data from serial port . Data is comming in QStringList and needs to be parsed */
/******************************************************************************************************************/
void MainWindow::onNewDataArrived(QStringList newData)
{
    if(plotting)
    {
        dataPointNumber++;                      // Increment data number
        int dataListSize = newData.size();      // Get size of received list
        QStringList filtrados = signal.append(newData, dataListSize-1);
        this->procesarSignals();
        qDebug() <<"Lista filtrada"<<filtrados;
        qDebug() <<"Lista sin filtro"<<newData;
        /*
        qDebug() <<"Data Arrive. Tamaño = "<<dataListSize;
        qDebug() <<"Numero de ejes = "<<numberOfAxes;
        qDebug() <<"Lista "<<promediados;
        qDebug() <<"Adding data plot 1"; */
        double tmp;
        for(int i=0; i < dataListSize-1; i++)
        {
            if(habilitado[i] == true)
            {
                tmp = (double)filtrados[i].toDouble();
                //tmp = (double)newData[i].toDouble();
                ui->plot->graph(i)->addData(dataPointNumber, tmp);
                ui->plot->graph(i)->removeDataBefore(dataPointNumber - NUMBER_OF_POINTS);
            }
        }
        if(dataPointNumber%2 == 0)
        {
            this->replot();
            ui->p1_label->setText(QString::number(filtrados[0].toDouble())+" bar");
        }
        if(dataPointNumber%100 == 0 && plotting_temp) // Grafico temperatura
        {
            float t1, t2;
            t1 = task_temp->getLastTemp(1);
            t2 = task_temp->getLastTemp(2);
            this->graficarTemp(t1, t2);

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
                        int dataListSize = incomingData.size();
                        long suma = 0;
                        long suma_recv=0;
                        //qDebug()<<"Lista = "<<incomingData;
                        suma_recv = incomingData[dataListSize-1].toLong();
                        for(int i = 0; i < dataListSize-1; i++)
                        {
                            suma += incomingData[i].toLong();
                        }
                        //qDebug()<<"Suma Recibida "<<suma_recv<<" Suma calculada ="<<suma;
                        if(suma_recv == suma)
                        {
                            emit newData(incomingData);         // Emit signal for data received with the list
                        }
                        else
                        {
                            qDebug() << "Frame incorrecto : La suma total no coincide";
                        }
                        break;
                    }
                    else if(isdigit(temp[i]) || isspace(temp[i]) )
                    {   // If examined char is a digit, and not '$' or ';', append it to temporary string
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

void MainWindow::graficarTemp(float temp1, float temp2)
{
    qDebug()<<"Graficar temperatura";
    dataPointNumber_temp++;
    ui->plot2->graph(0)->addData(dataPointNumber_temp, temp1);
    ui->plot2->graph(0)->removeDataBefore(dataPointNumber_temp - NUMBER_OF_POINTS_TEMP);

    ui->plot2->graph(1)->addData(dataPointNumber_temp, temp2);
    ui->plot2->graph(1)->removeDataBefore(dataPointNumber_temp - NUMBER_OF_POINTS_TEMP);

    ui->plot2->xAxis->setRange(dataPointNumber_temp - NUMBER_OF_POINTS_TEMP, dataPointNumber_temp);
    ui->plot2->replot();
    ui->t1_label->setText(QString::number(temp1)+" ºC");
    ui->t2_label->setText(QString::number(temp2)+" ºC");
}

void MainWindow::on_graficarTempButton_clicked()
{
    //tempLector.setInterval(500);
    //tempLector.start();
    //task_temp->run();

    if(plotting_temp == 0)
    {
        task_temp->start();
        plotting_temp = 1;
    }
    else if(plotting_temp == 1)
    {
        task_temp->stop();
        plotting_temp = 0;
    }
}
