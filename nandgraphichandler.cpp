#include "nandgraphichandler.h"

NandGraphicHandler::NandGraphicHandler(pair<size_t, size_t> counts): _counts(counts)
{
    _MGV = new MyGraphicsView(_N_A_N_D_);
    SetBitLine(_counts.first);
    SetWordLine(_counts.second);
}

MyGraphicsView *NandGraphicHandler::MGV() const
{
    return _MGV;
}

void NandGraphicHandler::SetWordLine(size_t count)
{
    _MGV->SetWordLine(count);
}

void NandGraphicHandler::SetBitLine(size_t count)
{
    _MGV->SetBitLine(count);
}

void NandGraphicHandler::SetCellDepth(size_t value)
{
    _MGV->ChangeCellDepth(value);
}
