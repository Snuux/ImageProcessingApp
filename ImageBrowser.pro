#-------------------------------------------------
#
# Project created by QtCreator 2016-09-10T15:39:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = ImageBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vadimimage.cpp \
    libs/qcustomplot.cpp \
    histogramchange.cpp \
    brightnesscontrast.cpp \
    palette.cpp \
    binarization.cpp \
    togreyscale.cpp \
    scalerotate.cpp \
    convolution.cpp

HEADERS  += mainwindow.h \
    vadimimage.h \
    libs/qcustomplot.h \
    histogramchange.h \
    brightnesscontrast.h \
    palette.h \
    binarization.h \
    togreyscale.h \
    scalerotate.h \
    convolution.h

FORMS    += mainwindow.ui \
    histogramchange.ui \
    brightnesscontrast.ui \
    palette.ui \
    binarization.ui \
    togreyscale.ui \
    scalerotate.ui \
    convolution.ui

DISTFILES += \
    libs/qxtnamespace.qdoc
