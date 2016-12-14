#include "boxgauss.h"
#include "ui_boxgauss.h"

BoxGauss::BoxGauss(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BoxGauss)
{
    ui->setupUi(this);
    on_spinBox_valueChanged(3);
}

BoxGauss::~BoxGauss()
{
    delete ui;
}

void BoxGauss::on_pushButton_clicked()
{
    int n = ui->spinBox->value();
    //QString str = "";
    //
    //QVector<double> arr(n*n);
    //for (int i = 0; i < n; i++)
    //{
    //    for (int j = 0; j < n; j++)
    //        str.append("1 ");
    //    str.append("\n");
    //}
    //
    //ui->plainTextEdit->document()->setPlainText(str);

    BaseUI::getImage(this).filterBox(n, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void BoxGauss::on_pushButton_3_clicked()
{
    int n = ui->spinBox->value();
    QVector<double> arr(n*n);
    double m = ui->spinBox->value()/2;
    double d = ui->doubleSpinBox_2->value();

    BaseUI::getImage(this).filterGauss(n, m, d, BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void BoxGauss::on_spinBox_valueChanged(int arg1)
{
    ui->doubleSpinBox->setValue(arg1/2);
    genGaussMatrix(arg1, arg1/2, ui->doubleSpinBox_2->value());
}

void BoxGauss::genGaussMatrix(double n, double m, double d)
{
    QVector<double> arr(n*n);

    double sum = 0;

    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            arr[y+x*n] = exp( -0.5 * (pow((x-m)/d, 2.0) + pow((y-m)/d,2.0)) )
                    / (2 * 3.1415926525 * d * d);

            sum += arr[y+x*n];
        }

    //norm
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            arr[y+x*n] /= sum;

    //lineEdit
    QString line = "";
    for (int i = 0; i < n; i++)
        line.append(QString::number(arr[n/2+i*n], 'f', 4)).append(" ");

    ui->lineEdit->setText(line);

    QString text = "";
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
            text.append(QString::number(arr[y+x*n], 'f', 4)).append(" ");
        text.append("\n");
    }

    ui->plainTextEdit->document()->clear();
    ui->plainTextEdit->document()->setPlainText(text);
}

void BoxGauss::on_doubleSpinBox_2_valueChanged(double arg1)
{
        genGaussMatrix(ui->spinBox->value(), ui->spinBox->value()/2, arg1);
}
