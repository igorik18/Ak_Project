#ifndef NORGRAPHICHANDLER_H
#define NORGRAPHICHANDLER_H

#include "mygraphicsview.h"

class NorGraphicHandler
{
    MyGraphicsView *_MGV;
    pair <size_t, size_t> _counts;
public:
    NorGraphicHandler(pair <size_t, size_t> counts = make_pair(1, 1));
    void SetWordLine(size_t count);
    void SetBitLine(size_t count);
    MyGraphicsView *MGV() const;
};

#endif // NORGRAPHICHANDLER_H
