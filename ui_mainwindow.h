/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHow_to_use;
    QAction *actionAcerca_de;
    QAction *actionSalir;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QCustomPlot *plot;
    QCustomPlot *plot2;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *stopPlotButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *GraficoAleatorio;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *controlsLayout;
    QGroupBox *PortControlsBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPort;
    QComboBox *comboPort;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBaud;
    QComboBox *comboBaud;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelData;
    QComboBox *comboData;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParity;
    QComboBox *comboParity;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStop;
    QComboBox *comboStop;
    QPushButton *connectButton;
    QSpacerItem *verticalSpacer;
    QGroupBox *PlotControlsBox;
    QGridLayout *gridLayout_2;
    QVBoxLayout *plotControlsLayout;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_3;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelAxes;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *comboAxes;
    QComboBox *comboAxes2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *pointsLabel;
    QHBoxLayout *horizontalLayout_16;
    QSpinBox *spinPoints;
    QSpinBox *spinPoints2;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labelYStep;
    QHBoxLayout *horizontalLayout_15;
    QSpinBox *spinYStep;
    QSpinBox *spinYStep2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QHBoxLayout *horizontalLayout_12;
    QSpinBox *spinAxesMin;
    QSpinBox *spinAxesMin2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_13;
    QSpinBox *spinAxesMax;
    QSpinBox *spinAxesMax2;
    QPushButton *resetPlotButton;
    QPushButton *saveJPGButton;
    QWidget *tab_3;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_21;
    QFormLayout *formLayout_5;
    QDoubleSpinBox *offset1DoubleSpinBox;
    QLabel *offset1Label;
    QDoubleSpinBox *offset2DoubleSpinBox;
    QLabel *offset2Label;
    QLabel *offset3Label;
    QDoubleSpinBox *offset3DoubleSpinBox;
    QLabel *offset4Label;
    QDoubleSpinBox *offset4DoubleSpinBox;
    QLabel *offset5Label;
    QDoubleSpinBox *offset5DoubleSpinBox;
    QLabel *offset6Label;
    QDoubleSpinBox *offset6DoubleSpinBox;
    QLabel *label_9;
    QFormLayout *formLayout_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_20;
    QFormLayout *formLayout;
    QLabel *label_7;
    QLabel *ganacia1Label;
    QDoubleSpinBox *ganacia1DoubleSpinBox;
    QLabel *ganancia2Label;
    QDoubleSpinBox *ganancia2DoubleSpinBox;
    QLabel *ganancia3Label;
    QDoubleSpinBox *ganancia3DoubleSpinBox;
    QLabel *ganancia4Label;
    QDoubleSpinBox *ganancia4DoubleSpinBox;
    QLabel *ganancia5Label;
    QDoubleSpinBox *ganancia5DoubleSpinBox;
    QLabel *ganancia6Label;
    QDoubleSpinBox *ganancia6DoubleSpinBox;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *filtroCanal1Label;
    QDoubleSpinBox *filtroCanal1DoubleSpinBox;
    QLabel *filtroCanal2Label;
    QDoubleSpinBox *filtroCanal2DoubleSpinBox;
    QLabel *filtroCanal3Label;
    QDoubleSpinBox *filtroCanal3DoubleSpinBox;
    QLabel *filtroCanal4Label;
    QDoubleSpinBox *filtroCanal4DoubleSpinBox;
    QLabel *filtroCanal5Label;
    QDoubleSpinBox *filtroCanal5DoubleSpinBox;
    QLabel *filtroCanal6Label;
    QDoubleSpinBox *filtroCanal6DoubleSpinBox;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_4;
    QWidget *tab_5;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuHelo;
    QMenu *menuArchivo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 747);
        MainWindow->setMinimumSize(QSize(0, 0));
        actionHow_to_use = new QAction(MainWindow);
        actionHow_to_use->setObjectName(QStringLiteral("actionHow_to_use"));
        actionAcerca_de = new QAction(MainWindow);
        actionAcerca_de->setObjectName(QStringLiteral("actionAcerca_de"));
        actionSalir = new QAction(MainWindow);
        actionSalir->setObjectName(QStringLiteral("actionSalir"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plot = new QCustomPlot(tab);
        plot->setObjectName(QStringLiteral("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(plot);

        plot2 = new QCustomPlot(tab);
        plot2->setObjectName(QStringLiteral("plot2"));
        sizePolicy.setHeightForWidth(plot2->sizePolicy().hasHeightForWidth());
        plot2->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(plot2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        stopPlotButton = new QPushButton(tab);
        stopPlotButton->setObjectName(QStringLiteral("stopPlotButton"));
        stopPlotButton->setMinimumSize(QSize(0, 0));
        stopPlotButton->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_11->addWidget(stopPlotButton);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_11->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_11->addWidget(pushButton_3);

        GraficoAleatorio = new QPushButton(tab);
        GraficoAleatorio->setObjectName(QStringLiteral("GraficoAleatorio"));

        horizontalLayout_11->addWidget(GraficoAleatorio);


        verticalLayout->addLayout(horizontalLayout_11);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        controlsLayout = new QVBoxLayout();
        controlsLayout->setSpacing(6);
        controlsLayout->setObjectName(QStringLiteral("controlsLayout"));
        PortControlsBox = new QGroupBox(tab_2);
        PortControlsBox->setObjectName(QStringLiteral("PortControlsBox"));
        PortControlsBox->setFlat(false);
        PortControlsBox->setCheckable(false);
        gridLayout = new QGridLayout(PortControlsBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPort = new QLabel(PortControlsBox);
        labelPort->setObjectName(QStringLiteral("labelPort"));
        labelPort->setMaximumSize(QSize(80, 16777215));

        horizontalLayout->addWidget(labelPort);

        comboPort = new QComboBox(PortControlsBox);
        comboPort->setObjectName(QStringLiteral("comboPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboPort->sizePolicy().hasHeightForWidth());
        comboPort->setSizePolicy(sizePolicy1);
        comboPort->setMinimumSize(QSize(69, 0));
        comboPort->setMaximumSize(QSize(69, 16777215));

        horizontalLayout->addWidget(comboPort);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelBaud = new QLabel(PortControlsBox);
        labelBaud->setObjectName(QStringLiteral("labelBaud"));
        labelBaud->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_2->addWidget(labelBaud);

        comboBaud = new QComboBox(PortControlsBox);
        comboBaud->setObjectName(QStringLiteral("comboBaud"));
        sizePolicy1.setHeightForWidth(comboBaud->sizePolicy().hasHeightForWidth());
        comboBaud->setSizePolicy(sizePolicy1);
        comboBaud->setMinimumSize(QSize(69, 0));
        comboBaud->setMaximumSize(QSize(69, 16777215));
        comboBaud->setEditable(true);

        horizontalLayout_2->addWidget(comboBaud);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        labelData = new QLabel(PortControlsBox);
        labelData->setObjectName(QStringLiteral("labelData"));
        labelData->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_3->addWidget(labelData);

        comboData = new QComboBox(PortControlsBox);
        comboData->setObjectName(QStringLiteral("comboData"));
        sizePolicy1.setHeightForWidth(comboData->sizePolicy().hasHeightForWidth());
        comboData->setSizePolicy(sizePolicy1);
        comboData->setMinimumSize(QSize(69, 0));
        comboData->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_3->addWidget(comboData);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        labelParity = new QLabel(PortControlsBox);
        labelParity->setObjectName(QStringLiteral("labelParity"));
        labelParity->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_4->addWidget(labelParity);

        comboParity = new QComboBox(PortControlsBox);
        comboParity->setObjectName(QStringLiteral("comboParity"));
        sizePolicy1.setHeightForWidth(comboParity->sizePolicy().hasHeightForWidth());
        comboParity->setSizePolicy(sizePolicy1);
        comboParity->setMinimumSize(QSize(69, 0));
        comboParity->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_4->addWidget(comboParity);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        labelStop = new QLabel(PortControlsBox);
        labelStop->setObjectName(QStringLiteral("labelStop"));
        labelStop->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(labelStop);

        comboStop = new QComboBox(PortControlsBox);
        comboStop->setObjectName(QStringLiteral("comboStop"));
        sizePolicy1.setHeightForWidth(comboStop->sizePolicy().hasHeightForWidth());
        comboStop->setSizePolicy(sizePolicy1);
        comboStop->setMinimumSize(QSize(69, 0));
        comboStop->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_5->addWidget(comboStop);


        verticalLayout_3->addLayout(horizontalLayout_5);

        connectButton = new QPushButton(PortControlsBox);
        connectButton->setObjectName(QStringLiteral("connectButton"));
        connectButton->setMinimumSize(QSize(0, 0));
        connectButton->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(connectButton);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);


        controlsLayout->addWidget(PortControlsBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        controlsLayout->addItem(verticalSpacer);

        PlotControlsBox = new QGroupBox(tab_2);
        PlotControlsBox->setObjectName(QStringLiteral("PlotControlsBox"));
        gridLayout_2 = new QGridLayout(PlotControlsBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        plotControlsLayout = new QVBoxLayout();
        plotControlsLayout->setSpacing(6);
        plotControlsLayout->setObjectName(QStringLiteral("plotControlsLayout"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        label_5 = new QLabel(PlotControlsBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_18->addWidget(label_5);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        label_3 = new QLabel(PlotControlsBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(69, 16777215));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_3);

        label_4 = new QLabel(PlotControlsBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(69, 16777215));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_19->addWidget(label_4);


        horizontalLayout_18->addLayout(horizontalLayout_19);


        plotControlsLayout->addLayout(horizontalLayout_18);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        labelAxes = new QLabel(PlotControlsBox);
        labelAxes->setObjectName(QStringLiteral("labelAxes"));
        labelAxes->setMinimumSize(QSize(0, 0));
        labelAxes->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_6->addWidget(labelAxes);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        comboAxes = new QComboBox(PlotControlsBox);
        comboAxes->setObjectName(QStringLiteral("comboAxes"));
        comboAxes->setMinimumSize(QSize(0, 0));
        comboAxes->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_17->addWidget(comboAxes);

        comboAxes2 = new QComboBox(PlotControlsBox);
        comboAxes2->setObjectName(QStringLiteral("comboAxes2"));
        comboAxes2->setMaximumSize(QSize(69, 16777215));

        horizontalLayout_17->addWidget(comboAxes2);


        horizontalLayout_6->addLayout(horizontalLayout_17);


        plotControlsLayout->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pointsLabel = new QLabel(PlotControlsBox);
        pointsLabel->setObjectName(QStringLiteral("pointsLabel"));
        pointsLabel->setMinimumSize(QSize(50, 0));
        pointsLabel->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_10->addWidget(pointsLabel);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        spinPoints = new QSpinBox(PlotControlsBox);
        spinPoints->setObjectName(QStringLiteral("spinPoints"));
        spinPoints->setMinimumSize(QSize(69, 0));
        spinPoints->setMaximumSize(QSize(69, 16777215));
        spinPoints->setMinimum(10);
        spinPoints->setMaximum(100000);
        spinPoints->setValue(500);

        horizontalLayout_16->addWidget(spinPoints);

        spinPoints2 = new QSpinBox(PlotControlsBox);
        spinPoints2->setObjectName(QStringLiteral("spinPoints2"));
        spinPoints2->setMaximumSize(QSize(69, 16777215));
        spinPoints2->setMinimum(10);
        spinPoints2->setMaximum(100000);
        spinPoints2->setValue(500);

        horizontalLayout_16->addWidget(spinPoints2);


        horizontalLayout_10->addLayout(horizontalLayout_16);


        plotControlsLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        labelYStep = new QLabel(PlotControlsBox);
        labelYStep->setObjectName(QStringLiteral("labelYStep"));
        labelYStep->setMinimumSize(QSize(50, 0));
        labelYStep->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_9->addWidget(labelYStep);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        spinYStep = new QSpinBox(PlotControlsBox);
        spinYStep->setObjectName(QStringLiteral("spinYStep"));
        spinYStep->setMinimumSize(QSize(69, 0));
        spinYStep->setMaximumSize(QSize(69, 16777215));
        spinYStep->setMinimum(1);
        spinYStep->setMaximum(100000);
        spinYStep->setSingleStep(10);
        spinYStep->setValue(500);

        horizontalLayout_15->addWidget(spinYStep);

        spinYStep2 = new QSpinBox(PlotControlsBox);
        spinYStep2->setObjectName(QStringLiteral("spinYStep2"));
        spinYStep2->setMaximumSize(QSize(69, 16777215));
        spinYStep2->setMinimum(1);
        spinYStep2->setMaximum(100000);
        spinYStep2->setSingleStep(10);
        spinYStep2->setValue(500);

        horizontalLayout_15->addWidget(spinYStep2);


        horizontalLayout_9->addLayout(horizontalLayout_15);


        plotControlsLayout->addLayout(horizontalLayout_9);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label = new QLabel(PlotControlsBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_7->addWidget(label);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        spinAxesMin = new QSpinBox(PlotControlsBox);
        spinAxesMin->setObjectName(QStringLiteral("spinAxesMin"));
        spinAxesMin->setMinimumSize(QSize(69, 0));
        spinAxesMin->setMaximumSize(QSize(69, 16777215));
        spinAxesMin->setMinimum(-65536);
        spinAxesMin->setMaximum(65536);
        spinAxesMin->setSingleStep(10);

        horizontalLayout_12->addWidget(spinAxesMin);

        spinAxesMin2 = new QSpinBox(PlotControlsBox);
        spinAxesMin2->setObjectName(QStringLiteral("spinAxesMin2"));
        sizePolicy1.setHeightForWidth(spinAxesMin2->sizePolicy().hasHeightForWidth());
        spinAxesMin2->setSizePolicy(sizePolicy1);
        spinAxesMin2->setMinimumSize(QSize(0, 0));
        spinAxesMin2->setMaximumSize(QSize(69, 16777215));
        spinAxesMin2->setMinimum(-65536);
        spinAxesMin2->setMaximum(65536);
        spinAxesMin2->setSingleStep(10);

        horizontalLayout_12->addWidget(spinAxesMin2);


        horizontalLayout_7->addLayout(horizontalLayout_12);


        plotControlsLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_2 = new QLabel(PlotControlsBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(50, 0));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_8->addWidget(label_2);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        spinAxesMax = new QSpinBox(PlotControlsBox);
        spinAxesMax->setObjectName(QStringLiteral("spinAxesMax"));
        spinAxesMax->setMinimumSize(QSize(69, 0));
        spinAxesMax->setMaximumSize(QSize(69, 16777215));
        spinAxesMax->setMinimum(-65536);
        spinAxesMax->setMaximum(65536);
        spinAxesMax->setSingleStep(10);
        spinAxesMax->setValue(4095);

        horizontalLayout_13->addWidget(spinAxesMax);

        spinAxesMax2 = new QSpinBox(PlotControlsBox);
        spinAxesMax2->setObjectName(QStringLiteral("spinAxesMax2"));
        spinAxesMax2->setMaximumSize(QSize(69, 16777215));
        spinAxesMax2->setMinimum(-65536);
        spinAxesMax2->setMaximum(65536);
        spinAxesMax2->setSingleStep(10);
        spinAxesMax2->setValue(4095);

        horizontalLayout_13->addWidget(spinAxesMax2);


        horizontalLayout_8->addLayout(horizontalLayout_13);


        plotControlsLayout->addLayout(horizontalLayout_8);

        resetPlotButton = new QPushButton(PlotControlsBox);
        resetPlotButton->setObjectName(QStringLiteral("resetPlotButton"));

        plotControlsLayout->addWidget(resetPlotButton);

        saveJPGButton = new QPushButton(PlotControlsBox);
        saveJPGButton->setObjectName(QStringLiteral("saveJPGButton"));

        plotControlsLayout->addWidget(saveJPGButton);


        gridLayout_2->addLayout(plotControlsLayout, 0, 0, 1, 1);


        controlsLayout->addWidget(PlotControlsBox);


        verticalLayout_4->addLayout(controlsLayout);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        gridLayout_5 = new QGridLayout(tab_3);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        formLayout_5 = new QFormLayout();
        formLayout_5->setSpacing(6);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        offset1DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset1DoubleSpinBox->setObjectName(QStringLiteral("offset1DoubleSpinBox"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, offset1DoubleSpinBox);

        offset1Label = new QLabel(tab_3);
        offset1Label->setObjectName(QStringLiteral("offset1Label"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, offset1Label);

        offset2DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset2DoubleSpinBox->setObjectName(QStringLiteral("offset2DoubleSpinBox"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, offset2DoubleSpinBox);

        offset2Label = new QLabel(tab_3);
        offset2Label->setObjectName(QStringLiteral("offset2Label"));

        formLayout_5->setWidget(2, QFormLayout::LabelRole, offset2Label);

        offset3Label = new QLabel(tab_3);
        offset3Label->setObjectName(QStringLiteral("offset3Label"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, offset3Label);

        offset3DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset3DoubleSpinBox->setObjectName(QStringLiteral("offset3DoubleSpinBox"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, offset3DoubleSpinBox);

        offset4Label = new QLabel(tab_3);
        offset4Label->setObjectName(QStringLiteral("offset4Label"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, offset4Label);

        offset4DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset4DoubleSpinBox->setObjectName(QStringLiteral("offset4DoubleSpinBox"));

        formLayout_5->setWidget(4, QFormLayout::FieldRole, offset4DoubleSpinBox);

        offset5Label = new QLabel(tab_3);
        offset5Label->setObjectName(QStringLiteral("offset5Label"));

        formLayout_5->setWidget(5, QFormLayout::LabelRole, offset5Label);

        offset5DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset5DoubleSpinBox->setObjectName(QStringLiteral("offset5DoubleSpinBox"));

        formLayout_5->setWidget(5, QFormLayout::FieldRole, offset5DoubleSpinBox);

        offset6Label = new QLabel(tab_3);
        offset6Label->setObjectName(QStringLiteral("offset6Label"));

        formLayout_5->setWidget(6, QFormLayout::LabelRole, offset6Label);

        offset6DoubleSpinBox = new QDoubleSpinBox(tab_3);
        offset6DoubleSpinBox->setObjectName(QStringLiteral("offset6DoubleSpinBox"));

        formLayout_5->setWidget(6, QFormLayout::FieldRole, offset6DoubleSpinBox);

        label_9 = new QLabel(tab_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_9);


        horizontalLayout_21->addLayout(formLayout_5);

        formLayout_7 = new QFormLayout();
        formLayout_7->setSpacing(6);
        formLayout_7->setObjectName(QStringLiteral("formLayout_7"));
        checkBox = new QCheckBox(tab_3);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        formLayout_7->setWidget(1, QFormLayout::LabelRole, checkBox);

        checkBox_2 = new QCheckBox(tab_3);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        formLayout_7->setWidget(2, QFormLayout::LabelRole, checkBox_2);

        checkBox_3 = new QCheckBox(tab_3);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        formLayout_7->setWidget(3, QFormLayout::LabelRole, checkBox_3);

        checkBox_4 = new QCheckBox(tab_3);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        formLayout_7->setWidget(4, QFormLayout::LabelRole, checkBox_4);

        checkBox_5 = new QCheckBox(tab_3);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        formLayout_7->setWidget(5, QFormLayout::LabelRole, checkBox_5);

        checkBox_6 = new QCheckBox(tab_3);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        formLayout_7->setWidget(6, QFormLayout::LabelRole, checkBox_6);

        label_10 = new QLabel(tab_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_10);


        horizontalLayout_21->addLayout(formLayout_7);


        gridLayout_4->addLayout(horizontalLayout_21, 3, 0, 2, 1);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        ganacia1Label = new QLabel(tab_3);
        ganacia1Label->setObjectName(QStringLiteral("ganacia1Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, ganacia1Label);

        ganacia1DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganacia1DoubleSpinBox->setObjectName(QStringLiteral("ganacia1DoubleSpinBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ganacia1DoubleSpinBox);

        ganancia2Label = new QLabel(tab_3);
        ganancia2Label->setObjectName(QStringLiteral("ganancia2Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, ganancia2Label);

        ganancia2DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganancia2DoubleSpinBox->setObjectName(QStringLiteral("ganancia2DoubleSpinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, ganancia2DoubleSpinBox);

        ganancia3Label = new QLabel(tab_3);
        ganancia3Label->setObjectName(QStringLiteral("ganancia3Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, ganancia3Label);

        ganancia3DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganancia3DoubleSpinBox->setObjectName(QStringLiteral("ganancia3DoubleSpinBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, ganancia3DoubleSpinBox);

        ganancia4Label = new QLabel(tab_3);
        ganancia4Label->setObjectName(QStringLiteral("ganancia4Label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, ganancia4Label);

        ganancia4DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganancia4DoubleSpinBox->setObjectName(QStringLiteral("ganancia4DoubleSpinBox"));

        formLayout->setWidget(4, QFormLayout::FieldRole, ganancia4DoubleSpinBox);

        ganancia5Label = new QLabel(tab_3);
        ganancia5Label->setObjectName(QStringLiteral("ganancia5Label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, ganancia5Label);

        ganancia5DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganancia5DoubleSpinBox->setObjectName(QStringLiteral("ganancia5DoubleSpinBox"));

        formLayout->setWidget(5, QFormLayout::FieldRole, ganancia5DoubleSpinBox);

        ganancia6Label = new QLabel(tab_3);
        ganancia6Label->setObjectName(QStringLiteral("ganancia6Label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, ganancia6Label);

        ganancia6DoubleSpinBox = new QDoubleSpinBox(tab_3);
        ganancia6DoubleSpinBox->setObjectName(QStringLiteral("ganancia6DoubleSpinBox"));

        formLayout->setWidget(6, QFormLayout::FieldRole, ganancia6DoubleSpinBox);


        horizontalLayout_20->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        filtroCanal1Label = new QLabel(tab_3);
        filtroCanal1Label->setObjectName(QStringLiteral("filtroCanal1Label"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, filtroCanal1Label);

        filtroCanal1DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal1DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal1DoubleSpinBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, filtroCanal1DoubleSpinBox);

        filtroCanal2Label = new QLabel(tab_3);
        filtroCanal2Label->setObjectName(QStringLiteral("filtroCanal2Label"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, filtroCanal2Label);

        filtroCanal2DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal2DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal2DoubleSpinBox"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, filtroCanal2DoubleSpinBox);

        filtroCanal3Label = new QLabel(tab_3);
        filtroCanal3Label->setObjectName(QStringLiteral("filtroCanal3Label"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, filtroCanal3Label);

        filtroCanal3DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal3DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal3DoubleSpinBox"));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, filtroCanal3DoubleSpinBox);

        filtroCanal4Label = new QLabel(tab_3);
        filtroCanal4Label->setObjectName(QStringLiteral("filtroCanal4Label"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, filtroCanal4Label);

        filtroCanal4DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal4DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal4DoubleSpinBox"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, filtroCanal4DoubleSpinBox);

        filtroCanal5Label = new QLabel(tab_3);
        filtroCanal5Label->setObjectName(QStringLiteral("filtroCanal5Label"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, filtroCanal5Label);

        filtroCanal5DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal5DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal5DoubleSpinBox"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, filtroCanal5DoubleSpinBox);

        filtroCanal6Label = new QLabel(tab_3);
        filtroCanal6Label->setObjectName(QStringLiteral("filtroCanal6Label"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, filtroCanal6Label);

        filtroCanal6DoubleSpinBox = new QDoubleSpinBox(tab_3);
        filtroCanal6DoubleSpinBox->setObjectName(QStringLiteral("filtroCanal6DoubleSpinBox"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, filtroCanal6DoubleSpinBox);


        horizontalLayout_20->addLayout(formLayout_2);


        gridLayout_4->addLayout(horizontalLayout_20, 1, 0, 1, 1);

        label_6 = new QLabel(tab_3);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 700, 27));
        menuHelo = new QMenu(menuBar);
        menuHelo->setObjectName(QStringLiteral("menuHelo"));
        menuArchivo = new QMenu(menuBar);
        menuArchivo->setObjectName(QStringLiteral("menuArchivo"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuArchivo->menuAction());
        menuBar->addAction(menuHelo->menuAction());
        menuHelo->addAction(actionHow_to_use);
        menuHelo->addSeparator();
        menuHelo->addAction(actionAcerca_de);
        menuArchivo->addSeparator();
        menuArchivo->addSeparator();
        menuArchivo->addAction(actionSalir);

        retranslateUi(MainWindow);
        QObject::connect(actionSalir, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);
        comboAxes->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionHow_to_use->setText(QApplication::translate("MainWindow", "Como usarlo", 0));
        actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de...", 0));
        actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0));
        stopPlotButton->setText(QApplication::translate("MainWindow", "Stop Plot", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Graficar Temperatura", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", 0));
        GraficoAleatorio->setText(QApplication::translate("MainWindow", "Aleatorio", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Grafico", 0));
        PortControlsBox->setTitle(QApplication::translate("MainWindow", "CONFIGURACION DEL PUERTO", 0));
        labelPort->setText(QApplication::translate("MainWindow", "PUERTO", 0));
        labelBaud->setText(QApplication::translate("MainWindow", "BAUDIOS", 0));
        labelData->setText(QApplication::translate("MainWindow", "BITS DE DATOS", 0));
        labelParity->setText(QApplication::translate("MainWindow", "PARIDAD", 0));
        labelStop->setText(QApplication::translate("MainWindow", "BIT DE PARADA", 0));
        connectButton->setText(QApplication::translate("MainWindow", "Conectar", 0));
        PlotControlsBox->setTitle(QApplication::translate("MainWindow", "CONTROLES DEL GRAFICO", 0));
        label_5->setText(QApplication::translate("MainWindow", "GRAFICO", 0));
        label_3->setText(QApplication::translate("MainWindow", "1", 0));
        label_4->setText(QApplication::translate("MainWindow", "2", 0));
        labelAxes->setText(QApplication::translate("MainWindow", "EJES", 0));
        comboAxes2->clear();
        comboAxes2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
        );
        pointsLabel->setText(QApplication::translate("MainWindow", "PUNTOS", 0));
        labelYStep->setText(QApplication::translate("MainWindow", "Y STEP", 0));
        label->setText(QApplication::translate("MainWindow", "MINIMO", 0));
        label_2->setText(QApplication::translate("MainWindow", "MAXIMO", 0));
        resetPlotButton->setText(QApplication::translate("MainWindow", "Resetear Grafico", 0));
        saveJPGButton->setText(QApplication::translate("MainWindow", "Guardar Grafico", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Configuracion", 0));
        offset1Label->setText(QApplication::translate("MainWindow", "Offset 1", 0));
        offset2Label->setText(QApplication::translate("MainWindow", "Offset 2", 0));
        offset3Label->setText(QApplication::translate("MainWindow", "Offset 3", 0));
        offset4Label->setText(QApplication::translate("MainWindow", "Offset 4", 0));
        offset5Label->setText(QApplication::translate("MainWindow", "Offset 5", 0));
        offset6Label->setText(QApplication::translate("MainWindow", "Offset 6", 0));
        label_9->setText(QApplication::translate("MainWindow", "Offsets", 0));
        checkBox->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 1", 0));
        checkBox_2->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 2", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 3", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 4", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 5", 0));
        checkBox_6->setText(QApplication::translate("MainWindow", "Habilitar se\303\261al 6", 0));
        label_10->setText(QApplication::translate("MainWindow", "Se\303\261ales", 0));
        label_7->setText(QApplication::translate("MainWindow", "Ganancias", 0));
        ganacia1Label->setText(QApplication::translate("MainWindow", "Ganacia 1", 0));
        ganancia2Label->setText(QApplication::translate("MainWindow", "Ganancia 2", 0));
        ganancia3Label->setText(QApplication::translate("MainWindow", "Ganancia 3", 0));
        ganancia4Label->setText(QApplication::translate("MainWindow", "Ganancia 4", 0));
        ganancia5Label->setText(QApplication::translate("MainWindow", "Ganancia 5", 0));
        ganancia6Label->setText(QApplication::translate("MainWindow", "Ganancia 6", 0));
        label_8->setText(QApplication::translate("MainWindow", "Filtros Pasa bajos", 0));
        filtroCanal1Label->setText(QApplication::translate("MainWindow", "Filtro Canal 1", 0));
        filtroCanal2Label->setText(QApplication::translate("MainWindow", "Filtro Canal 2", 0));
        filtroCanal3Label->setText(QApplication::translate("MainWindow", "Filtro Canal 3", 0));
        filtroCanal4Label->setText(QApplication::translate("MainWindow", "Filtro Canal 4", 0));
        filtroCanal5Label->setText(QApplication::translate("MainWindow", "Filtro Canal 5", 0));
        filtroCanal6Label->setText(QApplication::translate("MainWindow", "Filtro Canal 6", 0));
        label_6->setText(QApplication::translate("MainWindow", "Calibraciones de se\303\261ales", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Calibracion", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Historico", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Orden de trabajo", 0));
        menuHelo->setTitle(QApplication::translate("MainWindow", "Ayuda", 0));
        menuArchivo->setTitle(QApplication::translate("MainWindow", "Archivo", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
