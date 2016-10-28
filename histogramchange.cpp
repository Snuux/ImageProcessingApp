#include "histogramchange.h"
#include "ui_histogramchange.h"

HistogramChange::HistogramChange(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HistogramChange)
{
    ui->setupUi(this);
}

HistogramChange::~HistogramChange()
{
    delete ui;
}

void HistogramChange::on_horizontalSlider_sliderReleased()
{
    ui->spinBox->setValue(ui->horizontalSlider->value());
    editAndUpdateHistogram4();
}

void HistogramChange::on_horizontalSlider_2_sliderReleased()
{
    ui->spinBox_2->setValue(ui->horizontalSlider_2->value());
    editAndUpdateHistogram4();
}

void HistogramChange::on_horizontalSlider_3_sliderReleased()
{
    ui->spinBox_3->setValue(ui->horizontalSlider_3->value());
    editAndUpdateHistogram4();
}

void HistogramChange::on_horizontalSlider_4_sliderReleased()
{
    ui->spinBox_4->setValue(ui->horizontalSlider_4->value());
    editAndUpdateHistogram4();
}

MainWindow *HistogramChange::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}

void HistogramChange::editAndUpdateHistogram4()
{
    getWindow()->getRawImage()->editHistogram4(ui->spinBox->value(), ui->spinBox_4->value(), ui->spinBox_2->value(), ui->spinBox_3->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void HistogramChange::on_horizontalSlider_5_sliderReleased()
{
    ui->spinBox_5->setValue(ui->horizontalSlider_5->value());
    editAndUpdateHistogram3();
}

void HistogramChange::on_horizontalSlider_6_sliderReleased()
{
    ui->doubleSpinBox->setValue(ui->horizontalSlider_6->value()/100.0);
    editAndUpdateHistogram3();
}

void HistogramChange::on_horizontalSlider_7_sliderReleased()
{
    ui->spinBox_6->setValue(ui->horizontalSlider_7->value());
    editAndUpdateHistogram3();
}

void HistogramChange::editAndUpdateHistogram3()
{
    getWindow()->getRawImage()->editHistogram3(ui->spinBox_5->value(), ui->spinBox_6->value(), ui->doubleSpinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}
