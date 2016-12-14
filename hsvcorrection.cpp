#include "hsvcorrection.h"
#include "ui_hsvcorrection.h"

HSVCorrection::HSVCorrection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HSVCorrection)
{
    ui->setupUi(this);
}

HSVCorrection::~HSVCorrection()
{
    delete ui;
}

void HSVCorrection::updateImage()
{
    BaseUI::getImage(this).hsvCorrection(ui->spinBox->value(), ui->spinBox_2->value(), ui->spinBox_3->value());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
void HSVCorrection::on_horizontalSlider_sliderReleased()
{
    ui->spinBox->setValue(ui->horizontalSlider->value());
    updateImage();
}

void HSVCorrection::on_horizontalSlider_2_sliderReleased()
{
    ui->spinBox_2->setValue(ui->horizontalSlider_2->value());
    updateImage();
}

void HSVCorrection::on_horizontalSlider_3_sliderReleased()
{
    ui->spinBox_3->setValue(ui->horizontalSlider_3->value());
    updateImage();
}

void HSVCorrection::on_spinBox_editingFinished()
{
    ui->horizontalSlider->setValue(ui->spinBox->value());
    updateImage();
}

void HSVCorrection::on_spinBox_2_editingFinished()
{
    ui->horizontalSlider_2->setValue(ui->spinBox_2->value());
    updateImage();
}

void HSVCorrection::on_spinBox_3_editingFinished()
{
    ui->horizontalSlider_3->setValue(ui->spinBox_3->value());
    updateImage();
}

void HSVCorrection::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

void HSVCorrection::on_horizontalSlider_2_valueChanged(int value)
{
    ui->spinBox_2->setValue(value);
}

void HSVCorrection::on_horizontalSlider_3_valueChanged(int value)
{
    ui->spinBox_3->setValue(value);
}
