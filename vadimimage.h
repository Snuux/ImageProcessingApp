#ifndef VADIMIMAGE_H
#define VADIMIMAGE_H

#include <QDebug>
#include <QImage>
#include <QList>
#include <QtMath>

class VadimImage
{
    unsigned char *originalPixels;
    unsigned char *stepPixels;
    unsigned char *pixels;

    //VadimImage previous; //TODO

    int histogramBlue[256];
    int histogramRed[256];
    int histogramGreen[256];

    int width;
    int height;

    int originalWidth;
    int originalHeight;

    int stepWidth;
    int stepHeight;

    double xzoom;
    double yzoom;
    double angle;

    unsigned char trunc(unsigned char a);
    int trunc(int a);
    double trunc(double a);

public:
    enum ImageFormat { rgb, grey };
    enum ImageChannel { red, green, blue, alpha, all, middle };

private:
    ImageFormat format;

public:
    VadimImage(QImage& img);
    ~VadimImage();

    //VadimImage &operator=(const VadimImage &other); //TODO

    void doHistogram();
    void editHistogram3(int x1, int x2, double k, ImageChannel ch);
    void editHistogram4(int x1, int x2, double k1, double k2, ImageChannel ch);
    void setBrightnessContrast(int a, double b, ImageChannel ch);
    void autoContrast(ImageChannel ch);

    void binImage(int v, ImageChannel ch);
    void convertToGrey(int alg, int num, ImageChannel ch);

    QList<unsigned char> getPalette(int size, ImageChannel ch);

    void binirizeSimple(unsigned char term, ImageChannel ch);

    void zoomNeighbor(int w, int h);
    void zoomNeighbor(double k);
    void zoomBilinear(int w, int h);
    void zoomBilinear(double k);
    //void zoomBicubic(int w, int h);

    void conv(double *arr, int w, int h, double coef, int alg, ImageChannel ch);

    void flipHorizontal();
    void flipVertical();
    void rotate90clockwise();
    void rotate90counterClockwise();
    void rotate180();

    void rotate(int angle);

    QImage getImage();

    int getWidth() const;
    int getHeight() const;
    double getXzoom() const;
    double getYzoom() const;
    double getAngle() const;

    int *getHistogramBlue();
    int *getHistogramGreen();
    int *getHistogramRed();

    ImageFormat getFormat() const;
};

#endif // VADIMIMAGE_H
