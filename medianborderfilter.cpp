#include "medianborderfilter.h"
#include "ui_medianborderfilter.h"

MedianBorderFilter::MedianBorderFilter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedianBorderFilter)
{
    ui->setupUi(this);
}

MedianBorderFilter::~MedianBorderFilter()
{
    delete ui;
}

void MedianBorderFilter::on_pushButton_clicked()
{
    getWindow()->getRawImage()->medianFilter(ui->spinBox->value(), VadimImage::all);
    getWindow()->displayImage();
    getWindow()->updateHistogram();
}

MainWindow *MedianBorderFilter::getWindow()
{
    QWidget* widget = this;
    while (widget -> parentWidget() != Q_NULLPTR) widget = widget -> parentWidget() ;
    return qobject_cast<MainWindow *>(widget);
}
