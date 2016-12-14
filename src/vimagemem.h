#ifndef VIMAGEMEM_H
#define VIMAGEMEM_H

#include <vector>
#include <deque>
#include <string>

#include "vimage.h"

class VImageMem
{
public:
    VImage original;

    std::deque<VImage> undoArray;
    std::deque<VImage> redoArray;

public:
    VImageMem();
    VImageMem(const VImage &img);
    void setImage(const VImage& img);

    void undo(VImage &img); //<-
    void redo(VImage &img); //->
    VImage reset();

    void apply(VImage& img);
};

#endif // VIMAGEMEM_H
