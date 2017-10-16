#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/******************************************************************************************************************/
/* Crear Grafico 1 */
/******************************************************************************************************************/
void MainWindow::crearGrafico1()
{

    ui->plot->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot->xAxis->setTickLabelFont(font);
    ui->plot->yAxis->setTickLabelFont(font);
    ui->plot->legend->setFont(font);
    ui->plot->yAxis->setAutoTickStep(false);                                              // User can change tick step with a spin box
    ui->plot->yAxis->setTickStep(500);                                                    // Set initial tick step
    ui->plot->xAxis->grid()->setSubGridVisible(true);
    ui->plot->yAxis->grid()->setSubGridVisible(true);
    ui->plot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot->setInteraction(QCP::iRangeDrag, true);
    ui->plot->setInteraction(QCP::iRangeZoom, true);

    ui->plot->clearItems();                                                              // Remove everything from the plot

    ui->plot->yAxis->setTickStep(ui->spinYStep->value());                                // Set tick step according to user spin box
    numberOfAxes = ui->comboAxes2->currentText().toInt();                                 // Get number of axes from the user combo
    ui->plot->yAxis->setRange(ui->spinAxesMin->value(), ui->spinAxesMax->value());       // Set lower and upper plot range
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);                                      // Set x axis range for specified number of points

    qDebug()<<"Numero de ejes: "<<numberOfAxes;

    /*********
    if(numberOfAxes == 1) {                                                               // If 1 axis selected
        ui->plot->addGraph();                                                             // add Graph 0
        ui->plot->graph(0)->setPen(QPen(Qt::red));
        // ui->plot->graph(0)->setPen(QPen(Qt::red), 2);        // Linea mas gruesa
    } else if(numberOfAxes == 2) {                                                        // If 2 axes selected
        ui->plot->addGraph();                                                             // add Graph 0
        ui->plot->graph(0)->setPen(QPen(Qt::red));
        ui->plot->addGraph();                                                             // add Graph 1
        ui->plot->graph(1)->setPen(QPen(Qt::blue));
    } else if(numberOfAxes == 3) {                                                        // If 3 axis selected
        ui->plot->addGraph();                                                             // add Graph 0
        ui->plot->graph(0)->setPen(QPen(Qt::red));
        ui->plot->addGraph();                                                             // add Graph 1
        ui->plot->graph(1)->setPen(QPen(Qt::blue));
        ui->plot->addGraph();                                                             // add Graph 2
        ui->plot->graph(2)->setPen(QPen(Qt::green));
    }
    *^************************************/
    for(int i = 0; i < numberOfAxes; i++)
    {
        ui->plot->addGraph();
        ui->plot->graph(i)->setPen(colores[i]);
    }

}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Crear Grafico 2 */
/******************************************************************************************************************/
void MainWindow::crearGrafico2()
{
    //pl = new QCustomPlot();
    //pl->resize(800,600);


    ui->plot2->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    ui->plot2->xAxis->setTickLabelFont(font);
    ui->plot2->yAxis->setTickLabelFont(font);
    ui->plot2->legend->setFont(font);
    ui->plot2->yAxis->setAutoTickStep(false);                                              // User can change tick step with a spin box
    ui->plot2->yAxis->setTickStep(500);                                                    // Set initial tick step
    ui->plot2->xAxis->grid()->setSubGridVisible(true);
    ui->plot2->yAxis->grid()->setSubGridVisible(true);
    ui->plot2->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot2->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->plot2->setInteraction(QCP::iRangeDrag, true);
    ui->plot2->setInteraction(QCP::iRangeZoom, true);
    ui->plot2->clearItems();                                                              // Remove everything from the plot

    ui->plot2->yAxis->setTickStep(ui->spinYStep2->value());                                // Set tick step according to user spin box
    numberOfAxes2 = ui->comboAxes2->currentText().toInt();                                 // Get number of axes from the user combo
    ui->plot2->yAxis->setRange(ui->spinAxesMin2->value(), ui->spinAxesMax2->value());       // Set lower and upper plot range
    ui->plot2->xAxis->setRange(0, NUMBER_OF_POINTS_TEMP);                                      // Set x axis range for specified number of points

    /**************************************+
    if(numberOfAxes == 1) {                                                               // If 1 axis selected
        ui->plot2->addGraph();                                                             // add Graph 0
        ui->plot2->graph(0)->setPen(QPen(Qt::red, 2));
    } else if(numberOfAxes == 2) {                                                        // If 2 axes selected
        ui->plot2->addGraph();                                                             // add Graph 0
        ui->plot2->graph(0)->setPen(QPen(Qt::red));
        ui->plot2->addGraph();                                                             // add Graph 1
        ui->plot2->graph(1)->setPen(QPen(Qt::yellow));
    } else if(numberOfAxes == 3) {                                                        // If 3 axis selected
        ui->plot2->addGraph();                                                             // add Graph 0
        ui->plot2->graph(0)->setPen(QPen(Qt::red));
        ui->plot2->addGraph();                                                             // add Graph 1
        ui->plot2->graph(1)->setPen(QPen(Qt::yellow));
        ui->plot2->addGraph();                                                             // add Graph 2
        ui->plot2->graph(2)->setPen(QPen(Qt::green));
    }
    *************************************/
    for(int i = 0; i < numberOfAxes2; i++)
    {
        ui->plot2->addGraph();
        ui->plot2->graph(i)->setPen(colores[i]);
    }

}
/******************************************************************************************************************/


/******************************************************************************************************************/
/* Crear Grafico en ventana */
/******************************************************************************************************************/
void MainWindow::crearGraficoDesplegable()
{
    //pl = new QCustomPlot();
    //pl->resize(800,600);


    pl->setNotAntialiasedElements(QCP::aeAll);                                      // used for higher performance (see QCustomPlot real time example)
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    pl->xAxis->setTickLabelFont(font);
    pl->yAxis->setTickLabelFont(font);
    pl->legend->setFont(font);
    pl->yAxis->setAutoTickStep(false);                                              // User can change tick step with a spin box
    pl->yAxis->setTickStep(500);                                                    // Set initial tick step
    pl->xAxis->grid()->setSubGridVisible(true);
    pl->yAxis->grid()->setSubGridVisible(true);
    pl->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    pl->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    pl->setInteraction(QCP::iRangeDrag, true);
    pl->setInteraction(QCP::iRangeZoom, true);
    pl->clearItems();                                                              // Remove everything from the plot

    pl->yAxis->setTickStep(ui->spinYStep->value());                                // Set tick step according to user spin box
    numberOfAxes = ui->comboAxes->currentText().toInt();                                 // Get number of axes from the user combo
    pl->yAxis->setRange(ui->spinAxesMin->value(), ui->spinAxesMax->value());       // Set lower and upper plot range
    pl->xAxis->setRange(0, NUMBER_OF_POINTS);                                      // Set x axis range for specified number of points


    if(numberOfAxes == 1) {                                                               // If 1 axis selected
        pl->addGraph();                                                             // add Graph 0
        pl->graph(0)->setPen(QPen(Qt::red, 2));
    } else if(numberOfAxes == 2) {                                                        // If 2 axes selected
        pl->addGraph();                                                             // add Graph 0
        pl->graph(0)->setPen(QPen(Qt::red));
        pl->addGraph();                                                             // add Graph 1
        pl->graph(1)->setPen(QPen(Qt::yellow));
    } else if(numberOfAxes == 3) {                                                        // If 3 axis selected
        pl->addGraph();                                                             // add Graph 0
        pl->graph(0)->setPen(QPen(Qt::red));
        pl->addGraph();                                                             // add Graph 1
        pl->graph(1)->setPen(QPen(Qt::yellow));
        pl->addGraph();                                                             // add Graph 2
        pl->graph(2)->setPen(QPen(Qt::green));
    }

   pl->show();
}
/******************************************************************************************************************/


void MainWindow::colourSetup()
{

    /***********   Seteo de colores GRAFICO 1******/
    /*
    ui->plot->setBackground(QBrush(QColor(48,47,47)));                                    // Background for the plot area
    ui->plot->xAxis->setTickLabelColor(QColor(170,170,170));                              // Tick labels color
    ui->plot->yAxis->setTickLabelColor(QColor(170,170,170));                              // See QCustomPlot examples / styled demo
    ui->plot->xAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    ui->plot->xAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    ui->plot->xAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setBasePen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setTickPen(QPen(QColor(170,170,170)));
    ui->plot->xAxis->setSubTickPen(QPen(QColor(170,170,170)));
    ui->plot->yAxis->setSubTickPen(QPen(QColor(170,170,170)));
    */

    /************ Seteo de colores GRAFICO 2 *****/

    /*
    pl->setBackground(QBrush(QColor(48,47,47)));                                    // Background for the plot area
    pl->xAxis->setTickLabelColor(QColor(170,170,170));                              // Tick labels color
    pl->yAxis->setTickLabelColor(QColor(170,170,170));                              // See QCustomPlot examples / styled demo
    pl->xAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    pl->yAxis->grid()->setPen(QPen(QColor(170,170,170), 1, Qt::DotLine));
    pl->xAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    pl->yAxis->grid()->setSubGridPen(QPen(QColor(80,80,80), 1, Qt::DotLine));
    pl->xAxis->setBasePen(QPen(QColor(170,170,170)));
    pl->yAxis->setBasePen(QPen(QColor(170,170,170)));
    pl->xAxis->setTickPen(QPen(QColor(170,170,170)));
    pl->yAxis->setTickPen(QPen(QColor(170,170,170)));
    pl->xAxis->setSubTickPen(QPen(QColor(170,170,170)));
    pl->yAxis->setSubTickPen(QPen(QColor(170,170,170)));
    */
}



/******************************************************************************************************************/
/* Reiniciar el zoom del grafico a los valores iniciales */
/******************************************************************************************************************/
void MainWindow::on_resetPlotButton_clicked()
{
    /********* GRAFICO 1 ********/
    ui->plot->yAxis->setRange(0, 4095);
    //ui->plot->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
    ui->plot->xAxis->setRange(0, NUMBER_OF_POINTS);
    ui->plot->yAxis->setTickStep(500);
    ui->plot->replot();

    /******** GRAFICO 2 ********/
    ui->plot2->yAxis->setRange(0, 4095);
    //ui->plot2->xAxis->setRange(dataPointNumber - NUMBER_OF_POINTS, dataPointNumber);
    ui->plot2->xAxis->setRange(0, NUMBER_OF_POINTS_TEMP);
    ui->plot2->yAxis->setTickStep(500);
    ui->plot2->replot();


}
/******************************************************************************************************************/
