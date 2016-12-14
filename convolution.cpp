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
    QVector<double> arr = stringToDoubleVector(ui->plainTextEdit->toPlainText(), size);
    int y = ui->plainTextEdit->blockCount();

    BaseUI::getImage(this).conv(arr.toStdVector(), size / y, y, ui->doubleSpinBox->value(), ui->checkBox_2->isChecked(), BaseUI::getCurCh());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
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

QVector<double> Convolution::stringToDoubleVector(QString a, int &size)
{
    size = 0;

    QStringList list = a.split(" ",QString::SkipEmptyParts);
    QVector<double> ret;

    size = list.length();
    foreach (QString num, list) {
        ret.push_back(num.toDouble());
    }

    return ret;
}

void Convolution::on_plainTextEdit_textChanged()
{
    int size;
    QVector<double> arr = stringToDoubleVector(ui->plainTextEdit->toPlainText(), size);
    int y = ui->plainTextEdit->blockCount();

    ui->spinBox->setValue(size/y);
    ui->spinBox_2->setValue(y);
}

void Convolution::on_comboBox_activated(const QString &s)
{
    ui->plainTextEdit->document()->clear();
    int div; bool norm = false;

    QString arr;
    if (s == "Simple 3x3")
        { arr = "0 0 0 \n0 1 0 \n0 0 0 "; norm = false; }
    else if (s == "Right Simple 3x3")
        { arr = "0 0 0 \n"
              "0 0 1 \n"
              "0 0 0"; norm = false; }
    else if (s == "Left Simple 3x3")
        { arr = "0 0 0 \n"
              "1 0 0 \n"
              "0 0 0"; norm = false; }
    else if (s == "Up Simple 3x3")
        { arr = "0 1 0 \n"
              "0 0 0 \n"
              "0 0 0"; norm = false; }
    else if (s == "Down Simple 3x3")
        { arr = "0 0 0 \n"
              "0 0 0 \n"
              "0 1 0"; norm = false; }
    else if (s == "Negative")
        { arr = "0 0 0 \n"
              "0 -1 0 \n"
              "0 0 0"; norm = false; }
    else if (s == "Box 3x3")
        { arr = "1 1 1 \n1 1 1 \n1 1 1 ";  norm = true; }
    else if (s == "Box 3x3 Norm")
        { arr = "0.11 0.11 0.11 \n0.11 0.11 0.11 \n0.11 0.11 0.11 "; norm = false; }
    else if (s == "Box 5x5")
        { arr = "1 1 1 1 1 \n"
              "1 1 1 1 1 \n"
              "1 1 1 1 1 \n"
              "1 1 1 1 1 \n"
              "1 1 1 1 1"; norm = true; }
    else if (s == "Box 5x5 Norm")
        { arr = "0.04 0.04 0.04 0.04 0.04 \n"
              "0.04 0.04 0.04 0.04 0.04 \n"
              "0.04 0.04 0.04 0.04 0.04 \n"
              "0.04 0.04 0.04 0.04 0.04 \n"
              "0.04 0.04 0.04 0.04 0.04"; norm = false; }
    else if (s == "Gauss 3x3")
        { arr = "2 5 2 \n"
              "5 9 5 \n"
              "2 5 2"; norm = true; }
    else if (s == "Gauss 3x3 Norm")
        { arr = "0.077847 0.123317 0.077847 \n"
              "0.123317 0.195346 0.123317 \n"
              "0.077847 0.123317 0.077847"; norm = false; }
    else if (s == "Gauss 5x5")
        { arr = "2 4 5 4 2    \n"
              "4 9 12 9 4   \n"
              "5 12 15 12 5 \n"
              "4 9 12 9 4   \n"
              "2 4 5 4 2    \n"; norm = true; }
    else if (s == "Gauss 5x5 Norm")
        { arr = "0.003765 0.015019 0.023792 0.015019 0.003765 \n"
              "0.015019 0.059912 0.094907 0.059912 0.015019 \n"
              "0.023792 0.094907 0.150342 0.094907 0.023792 \n"
              "0.015019 0.059912 0.094907 0.059912 0.015019 \n"
              "0.003765 0.015019 0.023792 0.015019 0.003765"; }
    else if (s == "Sharpen 3x3")
        { arr = "-1 -1 -1 \n-1 9 -1 \n-1 -1 -1 "; norm = true; }
    else if (s == "Sharpen 5x5")
        { arr = "-1 -1 -1 -1 -1 \n"
              "-1 -1 -1 -1 -1 \n"
              "-1 -1 25 -1 -1 \n"
              "-1 -1 -1 -1 -1 \n"
              "-1 -1 -1 -1 -1"; norm = false; }

    ui->checkBox_2->setChecked(norm);
    ui->plainTextEdit->document()->setPlainText(arr);

    on_plainTextEdit_textChanged();
}
