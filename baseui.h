#ifndef BASEUI_H
#define BASEUI_H

#include "mainwindow.h"
#include "vimage.h"
#include <QString>

class BaseUI
{
public:
    BaseUI(){  }

    static QString channel;
    static MainWindow *getWindow(QWidget *parent);
    static VImage& getImage(QWidget *parent);
    static VImage::ImageChannel getCurCh();
    static void setCurCh(QString a);

};

#endif // BASEUI_H
