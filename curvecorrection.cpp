#include "curvecorrection.h"
#include "ui_curvecorrection.h"

CurveCorrection::CurveCorrection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CurveCorrection)
{
    ui->setupUi(this);

    ui->gamma_plot->addGraph();
    ui->gamma_plot->addGraph();
    ui->gamma_plot->addGraph();

    ui->s_plot->addGraph();
    ui->s_plot->addGraph();
    ui->s_plot->addGraph();
    //ui->s_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    ui->custom_plot->addGraph();
    ui->custom_plot->addGraph();
}

void CurveCorrection::updateGammaPlot(double a, double gamma)
{
    int n = 256; //x
    int m = 256; //y

    QVector<double> x(n);
    for (int i = 0; i < n; i++) x[i] = i / (double)n;
    QVector<double> y(m);
    for (int i = 0; i < m; i++) y[i] = x[i] * a;

    QVector<double> y1(m);
    for (int i = 0; i < m; i++) y1[i] = a * qPow(x[i], gamma);
    QVector<double> y2(m);
    for (int i = 0; i < m; i++) y2[i] = a * qPow(x[i], 1/gamma);

    ui->gamma_plot->graph(0)->setData(x, y);
    ui->gamma_plot->graph(1)->setData(x, y1);
    ui->gamma_plot->graph(2)->setData(x, y2);
    ui->gamma_plot->graph(0)->setPen(QPen(QColor(255, 0, 0, 255)));
    ui->gamma_plot->graph(1)->setPen(QPen(QColor(0, 255, 0, 255)));
    ui->gamma_plot->graph(2)->setPen(QPen(QColor(0, 0, 255, 255)));

    ui->gamma_plot->xAxis->setRange(0, 1);
    ui->gamma_plot->yAxis->setRange(0, 1);
    ui->gamma_plot->replot();

    BaseUI::getImage(this).curveCorrection(y2.toStdVector(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
void CurveCorrection::updateSPlot(double a, double gamma, unsigned char middlePoint)
{
    int n = 256; //x
    int m = 256; //y
    middlePoint = 127; //todo middlepoint

    QVector<double> x(n);
    for (int i = 0; i < n; i++) x[i] = i / (double)n;
    QVector<double> y(m);
    for (int i = 0; i < m; i++) y[i] = x[i] * a;

    QVector<double> y1(m);
    //y = x^2.2; y = (x*2)^2.2*0.5; y = x; y from 0 to 1, x from 0 to 1
    for (int i = 0; i <= middlePoint; i++)
        y1[i] = a * qPow(x[i]*2, gamma) * 0.5;
    //y = x^2.2; y = ((x-0.5)*2)^2.2*0.5+0.5; y = x; y from 0 to 1, x from 0 to 1
    for (int i = middlePoint+1; i < m; i++)
        y1[i] = a * (qPow((x[i]-0.5)*2, 1/gamma)*0.5+0.5);

    QVector<double> y2(m);
    for (int i = 0; i <= middlePoint; i++)
        y2[i] = a * qPow(x[i]*2, 1/gamma) * 0.5;
    for (int i = middlePoint+1; i < m; i++)
        y2[i] = a * (qPow((x[i]-0.5)*2, gamma)*0.5+0.5);

    ui->s_plot->graph(0)->setData(x, y);
    ui->s_plot->graph(1)->setData(x, y1);
    ui->s_plot->graph(2)->setData(x, y2);
    ui->s_plot->graph(0)->setPen(QPen(QColor(255, 0, 0, 255)));
    ui->s_plot->graph(1)->setPen(QPen(QColor(0, 255, 0, 255)));
    ui->s_plot->graph(2)->setPen(QPen(QColor(0, 0, 255, 255)));

    ui->s_plot->xAxis->setRange(0, 1);
    ui->s_plot->yAxis->setRange(0, 1);
    ui->s_plot->replot();

    double arr[256];
    for (int i = 0; i < 256; i++)
    {
        arr[i] = y1[i];
        //qDebug() << i <<  arr[i];
    }

    BaseUI::getImage(this).curveCorrection(y1.toStdVector(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void CurveCorrection::updateCustomPlot(QVector<double>& x, QVector<double>& y)
{
    /*int n = 256; //x
    int m = 256; //y

    QVector<double> x(n);
    for (int i = 0; i < n; i++) x[i] = i / (double)n;
    QVector<double> y(m);
    for (int i = 0; i < m; i++) y[i] = x[i];

    //TODO
    double step = m / number;
    QVector<double> y1(m);
    for (int i = 0; i < m; i++)
    {

    }

    BaseUI::getImage(this).curveCorrection(y1.toStdVector(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();*/
}


CurveCorrection::~CurveCorrection()
{
    delete ui;
}

void CurveCorrection::on_pushButton_clicked()
{
    updateGammaPlot(ui->doubleSpinBox->value(), ui->doubleSpinBox_2->value());
}

void CurveCorrection::on_pushButton_2_clicked()
{
    updateSPlot(ui->doubleSpinBox_3->value(), ui->doubleSpinBox_4->value(), ui->spinBox->value());
}

void CurveCorrection::on_pushButton_3_clicked()
{
    //ui->plainTextEdit->document()->
    //todo
    int n = 256; //x
    int m = 256; //y

    QString a = ui->plainTextEdit->document()->toPlainText();

    QStringList list = a.split(" ", QString::SkipEmptyParts);
    QVector<double> xx, yy;


    for (int i = 0; i < list.length() - 1; i+=2)
    {
        xx.push_back(list[i+0].toDouble() / (double)n);
        yy.push_back(list[i+1].toDouble());
        qDebug() << list[i+1].toDouble();
    }

    QVector<double> x(n);
    for (int i = 0; i < n; i++) x[i] = i / (double)n;
    QVector<double> y(m);
    for (int i = 0; i < m; i++) y[i] = x[i];

    //for (int i = 0; i < 20; i++)
    //{
    //    qDebug() << y[i] << yy[i];
    //}

    ui->custom_plot->graph(0)->setData(x, y);
    ui->custom_plot->graph(1)->setData(xx, yy);
    ui->custom_plot->graph(0)->setPen(QPen(QColor(255, 0, 0, 255)));
    ui->custom_plot->graph(1)->setPen(QPen(QColor(0, 255, 0, 255)));

    ui->custom_plot->xAxis->setRange(0, 1);
    ui->custom_plot->yAxis->setRange(0, 1);
    ui->custom_plot->replot();
    //

    BaseUI::getImage(this).curveCorrection(yy.toStdVector(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();

}
