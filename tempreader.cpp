#include "tempreader.h"

#include <iostream>
#include <ctime>

unsigned t3, t4;

tempReader::tempReader()
{
    TempSensorInit();
    ms_timer = 500;
    tempLector.setInterval(ms_timer);


    //tempLector.start();
    //QTimer* timer = new QTimer(this);
    // Read temp continuously
    // Opening the device's file triggers new reading
    fd = open(devPath, O_RDONLY);



}

void tempReader::setInterval(int ms)
{
    ms_timer = ms;
    tempLector.setInterval(ms);
}

void tempReader::run()
{
    tempLector.start();
    exec();
}

void tempReader::LeerTemperatura()
{
#ifdef MEASURE_TIME
    t3=clock();
#endif
    qDebug()<<"Tiempo entre ADS: "<<time;
    if(fd == -1)
    {
        perror ("Couldn't open the w1 device.");
        return;
    }
    else
    {
        lseek(fd, 0, SEEK_SET);
    }
    if((numRead = read(fd, buf, 256)) > 0)
    {
        strncpy(tmpData, strstr(buf, "t=") + 2, 5);
        float tempC = strtof(tmpData, NULL);
        tempC /= 1000.0;
        qDebug() << "Device: " << dev;
        qDebug() << "Temp:  " << tempC << "C";
        last_temp_1 = tempC;
        last_temp_2 = 0.0;
        //emit plotTemps(tempC, 0.0);
    }
    /****** Se midio el tiempo y se encontro que la lectura lleva 0.025 segundos de tiempo.*/
 #ifdef MEASURE_TIME
    t4=clock();
    double time = (double(t4-t3)/CLOCKS_PER_SEC);
    qDebug() << "Tiempo adquisicion temperatura"<<time;
#endif
}

float tempReader::getLastTemp(unsigned int n)
{
    if(n == 1)
    {
        return last_temp_1;
    }
    else if(n== 2)
    {
        return last_temp_2;
    }

    return 0.0;
}

void tempReader::TempSensorInit()
{
    connect(&tempLector, SIGNAL(timeout()), this, SLOT(LeerTemperatura()));

    strcpy(path, "/sys/bus/w1/devices");
    dir = opendir (path);
    if (dir != NULL)
    {
       // #ifdef LINUX
        while ((dirent = readdir (dir)))
        // 1-wire devices are links beginning with 28-
        if (dirent->d_type == DT_LNK && strstr(dirent->d_name, "28-") != NULL)
        {
            strcpy(dev, dirent->d_name);
            printf("\nDevice: %s\n", dev);
        }
        closedir (dir);
     //   #endif
    }
    else
    {
        perror ("Couldn't open the w1 devices directory");
        return;
    }
    // Assemble path to OneWire device
    sprintf(devPath, "%s/%s/w1_slave", path, dev);
}

void tempReader::stop()
{
    this->tempLector.stop();
}
