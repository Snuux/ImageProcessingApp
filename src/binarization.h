#ifndef BINARIZATION_H
#define BINARIZATION_H

#include <QWidget>
#include "baseui.h"

namespace Ui {
class Binarization;
}

class Binarization : public QWidget
{
    Q_OBJECT

public:
    explicit Binarization(QWidget *parent = 0);
    ~Binarization();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_pushButton_clicked();

private:
    Ui::Binarization *ui;
};

#endif // BINARIZATION_H
