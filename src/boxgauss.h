#ifndef BOXGAUSS_H
#define BOXGAUSS_H

#include <QWidget>
#include <QVector>
#include <QString>

#include "baseui.h"

namespace Ui {
class BoxGauss;
}

class BoxGauss : public QWidget
{
    Q_OBJECT

public:
    explicit BoxGauss(QWidget *parent = 0);
    ~BoxGauss();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

private:
    Ui::BoxGauss *ui;

    void genGaussMatrix(double size, double m, double d);
};

#endif // BOXGAUSS_H
