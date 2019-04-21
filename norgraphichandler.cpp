#include "norgraphichandler.h"

MyGraphicsView *NorGraphicHandler::MGV() const
{
    return _MGV;
}

NorGraphicHandler::NorGraphicHandler(pair<size_t, size_t> counts): _counts(counts)
{
    _MGV = new MyGraphicsView(_N_O_R_);
    SetBitLine(_counts.first);
    SetWordLine(_counts.second);
}

void NorGraphicHandler::SetWordLine(size_t count)
{
    _MGV->SetWordLine(count);
}

void NorGraphicHandler::SetBitLine(size_t count)
{
    _MGV->SetBitLine(count);
}
