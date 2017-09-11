#include "include/UI/UILabel.h"

UILabel::UILabel(){
    textColor = { 220, 110, 70 };
    text = "The quick brown fox jumps over the lazy dog";
    type = Constants::SpriteTypes::UI_LABEL;
}

void UILabel::setFont(TtfFont *font) {
    this->font = font;
    SDL_Surface* textSurface = TTF_RenderUTF8_Solid( font->getFont(), text.c_str(), textColor );
    if( textSurface == NULL ) {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else {
        image = SDL_CreateTextureFromSurface( renderer, textSurface );
        if( image == NULL ) {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        } else {
            this->w = textSurface->w;
            this->h = textSurface->h;
        }
        SDL_FreeSurface( textSurface );
    }

}

TtfFont* UILabel::getFont() {
    return this->font;
}

void UILabel::setText(string text){
    this->text = text;
}

void UILabel::setTextColor(SDL_Color textColor){
    this->textColor = textColor;
}

UILabel::~UILabel(){

}
