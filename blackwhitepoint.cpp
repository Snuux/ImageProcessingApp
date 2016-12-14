#include "blackwhitepoint.h"
#include "ui_blackwhitepoint.h"

BlackWhitePoint::BlackWhitePoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BlackWhitePoint)
{
    ui->setupUi(this);

    ui->custom_plot->addGraph();
    ui->custom_plot->addGraph();
}

BlackWhitePoint::~BlackWhitePoint()
{
    delete ui;
}

void BlackWhitePoint::updatePlot(unsigned char a, unsigned char b)
{
    int n = 256; //x
    int m = 256; //y

    QVector<double> x(n);
    for (int i = 0; i < n; i++) x[i] = i;
    QVector<double> y(m);
    for (int i = 0; i < m; i++) y[i] = x[i];

    double x1(a),x2(255-b),y1(0),y2(255);
    QVector<double> ya(m);
    for (int i = 0; i < m; i++)
        ya[i] = (x[i]-x1)/(x2-x1)*(y2-y1)+y1;//128 + (x[i] - 128) * b;

    ui->custom_plot->graph(0)->setData(x, y);
    ui->custom_plot->graph(1)->setData(x, ya);
    ui->custom_plot->graph(0)->setPen(QPen(QColor(255, 0, 0, 255)));
    ui->custom_plot->graph(1)->setPen(QPen(QColor(0, 255, 0, 255)));

    ui->custom_plot->xAxis->setRange(0, 256);
    ui->custom_plot->yAxis->setRange(0, 256);
    ui->custom_plot->replot();

    double arr[256];
    for (int i = 0; i < 256; i++)
        arr[i] = ya[i];

    //getWindow()->getRawImage()->blackWhitePoints(a, 255 - b);
    //getWindow()->getRawImage()->curveCorrection(arr, ya.length(), VadimImage::all);

    BaseUI::getImage(this).setBlackWhitePoints(a, 255 - b);
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void BlackWhitePoint::on_spinBox_editingFinished()
{
    ui->horizontalSlider->setValue(ui->spinBox->value());
    updatePlot(ui->spinBox->value(), ui->spinBox_2->value());
}

void BlackWhitePoint::on_spinBox_2_editingFinished()
{
    ui->horizontalSlider_2->setValue(ui->spinBox_2->value());
    updatePlot(ui->spinBox->value(), ui->spinBox_2->value());
}

void BlackWhitePoint::on_horizontalSlider_sliderReleased()
{
    ui->spinBox->setValue(ui->horizontalSlider->value());
    updatePlot(ui->spinBox->value(), ui->spinBox_2->value());
}

void BlackWhitePoint::on_horizontalSlider_2_sliderReleased()
{
    ui->spinBox_2->setValue(ui->horizontalSlider_2->value());
    updatePlot(ui->spinBox->value(), ui->spinBox_2->value());
}
