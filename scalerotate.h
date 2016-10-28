#ifndef SCALEROTATE_H
#define SCALEROTATE_H

#include <QWidget>
#include <QTimer>
#include "mainwindow.h"

namespace Ui {
class ScaleRotate;
}

class ScaleRotate : public QWidget
{
    Q_OBJECT

public:
    explicit ScaleRotate(QWidget *parent = 0);
    ~ScaleRotate();

private slots:
    void on_pushButton_10_clicked();
    void on_doubleSpinBox_editingFinished();
    void on_pushButton_clicked();
    void on_horizontalSlider_3_sliderReleased();
    void on_horizontalSlider_sliderReleased();

    void on_horizontalSlider_3_sliderMoved(int position);

    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_horizontalSlider_2_sliderReleased();

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_spinBox_editingFinished();

    void on_pushButton_2_clicked();

private:
    Ui::ScaleRotate *ui;

    MainWindow *getWindow();
};

#endif // SCALEROTATE_H
