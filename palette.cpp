#include "palette.h"
#include "ui_palette.h"

Palette::Palette(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Palette)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem();
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scale(15, 15);

    paletteImage = NULL;
}

Palette::~Palette()
{
    delete ui;
    delete scene;
    //delete item;
    delete paletteImage;
}

void Palette::on_pushButton_clicked()
{
    QList<unsigned char> p = getWindow()->getRawImage()->getPalette(ui->spinBox->value(), VadimImage::all);
    ui->lineEdit->clear();

    for (int i = 0; i < p.length(); i+=3)
    {
        ui->lineEdit->setText(ui->lineEdit->text() + "{");
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(p[i+2]) + ",");
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(p[i+1]) + ",");
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(p[i]));
        ui->lineEdit->setText(ui->lineEdit->text() + "} ");
    }

    item->setPixmap(QPixmap::fromImage( createPaletteImage(p) ));
}

QImage Palette::createPaletteImage(QList<unsigned char> a)
{
    int size = a.length();
    int width = 15;
    int height = size/width + 1;

    if (paletteImage)
        delete paletteImage;

    paletteImage = new QImage(width, height, QImage::Format_ARGB32);

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            paletteImage->setPixel(x, y, qRgb(255, 255, 255));

    int x = 0;
    int y = 0;

    for (int i = 0; i < size; i+=3)
    {
        QRgb col = qRgb(a[i+2], a[i+1], a[i]);
        paletteImage->setPixel(x, y, col);
        x++;
        if (x > width) {x = 0; y++;}
    }

    return *paletteImage;
}

MainWindow *Palette::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
