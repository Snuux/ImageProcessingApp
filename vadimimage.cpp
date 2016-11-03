#include "vadimimage.h"

int VadimImage::getWidth() const
{
    return width;
}

int VadimImage::getHeight() const
{
    return height;
}

double VadimImage::getXzoom() const
{
    return xzoom;
}

double VadimImage::getYzoom() const
{
    return yzoom;
}

double VadimImage::getAngle() const
{
    return angle;
}

int *VadimImage::getHistogramBlue()
{
    return histogramBlue;
}
int *VadimImage::getHistogramGreen()
{
    return histogramGreen;
}
int *VadimImage::getHistogramRed()
{
    return histogramRed;
}

VadimImage::ImageFormat VadimImage::getFormat() const
{
    return format;
}

unsigned char VadimImage::trunc(unsigned char a)
{
    a = a >= 255 ? 255 : a;
    a = a <= 0 ? 0 : a;
    return a;
}

int VadimImage::trunc(int a)
{
    a = a >= 255 ? 255 : a;
    a = a <= 0 ? 0 : a;
    return a;
}

double VadimImage::trunc(double a)
{
    a = a >= 255 ? 255 : a;
    a = a <= 0 ? 0 : a;
    return a;
}

VadimImage::VadimImage(QImage& img)
{
    img = img.convertToFormat(QImage::Format_ARGB32);

    width = img.width();
    height = img.height();

    originalWidth = img.width();
    originalHeight = img.height();

    stepWidth = img.width();
    stepHeight = img.height();

    pixels = new unsigned char[width*height*4];
    originalPixels = new unsigned char[width*height*4];
    stepPixels = new unsigned char[width*height*4];

    for (int i = 0; i < width*height*4; i++)
    {
        pixels[i] = img.constBits()[i];
        originalPixels[i] = img.constBits()[i];
        stepPixels[i] = img.constBits()[i];
    }

    hsvPixels = new double[width*height*3];
    hsvOriginalPixels = new double[width*height*3];
    hsvStepPixels = new double[width*height*3];

    copyRGBAtoHSV(pixels, hsvPixels);
    copyRGBAtoHSV(originalPixels, hsvOriginalPixels);
    copyRGBAtoHSV(stepPixels, hsvStepPixels);

    doHistogram();
}

VadimImage::~VadimImage()
{
    delete[] pixels;
    delete[] originalPixels;
    delete[] stepPixels;

    delete[] hsvPixels;
    delete[] hsvOriginalPixels;
    delete[] hsvStepPixels;
}

void VadimImage::copyHSLtoRGBA(double *a1, unsigned char *a2)
{
    unsigned char r,g,b;
    double h,s,l;
    double c, x, m;
    for (int i = 0, j = 0; i < width * height * 3; i+=3, j+=4)
    {
        h = a1[i];
        s = a1[i+1] ;
        l = a1[i+2];

        c = (1 - qAbs(2*l - 1)) * s;
        x = c * (1 - qAbs(fmod((h / 60), 2.0) - 1));
        m = l - c/2;

        if (h >= 0 && h < 60) {r = c; g = x; b = 0;}
        else if (h >= 60 && h < 120) {r = x; g = c; b = 0;}
        else if (h >= 120 && h < 180) {r = 0; g = c; b = x;}
        else if (h >= 180 && h < 240) {r = 0; g = x; b = c;}
        else if (h >= 240 && h < 300) {r = x; g = 0; b = c;}
        else if (h >= 300 && h < 360) {r = c; g = 0; b = x;}

        a2[j] = (b+m) * 255.0;
        a2[j+1] = (g+m) * 255.0;
        a2[j+2] = (r+m) * 255.0;
    }
}
void VadimImage::copyRGBAtoHSL(unsigned char *a1, double *a2)
{
    double h,s,l;
    double m1, m2, cmax, cmin, det, r,g,b;
    for (int i = 0, j = 0; i < width * height * 4; i+=4, j+=3)
    {
        b = a1[i]/255.0;
        g = a1[i+1]/255.0;
        r = a1[i+2]/255.0;

        m1 = qMin(b, g);
        m2 = qMin(g, r);
        cmin = qMin(m1, m2);

        m1 = qMax(b, g);
        m2 = qMax(g, r);
        cmax = qMax(m1, m2);

        det = cmax - cmin;

        if (det == 0)
            h = 0;
        else if (cmax == r)
            h = 60*fmod((g-b)/det,6.0);
        else if (cmax == g)
            h = 60*(((b-r)/det)+2);
        else //b
            h = 60*(((r-g)/det)+4);

        l = (cmax + cmin) / 2;

        if (det == 0)
            s = 0;
        else
            s = det / (1 - qAbs(2*l-1));

        a2[j] = h;
        a2[j+1] = s;
        a2[j+2] = l;
    }
}

void VadimImage::copyHSVtoRGBA(double *a1, unsigned char *a2)
{
    double r,g,b ,ar,ag,ab;
    double c,x,m,i,hh,ff, p,q,t; long tt;
    double h,s,v;
    double vmin, a, vinc, vdec;
    for (int i = 0, j = 0; i < width * height * 3; i+=3, j+=4)
    {
        h = a1[i];
        s = a1[i+1];
        v = a1[i+2];

        //vmin = ((100 - s) * v) / 100;
        //a = (v - vmin)*(fmod(h,60))/60;
        //vinc = vmin + a;
        //vdec = v - a;
        //
        //if (h >= 0 && h < 60) {r = v; g = vinc; b = vmin;}
        //else if (h >= 60 && h < 120) {r = vdec; g = v; b = vmin;}
        //else if (h >= 120 && h < 180) {r = vmin; g = v; b = vinc;}
        //else if (h >= 180 && h < 240) {r = vmin; g = vdec; b = v;}
        //else if (h >= 240 && h < 300) {r = vinc; g = vmin; b = v;}
        //else if (h >= 300 && h < 360) {r = v; g = vmin; b = vdec;}
        //
        //ar = r * 255;
        //ag = g * 255;
        //ab = b * 255;
        //
        //a2[j] = ab;
        //a2[j+1] = ag;
        //a2[j+2] = ar;

        c = v * s;
        x = c * (1 - qAbs( fmod(h/60,2) - 1) );//qAbs(fmod((h / 60), 2.0) - 1));
        m = v - c;

        if (h >= 0 && h < 60) {r = c; g = x; b = 0;}
        else if (h >= 60 && h < 120) {r = x; g = c; b = 0;}
        else if (h >= 120 && h < 180) {r = 0; g = c; b = x;}
        else if (h >= 180 && h < 240) {r = 0; g = x; b = c;}
        else if (h >= 240 && h < 300) {r = x; g = 0; b = c;}
        else if (h >= 300 && h < 360) {r = c; g = 0; b = x;}

        ab = (b+m) * 255.0;
        ag = (g+m) * 255.0;
        ar = (r+m) * 255.0;

        a2[j] =   ab;
        a2[j+1] = ag;
        a2[j+2] = ar;

        /*hh = h / 60.0;
        tt = (long)hh;
        ff = hh - tt;
        p = v * (1.0 - s);
        q = v * (1.0 - (s * ff));
        t = v * (1.0 - (s * (1.0 - ff)));

        switch(tt) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;

        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        case 5:
        default:
            r = v;
            g = p;
            b = q;
            break;
        }*/

        //c = v * s;
        //hh = h / 60.0;
        //x = c * (1 - qAbs( (fmod(hh,2)) - 1) );//qAbs(fmod((h / 60), 2.0) - 1));
        //m = v - c;
        //
        //     if (hh >= 0 && hh < 1) {r = c; g = x; b = 0;}
        //else if (hh >= 1 && hh < 2) {r = x; g = c; b = 0;}
        //else if (hh >= 2 && hh < 3) {r = 0; g = c; b = x;}
        //else if (hh >= 3 && hh < 4) {r = 0; g = x; b = c;}
        //else if (hh >= 4 && hh < 5) {r = x; g = 0; b = c;}
        //else if (hh >= 5 && hh < 6) {r = c; g = 0; b = x;}
        //
        //ab = (b+m) * 255.0;
        //ag = (g+m) * 255.0;
        //ar = (r+m) * 255.0;
        //
        //a2[j] =   b;
        //a2[j+1] = g;
        //a2[j+2] = r;
    }
}
void VadimImage::copyRGBAtoHSV(unsigned char *a1, double *a2)
{
    double h,s,v;
    double m1, m2, cmax, cmin, det, r,g,b ,dd,hh;
    for (int i = 0, j = 0; i < width * height * 4; i+=4, j+=3)
    {
        //qDebug() << a1[i] << a1[i+1] << a1[i+2];

        b = a1[i]/255.0;
        g = a1[i+1]/255.0;
        r = a1[i+2]/255.0;

        m1 = qMin(b, g);
        m2 = qMin(g, r);
        cmin = qMin(m1, m2);

        m1 = qMax(b, g);
        m2 = qMax(g, r);
        cmax = qMax(m1, m2);

        det = cmax - cmin;

        if (det == 0)
            h = 0;
        else if (cmax == r)
        {
            h = 60*(fmod((g-b)/det, 6));
        }
        else if (cmax == g)
            h = 60*(((b-r)/det) + 2);
        else //b
            h = 60*(((r-g)/det) + 4);

        v = cmax;

        if (cmax == 0)
            s = 0;
        else
            s = det/cmax; //cmax;//1 - cmin/cmax;

        if (h < 0) h += 360;
        else if (h > 360) h -= 360;
        if (s < 0) s = 0;
        else if (s > 100) s = 100;
        if (v < 0) v = 0;
        else if (v > 100) v = 100;

        a2[j] = h;
        a2[j+1] = s;
        a2[j+2] = v;

        //if (cmax == cmin)
        //    h = 0;
        //else if (cmax == r)
        //{
        //    if (g >= b)
        //        h = 60 * (g-b) / det + 0;
        //    else
        //        h = 60 * (g-b) / det + 360;
        //}
        //else if (cmax == g)
        //    h = 60*(((b-r)/det)+120);
        //else //b
        //    h = 60*(((r-g)/det)+240);

        //if (cmax == cmin)
        //    h = 0;
        //else if (cmax == r)
        //    h = 60*fmod((g-b)/det,6);
        //else if (cmax == g)
        //    h = 60*(((b-r)/det)+2);
        //else //b
        //    h = 60*(((r-g)/det)+4);
        //
        //qDebug() << fmod((g-b)/det,6);

        /*if (cmin == r) dd = g-b;
        else
        {
            if (cmin == b) dd = r-g;
            else dd = b-r;
        }
        if (cmin == r) hh = 3;
        else
        {
            if (cmin == b) hh = 1;
            else hh = 5;
        }

        h = 60 * (hh - dd / det);

        v = cmax;

        if (cmax == 0)
            s = 0;
        else
            s = det/cmax; //cmax;//1 - cmin/cmax;

        if (cmin == cmax)
        {
            h = 0;
            v = s;
        }

        a2[j] = h;
        a2[j+1] = s;
        a2[j+2] = v;*/
    }
}

void VadimImage::doHistogram()
{
    int i = 0;

    for (i = 0; i < 256; i++)
    {
        histogramBlue[i] = 0;
        histogramGreen[i] = 0;
        histogramRed[i] = 0;
    }

    for (i = 0; i < width * height; i+=4)
        histogramBlue[pixels[i]]++;

    for (i = 1; i < width * height-1; i+=4)
        histogramGreen[pixels[i]]++;

    for (i = 2; i < width * height-2; i+=4)
        histogramRed[pixels[i]]++;

}

void VadimImage::editHistogram3(int x1, int x2, double k, VadimImage::ImageChannel ch)
{
    if (ch == VadimImage::all)
    {
        //int t;
        //for (int i = 0; i < width * height * 4; i+=4)
        //{
        //    t = ((x2-x1) <= 0) ? 1 : x2-x1;
        //    pixels[i] = trunc(128 + (stepPixels[i] - 128) * k)/t;
        //    pixels[i+1] = trunc(128 + (stepPixels[i+1] - 128) * k)/t;
        //    pixels[i+2] = trunc(128 + (stepPixels[i+2] - 128) * k)/t;
        //}

        for (int i = 0; i < width * height * 4; i+=4)
        {
            pixels[i] = trunc(x1 + 128 + (stepPixels[i] - 128) * k - x2);
            pixels[i+1] = trunc(x1 + 128 + (stepPixels[i+1] - 128) * k - x2);
            pixels[i+2] = trunc(x1 + 128 + (stepPixels[i+2] - 128) * k - x2);
        }
    }

    doHistogram();
}

void VadimImage::editHistogram4(int x1, int x2, double k1, double k2, VadimImage::ImageChannel ch)
{
    if (ch == VadimImage::all)
    {
        int t;
        for (int i = 0; i < width * height * 4; i+=4)
        {
            t = ((x2-x1) <= 0) ? 1 : x2-x1;
            pixels[i] = trunc((stepPixels[i] - x1)/(t)*k2-k1+k1);
            pixels[i+1] = trunc((stepPixels[i+1] - x1)/(t)*k2-k1+k1);
            pixels[i+2] = trunc((stepPixels[i+2] - x1)/(t)*k2-k1+k1);
        }
    }

    doHistogram();
}

void VadimImage::setBrightnessContrast(int a, double b, VadimImage::ImageChannel ch)
{
    if (ch == VadimImage::all)
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            pixels[i] = trunc(a + 128 + (stepPixels[i] - 128) * b);
            pixels[i+1] = trunc(a + 128 + (stepPixels[i+1] - 128) * b);
            pixels[i+2] = trunc(a + 128 + (stepPixels[i+2] - 128) * b);
        }
    }
    else if (ch == VadimImage::blue)
    {
        for (int i = 0; i < width * height * 4; i+=4)
            pixels[i] = trunc(128 + (a - stepPixels[i]) * a);
    }
    else if (ch == VadimImage::green)
    {
        for (int i = 1; i < width * height * 4 - 1; i+=4)
            pixels[i] = trunc(128 + (a - stepPixels[i]) * a);
    }
    else if (ch == VadimImage::red)
    {
        for (int i = 2; i < width * height * 4 - 2; i+=4)
            pixels[i] = trunc(128 + (a - stepPixels[i]) * a);
    }

    doHistogram();
}

void VadimImage::autoContrast(VadimImage::ImageChannel ch)
{
    char min = 255;
    char max = 0;

    if (ch == VadimImage::all)
    {

    }
    //else if (ch == VadimImage::blue)
    //{
    //}
    //else if (ch == VadimImage::green)
    //{
    //}
    //else if (ch == VadimImage::red)
    //{
    //}

    doHistogram();
}

void VadimImage::convertToGrey(int alg, int num, VadimImage::ImageChannel ch)
{
    //http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/
    if (alg == 1) //simple sum/3
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            int grey = (stepPixels[i] + stepPixels[i+1] + stepPixels[i+2]) / 3;
            pixels[i] = grey;
            pixels[i+1] = grey;
            pixels[i+2] = grey;
        }
    }
    else if (alg == 2) //r*0.3+g*0.59+b*0.11
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            int grey = stepPixels[i] * 0.11 + stepPixels[i+1] * 0.59 + stepPixels[i+2] * 0.3;
            pixels[i] = grey;
            pixels[i+1] = grey;
            pixels[i+2] = grey;
        }
    }
    else if (alg == 3) //HSL Light (Cmax + Cmin)/2
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            unsigned char m1, m2, max, min;
            m1 = qMax(stepPixels[i], stepPixels[i+1]);
            m2 = qMax(stepPixels[i+1], stepPixels[i+2]);
            max = qMax(m1, m2);

            m1 = qMin(stepPixels[i], stepPixels[i+1]);
            m2 = qMin(stepPixels[i+1], stepPixels[i+2]);
            min = qMin(m1, m2);

            int grey = (max + min) / 2;
            pixels[i] = grey;
            pixels[i+1] = grey;
            pixels[i+2] = grey;
        }
    }
    else if (alg == 4) //Decomposition Max
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            unsigned char m1, m2, max;
            m1 = qMax(stepPixels[i], stepPixels[i+1]);
            m2 = qMax(stepPixels[i+1], stepPixels[i+2]);
            max = qMax(m1, m2);

            pixels[i] = max;
            pixels[i+1] = max;
            pixels[i+2] = max;
        }
    }
    else if (alg == 5) //Decomposition Min
    {
        for (int i = 0; i < width * height * 4; i+=4)
        {
            unsigned char m1, m2, min;

            m1 = qMin(stepPixels[i], stepPixels[i+1]);
            m2 = qMin(stepPixels[i+1], stepPixels[i+2]);
            min = qMin(m1, m2);

            pixels[i] = min;
            pixels[i+1] = min;
            pixels[i+2] = min;
        }
    }
    else if (alg == 6) //Single Color Channel
    {
        if (ch == VadimImage::all)
        {
            convertToGrey(1, 0, VadimImage::all);
        }
        else if (ch == VadimImage::blue)
        {
            for (int i = 0; i < width * height * 4; i+=4)
            {
                pixels[i] = stepPixels[i];
                pixels[i+1] = stepPixels[i];
                pixels[i+2] = stepPixels[i];
            }
        }
        else if (ch == VadimImage::green)
        {
            for (int i = 0; i < width * height * 4; i+=4)
            {
                pixels[i] = stepPixels[i+1];
                pixels[i+1] = stepPixels[i+1];
                pixels[i+2] = stepPixels[i+1];
            }
        }
        else if (ch == VadimImage::red)
        {
            for (int i = 0; i < width * height * 4; i+=4)
            {
                pixels[i] = stepPixels[i+2];
                pixels[i+1] = stepPixels[i+2];
                pixels[i+2] = stepPixels[i+2];
            }
        }
    }
    else if (alg == 7) //Custom N of gray shades
    {
        double conversionFactor = 255 / num;
        for (int i = 0; i < width * height * 4; i+=4)
        {
            double sum = (stepPixels[i] + stepPixels[i+1] + stepPixels[i+2]) / 3;
            unsigned char grey = (unsigned char) (sum / conversionFactor) * conversionFactor;
            pixels[i] = grey;
            pixels[i+1] = grey;
            pixels[i+2] = grey;
        }

    }
}

QList<unsigned char> VadimImage::getPalette(int size, VadimImage::ImageChannel ch)
{
    if (width*height > 300)
        zoomNeighbor(width*0.2, height*0.2);

    QList<unsigned char> p;

    struct colCount { unsigned char r; unsigned char g; unsigned char b; int count; };
    QList<colCount> list;

    for (int i = 4; i < width * height * 4; i+=4)
    {
        bool flag = false; // already exist
        colCount c;
        c.b = stepPixels[i];
        c.g = stepPixels[i+1];
        c.r = stepPixels[i+2];
        c.count = 1;

        for (int j = 0; j < list.length(); j++)
        {
            //qDebug() << c.b << list[i].b << c.g << list[i].g << c.r << list[i].r ;
            if (c.b == list[j].b && c.g == list[j].g && c.r == list[j].r)
            {
                list[j].count++;
                flag = true;
                break;
            }
        }

        if (!flag)
            list.append(c);
    }

    for (int i = 0; i < list.length(); i++) //sort
        for (int j = 0; j < list.length(); j++)
        {
            if (list[i].count > list[j].count)
                list.swap(i, j);
        }

    int j = 0;
    int k = (size < list.length()) ? size : list.length(); //if colors more then pixels
    for (int i = 0; i < k; i++)
    {
        p.append(list[j].b);
        p.append(list[j].g);
        p.append(list[j].r);
        j++;
        //if (hash.key(i) != 0)
        //qDebug() << (int)list[i].count;
    }

    return p;
}

void VadimImage::binirizeSimple(unsigned char term, VadimImage::ImageChannel ch)
{
    if (ch == VadimImage::all)
    {
        for (int i = 4; i < width * height * 4; i+=4)
        {
            int sum = (stepPixels[i] + stepPixels[i+1] + stepPixels[i+2]) / 3;
            if (sum < term)
            {
                pixels[i] = 0;
                pixels[i+1] = 0;
                pixels[i+2] = 0;
            }
            else
            {
                pixels[i] = 255;
                pixels[i+1] = 255;
                pixels[i+2] = 255;
            }
        }
    }
    else if (ch == VadimImage::blue)
    {
        for (int i = 0; i < width * height * 4; i+=4)
            pixels[i] = (stepPixels[i] > term) ? 255 : 0;
    }
    else if (ch == VadimImage::green)
    {
        for (int i = 1; i < width * height * 4 - 1; i+=4)
            pixels[i] = (stepPixels[i] > term) ? 255 : 0;
    }
    else if (ch == VadimImage::red)
    {
        for (int i = 2; i < width * height * 4 - 2; i+=4)
            pixels[i] = (stepPixels[i] > term) ? 255 : 0;
    }
}

void VadimImage::zoomNeighbor(int w, int h)
{
    //qDebug() << width << stepWidth << w;
    //qDebug() << height << stepHeight << h;

    width = stepWidth;
    height = stepHeight;

    int px, py, index;
    int count = 0;

    xzoom = (width - 1) / (float) w;
    yzoom = (height - 1) / (float) h;

    delete[] pixels;
    pixels = new unsigned char[w*h*4];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            px = (int) (xzoom * j);
            py = (int) (yzoom * i);
            index = py * width + px;

            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }

    width = w;
    height = h;
}

void VadimImage::zoomNeighbor(double k)
{
    int w = stepWidth * k;
    int h = stepHeight * k;
    zoomNeighbor(w, h);
}

void VadimImage::zoomBilinear(int w, int h)
{
    //qDebug() << width << stepWidth;
    //qDebug() << height << stepHeight;
    width = stepWidth;
    height = stepHeight;

    unsigned char A, B, C, D;
    int px, py, index;
    int count = 0;

    double pxD, pyD;
    xzoom = (width - 1) / (float) w;
    yzoom = (height - 1) / (float) h;

    delete[] pixels;
    pixels = new unsigned char[w*h*4];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            px = (int) (xzoom * j); //px пиксель между A,B
            py = (int) (yzoom * i); //py пиксель между C,D
            pxD = (xzoom * j) - px; //расстояние от A до px
            pyD = (yzoom * i) - py; //расстояние от C до py

            index = py * width + px; //текущее значение

            for (int k = 0; k < 4; k++)
            {
                A = stepPixels[index*4+k];
                B = stepPixels[(index+1)*4+k];
                C = stepPixels[(index+width)*4+k];
                D = stepPixels[(index+width+1)*4+k];

                //qDebug() << count << ": " << A << B << C << D << "  index: " << index << pixels[0] << index*4+k;

                pixels[count++] = (unsigned char) A*(1-pxD)*(1-pyD) + B*pxD*(1-pyD) + C*pyD*(1-pxD) + D*pxD*pyD;

                //qDebug() << count;
            }
        }
    }

    width = w;
    height = h;
}

void VadimImage::zoomBilinear(double k)
{
    int w = stepWidth * k;
    int h = stepHeight * k;
    zoomBilinear(w, h);
}

void VadimImage::conv(double *arr, int w, int h, double coef, int alg, VadimImage::ImageChannel chh)
{
    int cw = w/2, ch = h/2;

    int i,j,k,l,t, sum;
    int index, aIndex, sIndex;

    for (j = ch; j < height - ch; j++)
        for (i = cw; i < width - cw; i++)
        {
            index = i + j*width;

            for (t = 0; t < 4; t++)
            {
                sum = 0;
                for (l = 0; l < h; l++)
                    for (k = 0; k < w; k++)
                    {
                        aIndex = k + l*w;
                        sIndex = index + (k-cw + (l-ch)*width);//???? + t;
                        sum += stepPixels[sIndex*4 + t] * arr[aIndex] * coef;
                    }

                pixels[index*4 + t] = trunc(sum);
            }
        }
}

void VadimImage::medianFilter(int n, VadimImage::ImageChannel ch)
{
    int cn = n/2;

    unsigned char *tArr = new unsigned char [n*n];

    int i,j,k,l,t, count;
    int index, aIndex, sIndex;

    for (j = 0; j < height; j++)
        for (i = 0; i < width; i++)
        {
            index = i + j*width;

            for (t = 0; t < 4; t++)
            {
                count = 0;
                for (l = 0; l < n; l++)
                    for (k = 0; k < n; k++)
                    {
                        //aIndex = k + l*w;
                        //TODO
                        sIndex = ( index + (k - (cn-1) + (l- (cn-1))*width) )*4+t;
                        if (sIndex > 0 && sIndex < height * width* 4 - 0)
                        //if (i + k-n > 0 && i + k-n < width && j + l-n > 0 && j + l-n < height)
                            tArr[count++] = stepPixels[sIndex];
                        //sum += stepPixels[sIndex*4 + t] * arr[aIndex] * coef;
                    }

                sortArray(tArr, n);

                pixels[index*4 + t] = tArr[cn];

                //pixels[index*4 + t] = trunc(sum);
            }
        }

    delete[] tArr;
}

void VadimImage::sortArray(unsigned char *a, int size)
{
    bool swapp = true;
      while(swapp){
        swapp = false;
        for (int i = 0; i < size-1; i++) {
            if (a[i]>a[i+1] ){
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}

void VadimImage::flipHorizontal()
{
    int index;
    int count = 0;

    for (int py = 0; py < height; py++)
    {
        for (int px = 0; px < width; px++)
        {
            index = (py * width) + (width - px - 1);

            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }
}

void VadimImage::flipVertical()
{
    int index;
    int count = 0;

    for (int py = 0; py < height; py++)
    {
        for (int px = 0; px < width; px++)
        {
            index = ((height - py - 1) * width) + px;

            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }
}

void VadimImage::rotate90clockwise()
{
    height = stepHeight;
    width = stepWidth;

    int index;
    int count = 0;

    for (int px = 0; px < width; px++)
    {
        for (int py = 0; py < height; py++)
        {
            index = (height - 1 - py) * width + px;
            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }

    width = stepHeight;
    height = stepWidth;
}

void VadimImage::rotate90counterClockwise()
{
    height = stepHeight;
    width = stepWidth;

    int index;
    int count = 0;

    for (int px = 0; px < width; px++)
    {
        for (int py = 0; py < height; py++)
        {
            index = py * width + width - px - 1;
            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }

    width = stepHeight;
    height = stepWidth;
}

void VadimImage::rotate180()
{
    int index;
    int count = 0;

    for (int py = 0; py < height; py++)
    {
        for (int px = 0; px < width; px++)
        {
            index = (height - 1 - py) * width + width - px - 1;

            for (int k = 0; k < 4; k++)
                pixels[count++] = stepPixels[index*4+k];
        }
    }
}

void VadimImage::rotate(int ang)
{
    //ang = 45;
    bool clockwise = (ang < 0) ? false : true;

    ang = ang;
    if (clockwise)  //del
    {               //del
    width = stepWidth;
    height = stepHeight;

    double angle = qDegreesToRadians((double) ang);
    int w = qFabs(width * qCos(angle)) + qFabs(height * qSin(angle));
    int h = qFabs(width * qSin(angle)) + qFabs(height * qCos(angle));

    delete[] pixels;
    pixels = new unsigned char[w*h*4];

    for (int i = 0; i < w*h*4; i++)
        pixels[i] = 150;

    //if (clockwise) {
        int oldIndex;
        int index;
        int count = 0;
        double cos = qCos(angle);
        double sin = qSin(angle);
        qDebug() << "Cos" << cos << "Sin" << sin;
        double det = width * sin;

        int px, py;
        double rx, ry;

        //QDebug dbg = qDebug();

        for (py = 0; py < h; py++)
        {
            for (px = 0; px < w; px++)
            {
                rx = (px)*cos - (py-det)*sin;
                ry = (px)*sin + (py-det)*cos;

                index = px + py * w;
                oldIndex = rx + ry * width;

                index*=4;
                oldIndex*=4;

                //qDebug() << py << px << (px)*cos << (py-det)*sin << oldIndex/4;

                if (rx >= 0 && rx < width && ry >= 0 && ry < height)//oldIndex >= 0 && oldIndex < width * height * 4)
                {
                    //qDebug() << index/4 << oldIndex/4;
                    for (int k = 0; k < 4; k++)
                    {
                        pixels[index+k] = stepPixels[oldIndex+k];
                        //qDebug() << stepPixels[oldIndex+k];
                    }
                }

            }
        }

        width = w;
        height = h;

        //qDebug() << ang << angle << w << h;
    }


}

void VadimImage::curveCorrection(double *arr, int size, ImageChannel ch)
{
    for (int i = 0; i < width * height * 4; i+=4)
    {
        pixels[i] = trunc(stepPixels[i] * arr[stepPixels[i]]);
        pixels[i+1] = trunc(stepPixels[i+1] * arr[stepPixels[i+1]]);
        pixels[i+2] = trunc(stepPixels[i+2] * arr[stepPixels[i+2]]);
    }
}

void VadimImage::hsvCorrection(short int h, short int s, short int v)
{
    //copyRGBAtoHSV(stepPixels, hsvStepPixels);

    double ah = h/100.0;
    double as = s/100.0;
    double av = v/100.0;

    double nh, ns, nv;
    for (int i = 0; i < width * height * 3; i+=3)
    {
        nh = hsvStepPixels[i] + ah;
        if (nh > 360) nh -= 360; else if (nh < 0) nh = +360;
        ns = hsvStepPixels[i+1] + as;
        if (ns > 1) ns = 1; else if (ns < 0) ns = 0;
        nv = hsvStepPixels[i+2] + av;
        if (nv > 1) nv = 1; else if (nv < 0) nv = 0;

        hsvPixels[i] = nh;
        hsvPixels[i+1] = ns;
        hsvPixels[i+2] = nv;
    }

    copyHSVtoRGBA(hsvPixels, pixels);
}

void VadimImage::blackWhitePoints(unsigned char a, unsigned char b)
{
    if (a > b)
        qSwap(a,b);

    double k = (255 - 0) / (double)(b - a);
    double bb = (0 - k*a);

    for (int i = 0; i < width * height * 4; i+=4)
    {
        for (int j = 0; j < 4; j++)
        {
            pixels[i+j] = trunc(stepPixels[i+j]*k + bb);

            //if (pixels[i+j] < a)
            //    pixels[i+j] = a;
            //else
            //    pixels[i+j] = stepPixels[i+j];
            //
            //if (pixels[i+j] > b)
            //    pixels[i+j] = b;
            //else
            //    pixels[i+j] = stepPixels[i+j];
        }
    }
}

QImage VadimImage::getImage()
{
    QImage img(pixels, width, height, width * 4, QImage::Format_ARGB32);
    return img;
}

//VadimImage &VadimImage::operator=(const VadimImage &other) //TODO
//{
//    previous = other.previous;
//
//    //TODO
//    unsigned char *pixels;
//    unsigned char *palette;
//    int *histogram;
//
//    width = other.width;
//    height = other.height;
//
//    xzoom = other.xzoom;
//    yzoom = other.yzoom;
//    angle = other.angle;
//
//    format = other.format;
//}
