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
}

void Binarization::on_pushButton_clicked()
{
    BaseUI::getImage(this).binirizeSimple(ui->spinBox->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
