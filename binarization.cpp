#include "binarization.h"
#include "ui_binarization.h"

Binarization::Binarization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Binarization)
{
    ui->setupUi(this);
}

Binarization::~Binarization()
{
    delete ui;
}

void Binarization::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
    //getWindow()->getRawImage()->addBrightness(position, VadimImage::all);
}

void Binarization::on_pushButton_clicked()
{
    getWindow()->getRawImage()->binirizeSimple(ui->spinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *Binarization::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
