#include "addcolor.h"
#include "ui_addcolor.h"

AddColor::AddColor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddColor)
{
    ui->setupUi(this);
    curMode = "Normal";

}

AddColor::~AddColor()
{
    delete ui;
}

void AddColor::on_pushButton_clicked()
{
    QColor color = QColorDialog::getColor();
    unsigned char r = color.red();
    unsigned char g = color.green();
    unsigned char b = color.blue();
    unsigned char a = ui->spinBox->value();
    //qDebug() << r << g << b << a << curMode;

    BaseUI::getImage(this).addColor(r, g, b, a, curMode.toStdString());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void AddColor::on_comboBox_activated(const QString &v)
{
    curMode = v;
}

void AddColor::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}
