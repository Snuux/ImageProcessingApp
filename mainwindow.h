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
#include <QDateTime>

#include "vimage.h"
#include "vimageloader.h"
#include "vimagemem.h"

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

    VImage image;
    VImageMem imageMem;

    Ui::MainWindow *ui;

private:
    QString fileName;
    QImage fileImage;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QCPBars *barB, *barG, *barR, *barAll;

    void loadImage();
    void loadImage(QString filepath);

public slots:
    void slotOpenFileDialog();
    void slotSaveFileDialog();
    void slotChangeHistogramChannels(QString str);
    void slotUndo();
    void slotRedo();
    void updateImage();
    void updateHistogram();
    void wait(int millisecondsToWait);

private slots:
    void on_applyButton_clicked();
    void on_revertButton_clicked();
    void on_undoButton_clicked();
    void on_redoButton_clicked();
    void on_comboBox_currentIndexChanged(const QString &arg1);
    void on_checkBox_stateChanged(int arg1);
};

#endif // MAINWINDOW_H
