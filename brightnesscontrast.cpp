#include "brightnesscontrast.h"
#include "ui_brightnesscontrast.h"

#include <QDebug>

BrightnessContrast::BrightnessContrast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrightnessContrast)
{
    ui->setupUi(this);

    //qDebug() << parentWidget()->parentWidget()->parentWidget()->parentWidget()->width();
    //qDebug() << parentWidget()->parentWidget()->parentWidget()->parentWidget()->width();
    //w = qobject_cast<MainWindow *>(parent->parent()->parent());
    //qDebug() << w->getRawImage()->getHeight();
}

BrightnessContrast::~BrightnessContrast()
{
    delete ui;
}

void BrightnessContrast::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
    //getWindow()->getRawImage()->addBrightness(position, VadimImage::all);
    getWindow()->getRawImage()->setBrightnessContrast(ui->spinBox->value(), ui->doubleSpinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
    //qDebug() << parentWidget()->parentWidget()->parentWidget()->parentWidget()->width();
}

void BrightnessContrast::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->doubleSpinBox->setValue(position/100.0);
    //getWindow()->getRawImage()->addBrightness(position, VadimImage::all);
    getWindow()->getRawImage()->setBrightnessContrast(ui->spinBox->value(), ui->doubleSpinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *BrightnessContrast::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
