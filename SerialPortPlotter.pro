#-------------------------------------------------
#
# Project created by QtCreator 2014-12-22T14:53:33
#
# En linux isntala qtbase5-private-dev para que encuentre
# el include <private/qzipwriter_p.h>
#-------------------------------------------------

QT       += core gui
QT       += serialport
CONFIG += c++11

include(3rdparty/qtxlsx/src/xlsx/qtxlsx.pri)

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = SerialPortPlotter
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    	qcustomplot.cpp \
    helpwindow.cpp \
    mainplot.cpp \
    maincontrols.cpp \
    main_calib.cpp \
    main_registro.cpp \
    signals.cpp \
    main_workorder.cpp

HEADERS  += mainwindow.hpp \
    		qcustomplot.h \
    helpwindow.hpp \
    signals.h


FORMS    += mainwindow.ui \
    helpwindow.ui

RC_FILE = myapp.rc

RESOURCES += \
    appresources.qrc


