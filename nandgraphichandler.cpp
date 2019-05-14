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
    _MGV->ClearTable();
    _MGV->SetWordLine(count);
}

void NandGraphicHandler::SetBitLine(size_t count)
{
    _MGV->ClearTable();
    _MGV->SetBitLine(count);
}

void NandGraphicHandler::SetCellDepth(size_t value)
{
    _MGV->ClearTable();
    _MGV->ChangeCellDepth(value);
}

bool NandGraphicHandler::RecordInfo(string word)
{
    if (word.size() < _MGV->getCounts().first)
        for (size_t i = word.size(); i < _MGV->getCounts().first; i++) word.push_back('0');
    return _MGV->RecordInfo(word);
}

string NandGraphicHandler::ReadInfo(size_t number)
{
    return _MGV->ReadInfo(number);
}

void NandGraphicHandler::Clear()
{
    _MGV->ClearTable();
}
