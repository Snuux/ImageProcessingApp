#ifndef MEDIANBORDERFILTER_H
#define MEDIANBORDERFILTER_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class MedianBorderFilter;
}

class MedianBorderFilter : public QWidget
{
    Q_OBJECT

public:
    explicit MedianBorderFilter(QWidget *parent = 0);
    ~MedianBorderFilter();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MedianBorderFilter *ui;

    MainWindow* getWindow();
};

#endif // MEDIANBORDERFILTER_H
