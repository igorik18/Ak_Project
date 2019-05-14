#ifndef NANDGRAPHICHANDLER_H
#define NANDGRAPHICHANDLER_H

#include "mygraphicsview.h"

class NandGraphicHandler
{
    MyGraphicsView *_MGV;
    pair <size_t, size_t> _counts;
public:
    NandGraphicHandler(pair <size_t, size_t> counts = make_pair(1, 1));
    void SetWordLine(size_t count);
    void SetBitLine(size_t count);
    void SetCellDepth(size_t value);
    bool RecordInfo(string word);
    string ReadInfo(size_t number);
    void Clear();
    MyGraphicsView *MGV() const;
};

#endif // NANDGRAPHICHANDLER_H
