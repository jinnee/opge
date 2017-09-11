#include "../include/StaticSprite.h"

StaticSprite::StaticSprite() : AbstractSprite()
{
    x_mouse = 0;
    y_mouse = 0;
    tilesX = 1;
    tilesY = 1;
    name = "StaticSprite";
    type = Constants::SpriteTypes::STATIC_SPRITE;
    isKeyRel = false;
    cursorInSprite = false;
    typeKey = "";
    skipMouseEventFrom = false;
}

StaticSprite::~StaticSprite() {
    SpriteManager::deleteSprite(this->name);
    SDL_DestroyTexture( this->image );
    this->image  = NULL;
}

bool StaticSprite::isMouseButtonDown(string type) {

    if (Messages::messageExistsAndRemove(type, this->name, cursorInSprite)) {
        return true;
    }

    return false;
}

void StaticSprite::render() {
//    if (this->skipMouseEventFrom)
//        cout << "TRUUUUUUUUU:" << this->getName() << endl;

    if ( this->isCursorInSprite() && !this->skipMouseEventFrom) {
        if(this->getName() != "background" )
            cout << this->getName() << endl;
        SpriteManager::mouseEventFrom = this->getName();
    } else {
//        SpriteManager::mouseEventFrom = "";
    }
    AbstractSprite::render();
}

bool StaticSprite::isMouseButtonUp(string type) {

    if (Messages::messageExistsAndRemove(type, this->name, cursorInSprite)) {
        return true;
    }

    return false;
}

bool StaticSprite::isMouseButtonClick(string type) {
//    if (Messages::messageExists(type, this->name, cursorInSprite)) {
//        if (Messages::messageExistsAndRemove(type, this->name, cursorInSprite)) {
//            return true;
//        }
//    }

    return false;
}

//позиция на мишката върху спрайта
void StaticSprite::setMousePosX(int x) {
    if ( this->w/this->tilesX + this->position.x > x && x >  this->position.x) {
        this->x_mouse = x;
    }
}

Sint16 StaticSprite::getMousePosX() {
    if ( this->w/this->tilesX + this->position.x > x_mouse && x_mouse >  this->position.x ) {
        return this->x_mouse;
    }
    return -1;
}

//позиция на мишката върху спрайта
void StaticSprite::setMousePosY(int y) {
    if ( this->h/this->tilesY + this->position.y > y && y >  this->position.y) {
        this->y_mouse = y;
    }
}

Sint16 StaticSprite::getMousePosY() {
    if ( this->h/this->tilesY + this->position.y > y_mouse && y_mouse >  this->position.y) {
        return this->y_mouse;
    }
    return -1;
}

void StaticSprite::setMousePosXY(int x, int y) {
    if (this->scaleCoefficient == 1) {
        //cout << name << ": " << w << " - " << h << endl;
        if (
                this->w /this->tilesX + this->position.x > x
                && x >  this->position.x
                && this->h/this->tilesY + this->position.y > y
                && y >  this->position.y) {
            x_mouse = x;
            y_mouse = y;
            this->cursorInSprite = true;
        } else {
            this->cursorInSprite = false;
        }
    } else {
        if (
                (this->w * this->scaleCoefficient)/this->tilesX + this->position.x > x
                && x >  this->position.x
                && (this->h * this->scaleCoefficient)/this->tilesY + this->position.y > y
                && y >  this->position.y) {
            x_mouse = x;
            y_mouse = y;
            this->cursorInSprite = true;
        } else {
            this->cursorInSprite = false;
        }
    }
}

bool StaticSprite::isCursorInSprite() {
    return this->cursorInSprite;
}

void StaticSprite::setTilesXY(int tilesX, int tilesY) {
    this->tilesX = tilesX;
    this->tilesY = tilesY;
}

int StaticSprite::getTileX() {
    return this->tilesX;
}

int StaticSprite::getTileY() {
    return this->tilesY;
}

bool StaticSprite::isKeyReleased(){
    return this->isKeyRel;
}

void StaticSprite::setKeyReleased(bool isKeyReleased){
    this->isKeyRel = isKeyReleased;
}
void StaticSprite::setTypeKeyReleased(string type){
    typeKey = type;
}

string StaticSprite::getTypeKeyReleased(){
    return this->typeKey;
}

SDL_Rect StaticSprite::GetBounds() {
	SDL_Rect bounds;
	bounds.x = (Sint16)(position.x - oldPosition.x);
	bounds.y = (Sint16)(position.x - oldPosition.x);
	bounds.w = (Sint16)(tileWidth);
	bounds.h = (Sint16)(tileHeight);

	return bounds;
}
