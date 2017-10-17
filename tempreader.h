#ifndef TEMPREADER_H
#define TEMPREADER_H

#include <QThread>
#include <QTimer>
#include <QDebug>

// temperatura incs
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>



class tempReader : public QThread
{
    Q_OBJECT
public:
    tempReader();
    void run();
    void setInterval(int ms);
    float getLastTemp(unsigned int n);
    void stop();

private slots:
    //Lectura de temperaturas
     void LeerTemperatura();

signals:
     void plotTemps(float a, float b);

private:
     QTimer tempLector;
     float last_temp_1, last_temp_2;
     void TempSensorInit();

     long ms_timer;

     int fd; // File descriptor

     DIR *dir;
     struct dirent *dirent;
     char dev[16];      // Dev ID
     char devPath[128]; // Path to device
     char buf[256];     // Data from device
     char tmpData[6];   // Temp C * 1000 reported by device
     char path[20];
     ssize_t numRead;
};

#endif // TEMPREADER_H
