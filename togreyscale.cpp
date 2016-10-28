#include "togreyscale.h"
#include "ui_togreyscale.h"

ToGreyscale::ToGreyscale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ToGreyscale)
{
    ui->setupUi(this);
}

ToGreyscale::~ToGreyscale()
{
    delete ui;
}

void ToGreyscale::on_pushButton_clicked()
{
    getWindow()->getRawImage()->convertToGrey(1, 0, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_2_clicked()
{
    getWindow()->getRawImage()->convertToGrey(2, 0, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_3_clicked()
{
    getWindow()->getRawImage()->convertToGrey(3, 0, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_4_clicked()
{
    getWindow()->getRawImage()->convertToGrey(4, 0, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_5_clicked()
{
    getWindow()->getRawImage()->convertToGrey(5, 0, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_6_clicked()
{
    if (ui->comboBox->currentText() == "Red Channel")
        getWindow()->getRawImage()->convertToGrey(6, 0, VadimImage::red);
    else if (ui->comboBox->currentText() == "Green Channel")
        getWindow()->getRawImage()->convertToGrey(6, 0, VadimImage::green);
    else if (ui->comboBox->currentText() == "Blue Channel")
        getWindow()->getRawImage()->convertToGrey(6, 0, VadimImage::blue);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_pushButton_7_clicked()
{
    getWindow()->getRawImage()->convertToGrey(7, ui->spinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ToGreyscale::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void ToGreyscale::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
}

MainWindow *ToGreyscale::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
