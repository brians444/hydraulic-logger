#include "mainwindow.hpp"
#include "ui_mainwindow.h"



/******************************************************************************************************************/
/* Save a JPG image of the plot to current EXE directory */
/******************************************************************************************************************/
void MainWindow::on_saveJPGButton_clicked()
{
    QString file2;
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Exportar Grafico", QString(), "*.jpg");
    file2 = fileName;
    if (QFileInfo(fileName).suffix().isEmpty())
    {

        file2.append("_2.jpg");
        fileName.append(".jpg");

    }
    else
    {
        file2.remove(".jpg");
        file2.append("_2.jpg");

    }
    //fileName = QFileInfo(fileName).baseName();

    bool ok = ui->plot->saveJpg(fileName);
    qDebug()<< "Nombre: "+fileName+" jpg 1 ="<<ok;
    ok = ui->plot2->saveJpg(file2);
    qDebug()<< "Nombre: "+file2+" jpg 2 ="<<ok;



    /*
    QString nombre = QString::number(dataPointNumber) + ".jpg";
    ok = ui->plot->saveJpg(nombre);
    qDebug()<< nombre+" jpg 1 ="<<ok;
    nombre.clear();
    nombre.append(QString::number(dataPointNumber) + "_2.jpg");
    ok = ui->plot->saveJpg(nombre);
    qDebug()<< nombre+" jpg 2 ="<<ok;
    */


    // ui->plot->saveBmp();
    // ui->plot->savePdf();
    // ui->plot->savePng();

}
/******************************************************************************************************************/

