#ifndef SIGNALS_H
#define SIGNALS_H

#include <QStringList>
#include <QFileDialog>
#include <QFileInfo>
#include <QDebug>
#include <QPicture>

/*************** Excel Writer ************/
#include "xlsxdocument.h"
#include "xlsxworksheet.h"

#define CANALES 4


struct WorkOrder{
    QString ordenTrabajo;
    QString cliente;
    QString fecha;
    QString equipo;
    QString observaciones;

    QString channelObs[6];
};


void CalcFilter();

class Signals
{
private:
    double ganancias[6];
    double offset[6];
    double filtro[6];

    double x0[6];
    double x1[6];           // Valor x-1 para filtrado
    double x2[6];           // Valor x-2 para filtrado
    double y0[6];
    double y1[6];           // Valor x-1 para filtrado
    double y2[6];           // Valor x-2 para filtrado


    double b0[6];          // Constantes de filtrado
    double b1[6];          // Constantes de filtrado
    double b2[6];          // Constantes de filtrado
    double a0[6];          // Constantes de filtrado
    double a1[6];          // Constantes de filtrado
    double a2[6];          // Constantes de filtrado

    void getLPCoefficientsButterworth2Pole(int samplerate, double cutoff, int m);

    QStringList last_value;


    QXlsx::Document xlsx;
    QStringList datos;
    QStringList last_update, last_filtered;
    bool filter;

    void initFilter();

public:
    Signals();
    double Filtro(double x, int i);

    QStringList append(QStringList d, unsigned int cant);
    void filterOff();
    void filterOn();

    void setOffset(int n, double g);
    void setGain(int n, double g);
    void setFilter(int n, double g);
    void exportarExcel(WorkOrder *a);



    QStringList lastValue();
    QStringList lastValueUpdate();
    QStringList lastValueFiltered();

};



#endif // SIGNALS_H
