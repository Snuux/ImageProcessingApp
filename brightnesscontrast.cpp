#include "brightnesscontrast.h"
#include "ui_brightnesscontrast.h"

BrightnessContrast::BrightnessContrast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BrightnessContrast)
{
    ui->setupUi(this);
}

BrightnessContrast::~BrightnessContrast()
{
    delete ui;
}

void BrightnessContrast::on_horizontalSlider_sliderMoved(int position)
{
    int ch = (int)BaseUI::getCurCh();

    ui->spinBox->setValue(position);
    BaseUI::getImage(this).brightnessContrast(ui->spinBox->value(), ui->doubleSpinBox->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void BrightnessContrast::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->doubleSpinBox->setValue(position/100.0);
    BaseUI::getImage(this).brightnessContrast(ui->spinBox->value(), ui->doubleSpinBox->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
