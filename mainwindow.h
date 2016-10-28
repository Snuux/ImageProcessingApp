#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>
#include <QPainter>
#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include <QtMath>
#include <QVector>
#include <QTime>

#include "vadimimage.h"
//#include "histogramchange.h"

#include "libs/qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    VadimImage *getRawImage() const;

    Ui::MainWindow *ui;

private:
    QString fileName;
    QImage image;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QCPBars *barB, *barG, *barR, *barAll;

    VadimImage *rawImage;

    void loadImage();

public slots:
    void slotOpenFileDialog();
    void slotChangeHistogramChannels(QString str);
    void displayImage();
    void updateHistogram();
    void wait(int millisecondsToWait);

private slots:
    void on_groupBox_toggled(bool arg1);
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
