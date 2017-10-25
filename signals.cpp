#include "signals.h"
#include <QImageReader>

#define DEBUG 0
#define SAMPLERATE 1000
#define DEFAULTFC 100

#define RES 150

Signals::Signals()
{
    for(int i = 0; i <  4; i++)
    {
        ganancias[i] = 1;
        filtro[i] = 100.0;
        offset[i] = 0.0;
        x1[i] = 0;
        x2[i] = 0;
        x0[i] = 0;
        y0[i] = 0;
        y1[i] = 0;
        y2[i] = 0;
    }
    initFilter();

}

Signals::~Signals()
{
    this->datos.clear();
    last_update.clear();
    last_filtered.clear();
    last_value.clear();
}

void Signals::initFilter()
{
    filter = 1;
    for(int i = 0; i<4; i++)
    {
        getLPCoefficientsButterworth2Pole(SAMPLERATE, filtro[i], i);
    }
}


double Signals::Filtro(double x, int m)
{
    int i = m;

    if(filter)
    {

        x2[m] = x1[m]; x1[m] = x0[m];
        x0[m] = x;

        y2[m] = y1[m]; y1[m] = y0[m];
        #if DEBUG
        qDebug() << "Filtro ("<<m<<") :";
        qDebug() << "Entrada = "<<x0[m];
        #endif
        // y(n)  =  b0.x(n) + b1.x(n-1) + b2.x(n-2) + a1.y(n-1) + a2.y(n-2)


        y0[m] = ( b0[m]*x0[m] ) + ( b1[m]*x1[m] ) + (b2[m]*x2[m]) - (a1[m]*y1[m]) -(a2[m]*y2[m]) ;



        #if DEBUG
        qDebug() << "Salida = "<<y0[m];
        //qDebug() << "Filtro constantes["<<m<<"]: "<<cte1[m]<<", "<<cte2[m]<<", "<<cte3[m];
        //qDebug() << "Valor actual: "<<tmp<< "x-1 = "<< x1[m] <<" x-2= "<<x2[m];
        #endif
        return y0[m];
    }
    else
        return x;

}

void Signals::filterOn()
{
    filter = true;
}

void Signals::filterOff()
{
    filter = false;
}

QStringList Signals::append(QStringList d, unsigned int cant)
{
    datos.append(d);
    last_value = d;
    QStringList valores_pasados = last_update;
    last_update.clear();
    double value;
    #if DEBUG
    qDebug() << "Append filter";
    #endif
    for(int i = 0; i < cant; i++)
    {
        value = (double)d[i].toInt()*1.0;
        /* Conversion de tension a presion
         * Como utilizamos una R=150 ohm
        */
        value = (value)*(3.3/4096.0);
        value = (value-0.592)*(2/3);

        /*if(value < 4096 && value >= 0)
        {*/
            #if DEBUG
            qDebug() << "Valor["<<QString::number(i)<<"] : "<<value;
            #endif
            value = Filtro(value, i);
            value = value*ganancias[i];
            value = value+offset[i];
            last_update.append(QString::number(value));
        //}
        /*else
        {
            #if DEBUG
            qDebug() << "Valor anterior ya que se excede del deseado;
            #endif
            if(!valores_pasados.isEmpty())
                last_update.append((valores_pasados.at(i)));
            else
                last_update.append(QString::number(value));
        }*/
    }
    #if DEBUG
    qDebug() << "Lista = "<<last_update;
    #endif
    return last_update;
}

void Signals::getLPCoefficientsButterworth2Pole(int samplerate, double cutoff, int m)
{
    double PI      = 3.1415926535897932385;
    double sqrt2 = 1.4142135623730950488;

    double QcRaw  = (2 * PI * cutoff) / samplerate; // Find cutoff frequency in [0..PI]
    double QcWarp = tan(QcRaw); // Warp cutoff frequency

    double gain = 1 / (1+sqrt2/QcWarp + 2/(QcWarp*QcWarp));

    a2[m] = (1 - sqrt2/QcWarp + 2/(QcWarp*QcWarp)) * gain;
    a1[m] = (2 - 2 * 2/(QcWarp*QcWarp)) * gain;
    a0[m] = 1;

    b2[m] = 1 * gain;
    b1[m] = 2 * gain;
    b0[m] = 1 * gain;

    qDebug()<< "Coeficientes ("<<m<<") ";
    qDebug() << "b0: "<<b0[m];
    qDebug() << "b1: "<<b1[m];
    qDebug() << "b2: "<<b2[m];

    qDebug() << "a0: "<<a0[m];
    qDebug() << "a1: "<<a1[m];
    qDebug() << "a2: "<<a2[m];
}

QStringList Signals::lastValueUpdate()
{
    return this->last_update;
}

QStringList Signals::lastValueFiltered()
{
    return this->last_filtered;
}

QStringList Signals::lastValue()
{
    return this->last_value;
}

void Signals::setGain(int n, double g)
{
    if(n < CANALES)
        ganancias[n] = g;
}

void Signals::setFilter(int m, double fc)
{
    if(m < CANALES)
    {
        filtro[m] = fc;
        getLPCoefficientsButterworth2Pole(SAMPLERATE, fc, m);
    }
}


void Signals::setOffset(int n, double g)
{
    if(n < CANALES)
        offset[n] = g;
}


/************************** Guardar en Excel ************************
 *      Exportamos los datos en un Excel
 * *******************************************************************/
void Signals::exportarExcel(WorkOrder *a)
{

    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export Excel", QString(), "*.xlsx");
    if (QFileInfo(fileName).suffix().isEmpty())
    {
        fileName.append(".xlsx");
    }

    /**************+ CARGA DE ORDEN DE TRABAJO **********************/
    xlsx.addSheet("Orden de trabajo");
    QXlsx::Worksheet *sheet = xlsx.currentWorksheet();

    QImageReader imagen;
    imagen.setFileName("logo.jpg");
    qDebug()<<"Tamaño de imagen" << imagen.size();

    sheet->insertImage(10,10, imagen.read());
    sheet->write(1, 1, "Cliente");
    sheet->write(1, 2, "Orden de trabajo");
    sheet->write(1, 3, "Fecha");
    sheet->write(1, 4, "Equipo");
    sheet->write(1, 5, "Observaciones");

    sheet->write(2, 1, a->cliente);
    sheet->write(2, 2, a->ordenTrabajo);
    sheet->write(2, 3, a->fecha);
    sheet->write(2, 4, a->equipo);
    sheet->write(2, 5, a->observaciones);


    /**************** FIN CARGA ORDEN DE TRABAJO ******************/

    /**************+ CARGA DATOS DE CALIBRACION **********************/
    xlsx.addSheet("Datos de calibracion");
    QXlsx::Worksheet *sheet2 = xlsx.currentWorksheet();

    sheet2->write(1, 1, "Ganancias");
    sheet2->write(1, 2, "Filtros");
    sheet2->write(1, 3, "Habilitado");
    sheet2->write(1, 4, "Offset");
    sheet2->write(1, 5, "Observaciones");

    for(int i = 0; i<CANALES; i++)
    {
        sheet2->write(i+2,1, ganancias[i]);
        sheet2->write(i+2,2, filtro[i]);
        //sheet->write(i+2,3, this-[i]);
        sheet2->write(i+2,4, offset[i]);
        sheet2->write(i+2,5, a->channelObs[i]);
    }
    /**************** FIN CARGA DATOS DE CALIBRACION ******************/

    xlsx.addSheet("Datos");
    QXlsx::Worksheet *sheet3 = xlsx.currentWorksheet();


    int tmp;
    sheet3->write(1, 1, "Tiempo");

    for(int i = 0; i < CANALES; i++)
    {
        sheet3->write(1, i+2, "Datos "+QString::number(i));
    }

    int columnas = this->datos.size()/CANALES;
    for(int i = 0; i < columnas;  i++)
    {
        /************ escribo el tiempo ***********/
        sheet3->write(i+2, 1, i);
        for(int j = 0; j < CANALES/2; j++)
        {
            int ub = (i*(CANALES/2))+j;
            #if DEBUG
            qDebug() << "Ubicacion : "<<ub;
            #endif
            tmp = datos[ub].toInt();
            /************** escribo los datos ****************/
            sheet3->write(i+2, 2+j, tmp);
        }
    }

    xlsx.saveAs(fileName);
}

/*
void CalcFilter()
{
     *  y(n)  =  b0.x(n) + b1.x(n-1) + b2.x(n-2) + a1.y(n-1) + a2.y(n-2)
     * if(argc < 4)
    {
        printf("Usage: %s n s f\n", argv[0]);
        printf("Butterworth lowpass filter.\n");
        printf("  n = filter order 2,4,6,...\n");
        printf("  s = sampling frequency\n");
        printf("  f = half power frequency\n");
        return(-1);
    }

    int n = 2;  // Orden del filtro
    n = n/2;
    double s = 1000;       // Frecuencia de muestreo
    double f = 100;        // Frecuencia de corte
    double a = tan(M_PI*f/s);
    double a2 = a*a;
    double r;
    double *A = (double *)malloc(n*sizeof(double));
    double *d1 = (double *)malloc(n*sizeof(double));
    double *d2 = (double *)malloc(n*sizeof(double));

    for(int i=0; i<n; ++i){
      r = sin(M_PI*(2.0*i+1.0)/(4.0*n));
      s = a2 + 2.0*a*r + 1.0;
      A[i] = a2/s;
      d1[i] = 2.0*(1-a2)/s;
      d2[i] = -(a2 - 2.0*a*r + 1.0)/s;

      qDebug() << (1/A[i]);
      qDebug() << d1[i];
      qDebug() << d2[i];
    }
}
*/
