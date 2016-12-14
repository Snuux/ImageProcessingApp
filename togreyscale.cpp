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
    BaseUI::getImage(this).convertToGrey(1, 0, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_2_clicked()
{
    BaseUI::getImage(this).convertToGrey(2, 0, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_3_clicked()
{
    BaseUI::getImage(this).convertToGrey(3, 0, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_4_clicked()
{
    BaseUI::getImage(this).convertToGrey(4, 0, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_5_clicked()
{
    BaseUI::getImage(this).convertToGrey(5, 0, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_6_clicked()
{
    if (ui->comboBox->currentText() == "Red Channel")
        BaseUI::getImage(this).convertToGrey(6, 0, VImage::channelRed);
    else if (ui->comboBox->currentText() == "Green Channel")
        BaseUI::getImage(this).convertToGrey(6, 0, VImage::channelGreen);
    else if (ui->comboBox->currentText() == "Blue Channel")
        BaseUI::getImage(this).convertToGrey(6, 0, VImage::channelBlue);
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_pushButton_7_clicked()
{
    BaseUI::getImage(this).convertToGrey(7, ui->spinBox->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ToGreyscale::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}

void ToGreyscale::on_horizontalSlider_sliderMoved(int position)
{
    ui->spinBox->setValue(position);
}
