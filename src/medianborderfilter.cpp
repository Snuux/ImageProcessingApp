#include "medianborderfilter.h"
#include "ui_medianborderfilter.h"

MedianBorderFilter::MedianBorderFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedianBorderFilter)
{
    ui->setupUi(this);
}

MedianBorderFilter::~MedianBorderFilter()
{
    delete ui;
}

void MedianBorderFilter::on_pushButton_clicked()
{
    BaseUI::getImage(this).filterMedian(ui->spinBox->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void MedianBorderFilter::on_pushButton_2_clicked()
{
    BaseUI::getImage(this).filterSharpen(ui->spinBox_2->value(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
