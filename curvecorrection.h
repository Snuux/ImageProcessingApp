#ifndef CURVECORRECTION_H
#define CURVECORRECTION_H

#include <QWidget>
#include "mainwindow.h"
#include <QtMath>

namespace Ui {
class CurveCorrection;
}

class CurveCorrection : public QWidget
{
    Q_OBJECT

public:
    explicit CurveCorrection(QWidget *parent = 0);
    ~CurveCorrection();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CurveCorrection *ui;

    void updateGammaPlot(double a, double gamma);
    void updateSPlot(double a, double gamma, unsigned char middlePoint);
    void updateCustomPlot(double number);
    MainWindow *getWindow();
};

#endif // CURVECORRECTION_H
