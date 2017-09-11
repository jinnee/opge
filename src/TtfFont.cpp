#include "include/TtfFont.h"

TtfFont::TtfFont(){
    font = NULL;
    path = "";
    size = 64;
}

bool TtfFont::loadFont() {
    bool result = true;

    font = TTF_OpenFont( path.c_str(), size );
    if( font == NULL ) {
        result = false;
    }
    return result;
}

TTF_Font* TtfFont::getFont(){
    return this->font;
}

void TtfFont::setPath(string path){
    this->path = path;
}

void TtfFont::setSize(int size) {
    this->size = size;
}

//TTF_STYLE_BOLD|TTF_STYLE_ITALIC
void TtfFont::setStyle(int style) {
    if (font) {
        TTF_SetFontStyle(font, style);
    }
}

int TtfFont::getSize() {
    return this->size;
}

void TtfFont::close(){
    if (font) {
        TTF_CloseFont( font );
        font = NULL;
    }
}

TtfFont::~TtfFont(){
    this->close();
}
