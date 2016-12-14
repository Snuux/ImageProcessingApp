#include "scalerotate.h"
#include "ui_scalerotate.h"

ScaleRotate::ScaleRotate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScaleRotate)
{
    ui->setupUi(this);
}

ScaleRotate::~ScaleRotate()
{
    delete ui;
}

void ScaleRotate::on_pushButton_10_clicked()
{
    BaseUI::getImage(this).zoomBilinear(ui->spinBox_2->value(), ui->spinBox_3->value());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_doubleSpinBox_editingFinished()
{
    ui->horizontalSlider->setValue(ui->doubleSpinBox->value() * 100);

    if (ui->checkBox->isChecked())
    {
        BaseUI::getImage(this).zoomBilinear(ui->doubleSpinBox->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_pushButton_clicked()
{
    BaseUI::getImage(this).zoomBilinear(ui->doubleSpinBox->value());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_horizontalSlider_3_sliderReleased()
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox_3->setValue(ui->horizontalSlider_3->value() / 100.0);

        BaseUI::getImage(this).zoomNeighbor(ui->doubleSpinBox_3->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_sliderReleased()
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox->setValue(ui->horizontalSlider->value() / 100.0);

        BaseUI::getImage(this).zoomBilinear(ui->doubleSpinBox->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->doubleSpinBox_3->setValue(position / 100.0);

    if (ui->checkBox->isChecked())
    {
        BaseUI::getImage(this).zoomNeighbor(ui->doubleSpinBox_3->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_sliderMoved(int position)
{
    ui->doubleSpinBox->setValue(position / 100.0);

    if (ui->checkBox->isChecked())
    {
        BaseUI::getImage(this).zoomBilinear(ui->doubleSpinBox->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_pushButton_8_clicked()
{
    BaseUI::getImage(this).flipHorizontal();
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_pushButton_9_clicked()
{
    BaseUI::getImage(this).flipVertical();
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_pushButton_6_clicked()
{
    BaseUI::getImage(this).rotate90clockwise();
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_pushButton_7_clicked()
{
    BaseUI::getImage(this).rotate90counterClockwise();
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_pushButton_4_clicked()
{
    BaseUI::getImage(this).rotate180();
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}

void ScaleRotate::on_horizontalSlider_2_sliderReleased() // rotate
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox_2->setValue(ui->horizontalSlider_2->value() / 10.0);
        qDebug() << ui->horizontalSlider_2->value() << ui->horizontalSlider_2->value() / 10.0;

        BaseUI::getImage(this).rotate(ui->doubleSpinBox_2->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_2_sliderMoved(int position) // rotate
{
    ui->doubleSpinBox_2->setValue(position/10.0);

    if (ui->checkBox->isChecked())
    {
        BaseUI::getImage(this).rotate(ui->doubleSpinBox_2->value());
        BaseUI::getWindow(this)->updateImage();
        BaseUI::getWindow(this)->updateHistogram();
    }
}

void ScaleRotate::on_pushButton_2_clicked()
{
    BaseUI::getImage(this).rotate(ui->doubleSpinBox_2->value());
    BaseUI::getWindow(this)->updateImage();
    BaseUI::getWindow(this)->updateHistogram();
}
