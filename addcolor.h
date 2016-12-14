#ifndef ADDCOLOR_H
#define ADDCOLOR_H

#include <QWidget>
#include <QString>
#include <QColorDialog>
#include <QRgb>
#include <QColor>

#include <QDebug>

#include "baseui.h"

namespace Ui {
class AddColor;
}

class AddColor : public QWidget
{
    Q_OBJECT

public:
    explicit AddColor(QWidget *parent = 0);
    ~AddColor();

private slots:
    void on_pushButton_clicked();
    void on_comboBox_activated(const QString &arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::AddColor *ui;

    QString curMode;
};

#endif // ADDCOLOR_H
