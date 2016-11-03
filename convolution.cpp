#include "convolution.h"
#include "ui_convolution.h"

Convolution::Convolution(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Convolution)
{
    ui->setupUi(this);
}

Convolution::~Convolution()
{
    delete ui;
}

void Convolution::on_pushButton_clicked()
{
    int size;
    double *arr = stringToChar(ui->plainTextEdit->toPlainText(), size);

    getWindow()->getRawImage()->conv(arr, ui->spinBox->value(), ui->spinBox_2->value(), ui->doubleSpinBox->value(), -1, VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *Convolution::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}

double *Convolution::stringToChar(QString a, int &size)
{
    QStringList list = a.split(" ",QString::SkipEmptyParts);

    size = list.length();
    double *arr = new double[size];

    int count = 0;
    foreach(QString num, list)
        arr[count++] = num.toDouble();

    return arr;
}
