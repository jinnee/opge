
#include "../include/LineText.h"

LineText::LineText(): StaticSprite(){
    name = Constants::SpriteTypes::LINE_TEXT;
    type = Constants::SpriteTypes::LINE_TEXT;
    text = L"Line text";
    width = 0;
    height = 0;
    numberOfLetters = 0;
    this->setX(0);
    this->setY(0);
}

void LineText::setText(wstring text) {
    this->text = text;
    numberOfLetters = text.length();
    textLength = (this->text).length();
}

void LineText::setFont(BmpFont* bf) {
    this->bmpFont = bf;
    this->image = bf->getImage();
    this->width = bf->getWidth();
    this->height = bf->getHeight();
    ImageInstruments::w = bf->getWidth();
    ImageInstruments::h = bf->getHeight();
    programFontMap = bmpFont->getFontMap();
}

LineText::~LineText() {
    //dtor
}

void LineText::render() {
    SDL_Rect* src = new SDL_Rect();;

    for (unsigned int i = 0; i < textLength; ++i)
    {
        src->x = (programFontMap[this->text[i]]) * this->width;
        src->y = 0;
        src->w = this->width;
        src->h = this->height;
        setClip(src);
        position.x = oldPosition.x + i * this->width;
        StaticSprite::render();
    }
}

int LineText::getHeight() {
    return bmpFont->getHeight();
}

int LineText::getWidth() {
    return bmpFont->getWidth() * numberOfLetters;
}
