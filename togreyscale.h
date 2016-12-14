#ifndef TOGREYSCALE_H
#define TOGREYSCALE_H

#include <QWidget>
#include <baseui.h>

namespace Ui {
class ToGreyscale;
}

class ToGreyscale : public QWidget
{
    Q_OBJECT

public:
    explicit ToGreyscale(QWidget *parent = 0);
    ~ToGreyscale();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::ToGreyscale *ui;
};

#endif // TOGREYSCALE_H
