#ifndef VIMAGE_H
#define VIMAGE_H

#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

#include <QDebug>

#define PI 3.1415926525

class VImage
{
public:
    static std::vector<unsigned char> viewPix;
    static int viewW, viewH;

    static std::vector<long int> histB;
    static std::vector<long int> histG;
    static std::vector<long int> histR;

    std::vector<unsigned char> memPix;
    int memW, memH;

    std::string commandName;
    std::vector<double> commandParameters;

public:
    VImage();
    VImage(const std::vector<unsigned char> &p, const int &width, const int &height);
    VImage(const VImage& copy);
    VImage &operator=(const VImage& copy); //copy

    enum ImageChannel { channelRed, channelGreen, channelBlue, channelAll };

    static void computeHistogram(const std::vector<unsigned char>& p);

    void viewToMem();
    void memToView();

    //LOGIC FUNCTIONS//

    void brightnessContrast(const int a, const double b, const VImage::ImageChannel ch);
    void editHistogram3(const int x1, const int x2, const double k, const ImageChannel ch);
    void editHistogram4(const int x1, const int x2, const double k1, const double k2, const ImageChannel ch);
    void autoContrast(ImageChannel ch);

    void binImage(const int v, const ImageChannel ch);
    void convertToGrey(const int alg, const int num, const ImageChannel ch);

    std::vector<unsigned char> getPalette(int n);
    void binirizeSimple(const unsigned char term, const ImageChannel ch);

    void zoomNeighbor(const int w, const int h);
    void zoomNeighbor(const double k);
    void zoomBilinear(const int w, const int h);
    void zoomBilinear(const double k);

    void conv(std::vector<double> arr, const int w, const int h, const double divider, const bool norm, const ImageChannel ch);
    void filterMedian(const int n, const ImageChannel ch);
    void filterSharpen(const double n, const ImageChannel ch);
    void filterBox(const int n, const ImageChannel ch);
    void filterGauss(const int n, const double m, const double d, const ImageChannel ch);

    void flipHorizontal();
    void flipVertical();
    void rotate90clockwise();
    void rotate90counterClockwise();
    void rotate180();

    void rotate(const double angle);

    void curveCorrection(const std::vector<double> &arr, const ImageChannel ch);
    void hsvCorrection(const short int h, const short int s, const short int v);

    void setBlackWhitePoints(unsigned char a, unsigned char b);
    void getBlackWhitePoints(unsigned char &a, unsigned char &b);

    void addColor(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha, std::string mode);

    //ADDITIONAL INLINE FUNCTIONS//
public:
    static inline unsigned char checkBounds0to255(const double &number)
    {
        if (number < 0)
            return 0;
        else if (number > 255)
            return 255;
        else
            return number;
    }

    static inline double checkBoundsCustom(const double &number, const double &a, const double &b)
    {
        if (number < a)
            return a;
        else if (number > b)
            return b;
        else
            return number;
    }

    static inline void pixelRGBtoHSV(const unsigned char &r, const unsigned char &g, const unsigned char &b, double &h, double &s, double &v)
    {
        double cr,cg,cb;
        double m1,m2, cmax, cmin, det;

        cr = r/255.0;
        cg = g/255.0;
        cb = b/255.0;

        m1 = std::min(cb, cg);
        m2 = std::min(cg, cr);
        cmin = std::min(m1, m2);
        m1 = std::max(cb, cg);
        m2 = std::max(cg, cr);
        cmax = std::max(m1, m2);

        det = cmax - cmin;

        v = cmax;

        /////

        if (det < 0.00001)
        {
            s = 0;
            h = 0;
            return;
        }
        if (cmax > 0.0)
            s = (det / cmax);
        else
        {
            s = 0;
            h = 0;
            return;
        }
        if (cr >= cmax)
            h = (cg - cb) / det;
        else if (cg >= cmax)
            h = 2.0 + (cb- cr) / det;
        else
            h = 4.0 + (cr - cg) / det;

        h *= 60.0;

        if (h < 0.0)
            h += 360;

        s *= 100.0;
        v *= 100.0;


        /*if (cmax == 0)
            s = 0;
        else
            s = det/cmax;

        if (det < 0.00001)
            h = 0;
        else if (cmax == cr)
            h = 60*(fmod((cg-cb)/det, 6));
        else if (cmax == cg)
            h = 60*(((cb-cr)/det) + 2);
        else //b
            h = 60*(((cr-cg)/det) + 4);

        h = VImage::checkBoundsCustom(h, 0, 360);
        s = VImage::checkBoundsCustom(h, 0, 100);
        v = VImage::checkBoundsCustom(h, 0, 100);*/
    }

    static inline void pixelHSVtoRGB(const double &h, const double &s, const double &v, unsigned char &r, unsigned char &g, unsigned char &b)
    {
        double c,x,m;
        double cr,cg,cb;

        double ch;
        double cs, cv;
        int i;
        double ff;

        if (s <= 0)
        {
            r = v / 100 * 255;
            g = v / 100 * 255;
            b = v / 100 * 255;
            return;
        }

        ch = h / 60.0;
        cs = s / 100;
        cv = v / 100;
        i = (int) ch;

        ff = ch - i;
        c = cv * (1.0 - cs);
        x = cv * (1.0 - (cs * ff));
        m = cv * (1.0 - (cs * (1.0 - ff)));

        //qDebug() << "cv, c, x, m" << cv << c << x << m;

        switch(i) {
        case 0:
            cr = cv;
            cg = m;
            cb = c;
            break;
        case 1:
            cr = x;
            cg = cv;
            cb = c;
            break;
        case 2:
            cr = c;
            cg = cv;
            cb = m;
            break;
        case 3:
            cr = c;
            cg = x;
            cb = cv;
            break;
        case 4:
            cr = m;
            cg = c;
            cb = cv;
            break;
        case 5:
        default:
            cr = cv;
            cg = c;
            cb = x;
            break;
        }

        r = cr * 255;
        g = cg * 255;
        b = cb * 255;


        /*double c,x,m;
        double cr,cg,cb;

        double ch;
        double cs, cv;
        ch = h / 60.0;
        cs = s / 100.0;
        cv = v / 100.0;

        c = cv * cs;
        x = c * (1 - abs( fmod(ch, 2) - 1) );
        m = cv - c;

        qDebug() << "fmod(ch, 2)" << fmod(ch, 2) << "ch % 2" << (int)ch % 2 << "ch / 2" << ch / 2;
        qDebug() << "c,x,m" << c << x << m;
        double xx = c * (1 - abs( fmod(ch, 2) - 1) );

        if      (ch >= 0 && ch < 1) {cr = c; cg = x; cb = 0;}
        else if (ch >= 1 && ch < 2) {cr = x; cg = c; cb = 0;}
        else if (ch >= 2 && ch < 3) {cr = 0; cg = c; cb = x;}
        else if (ch >= 3 && ch < 4) {cr = 0; cg = x; cb = c;}
        else if (ch >= 4 && ch < 5) {cr = x; cg = 0; cb = c;}
        else if (ch >= 5 && ch < 6) {cr = c; cg = 0; cb = x;}

        cb = (cb+m)*255.0;
        cg = (cg+m)*255.0;
        cr = (cr+m)*255.0;

        b = VImage::checkBounds0to255(cb);
        g = VImage::checkBounds0to255(cg);
        r = VImage::checkBounds0to255(cr);*/
    }

};

#endif // VIMAGE_H
