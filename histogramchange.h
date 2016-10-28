#ifndef HISTOGRAMCHANGE_H
#define HISTOGRAMCHANGE_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class HistogramChange;
}

class HistogramChange : public QWidget
{
    Q_OBJECT

public:
    explicit HistogramChange(QWidget *parent = 0);
    ~HistogramChange();

private slots:
    void on_horizontalSlider_sliderReleased();
    void on_horizontalSlider_2_sliderReleased();
    void on_horizontalSlider_3_sliderReleased();
    void on_horizontalSlider_4_sliderReleased();

    MainWindow *getWindow();

    void editAndUpdateHistogram4();
    void editAndUpdateHistogram3();

    void on_horizontalSlider_5_sliderReleased();
    void on_horizontalSlider_6_sliderReleased();
    void on_horizontalSlider_7_sliderReleased();

private:
    Ui::HistogramChange *ui;
};

#endif // HISTOGRAMCHANGE_H
