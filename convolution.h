#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <QWidget>
#include "baseui.h"

#include <QString>
#include <QStringList>

namespace Ui {
class Convolution;
}

class Convolution : public QWidget
{
    Q_OBJECT

public:
    explicit Convolution(QWidget *parent = 0);
    ~Convolution();

private slots:
    void on_pushButton_clicked();
    void on_plainTextEdit_textChanged();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Convolution *ui;

    double *stringToChar(QString a, int &size);
    QVector<double> stringToDoubleVector(QString a, int &size);
};

#endif // CONVOLUTION_H
