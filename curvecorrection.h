#ifndef CURVECORRECTION_H
#define CURVECORRECTION_H

#include <QWidget>
#include <QtMath>
#include <QStringList>


#include "baseui.h"

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

    void on_pushButton_3_clicked();

private:
    Ui::CurveCorrection *ui;

    void updateGammaPlot(double a, double gamma);
    void updateSPlot(double a, double gamma, unsigned char middlePoint);
    void updateCustomPlot(QVector<double>& x, QVector<double>& y);
};

#endif // CURVECORRECTION_H
