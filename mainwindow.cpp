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
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::slotSaveFileDialog);
    connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::slotUndo);
    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::slotRedo);
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

    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->removeTab(0);

    //todo
    loadImage();

    __int64 c1, c2, fr;
    double t;
    for (int i = 3; i < 31; i += 2)
    {
        QueryPerformanceCounter((LARGE_INTEGER *)&c1); //засекаем время запуска выполнения

        image.filterBox(i, VImage::channelAll);

        QueryPerformanceCounter((LARGE_INTEGER *)&c2); //засекаем время окончания выполнения
        QueryPerformanceFrequency((LARGE_INTEGER *)&fr); //получаем частоту

        t = (c2 - c1) / (float)fr;

        qDebug() << t;
    }

    //for (int i = 3; i < 15; i += 2)
    //{
    //QDateTime start = QDateTime::currentDateTime();
    //image.filterBox(i, VImage::channelAll);
    //QDateTime finish = QDateTime::currentDateTime();
    //
    //int secs = finish.secsTo(start);
    //start.addSecs(secs);
    //int msecs = finish.time().msecsTo(start.time());
    //
    //int msecs_duration = secs * 1000 + msecs;
    //
    //qDebug() << msecs_duration;
    //}


    //updateHistogram();
    //updateImage();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    //delete item;
}

void MainWindow::loadImage()
{
    image = VImageLoader::loadImage("C:/Users/snuux/Documents/Qt Projects/build-ImageBrowser-Desktop_Qt_5_7_0_MinGW_32bit-Debug/LenaCut.png");
    imageMem.setImage(image);
}

void MainWindow::loadImage(QString filepath)
{
    image = VImageLoader::loadImage(filepath);
    imageMem.setImage(image);
}

void MainWindow::updateImage()
{
    if (!ui->checkBox->isChecked() || (image.viewW != image.memW || image.viewH != image.memH))
    {
        QImage img(&image.viewPix[0], image.viewW, image.viewH, image.viewW * 4, QImage::Format_ARGB32);
        item->setPixmap(QPixmap::fromImage(img));
    }
    else
    {
        long int index;
        QVector<unsigned char> arr(QVector<unsigned char>::fromStdVector(image.viewPix));
        for (int i = 0; i < image.memH*4; i+=4)
            for (int j = 0; j < image.memW*4/2; j+=4)
            {
                index = j + i * image.memW;
                arr[index+0] = image.memPix[index+0];
                arr[index+1] = image.memPix[index+1];
                arr[index+2] = image.memPix[index+2];
                arr[index+3] = image.memPix[index+3];
            }

        QImage img(arr.data(), image.viewW, image.viewH, image.viewW * 4, QImage::Format_ARGB32);
        item->setPixmap(QPixmap::fromImage(img));
    }
}

void MainWindow::updateHistogram()
{
    VImage::computeHistogram(image.viewPix);
    //getRawImage()->doHistogram();

    QVector<double> x(256);
    for (int i = 0; i < 256; i++)
        x[i] = i;

    QVector<double> y(256);
    for (int i = 0; i < 256; i++)
        y[i] = VImage::histB[i];
    QVector<double> y1(256);
    for (int i = 0; i < 256; i++)
        y1[i] = VImage::histG[i];
    QVector<double> y2(256);
    for (int i = 0; i < 256; i++)
        y2[i] = VImage::histR[i];

    QVector<double> y3(256); //grey
    for (int i = 0; i < 256; i++)
        y3[i] = y[i]+y1[i]+y2[i];

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

    //ui->customPlot->xAxis->setLabel("Brightness");
    //ui->customPlot->yAxis->setLabel("Pixels");

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

void MainWindow::slotOpenFileDialog()
{
    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp *.tiff)"));

    loadImage(fileName);
    updateHistogram();
    updateImage();
}

void MainWindow::slotSaveFileDialog()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Image"), "", tr("Image Files (*.png *.jpg *.bmp *.tiff)"));
    VImageLoader::saveImage(image, fileName);
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

void MainWindow::slotUndo()
{
    imageMem.undo(image);
    updateImage();
    updateHistogram();
    qDebug() << "slotUndo";
}

void MainWindow::slotRedo()
{
    imageMem.redo(image);
    updateImage();
    updateHistogram();
    qDebug() << "slotRedo";
}

void MainWindow::on_applyButton_clicked()
{
    imageMem.apply(image);
    qDebug() << "on_applyButton_clicked";
}

void MainWindow::on_revertButton_clicked()
{
    image.memToView();
    updateImage();
    updateHistogram();
}

void MainWindow::on_undoButton_clicked()
{
    imageMem.undo(image);
    updateImage();
    updateHistogram();
    qDebug() << "on_undoButton_clicked";
}

void MainWindow::on_redoButton_clicked()
{
    imageMem.redo(image);
    updateImage();
    updateHistogram();
    qDebug() << "on_redoButton_clicked";
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &s)
{
    BaseUI::setCurCh(s);
    qDebug() << s;
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    qDebug() << "aa";
}
