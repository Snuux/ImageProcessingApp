#include "vimagemem.h"

VImageMem::VImageMem()
{

}

VImageMem::VImageMem(const VImage &img)
{
    original = img;

    redoArray.clear();
    undoArray.clear();
    //undoArray.push(img);
}

void VImageMem::setImage(const VImage& img)
{
    original = img;

    redoArray.clear();
    undoArray.clear();
    //undoArray.push(img);
}

void VImageMem::undo(VImage &img)
{
    if (undoArray.size() > 0)
    {
        redoArray.push_back(img);
        img = undoArray.back();
        undoArray.pop_back();
        img.memToView();
    }
    else
    {
        img = original;
        img.memToView();
    }
}

void VImageMem::redo(VImage &img)
{
    if (redoArray.size() > 0)
    {
        undoArray.push_back(img);
        img = redoArray.back();
        redoArray.pop_back();
        img.memToView();
    }
}

VImage VImageMem::reset()
{
    redoArray.clear();
    return original;
}

void VImageMem::apply(VImage &img)
{
    redoArray.clear();
    undoArray.push_back(img);
    img.viewToMem();
}
