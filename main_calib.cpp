#include "mainwindow.hpp"
#include "ui_mainwindow.h"


/************************ PAGINA DE CALIBRACION *****************/
void MainWindow::on_ganacia1DoubleSpinBox_valueChanged(double arg1)
{
    signal.setGain(0 ,arg1);
}

void MainWindow::on_ganancia2DoubleSpinBox_valueChanged(double arg1)
{
    signal.setGain(1 ,arg1);
}

void MainWindow::on_ganancia3DoubleSpinBox_valueChanged(double arg1)
{
    signal.setGain(2 ,arg1);
}

void MainWindow::on_ganancia4DoubleSpinBox_valueChanged(double arg1)
{
    signal.setGain(3 ,arg1);
}


void MainWindow::on_filtroCanal1DoubleSpinBox_valueChanged(double arg1)
{
    signal.setFilter(0 ,arg1);
}

void MainWindow::on_filtroCanal2DoubleSpinBox_valueChanged(double arg1)
{
    signal.setFilter(1 ,arg1);
}

void MainWindow::on_filtroCanal3DoubleSpinBox_valueChanged(double arg1)
{
    signal.setFilter(2 ,arg1);
}

void MainWindow::on_filtroCanal4DoubleSpinBox_valueChanged(double arg1)
{
    signal.setFilter(3 ,arg1);
}
void MainWindow::on_offset1DoubleSpinBox_valueChanged(double arg1)
{
    signal.setOffset(0 ,arg1);
}

void MainWindow::on_offset2DoubleSpinBox_valueChanged(double arg1)
{
    signal.setOffset(1 ,arg1);
}

void MainWindow::on_offset3DoubleSpinBox_valueChanged(double arg1)
{
    signal.setOffset(2 ,arg1);
}

void MainWindow::on_offset4DoubleSpinBox_valueChanged(double arg1)
{
    signal.setOffset(3 ,arg1);
}

void MainWindow::on_signal1Check_clicked(bool checked)
{
    habilitado[0] = checked;
}

void MainWindow::on_signal2Check_clicked(bool checked)
{
    habilitado[1] = checked;
}

void MainWindow::on_signal3Check_clicked(bool checked)
{
    habilitado[2] = checked;
}

void MainWindow::on_signal4Check_clicked(bool checked)
{
    habilitado[3] = checked;
}

void MainWindow::procesarSignals()
{
}


void MainWindow::on_gainCheckBox_clicked(bool checked)
{
    ganancias = checked;

}

void MainWindow::on_filterCheckBox_clicked(bool checked)
{
    filtrar = checked;
    if(filtrar)
        signal.filterOn();
    else
        signal.filterOff();
}
