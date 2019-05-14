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
    _MGV->ClearTable();
    _MGV->SetWordLine(count);
}

void NorGraphicHandler::SetBitLine(size_t count)
{
    _MGV->ClearTable();
    _MGV->SetBitLine(count);
}

bool NorGraphicHandler::RecordInfo(string word)
{
    if (word.size() < _MGV->getCounts().first)
        for (size_t i = word.size(); i < _MGV->getCounts().first; i++) word.push_back('0');
    return _MGV->RecordInfo(word);
}

string NorGraphicHandler::ReadInfo(size_t number)
{
    return _MGV->ReadInfo(number);
}

void NorGraphicHandler::Clear()
{
    _MGV->ClearTable();
}
