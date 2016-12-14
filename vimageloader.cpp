#include "vimageloader.h"

VImage VImageLoader::loadImage(const QString fileName)
{
    VImage image;

    QFile file(fileName);
    QFileInfo fileInfo(file);

    if (fileInfo.suffix() == QString("vimgraw"))
    {
        file.open(QIODevice::ReadOnly);
        QDataStream in(&file);

        int w,h;
        in >> w >> h;
        char* b = new char [w*h*4]; //hack
        in.readRawData(b, w*h*4);

        QVector<unsigned char> a;
        std::vector<unsigned char> v;
        v.assign(b, b + w*h*4);
        a = QVector<unsigned char>::fromStdVector(v);

        delete[] b;

        file.close();

        image = VImage(a.toStdVector(), w, h);
    }
    else if (fileInfo.suffix() == QString("vimgcomp"))
    {

    }
    else
    {
        QImage fileImage;
        fileImage.load(fileName);

        fileImage = fileImage.convertToFormat(QImage::Format_ARGB32);

        int w = fileImage.width();
        int h = fileImage.height();

        QVector<unsigned char> a;
        for (int i = 0; i < w*h*4; i++)
            //qDebug() << fileImage.bits()[i];
            a.push_back(fileImage.bits()[i]);

        image = VImage(a.toStdVector(), w, h);
    }

    return image;
}

void VImageLoader::saveImage(const VImage &image, const QString savePath)
{
    QString f = QFileInfo(savePath).suffix();

    QImage fileImage(&image.memPix[0], image.viewW, image.viewH, image.viewW * 4, QImage::Format_ARGB32);

    if (f == "tiff")
        fileImage.save(savePath, "tiff", 100);
    else if (f == "jpg")
        fileImage.save(savePath, "jpg", 100);
    else if (f == "bmp")
        fileImage.save(savePath, "bmp", 100);
    else if (f == "png")
        fileImage.save(savePath, "png", 100);
    else if (f == "vimgraw")
    {
        QFile file(savePath);

        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);

        out << (qint32)image.memW << (qint32)image.memH;

        for (int i = 0; i < image.memPix.size(); i++)
            out << image.memPix[i];

        file.close();
    }
    else if (f == "vimgcomp")
    {
        /*QFile file(QString(savePath));

        file.open(QIODevice::WriteOnly);
        QDataStream out(&file);

        QByteArray a;
        a.push_back((qint32)image.memW);
        a.push_back((qint32)image.memH);

        for (int i = 0; i < image.memPix.size(); i++)
            a.push_back(image.memPix[i]);

        QByteArray b;
        b = qCompress(a);

        out << b;

        file.close();*/
    }
}
