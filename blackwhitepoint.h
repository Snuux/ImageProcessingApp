#ifndef BLACKWHITEPOINT_H
#define BLACKWHITEPOINT_H

#include <QWidget>
#include "baseui.h"

namespace Ui {
class BlackWhitePoint;
}

class BlackWhitePoint : public QWidget
{
    Q_OBJECT

public:
    explicit BlackWhitePoint(QWidget *parent = 0);
    ~BlackWhitePoint();

private slots:
    void on_spinBox_editingFinished();
    void on_spinBox_2_editingFinished();

    void on_horizontalSlider_sliderReleased();
    void on_horizontalSlider_2_sliderReleased();

private:
    Ui::BlackWhitePoint *ui;

    void updatePlot(unsigned char a, unsigned char b);
};

#endif // BLACKWHITEPOINT_H
