#ifndef VIMAGELOADER_H
#define VIMAGELOADER_H

#include <QString>
#include <QImage>
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QFileInfo>
#include <QByteArray>

#include "vector"

#include "vimage.h"

class VImageLoader
{
public:
    enum Format {bmp, jpg, tiff, png, vimgraw, vimgcomp};

    static VImage loadImage(const QString fileName);
    static void saveImage(const VImage& image, const QString savePath);

private:
    VImageLoader() {}
};

#endif // VIMAGELOADER_H
