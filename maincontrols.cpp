#include "mainwindow.hpp"
#include "ui_mainwindow.h"

/******************************************************************************************************************/
/* Enable/disable controls */
/******************************************************************************************************************/
void MainWindow::enableControls(bool enable)
{
    ui->comboBaud->setEnabled(enable);                                                    // Disable controls in the GUI
    ui->comboData->setEnabled(enable);
    ui->comboParity->setEnabled(enable);
    ui->comboPort->setEnabled(enable);
    ui->comboStop->setEnabled(enable);
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Open the inside serial port; connect its signals */
/******************************************************************************************************************/
void MainWindow::openPort(QSerialPortInfo portInfo, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::Parity parity, QSerialPort::StopBits stopBits)
{
    serialPort = new QSerialPort(portInfo, 0);                                            // Create a new serial port

    connect(this, SIGNAL(portOpenOK()), this, SLOT(portOpenedSuccess()));                 // Connect port signals to GUI slots
    connect(this, SIGNAL(portOpenFail()), this, SLOT(portOpenedFail()));
    connect(this, SIGNAL(portClosed()), this, SLOT(onPortClosed()));
    connect(this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
    connect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));

    if(serialPort->open(QIODevice::ReadWrite) ) {
        serialPort->setBaudRate(baudRate);
        serialPort->setParity(parity);
        serialPort->setDataBits(dataBits);
        serialPort->setStopBits(stopBits);
        emit portOpenOK();
    } else {
        emit portOpenedFail();
        qDebug() << serialPort->errorString();
    }

}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Port Combo Box index changed slot; displays info for selected port when combo box is changed */
/******************************************************************************************************************/
void MainWindow::on_comboPort_currentIndexChanged(const QString &arg1)
{
    QSerialPortInfo selectedPort(arg1);                                                   // Dislplay info for selected port
    ui->statusBar->showMessage(selectedPort.description());
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Connect Button clicked slot; handles connect and disconnect */
/******************************************************************************************************************/
void MainWindow::on_connectButton_clicked()
{
    if(connected) {                                                                       // If application is connected, disconnect
        serialPort->close();                                                              // Close serial port
        emit portClosed();                                                                // Notify application
        delete serialPort;                                                                // Delete the pointer
        serialPort = NULL;                                                                // Assign NULL to dangling pointer
        ui->connectButton->setText("Conectar");                                            // Change Connect button text, to indicate disconnected
        ui->statusBar->showMessage("Desconectado!");                                      // Show message in status bar
        connected = false;                                                                // Set connected status flag to false
        plotting = false;                                                                 // Not plotting anymore
        receivedData.clear();                                                             // Clear received string
        ui->stopPlotButton->setEnabled(false);                                            // Take care of controls
        ui->saveJPGButton->setEnabled(false);
        enableControls(true);
    } else {                                                                              // If application is not connected, connect
                                                                                          // Get parameters from controls first
        QSerialPortInfo portInfo(ui->comboPort->currentText());                           // Temporary object, needed to create QSerialPort
        int baudRate = ui->comboBaud->currentText().toInt();                              // Get baud rate from combo box
        int dataBitsIndex = ui->comboData->currentIndex();                                // Get index of data bits combo box
        int parityIndex = ui->comboParity->currentIndex();                                // Get index of parity combo box
        int stopBitsIndex = ui->comboStop->currentIndex();                                // Get index of stop bits combo box
        QSerialPort::DataBits dataBits;
        QSerialPort::Parity parity;
        QSerialPort::StopBits stopBits;

        if(dataBitsIndex == 0) {                                                          // Set data bits according to the selected index
            dataBits = QSerialPort::Data8;
        } else {
            dataBits = QSerialPort::Data7;
        }

        if(parityIndex == 0) {                                                            // Set parity according to the selected index
            parity = QSerialPort::NoParity;
        } else if(parityIndex == 1) {
            parity = QSerialPort::OddParity;
        } else {
            parity = QSerialPort::EvenParity;
        }

        if(stopBitsIndex == 0) {                                                          // Set stop bits according to the selected index
             stopBits = QSerialPort::OneStop;
        } else {
            stopBits = QSerialPort::TwoStop;
        }

        serialPort = new QSerialPort(portInfo, 0);                                        // Use local instance of QSerialPort; does not crash
        openPort(portInfo, baudRate, dataBits, parity, stopBits);                         // Open serial port and connect its signals
        serialPort->clear();
    }
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for port opened successfully */
/******************************************************************************************************************/
void MainWindow::portOpenedSuccess()
{
    //qDebug() << "Port opened signal received!";
    ui->connectButton->setText("Desconectar");                                             // Change buttons
    ui->statusBar->showMessage("Conectado!");
    enableControls(false);                                                                // Disable controls if port is open

    ui->saveJPGButton->setEnabled(true);                                                  // Enable button for saving plot
    crearGrafico1();                                                                          // Create the QCustomPlot area
    crearGrafico2();                                                                          // Create the QCustomPlot area
    updateTimer.setInterval(20);                                                                // Slot is refreshed 20 times per second
    /********* Modificacion
     * ui->stopPlotButton->setText("Stop Plot");                                             // Enable button for stopping plot
     * ui->stopPlotButton->setEnabled(true);
     *  updateTimer.stop();             // Stop updating plot timer
     *
     * Con la modificacion no inicia solo el grafico
     * */

    plotting = false;
    ui->stopPlotButton->setEnabled(true);
    ui->stopPlotButton->setText("Iniciar! ");

    connected = true;                                                                     // Set flags
    //plotting = true;
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for fail to open the port */
/******************************************************************************************************************/
void MainWindow::portOpenedFail()
{
    //qDebug() << "Port cannot be open signal received!";
    ui->statusBar->showMessage("No se puede abrir el puerto!");
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Slot for closing the port */
/******************************************************************************************************************/
void MainWindow::onPortClosed()
{
    //qDebug() << "Port closed signal received!";
    updateTimer.stop();
    connected = false;
    disconnect(serialPort, SIGNAL(readyRead()), this, SLOT(readData()));
    disconnect(this, SIGNAL(portOpenOK()), this, SLOT(portOpenedSuccess()));             // Disconnect port signals to GUI slots
    disconnect(this, SIGNAL(portOpenFail()), this, SLOT(portOpenedFail()));
    disconnect(this, SIGNAL(portClosed()), this, SLOT(onPortClosed()));
    disconnect(this, SIGNAL(newData(QStringList)), this, SLOT(onNewDataArrived(QStringList)));
}


/******************************************************************************************************************/
/* Number of axes combo; when changed, display axes colors in status bar */
/******************************************************************************************************************/
void MainWindow::on_comboAxes_currentIndexChanged(int index)
{
    if(index == 0) {
      ui->statusBar->showMessage("Axis 1: Red");
    } else if(index == 1) {
        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow");
    } else {
        ui->statusBar->showMessage("Axis 1: Red; Axis 2: Yellow; Axis 3: Green");
    }
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Imprime las coordenadas del puntero del mouse en el barra de estado */
/******************************************************************************************************************/
void MainWindow::onMouseMoveInPlot(QMouseEvent *event)
{
    int xx = ui->plot->xAxis->pixelToCoord(event->x());
    int yy = ui->plot->yAxis->pixelToCoord(event->y());
    QString coordinates("X: %1 Y: %2");
    coordinates = coordinates.arg(xx).arg(yy);
    ui->statusBar->showMessage(coordinates);
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Shows a window with instructions */
/******************************************************************************************************************/
void MainWindow::on_actionHow_to_use_triggered()
{
    helpWindow = new HelpWindow(this);
    helpWindow->setWindowTitle("Como usar esta aplicacion!");
    helpWindow->show();
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Stop Plot Button */
/******************************************************************************************************************/
void MainWindow::on_stopPlotButton_clicked()
{
    if(plotting) {                                                                        // Stop plotting
        updateTimer.stop();                                                               // Stop updating plot timer
        plotting = false;
        ui->stopPlotButton->setText("Iniciar grafico");
    } else {                                                                              // Start plotting
        //updateTimer.start();                                                              // Start updating plot timer
        plotting = true;
        ui->stopPlotButton->setText("Detener grafico");
        serialPort->clear();
        serialPort->flush();

    }
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/**Create the GUI */
/******************************************************************************************************************/
void MainWindow::createUI()
{
    if(QSerialPortInfo::availablePorts().size() == 0) {                                   // Check if there are any ports at all; if not, disable controls and return
        enableControls(false);
        ui->connectButton->setEnabled(false);
        ui->statusBar->showMessage("No se detectaron puertos disponibles.");
        ui->saveJPGButton->setEnabled(false);
        return;
    }

    for(QSerialPortInfo port : QSerialPortInfo::availablePorts()) {                       // List all available serial ports and populate ports combo box
        ui->comboPort->addItem(port.portName());
    }

    ui->comboBaud->addItem("1200");                                                       // Populate baud rate combo box
    ui->comboBaud->addItem("2400");
    ui->comboBaud->addItem("4800");
    ui->comboBaud->addItem("9600");
    ui->comboBaud->addItem("19200");
    ui->comboBaud->addItem("38400");
    ui->comboBaud->addItem("57600");
    ui->comboBaud->addItem("115200");
    ui->comboBaud->setCurrentIndex(7);                                                    // Select 9600 bits by default

    ui->comboData->addItem("8 bits");                                                     // Populate data bits combo box
    ui->comboData->addItem("7 bits");

    ui->comboParity->addItem("none");                                                     // Populate parity combo box
    ui->comboParity->addItem("odd");
    ui->comboParity->addItem("even");

    ui->comboStop->addItem("1 bit");                                                      // Populate stop bits combo box
    ui->comboStop->addItem("2 bits");

    ui->comboAxes->addItem("1");                                                          // Populate axes combo box; 3 axes maximum allowed
    ui->comboAxes->addItem("2");
    ui->comboAxes->addItem("3");
}
/******************************************************************************************************************/




/******************************************************************************************************************/
/* Slot for spin box for plot maximum value on y axis */
/******************************************************************************************************************/
void MainWindow::on_spinAxesMax_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeUpper(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Slot for spin box for plot minimum value on y axis */
/******************************************************************************************************************/
void MainWindow::on_spinAxesMin_valueChanged(int arg1)
{
    ui->plot->yAxis->setRangeLower(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Spin box controls how many data points are collected and displayed */
/******************************************************************************************************************/
void MainWindow::on_spinPoints_valueChanged(int arg1)
{
    NUMBER_OF_POINTS = arg1;
    ui->plot->replot();
}
/******************************************************************************************************************/

/******************************************************************************************************************/
/* Spin box for changing the Y Tick step */
/******************************************************************************************************************/
void MainWindow::on_spinYStep_valueChanged(int arg1)
{
    ui->plot->yAxis->setTickStep(arg1);
    ui->plot->replot();
}
/******************************************************************************************************************/



/******************************************************************************************************************/
//              GRAFICO 2
/******************************************************************************************************************/

void MainWindow::on_spinYStep2_valueChanged(int arg1)
{
    ui->plot2->yAxis->setTickStep(arg1);
    ui->plot2->replot();
}

void MainWindow::on_spinPoints2_valueChanged(int arg1)
{
    NUMBER_OF_POINTS_TEMP = arg1;
    ui->plot2->xAxis->setRangeUpper(NUMBER_OF_POINTS_TEMP);
    ui->plot2->replot();
}

void MainWindow::on_spinAxesMin2_valueChanged(int arg1)
{
    ui->plot2->yAxis->setRangeLower(arg1);
    ui->plot2->replot();
}

void MainWindow::on_spinAxesMax2_valueChanged(int arg1)
{
    ui->plot2->yAxis->setRangeUpper(arg1);
    ui->plot2->replot();
}

/******************************************************************************************************************/
