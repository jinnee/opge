
#include "../include/BmpFont.h"

BmpFont::BmpFont(): ImageInstruments(){
    tilesX = 1;
    tilesY = 1;
    width = 0;
    height = 0;
    stringFont = L" ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюя";
    fontLength = stringFont.length();

    for ( int i = 0; i < fontLength; ++i )
    {
        fontMap.insert( make_pair( stringFont[i], i ) );
    }
}

void BmpFont::setStringFont(wstring stringFont) {
    this->stringFont = stringFont;
    fontLength = stringFont.length();
    fontMap.clear();

    for ( int i = 0; i < fontLength; ++i )
    {
        fontMap.insert( make_pair( stringFont[i], i ) );
    }
}

/**
* Изпълнява се след зареждането на картинката!
*/
void BmpFont::initFont(int tilesX, int tilesY)
{
    this->width = w / tilesX;
    this->height = h / tilesY;
}

int BmpFont::getFontLength()
{
    return this->fontLength;
}

map<int, int> BmpFont::getFontMap()
{
    return this->fontMap;
}

int BmpFont::getWidth()
{
    return this->width;
}

int BmpFont::getHeight()
{
    return this->height;
}

BmpFont::~BmpFont(){
    //dtor
}

