#include "../include/Background.h"

Background::Background() : StaticSprite()
{
    type = Constants::SpriteTypes::BACKGROUND;
    name = "background";
    setX(0);
    setY(0);
}

void Background::render() {
    SpriteManager::mouseEventFrom = this->getName();
    StaticSprite::render();
}

Background::~Background()
{
    //dtor
}

