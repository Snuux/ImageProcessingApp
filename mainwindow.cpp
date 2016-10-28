#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    item = new QGraphicsPixmapItem();
    scene->addItem(item);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMinimumHeight(20);
    ui->graphicsView->setMinimumWidth(20);

    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::slotOpenFileDialog);
    connect(ui->comboBox, &QComboBox::currentTextChanged, this, &MainWindow::slotChangeHistogramChannels);

    barAll = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    barB = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    barG = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    barR = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);



    //ui->tab->setParent(ui->tabWidget);
    //ui->tab_2->setParent(ui->tabWidget);
    //ui->tab_3->setParent(ui->tabWidget);
    //ui->tab_4->setParent(ui->tabWidget);
    //ui->tab_5->setParent(ui->tabWidget);
    //ui->tab_6->setParent(ui->tabWidget);
    //ui->tab_7->setParent(ui->tabWidget);
    //ui->tab_8->setParent(ui->tabWidget);
    //ui->tabWidget->setParent(ui->verticalLayout);
    //ui->verticalLayout->setParent(ui->centralWidget);
    //ui->centralWidget->setParent(this);
    /*QPainter painter(this);
    painter.drawRect(QRect(0, 0, width() - 1, height() - 1));

    QImage img;
    img.load("Lena.png");
    img = img.convertToFormat(QImage::Format_ARGB32);

    int width = img.width();
    int height = img.height();

    QDebug dbg(QtDebugMsg);
    for (int i = 0; i < 100; i++)
        dbg << (int) img.bits()[i];
    dbg << "\n";

    unsigned char *bits = new unsigned char[width*height*4];
    for (int i = 0; i < width*height*4; i++)
    {
        bits[i] = img.bits()[i];
    }

    for (int i = 0; i < 100; i++)
        dbg << (int) bits[i];

    int w1 = 800;
    int h1 = 800;
    float zw;
    float zh;
    unsigned char *zoomInBits;
    zoomInBits = new unsigned char [w1*h1*4];

    zoom(bits, zoomInBits, width, height, w1, h1, zw, zh);
    //resample(bits, zoomInBits, width, height, w1, h1);
    QImage imgDisp(zoomInBits, w1, h1, w1 * 4, QImage::Format_ARGB32);
    //qDebug() << imgDisp.format();

    //QImage imgDisp(bits, width, height, width * 4, QImage::Format_ARGB32);
    //ui->imageLabel->setPixmap(QPixmap::fromImage(imgDisp));

    QGraphicsScene* scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(imgDisp));
    scene->addItem(item);

    ui->imageLabel->setScaledContents(true);
    ui->imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);*/


    loadImage();
    updateHistogram();
    displayImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    //delete item;
}

void MainWindow::loadImage()
{
    image.load("C:/Users/snuux/Documents/Qt Projects/build-ImageBrowser-Desktop_Qt_5_7_0_MinGW_32bit-Debug/Lena.png");
    //image = image.convertToFormat(QImage::Format_RGB32);

    rawImage = new VadimImage(image);
}

void MainWindow::displayImage()
{
    //item->clearFocus();
    wait(400);
    item->setPixmap(QPixmap::fromImage(rawImage->getImage()));
    //updateHistogram();
    //item->update();
    //scene->update();
    //ui->graphicsView->update();
}

void MainWindow::updateHistogram()
{
        QVector<double> x(256);
        for (int i = 0; i < 256; i++)
            x[i] = i;

        QVector<double> y(256);
        for (int i = 0; i < 256; i++)
            y[i] = rawImage->getHistogramBlue()[i];
        QVector<double> y1(256);
        for (int i = 0; i < 256; i++)
            y1[i] = rawImage->getHistogramGreen()[i];
        QVector<double> y2(256);
        for (int i = 0; i < 256; i++)
            y2[i] = rawImage->getHistogramRed()[i];

        QVector<double> y3(256); //grey
        for (int i = 0; i < 256; i++)
            y3[i] = rawImage->getHistogramRed()[i]+
                    rawImage->getHistogramGreen()[i]+
                    rawImage->getHistogramBlue()[i];

        barB->setData(x, y);
        barB->setPen(QPen(QColor(0, 0, 255, 25)));
        barB->setVisible(false);
        barG->setData(x, y1);
        barG->setPen(QPen(QColor(0, 255, 0, 25)));
        barG->setVisible(false);
        barR->setData(x, y2);
        barR->setPen(QPen(QColor(255, 0, 0, 25)));
        barR->setVisible(false);
        barAll->setData(x, y3);
        barAll->setPen(QPen(QColor(100, 100, 100, 255)));

        ui->customPlot->xAxis->setLabel("Brightness");
        ui->customPlot->yAxis->setLabel("Pixels");

        ui->customPlot->xAxis->setRange(0, 255);

        int maxY = 0;
        for (int i = 1; i < y.size() - 1; i++)
            if (maxY < y[i] || maxY < y1[i] || maxY < y2[i] || maxY < y3[i])
                maxY = qMax(qMax(y[i], y1[i]), qMax(y2[i], y3[i]));

        ui->customPlot->yAxis->setRange(0, maxY);
        ui->customPlot->replot();
}

void MainWindow::wait(int millisecondsToWait)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

VadimImage *MainWindow::getRawImage() const
{
    return rawImage;
}

void MainWindow::slotOpenFileDialog()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    loadImage();
    displayImage();
}

void MainWindow::slotChangeHistogramChannels(QString str)
{
    if (str == "RGB Channels")
    {
        barB->setVisible(false);
        barG->setVisible(false);
        barR->setVisible(false);
        barAll->setVisible(true);
    }
    else if (str == "Blue Channel")
    {
        barB->setVisible(true);
        barG->setVisible(false);
        barR->setVisible(false);
        barAll->setVisible(false);
    }
    else if (str == "Green Channel")
    {
        barB->setVisible(false);
        barG->setVisible(true);
        barR->setVisible(false);
        barAll->setVisible(false);
    }
    else if (str == "Red Channel")
    {
        barB->setVisible(false);
        barG->setVisible(false);
        barR->setVisible(true);
        barAll->setVisible(false);
    }

    ui->customPlot->replot();
}

void MainWindow::on_groupBox_toggled(bool arg1)
{
    if (arg1 == true)
        ui->groupBox->adjustSize();
    else
        ui->groupBox->resize(ui->groupBox->width(), 15);
}

void MainWindow::on_pushButton_clicked()
{
    displayImage();
}
