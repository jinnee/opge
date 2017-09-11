#include "include/UI/UIButton.h"

UIButton::UIButton(){
    areaWorld = new SDL_Rect();
    name = "UI_BUTTONX";
    type = Constants::SpriteTypes::UI_BUTTONX;
    this->setTilesXY(1,2);
}

void UIButton::init() {

}

void UIButton::render(){
    SDL_Rect* src = new SDL_Rect();

    if ( this->isCursorInSprite() ) {
        src->h = areaWorld->h / 2;
        src->w = areaWorld->w;
        src->x = areaWorld->x;
        src->y = areaWorld->y + areaWorld->h / 2;
    } else {
        src->h = areaWorld->h / 2;
        src->w = areaWorld->w;
        src->x = areaWorld->x;
        src->y = areaWorld->y;
    }
    setClip(src);
    StaticSprite::render();

    delete src;
    src = 0;
}

void UIButton::setAreaWorld(SDL_Rect* areaWorld){
    w = areaWorld->w;
    h = areaWorld->h;
    this->areaWorld = areaWorld;
}

UIButton::~UIButton(){
    delete areaWorld;
    areaWorld = 0;
}
