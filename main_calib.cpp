#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/************************ PAGINA DE CALIBRACION *****************/
void MainWindow::on_ganacia1DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[0] = arg1;
}

void MainWindow::on_ganancia2DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[1] = arg1;
}

void MainWindow::on_ganancia3DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[2] = arg1;
}

void MainWindow::on_ganancia4DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[3] = arg1;
}

void MainWindow::on_ganancia5DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[4] = arg1;
}

void MainWindow::on_ganancia6DoubleSpinBox_valueChanged(double arg1)
{
    ganancias[5] = arg1;
}


void MainWindow::on_filtroCanal1DoubleSpinBox_valueChanged(double arg1)
{
    filtro[0] = arg1;
}

void MainWindow::on_filtroCanal2DoubleSpinBox_valueChanged(double arg1)
{
    filtro[1] = arg1;
}

void MainWindow::on_filtroCanal3DoubleSpinBox_valueChanged(double arg1)
{
    filtro[2] = arg1;
}

void MainWindow::on_filtroCanal4DoubleSpinBox_valueChanged(double arg1)
{
    filtro[3] = arg1;
}

void MainWindow::on_filtroCanal5DoubleSpinBox_valueChanged(double arg1)
{
    filtro[4] = arg1;
}

void MainWindow::on_filtroCanal6DoubleSpinBox_valueChanged(double arg1)
{
    filtro[5] = arg1;
}


void MainWindow::on_offset1DoubleSpinBox_valueChanged(double arg1)
{
    offset[0] = arg1;
}

void MainWindow::on_offset2DoubleSpinBox_valueChanged(double arg1)
{
    offset[1] = arg1;
}

void MainWindow::on_offset3DoubleSpinBox_valueChanged(double arg1)
{
    offset[2] = arg1;
}

void MainWindow::on_offset4DoubleSpinBox_valueChanged(double arg1)
{
    offset[3] = arg1;
}

void MainWindow::on_offset5DoubleSpinBox_valueChanged(double arg1)
{
    offset[4] = arg1;
}

void MainWindow::on_offset6DoubleSpinBox_valueChanged(double arg1)
{
    offset[5] = arg1;
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    habilitado[0] = checked;
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    habilitado[1] = checked;
}

void MainWindow::on_checkBox_3_clicked(bool checked)
{
    habilitado[2] = checked;
}

void MainWindow::on_checkBox_4_clicked(bool checked)
{
    habilitado[3] = checked;
}

void MainWindow::on_checkBox_5_clicked(bool checked)
{
    habilitado[4] = checked;
}

void MainWindow::on_checkBox_6_clicked(bool checked)
{
    habilitado[5] = checked;
}

void MainWindow::procesarSignals()
{

}
