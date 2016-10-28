#ifndef BRIGHTNESSCONTRAST_H
#define BRIGHTNESSCONTRAST_H

#include <QWidget>
#include "mainwindow.h"
#include "vadimimage.h"

namespace Ui {
class BrightnessContrast;
}

class BrightnessContrast : public QWidget
{
    Q_OBJECT

public:
    explicit BrightnessContrast(QWidget *parent = 0);
    ~BrightnessContrast();

private slots:
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_2_sliderMoved(int position);

private:
    Ui::BrightnessContrast *ui;

    MainWindow *getWindow();
};

#endif // BRIGHTNESSCONTRAST_H
