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

    doHistogram();
}

VadimImage::~VadimImage()
{
    delete[] pixels;
    delete[] originalPixels;
    delete[] stepPixels;
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

    int i,j,k,l,m,n;

    for (j = ch; j < height - ch; j++)
        for (i = cw; i < width - cw; i++)
            for (l = 0; l < h; l++)
                for (k = 0; k < w; k++)
                {
                    m = l - ch;
                    n = k - cw;
                    pixels[i + j*height] = 0;
                    pixels[i + j*height] += trunc(stepPixels[i + j*height  +  n + m*h] * arr[k + l*h] * coef);
                    pixels[i + j*height] /= (w * h);
                }

    //int index, aIndex, oldIndex;
    //
    //for (int j = 0; j < height; j++)
    //    for (int i = 0; i < width; i++)
    //    {
    //        index = i + j*4;
    //        for (int l = 0; l < h; l++)
    //            for (int k = 0; k < w; k++)
    //            {
    //                aIndex = k + l*4;
    //                oldIndex = index - (cw - ch*4);
    //
    //                pixels[index] = trunc(stepPixels[])
    //            }
    //    }



    //for (int i = 0; i < width * height * 4; i+=4)
    //{
    //    for (int j = 0; j < w * h * 4; j+=4)
    //    {
    //        pixels[i] = stepPixels[j]
    //    }
    //}

    //int py, px, ay, ax, mm, nn, ii, jj;
    //int newIndex, oldIndex, arrIndex;
    //
    //for (py = 0; py < height; py++)
    //{
    //    for (px = 0; px < width; px++)
    //    {
    //        for (ay = 0; ay < h; ay++)
    //        {
    //            mm = h - 1 - ay;
    //            for (ax = 0; ax < w; ax++)
    //            {
    //                nn = w - 1 - ax;
    //
    //                // index of input signal, used for checking boundary
    //                ii = py + (ay - ch);
    //                jj = px + (ax - cw);
    //
    //                newIndex = px+py*width;
    //                oldIndex = ii*width+jj;
    //                arrIndex = mm*width+nn;
    //
    //                // ignore input samples which are out of bound
    //                if( ii >= 0 && ii < height && jj >= 0 && jj < width )
    //                    for (int k = 0; k < 4; k++)
    //                        pixels[newIndex+k] += trunc(stepPixels[oldIndex+k] * arr[arrIndex] * coef);
    //
    //            }
    //        }
    //    }
    //}
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
        //qDebug() << "Cos" << cos << "Sin" << sin;
        double det = width * sin;

        int px, py;
        double rx, ry;

        QDebug dbg = qDebug();

        for (py = 0; py < h; py++)
        {
            for (px = 0; px < w; px++)
            {
                rx = px*cos - (py)*sin;
                ry = px*sin + (py)*cos;

                index = px + py * w;
                oldIndex = rx + ry * width;

                index*=4;
                oldIndex*=4;

                dbg << index << ", ";
                if (oldIndex >= 0 && oldIndex < width * height * 4)
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
