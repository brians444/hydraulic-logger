#include "mainwindow.hpp"
#include "ui_mainwindow.h"



/******************************************************************************************************************/
/* Save a JPG image of the plot to current EXE directory */
/******************************************************************************************************************/
void MainWindow::on_saveJPGButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Exportar Grafico", QString(), "*.jpg");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".jpg");
    }
    fileName = QFileInfo(fileName).baseName();
    QString file2 = fileName.prepend("2_");

    bool ok = ui->plot->saveJpg(fileName);
    qDebug()<< "Nombre: "+fileName+" jpg 1 ="<<ok;
    ok = ui->plot2->saveJpg(file2);
    qDebug()<< "Nombre: "+file2+" jpg 2 ="<<ok;

    exportarExcel();

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


/************************** Guardar en Excel ************************
 *      Exportamos los datos en un Excel
 * *******************************************************************/
void MainWindow::exportarExcel()
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export Excel", QString(), "*.xlsx");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".xlsx");
    }

    int tmp;
    xlsx.write(1, 1, "Tiempo");

    for(int i = 0; i < numberOfAxes; i++)
    {
        xlsx.write(1, i+2, "Datos "+QString::number(i));
    }

    int columnas = datos.size()/numberOfAxes;
    for(int i = 0; i < columnas;  i++)
    {
        /************ escribo el tiempo ***********/
        xlsx.write(i+2, 1, i);
        for(int j = 0; j < numberOfAxes; j++)
        {
            int ub = (i*numberOfAxes)+j;

            qDebug() << "Ubicacion : "<<ub;
            tmp = datos[ub].toInt();
            /************** escribo los datos ****************/
            xlsx.write(i+2, 2+j, tmp);
        }
    }
    xlsx.saveAs(fileName);
}
