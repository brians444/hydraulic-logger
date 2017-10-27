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
**           Author: Borislav                                             **
**           Contact: b.kereziev@gmail.com                                **
**           Date: 29.12.14                                               **
****************************************************************************/

#include "mainwindow.hpp"
#include <QApplication>
#include <QSplashScreen>
#include <qthread.h>

class I : public QThread
{
public:
    static void sleep(unsigned long secs) { QThread::sleep(secs); }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
    QFile file(":/StyleSheet/StyleSheet/style.qss");                            // Apply style sheet
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        a.setStyleSheet(file.readAll());
        file.close();
    }*/
    QPixmap pixmap(":splash.jpg");
    QSplashScreen splash(pixmap);
    splash.show();

    MainWindow w;
    QIcon appIcon(":/Icons/Icons/serial_port_icon.icns");                       // Get the icon for the right corner
    w.setWindowIcon(appIcon);
    w.setWindowTitle("Graficador de Curva de presion");


    QTimer::singleShot(4000, &splash,SLOT(close())); // Timer
    QTimer::singleShot(4000,&w,SLOT(showMaximized()));
//    I::sleep(5); // splash is shown for 5 seconds


//    w.showMaximized();
//    splash.finish(&w);


    return a.exec();
}
