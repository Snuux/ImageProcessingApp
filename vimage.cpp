#include "vimage.h"

std::vector<unsigned char>  VImage::viewPix;
int                         VImage::viewW;
int                         VImage::viewH;
std::vector<long int>            VImage::histB;
std::vector<long int>            VImage::histG;
std::vector<long int>            VImage::histR;

VImage::VImage()
{

}

VImage::VImage(const std::vector<unsigned char>& p, const int &width, const int &height)
{
    memW = width;
    memH = height;
    memPix = p;

    viewW = memW;
    viewH = memH;
    viewPix = memPix;

    histB.resize(256);
    histG.resize(256);
    histR.resize(256);
}

VImage::VImage(const VImage &copy)
{
    memW = copy.memW;
    memH = copy.memH;
    memPix = copy.memPix;
}

VImage &VImage::operator=(const VImage &v)
{
    memW = v.memW;
    memH = v.memH;
    memPix = v.memPix;

    return *this;
}

void VImage::computeHistogram(const std::vector<unsigned char>& p)
{
    for (int i = 0; i < 256; i++) { histB[i] = 0; histG[i] = 0; histR[i] = 0; }

    int i = 0;
    int size = p.size()/4;

    for (i = 0; i < size; i+=4)
        histB[p[i]]++;

    for (i = 1; i < size-1; i+=4)
        histG[p[i]]++;

    for (i = 2; i < size-2; i+=4)
        histR[p[i]]++;
}

void VImage::viewToMem()
{
    memPix = viewPix;
    memW   = viewW;
    memH   = viewH;
}

void VImage::memToView()
{
    viewPix = memPix;
    viewW   = memW;
    viewH   = memH;
}

void VImage::editHistogram3(const int x1, const int x2, const double k, const VImage::ImageChannel ch)
{
    if (ch == VImage::channelAll)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i]   = checkBounds0to255(x1 + 128 + (memPix[i] - 128) * k - x2);
            viewPix[i+1] = checkBounds0to255(x1 + 128 + (memPix[i+1] - 128) * k - x2);
            viewPix[i+2] = checkBounds0to255(x1 + 128 + (memPix[i+2] - 128) * k - x2);
        }
    }
    else if (ch == VImage::channelBlue)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i]   = checkBounds0to255(x1 + 128 + (memPix[i] - 128) * k - x2);
    }
    else if (ch == VImage::channelGreen)
    {
        for (int i = 0; i < viewPix.size() - 1; i+=4)
            viewPix[i+1] = checkBounds0to255(x1 + 128 + (memPix[i+1] - 128) * k - x2);
    }
    else if (ch == VImage::channelRed)
    {
        for (int i = 0; i < viewPix.size() - 2; i+=4)
            viewPix[i+2] = checkBounds0to255(x1 + 128 + (memPix[i+2] - 128) * k - x2);
    }
}

void VImage::editHistogram4(const int x1, const int x2, const double k1, const double k2, const VImage::ImageChannel ch)
{
    int t = ((x2-x1) <= 0) ? 1 : x2-x1;

    if (ch == VImage::channelAll)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i]   = checkBounds0to255((memPix[i] - x1)/(t)*k2-k1+k1);
            viewPix[i+1] = checkBounds0to255((memPix[i+1] - x1)/(t)*k2-k1+k1);
            viewPix[i+2] = checkBounds0to255((memPix[i+2] - x1)/(t)*k2-k1+k1);
        }
    }
    else if (ch == VImage::channelBlue)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i]   = checkBounds0to255((memPix[i] - x1)/(t)*k2-k1+k1);
    }
    else if (ch == VImage::channelGreen)
    {
        for (int i = 0; i < viewPix.size() - 1; i+=4)
            viewPix[i+1] = checkBounds0to255((memPix[i+1] - x1)/(t)*k2-k1+k1);
    }
    else if (ch == VImage::channelRed)
    {
        for (int i = 0; i < viewPix.size() - 2; i+=4)
            viewPix[i+2] = checkBounds0to255((memPix[i+2] - x1)/(t)*k2-k1+k1);
    }
}

void VImage::autoContrast(VImage::ImageChannel ch)
{
    computeHistogram(viewPix);

    //vector<long int> hist(256);
    //for (int i = 0; i < 256; i++)
    //    hist = histB + histG + histR;
    //
    //vector<long int> perc(256);
    //for (int i = 0; i < 256; i++)
    //    perc[i] = 0;
    //
    //for (int i = 0; i < 256; i++)
    //    for (int j = 0; j < 256; j++)
    //        if (hist[i] >= hist[j])
    //            perc[i]++;
    //
    //
    //p5 = 0.05 * 255;
    //p95 = 0.95 * 255;


}

void VImage::convertToGrey(const int alg, const int num, const VImage::ImageChannel ch)
{
    //http://www.tannerhelland.com/3643/grayscale-image-algorithm-vb6/
    if (alg == 1) //simple sum/3
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            int grey = (memPix[i] + memPix[i+1] + memPix[i+2]) / 3;
           viewPix[i] = grey;
           viewPix[i+1] = grey;
           viewPix[i+2] = grey;
        }
    }
    else if (alg == 2) //r*0.3+g*0.59+b*0.11
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            int grey = memPix[i] * 0.11 + memPix[i+1] * 0.59 + memPix[i+2] * 0.3;
           viewPix[i] = grey;
           viewPix[i+1] = grey;
           viewPix[i+2] = grey;
        }
    }
    else if (alg == 3) //HSL Light (Cmax + Cmin)/2
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            unsigned char m1, m2, max, min;
            m1 = std::max(memPix[i], memPix[i+1]);
            m2 = std::max(memPix[i+1], memPix[i+2]);
            max = std::max(m1, m2);

            m1 = std::min(memPix[i], memPix[i+1]);
            m2 = std::min(memPix[i+1], memPix[i+2]);
            min = std::min(m1, m2);

            int grey = (max + min) / 2;
           viewPix[i] = grey;
           viewPix[i+1] = grey;
           viewPix[i+2] = grey;
        }
    }
    else if (alg == 4) //Decomposition Max
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            unsigned char m1, m2, max;
            m1 = std::max(memPix[i], memPix[i+1]);
            m2 = std::max(memPix[i+1], memPix[i+2]);
            max = std::max(m1, m2);

           viewPix[i] = max;
           viewPix[i+1] = max;
           viewPix[i+2] = max;
        }
    }
    else if (alg == 5) //Decomposition Min
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            unsigned char m1, m2, min;

            m1 = std::min(memPix[i], memPix[i+1]);
            m2 = std::min(memPix[i+1], memPix[i+2]);
            min = std::min(m1, m2);

           viewPix[i] = min;
           viewPix[i+1] = min;
           viewPix[i+2] = min;
        }
    }
    else if (alg == 6) //Single Color Channel
    {
        if (ch == channelAll)
        {
            convertToGrey(1, 0, channelAll);
        }
        else if (ch == channelBlue)
        {
            for (int i = 0; i < viewPix.size(); i+=4)
            {
               viewPix[i] = memPix[i];
               viewPix[i+1] = memPix[i];
               viewPix[i+2] = memPix[i];
            }
        }
        else if (ch == channelGreen)
        {
            for (int i = 0; i < viewPix.size(); i+=4)
            {
               viewPix[i] = memPix[i+1];
               viewPix[i+1] = memPix[i+1];
               viewPix[i+2] = memPix[i+1];
            }
        }
        else if (ch == channelRed)
        {
            for (int i = 0; i < viewPix.size(); i+=4)
            {
               viewPix[i] = memPix[i+2];
               viewPix[i+1] = memPix[i+2];
               viewPix[i+2] = memPix[i+2];
            }
        }
    }
    else if (alg == 7) //Custom N of gray shades
    {
        double conversionFactor = 255 / num;
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            double sum = (memPix[i] + memPix[i+1] + memPix[i+2]) / 3;
            unsigned char grey = (unsigned char) (sum / conversionFactor) * conversionFactor;
            viewPix[i] = grey;
            viewPix[i+1] = grey;
            viewPix[i+2] = grey;
        }

    }
}

std::vector<unsigned char> VImage::getPalette(int size)
{
    zoomBilinear(50, 50);

    std::vector<unsigned char> p(0);

    struct colCount { unsigned char r; unsigned char g; unsigned char b; int count; };
    std::vector<colCount> list;

    for (int i = 4; i < viewPix.size(); i+=4)
    {
        bool flag = false; // already exist
        colCount c;
        c.b = viewPix[i];
        c.g = viewPix[i+1];
        c.r = viewPix[i+2];
        c.count = 1;

        if (!list.empty())
            for (int j = 0; j < list.size()-1; j++)
            {
                //qDebug() << c.b << list[i].b << c.g << list[i].g << c.r << list[i].r ;
                if (c.b == list.at(j).b && c.g == list.at(j).g && c.r == list.at(j).r)
                {
                    list[j].count++;
                    flag = true;
                    break;
                }
            }

        if (!flag)
            list.push_back(c);
    }

    for (int i = 0; i < list.size()-1; i++) //sort
        for (int j = 0; j < list.size()-1; j++)
        {
            if (list[i].count > list[j].count)
                std::swap(list[i], list[j]);
                //list.swap(i, j);
        }

    int j = 0;
    int k = (size < list.size()) ? size : list.size(); //if colors more then pixels
    for (int i = 0; i < k; i++)
    {
        p.push_back(list[j].b);
        p.push_back(list[j].g);
        p.push_back(list[j].r);
        j++;
        //if (hash.key(i) != 0)
        //qDebug() << (int)list[i].count;
    }

    memToView();

    return p;
}

void VImage::binirizeSimple(const unsigned char term, const VImage::ImageChannel ch)
{
    if (ch == VImage::channelAll)
    {
        for (int i = 4; i < viewPix.size(); i+=4)
        {
            int sum = (memPix[i] + memPix[i+1] + memPix[i+2]) / 3;
            if (sum < term)
            {
                viewPix[i] = 0;
                viewPix[i+1] = 0;
                viewPix[i+2] = 0;
            }
            else
            {
                viewPix[i] = 255;
                viewPix[i+1] = 255;
                viewPix[i+2] = 255;
            }
        }
    }
    else if (ch == VImage::channelBlue)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i] = (memPix[i] > term) ? 255 : 0;
    }
    else if (ch == VImage::channelGreen)
    {
        for (int i = 0; i < viewPix.size() - 1; i+=4)
            viewPix[i] = (memPix[i] > term) ? 255 : 0;
    }
    else if (ch == VImage::channelRed)
    {
        for (int i = 0; i < viewPix.size() - 2; i+=4)
            viewPix[i] = (memPix[i] > term) ? 255 : 0;
    }
}

void VImage::zoomNeighbor(const int w, const int h)
{
    viewW = memW;
    viewH = memH;

    int px, py, index;
    int count = 0;

    double xzoom = (viewW - 1) / (float) w;
    double yzoom = (viewH - 1) / (float) h;

    viewPix.resize(w*h*4);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            px = (int) (xzoom * j);
            py = (int) (yzoom * i);
            index = py * viewW + px;

            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }

    viewW = w;
    viewH = h;
}

void VImage::zoomNeighbor(const double k)
{
    int w = memW * k;
    int h = memH * k;
    zoomNeighbor(w, h);
}

void VImage::zoomBilinear(const int w, const int h)
{
    viewW = memW;
    viewH = memH;

    unsigned char A, B, C, D;
    int px, py, index;
    int count = 0;

    double pxD, pyD;
    double xzoom = (viewW - 1) / (float) w;
    double yzoom = (viewH - 1) / (float) h;

    viewPix.resize(w*h*4);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            px = (int) (xzoom * j); //px пиксель между A,B
            py = (int) (yzoom * i); //py пиксель между C,D
            pxD = (xzoom * j) - px; //расстояние от A до px
            pyD = (yzoom * i) - py; //расстояние от C до py

            index = py * viewW + px; //текущее значение

            for (int k = 0; k < 4; k++)
            {
                A = memPix[index*4+k];
                B = memPix[(index+1)*4+k];
                C = memPix[(index+viewW)*4+k];
                D = memPix[(index+viewW+1)*4+k];

                viewPix[count++] = (unsigned char) A*(1-pxD)*(1-pyD) + B*pxD*(1-pyD) + C*pyD*(1-pxD) + D*pxD*pyD;
            }
        }
    }

    viewW = w;
    viewH = h;
}

void VImage::zoomBilinear(const double k)
{
    int w = memW * k;
    int h = memH * k;
    zoomBilinear(w, h);
}

void VImage::conv(std::vector<double> arr, const int w, const int h, const double divider, const bool norm, const VImage::ImageChannel chh)
{
    int cw = w/2, ch = h/2;

    int i,j,k,l, sx,sy;
    int index, aIndex, sIndex;
    double r,g,b,a;

    //norm
    if (norm)
    {
        //double vmax = arr[0];
        //for (i = 0; i < arr.size() - 1; i++)
        //    if (vmax < arr[i]);
        //        vmax = arr[i];
        //vmax *= h*w;
        //
        //for (i = 0; i < arr.size() - 1; i++)
        //   arr[i] /= vmax;

        double sum = 0;
        for (i = 0; i < arr.size(); i++)
            sum += arr[i];
        for (i = 0; i < arr.size(); i++)
            arr[i] /= sum;
    }

    for (j = 0; j < memH; j++)
        for (i = 0; i < memW; i++)
        {
            index = i + j * memW;
            r=0;g=0;b=0;a=0;

            for (l = 0; l < h; l++)
                for (k = 0; k < w; k++)
                {
                    sx = i + k-cw;
                    sy = j + l-ch;

                    if (sx < 0 || sy < 0 || sx >= memW || sy >= memH)
                    {
                        aIndex = k + l*w;

                        if (sx < 0 && sy < 0)
                            sIndex = (i+k-cw-sx) + (j+l-ch-sy)*memW;
                        else if (sx < 0 && sy >= memH)
                            sIndex = (i+k-cw-sx) + (j+l-ch-(sy-memH))*memW;
                        else if (sx >= memW && sy < 0)
                            sIndex = (i+k-cw-(sx-memW)) + (j+l-ch-sy)*memW;
                        else if (sx >= memW && sy >= memH)
                            sIndex = (i+k-cw-(sx-memW)) + (j+l-ch-(sy-memH))*memW;

                        b += memPix[sIndex*4+0] * arr[aIndex];
                        g += memPix[sIndex*4+1] * arr[aIndex];
                        r += memPix[sIndex*4+2] * arr[aIndex];
                        //a += memPix[sIndex*4+3] * arr[aIndex];
                    }
                    else
                    {
                        aIndex = k + l*w;
                        sIndex = (i+k-cw) + (j+l-ch)*memW;

                        //qDebug() << memPix[sIndex*4+0] << arr[aIndex] << memPix[sIndex*4+0] * arr[aIndex];

                        b += memPix[sIndex*4+0] * arr[aIndex];
                        g += memPix[sIndex*4+1] * arr[aIndex];
                        r += memPix[sIndex*4+2] * arr[aIndex];
                        //a += memPix[sIndex*4+3] * arr[aIndex];
                    }
                }

            b /= divider;
            g /= divider;
            r /= divider;
            //a /= divider;

            if (b < 0) b = 255 - checkBounds0to255(-b);
            if (r < 0) r = 255 - checkBounds0to255(-r);
            if (g < 0) g = 255 - checkBounds0to255(-g);
            //if (a < 0) a = 255 + a;

            viewPix[index*4 + 0] = checkBounds0to255(b);
            viewPix[index*4 + 1] = checkBounds0to255(g);
            viewPix[index*4 + 2] = checkBounds0to255(r);
            //viewPix[index*4 + 3] = a;
        }

    viewToMem(); //hack
}

void VImage::filterMedian(const int n, const VImage::ImageChannel ch)
{
    int cn = n/2;
    std::vector<unsigned char> arr(n*n);

    int i,j,k,l,t, sx,sy , count;
    int index, aIndex, sIndex;
    double r,g,b,a;
    double vmax;

    for (j = 0; j < viewH; j++)
        for (i = 0; i < viewW; i++)
        {
            index = i + j * viewW;

            for (int t = 0; t < 4; t++)
            {
                count = 0;

                for (l = 0; l < n; l++)
                    for (k = 0; k < n; k++)
                    {
                        sx = i + k-cn;
                        sy = j + l-cn;

                        if (sx < 0 || sy < 0 || sx >= viewW || sy >= viewH)
                        {
                            if (sx < 0 && sy < 0)
                                sIndex = (i+k-cn-sx) + (j+l-cn-sy)*viewW;
                            else if (sx < 0 && sy >= viewH)
                                sIndex = (i+k-cn-sx) + (j+l-cn-(sy-viewH))*viewW;
                            else if (sx >= viewW && sy < 0)
                                sIndex = (i+k-cn-(sx-viewW)) + (j+l-cn-sy)*viewW;
                            else if (sx >= viewW && sy >= viewH)
                                sIndex = (i+k-cn-(sx-viewW)) + (j+l-cn-(sy-viewH))*viewW;

                            arr[count++] = viewPix[sIndex*4 + t];
                        }
                        else
                        {
                            sIndex = (i+k-cn) + (j+l-cn)*viewW;
                            arr[count++] = viewPix[sIndex*4 + t];
                        }
                    }

                std::sort(arr.begin(), arr.end(),std::less<unsigned char>());
                viewPix[index*4 + t] = arr[arr.size()/2];
            }
        }
}

void VImage::filterSharpen(const double n, const VImage::ImageChannel ch)
{
    std::vector<double> arr(n*n);
    for (int i = 0; i < n*n; i++)
    {
        arr[i] = -1;
    }
    arr[arr.size()/2] = n*n;

    conv(arr, n, n, 1, 0, ch);
}

void VImage::filterBox(const int n, const VImage::ImageChannel ch)
{
    std::vector<double> arr(n*n);
    for (int i = 0; i < n*n; i++)
        arr[i] = 1;

    conv(arr, n, n, n*n, 0, ch);
}

void VImage::filterGauss(const int n, const double m, const double d, const VImage::ImageChannel ch)
{
    std::vector<double> arr(n*n);
    double sum = 0;

    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
        {
            arr[y+x*n] = exp( -0.5 * (pow((x-m)/d, 2.0) + pow((y-m)/d,2.0)) )
                    / (2 * PI * d * d);

            sum += arr[y+x*n];
        }

    //norm
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            arr[y+x*n] /= sum;

    conv(arr, n, n, 1, 0, ch);
}

void VImage::flipHorizontal()
{
    int index;
    int count = 0;

    for (int py = 0; py < viewH; py++)
    {
        for (int px = 0; px < viewW; px++)
        {
            index = (py * viewW) + (viewW - px - 1);

            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }
}

void VImage::flipVertical()
{
    int index;
    int count = 0;

    for (int py = 0; py < viewH; py++)
    {
        for (int px = 0; px < viewW; px++)
        {
            index = ((viewH - py - 1) * viewW) + px;

            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }
}

void VImage::rotate90clockwise()
{
    viewW = memH;
    viewH = memW;

    int index;
    int count = 0;

    for (int px = 0; px < memW; px++)
    {
        for (int py = 0; py < memH; py++)
        {
            index = (memH - 1 - py) * memW + px;
            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }

    //memW = viewW;
    //memH = viewH;
}

void VImage::rotate90counterClockwise()
{
    viewW = memH;
    viewH = memW;

    int index;
    int count = 0;

    for (int px = 0; px < memW; px++)
    {
        for (int py = 0; py < memH; py++)
        {
            index = py * memW + memW - px - 1;
            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }

    //memW = viewW;
    //memH = viewH;
}

void VImage::rotate180()
{
    int index;
    int count = 0;

    for (int py = 0; py < viewH; py++)
    {
        for (int px = 0; px < viewW; px++)
        {
            index = (viewH - 1 - py) * viewW + viewW - px - 1;

            for (int k = 0; k < 4; k++)
                viewPix[count++] = memPix[index*4+k];
        }
    }
}

void VImage::rotate(const double ang)
{
    //ang = 45;
    //bool clockwise = (ang < 0) ? false : true;

    //ang = ang;
    //if (clockwise)  //del
    //{               //del
        viewW = memW;
        viewH = memH;

        double angle = ang*PI/180;
        double bcos = cos(angle);
        double bsin = sin(angle);

        int w = abs(viewW * bcos) + abs(viewH * bsin);
        int h = abs(viewW * bsin) + abs(viewH * bcos);

        viewPix.resize(w*h*4);

        for (int i = 0; i < w*h*4; i++)
            viewPix[i] = 150;

        int oldIndex;
        int index;
        int px, py;
        double rx, ry;

        double detx = 0;
        double dety = 0;

        if (ang >= 0 && ang <= 90 || ang >= -360 && ang <= -270)
        {
            dety = viewW * bsin;
        }
        else if (ang >= 90 && ang <= 180 || ang >= -270 && ang <= -180)
        {
            dety = viewW * cos (90*PI/180-angle) - viewH * sin (90*PI/180-angle);
            detx = -viewW * sin( 90*PI/180-angle);
        }
        else if (ang >= 180 && ang <= 270 || ang >= -180 && ang <= -90)
        {
            dety = viewH * sin(180*PI/180 - (360*PI/180 - 90*PI/180 - angle));
            detx = - viewH * sin(180*PI/180 - (180*PI/180 - 90*PI/180 - (180*PI/180 - (360*PI/180-90*PI/180 - angle)))) + viewW * sin(180*PI/180 - (360*PI/180 - 90*PI/180 - angle));
        }
        else if (ang >= 270 && ang <= 360 || ang >= -90 && ang <= -0)
        {
            detx = viewH * sin(90*PI/180 - (angle - 180*PI/180 - 90*PI/180));
        }

        for (py = 0; py < h; py++)
            for (px = 0; px < w; px++)
            {
                rx = (px - detx)*bcos - (py - dety)*bsin;
                ry = (px - detx)*bsin + (py - dety)*bcos;

                index = px + py * w;
                oldIndex = abs(rx) + abs(ry) * viewW;

                index*=4;
                oldIndex*=4;

                if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))
                    for (int k = 0; k < 4; k++)
                        viewPix[index+k] = memPix[oldIndex+k];
            }

        /*if (angle >= 0 && angle <= 90 || angle >= -360 && angle <= -270)
        {
            double det = viewW * bsin;

            for (py = 0; py < h; py++)
                for (px = 0; px < w; px++)
                {
                    rx = (px-detx)*bcos - (py-dety)*bsin;
                    ry = (px-detx)*bsin + (py-dety)*bcos;

                    index = px + py * w;
                    oldIndex = abs(rx) + abs(ry) * viewW;

                    index*=4;
                    oldIndex*=4;

                    if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))
                        for (int k = 0; k < 4; k++)
                            viewPix[index+k] = memPix[oldIndex+k];
                }
        }
        else if (angle >= 90 && angle <= 180 || angle >= -270 && angle <= -180)
        {
            double dety = viewW * cos (90*PI/180-angle) - viewH * sin (90*PI/180-angle);
            double detx = -viewW * sin( 90*PI/180-angle);

            for (py = 0; py < h; py++)
                for (px = 0; px < w; px++)
                {
                    rx = (px - detx)*bcos - (py - dety)*bsin;
                    ry = (px - detx)*bsin + (py - dety)*bcos;

                    index = px + py * w;
                    oldIndex = abs(rx) + abs(ry) * viewW;

                    index*=4;
                    oldIndex*=4;

                    if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))
                        for (int k = 0; k < 4; k++)
                            viewPix[index+k] = memPix[oldIndex+k];
                }
        }
        else if (angle >= 180 && angle <= 270 || angle >= -180 && angle <= -90)
        {
        double dety = viewH * sin(180*PI/180 - (360*PI/180 - 90*PI/180 - angle));
        double detx = - viewH * sin(180*PI/180 - (180*PI/180 - 90*PI/180 - (180*PI/180 - (360*PI/180-90*PI/180 - angle)))) + viewW * sin(180*PI/180 - (360*PI/180 - 90*PI/180 - angle));
                //- viewW * cos (360*PI/180 - 90*PI/180 - 90*PI/180 - angle) - viewH * sin (360*PI/180 - 90*PI/180 - angle);

        qDebug() << dety << detx;

        for (py = 0; py < h; py++)
            for (px = 0; px < w; px++)
            {
                rx = (px - detx)*bcos - (py - dety)*bsin;
                ry = (px - detx)*bsin + (py - dety)*bcos;

                index = px + py * w;
                oldIndex = abs(rx) + abs(ry) * viewW;

                index*=4;
                oldIndex*=4;

                if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))
                    for (int k = 0; k < 4; k++)
                        viewPix[index+k] = memPix[oldIndex+k];
            }
        } else if (angle >= 270 && angle <= 360 || angle >= -90 && angle <= -0)

            double dety = 0;//viewW * sin(360*PI/180 - angle) + viewH * cos(180*PI/180 - 90*PI/180 - (180*PI/180 - (360*PI/180 - angle)));
            double detx = viewH * sin(90*PI/180 - (angle - 180*PI/180 - 90*PI/180));
                    //- viewH * sin(180*PI/180 - (180*PI/180 - 90*PI/180 - (180*PI/180 - (360*PI/180-90*PI/180 - angle)))) + viewW * sin(180*PI/180 - (360*PI/180 - 90*PI/180 - angle));
                    //- viewW * cos (360*PI/180 - 90*PI/180 - 90*PI/180 - angle) - viewH * sin (360*PI/180 - 90*PI/180 - angle);

            //qDebug() << viewW * sin(360*PI/180 - angle) << viewH * cos(180*PI/180 - 90*PI/180 - (180*PI/180 - (360*PI/180 - angle)));
            qDebug() << dety << detx;

            for (py = 0; py < h; py++)
                for (px = 0; px < w; px++)
                {
                    rx = (px - detx)*bcos - (py - dety)*bsin;
                    ry = (px - detx)*bsin + (py - dety)*bcos;

                    index = px + py * w;
                    oldIndex = abs(rx) + abs(ry) * viewW;

                    index*=4;
                    oldIndex*=4;

                    if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))
                        for (int k = 0; k < 4; k++)
                            viewPix[index+k] = memPix[oldIndex+k];
                }*/


        /*int oldIndex;
        int index;
        int count = 0;
        double det = viewW * bsin;

        int px, py;
        double rx, ry;

        for (py = 0; py < h; py++)
        {
            for (px = 0; px < w; px++)
            {
                rx = (px)*bcos - (py)*bsin;
                ry = (px)*bsin + (py)*bcos;

                index = px + py * w;
                oldIndex = rx + ry * viewW;

                index*=4;
                oldIndex*=4;

                //qDebug() << px << rx << py << ry << oldIndex/4;

                if (!(rx < 0 || rx > viewW || ry < 0 || ry > viewH))//oldIndex >= 0 && oldIndex < width * height * 4)
                {
                    //qDebug() << index/4 << oldIndex/4;
                    for (int k = 0; k < 4; k++)
                    {
                        viewPix[index+k] = memPix[oldIndex+k];
                        //qDebug() << stepPixels[oldIndex+k];
                    }
                }

            }
        }*/

        viewW = w;
        viewH = h;
    //}

}

void VImage::curveCorrection(const std::vector<double> &arr, const VImage::ImageChannel ch)
{
    if (ch == VImage::channelAll)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i] =   checkBounds0to255(memPix[i]   * arr[memPix[i]]);
            viewPix[i+1] = checkBounds0to255(memPix[i+1] * arr[memPix[i+1]]);
            viewPix[i+2] = checkBounds0to255(memPix[i+2] * arr[memPix[i+2]]);
        }
    }
    else if (ch == VImage::channelBlue)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i] =   checkBounds0to255(memPix[i]   * arr[memPix[i]]);
    }
    else if (ch == VImage::channelGreen)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i+1] = checkBounds0to255(memPix[i+1] * arr[memPix[i+1]]);
    }
    else if (ch == VImage::channelRed)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i+2] = checkBounds0to255(memPix[i+2] * arr[memPix[i+2]]);
    }
}

void VImage::hsvCorrection(const short h, const short s, const short v)
{
    //QVector<double> hsv(viewW*viewH*3);
    unsigned char r,g,b;
    double ch,cs,cv;
    //double m1,m2, cmax, cmin, det;
    //
    for (int i = 0; i < viewPix.size(); i+=4)
    {
        b = memPix[i];
        g = memPix[i+1];
        r = memPix[i+2];

        pixelRGBtoHSV(r,g,b, ch,cs,cv);
        ch = checkBoundsCustom(h, 0, 360);
        cs = checkBoundsCustom(cs + s, 0, 100);
        cv = checkBoundsCustom(cv + v, 0, 100);
        pixelHSVtoRGB(ch,cs,cv, r,g,b);

        viewPix[i+0] = b;
        viewPix[i+1] = g;
        viewPix[i+2] = r;
    }

    //rgb-to-hsv
    //proceed
    //hsv-to-rgb
}

void VImage::setBlackWhitePoints(unsigned char a, unsigned char b)
{
    if (a > b) { unsigned char f = a; a = b; b = f; } //swap

    double k = (255 - 0) / (double)(b - a);
    double bb = (0 - k*a);

    for (int i = 0; i < viewPix.size(); i+=4)
    {
        for (int j = 0; j < 4; j++)
        {
            viewPix[i+j] = checkBounds0to255(memPix[i+j]*k + bb);

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

void VImage::addColor(unsigned char r, unsigned char g, unsigned char b, unsigned char alpha, std::string mode)
{
    //unsigned char oldB, oldG, oldR;
    //unsigned char newB, newG, newR;
    if (mode == std::string("Normal"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(memPix[i+0] + b * alpha/255.0);
            viewPix[i+1] = checkBounds0to255(memPix[i+1] + g * alpha/255.0);
            viewPix[i+2] = checkBounds0to255(memPix[i+2] + r * alpha/255.0);
        }
    }
    else if (mode == std::string("Darken"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = std::min((double) memPix[i+0], b * alpha/255.0); //checkBounds0to255(memPix[i+0] + b * alpha/255);
            viewPix[i+1] = std::min((double) memPix[i+1], g * alpha/255.0);
            viewPix[i+2] = std::min((double) memPix[i+2], r * alpha/255.0);
        }
    }
    else if (mode == std::string("Multiply"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(memPix[i+0] * b * alpha/255.0);
            viewPix[i+1] = checkBounds0to255(memPix[i+1] * g * alpha/255.0);
            viewPix[i+2] = checkBounds0to255(memPix[i+2] * r * alpha/255.0);
        }
    }
    else if (mode == std::string("Color Burn"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(255.0 - (255.0 - memPix[i+0]) / b * alpha/255.0);
            viewPix[i+1] = checkBounds0to255(255.0 - (255.0 - memPix[i+1]) / g * alpha/255.0);
            viewPix[i+2] = checkBounds0to255(255.0 - (255.0 - memPix[i+2]) / r * alpha/255.0);
        }
    }
    else if (mode == std::string("Linear Burn"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(memPix[i+0] + b * alpha/255.0 - 255.0);
            viewPix[i+1] = checkBounds0to255(memPix[i+1] + g * alpha/255.0 - 255.0);
            viewPix[i+2] = checkBounds0to255(memPix[i+2] + r * alpha/255.0 - 255.0);
        }
    }
    else if (mode == std::string("Lighten"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = std::max((double) memPix[i+0], b * alpha/255.0); //checkBounds0to255(memPix[i+0] + b * alpha/255);
            viewPix[i+1] = std::max((double) memPix[i+1], g * alpha/255.0);
            viewPix[i+2] = std::max((double) memPix[i+2], r * alpha/255.0);
        }
    }
    else if (mode == std::string("Screen"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(255.0 - (255.0 - memPix[i+0]) * (255.0 - b * alpha/255.0));
            viewPix[i+1] = checkBounds0to255(255.0 - (255.0 - memPix[i+1]) * (255.0 - g * alpha/255.0));
            viewPix[i+2] = checkBounds0to255(255.0 - (255.0 - memPix[i+2]) * (255.0 - r * alpha/255.0));
        }
    }
    else if (mode == std::string("Color Dodge"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(memPix[i+0] / (255.0 - b * alpha/255.0));
            viewPix[i+1] = checkBounds0to255(memPix[i+1] / (255.0 - g * alpha/255.0));
            viewPix[i+2] = checkBounds0to255(memPix[i+2] / (255.0 - r * alpha/255.0));
        }
    }
    else if (mode == std::string("Linear Dodge"))
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i+0] = checkBounds0to255(memPix[i+0] + b * alpha/255.0);
            viewPix[i+1] = checkBounds0to255(memPix[i+1] + g * alpha/255.0);
            viewPix[i+2] = checkBounds0to255(memPix[i+2] + r * alpha/255.0);
        }
    }
}

void VImage::brightnessContrast(int a, double b, VImage::ImageChannel ch)
{
    if (ch == VImage::channelAll)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
        {
            viewPix[i]   = checkBounds0to255(a + 128 + (memPix[i] - 128) * b);
            viewPix[i+1] = checkBounds0to255(a + 128 + (memPix[i+1] - 128) * b);
            viewPix[i+2] = checkBounds0to255(a + 128 + (memPix[i+2] - 128) * b);
        }
    }
    else if (ch == VImage::channelBlue)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i]   = checkBounds0to255(a + 128 + (memPix[i] - 128) * b);
    }
    else if (ch == VImage::channelGreen)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i+1] = checkBounds0to255(a + 128 + (memPix[i+1] - 128) * b);
    }
    else if (ch == VImage::channelRed)
    {
        for (int i = 0; i < viewPix.size(); i+=4)
            viewPix[i+2] = checkBounds0to255(a + 128 + (memPix[i+2] - 128) * b);
    }
}
