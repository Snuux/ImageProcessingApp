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
    libs/qcustomplot.cpp \
    histogramchange.cpp \
    brightnesscontrast.cpp \
    palette.cpp \
    binarization.cpp \
    togreyscale.cpp \
    scalerotate.cpp \
    convolution.cpp \
    curvecorrection.cpp \
    hsvcorrection.cpp \
    blackwhitepoint.cpp \
    medianborderfilter.cpp \
    vimage.cpp \
    vimageloader.cpp \
    vimagemem.cpp \
    boxgauss.cpp \
    addcolor.cpp \
    baseui.cpp

HEADERS  += mainwindow.h \
    libs/qcustomplot.h \
    histogramchange.h \
    brightnesscontrast.h \
    palette.h \
    binarization.h \
    togreyscale.h \
    scalerotate.h \
    convolution.h \
    curvecorrection.h \
    hsvcorrection.h \
    blackwhitepoint.h \
    medianborderfilter.h \
    vimage.h \
    vimageloader.h \
    vimagemem.h \
    baseui.h \
    boxgauss.h \
    addcolor.h

FORMS    += mainwindow.ui \
    histogramchange.ui \
    brightnesscontrast.ui \
    palette.ui \
    binarization.ui \
    togreyscale.ui \
    scalerotate.ui \
    convolution.ui \
    curvecorrection.ui \
    hsvcorrection.ui \
    blackwhitepoint.ui \
    medianborderfilter.ui \
    boxgauss.ui \
    addcolor.ui

DISTFILES += \
    libs/qxtnamespace.qdoc
