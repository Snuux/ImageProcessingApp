#ifndef HSVCORRECTION_H
#define HSVCORRECTION_H

#include <QWidget>
#include <cmath>
#include "baseui.h"

namespace Ui {
class HSVCorrection;
}

class HSVCorrection : public QWidget
{
    Q_OBJECT

public:
    explicit HSVCorrection(QWidget *parent = 0);
    ~HSVCorrection();

private slots:
    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_2_sliderReleased();

    void on_horizontalSlider_3_sliderReleased();

    void on_spinBox_editingFinished();

    void on_spinBox_2_editingFinished();

    void on_spinBox_3_editingFinished();

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

private:
    Ui::HSVCorrection *ui;

    void updateImage();
};

#endif // HSVCORRECTION_H
