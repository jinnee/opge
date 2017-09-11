#include "include/UI/Button.h"

Button::Button(): StaticSprite() {
    name = "BUTTON";
    type = Constants::SpriteTypes::UI_BUTTON;
    setX(0);
    setY(0);
    this->setTilesXY(1,2);
}

Button::~Button() {
    SpriteManager::deleteSprite(this->name);
}

void Button::render() {
    SDL_Rect* src = new SDL_Rect();
    if ( this->isCursorInSprite() ) {
        SpriteManager::mouseEventFrom = this->getName();
        src->x = 0;
        src->y = this->h/2;
        src->w = this->w;
        src->h = this->h/2;
    } else {
        src->x = 0;
        src->y = 0;
        src->w = this->w;
        src->h = this->h / 2;
    }

    setClip(src);
    StaticSprite::render();
    delete src;
    src = 0;
}

