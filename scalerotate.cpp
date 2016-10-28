#include "scalerotate.h"
#include "ui_scalerotate.h"

ScaleRotate::ScaleRotate(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScaleRotate)
{
    ui->setupUi(this);

    //ui->spinBox_2->setValue(getWindow()->getRawImage()->getHeight());
    //ui->spinBox_2->setValue(getWindow()->getRawImage()->getWidth());
}

ScaleRotate::~ScaleRotate()
{
    delete ui;
}

void ScaleRotate::on_pushButton_10_clicked()
{
    getWindow()->getRawImage()->zoomBilinear(ui->spinBox_2->value(), ui->spinBox_3->value());
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *ScaleRotate::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}

void ScaleRotate::on_doubleSpinBox_editingFinished()
{
    ui->horizontalSlider->setValue(ui->doubleSpinBox->value() * 100);

    if (ui->checkBox->isChecked())
    {
        getWindow()->getRawImage()->zoomBilinear(ui->doubleSpinBox->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_pushButton_clicked()
{
    getWindow()->getRawImage()->zoomBilinear(ui->doubleSpinBox->value());
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_horizontalSlider_3_sliderReleased()
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox_3->setValue(ui->horizontalSlider_3->value() / 100.0);

        getWindow()->getRawImage()->zoomNeighbor(ui->doubleSpinBox_3->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_sliderReleased()
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox->setValue(ui->horizontalSlider->value() / 100.0);

        getWindow()->getRawImage()->zoomBilinear(ui->doubleSpinBox->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_3_sliderMoved(int position)
{
    ui->doubleSpinBox_3->setValue(position / 100.0);

    if (ui->checkBox->isChecked())
    {
        getWindow()->getRawImage()->zoomNeighbor(ui->doubleSpinBox_3->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_sliderMoved(int position)
{
    ui->doubleSpinBox->setValue(position / 100.0);

    if (ui->checkBox->isChecked())
    {
        getWindow()->getRawImage()->zoomBilinear(ui->doubleSpinBox->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_pushButton_8_clicked()
{
    getWindow()->getRawImage()->flipHorizontal();
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_pushButton_9_clicked()
{
    getWindow()->getRawImage()->flipVertical();
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_pushButton_6_clicked()
{
    getWindow()->getRawImage()->rotate90clockwise();
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_pushButton_7_clicked()
{
    getWindow()->getRawImage()->rotate90counterClockwise();
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_pushButton_4_clicked()
{
    getWindow()->getRawImage()->rotate180();
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_horizontalSlider_2_sliderReleased()
{
    if (!ui->checkBox->isChecked())
    {
        ui->doubleSpinBox->setValue(ui->horizontalSlider->value() / 100.0);

        getWindow()->getRawImage()->rotate(ui->spinBox->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_horizontalSlider_2_sliderMoved(int position)
{
    ui->spinBox->setValue(position);

    if (ui->checkBox->isChecked())
    {
        getWindow()->getRawImage()->rotate(ui->spinBox->value());
        getWindow()->displayImage();
        getWindow()->updateHistogram();
    }
}

void ScaleRotate::on_spinBox_editingFinished()
{
    getWindow()->getRawImage()->rotate(ui->spinBox->value());
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

void ScaleRotate::on_pushButton_2_clicked()
{
    getWindow()->getRawImage()->rotate(ui->spinBox->value());
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}
