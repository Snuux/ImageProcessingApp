#include "convolution.h"
#include "ui_convolution.h"

Convolution::Convolution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Convolution)
{
    ui->setupUi(this);
}

Convolution::~Convolution()
{
    delete ui;
}

void Convolution::on_pushButton_clicked()
{
    double arr[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    getWindow()->getRawImage()->conv(arr, 3, 3, 2.0, -1, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *Convolution::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
