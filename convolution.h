#ifndef CONVOLUTION_H
#define CONVOLUTION_H

#include <QWidget>
#include "mainwindow.h"

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

private:
    Ui::Convolution *ui;

    MainWindow *getWindow();
    double *stringToChar(QString a, int &size);
};

#endif // CONVOLUTION_H
