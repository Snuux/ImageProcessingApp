#include "baseui.h"

QString BaseUI::channel;

MainWindow *BaseUI::getWindow(QWidget *parent)
{
    QWidget* widget = parent;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}

VImage& BaseUI::getImage(QWidget *parent)
{
    return getWindow(parent)->image;
}

VImage::ImageChannel BaseUI::getCurCh()
{
    if (BaseUI::channel == "Red Channel")
        return VImage::channelRed;
    else if (BaseUI::channel == "Green Channel")
        return VImage::channelGreen;
    else if (BaseUI::channel == "Blue Channel")
        return VImage::channelBlue;
    else
        return VImage::channelAll;
}

void BaseUI::setCurCh(QString a)
{
    BaseUI::channel = a;
}
