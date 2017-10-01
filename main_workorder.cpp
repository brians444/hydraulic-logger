#include "mainwindow.hpp"
#include "ui_mainwindow.h"

void MainWindow::on_ordenDeTrabajoSpinBox_valueChanged(int arg1)
{
    work.ordenTrabajo = QString::number(arg1);
}

void MainWindow::on_clienteLineEdit_textChanged(const QString &arg1)
{
    work.cliente = arg1;
}

void MainWindow::on_fechaDateEdit_dateChanged(const QDate &date)
{
    work.fecha = date.toString();
}

void MainWindow::on_equipoLineEdit_textChanged(const QString &arg1)
{
    work.equipo = arg1;
}

void MainWindow::on_observacionesLineEdit_textChanged(const QString &arg1)
{
    work.observaciones = arg1;
}

void MainWindow::on_canal1LineEdit_textChanged(const QString &arg1)
{
    work.channelObs[0] = arg1;
}

void MainWindow::on_canal2LineEdit_textChanged(const QString &arg1)
{
    work.channelObs[1] = arg1;
}

void MainWindow::on_canal3LineEdit_textChanged(const QString &arg1)
{
    work.channelObs[2] = arg1;
}

void MainWindow::on_canal4LineEdit_textChanged(const QString &arg1)
{
    work.channelObs[3] = arg1;
}

