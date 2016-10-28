#ifndef PALETTE_H
#define PALETTE_H

#include <QWidget>
#include <QString>
#include <QList>
#include <QImage>
#include <QPixmap>
#include "mainwindow.h"

namespace Ui {
class Palette;
}

class Palette : public QWidget
{
    Q_OBJECT

public:
    explicit Palette(QWidget *parent = 0);
    ~Palette();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Palette *ui;
    MainWindow *getWindow();
    QImage createPaletteImage(QList<unsigned char> a);

    QGraphicsScene *scene;
    QGraphicsPixmapItem *item;
    QImage *paletteImage;
};

#endif // PALETTE_H
