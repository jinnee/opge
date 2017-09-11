#include "../include/Cursor.h"

void Cursor::changeCursorFromPath(string pathCursor, SDL_Renderer *renderer) {
    if (this->image != NULL) {
        SDL_DestroyTexture( this->image );
    }
    Cursor::pathCursor = pathCursor;
    setImage(pathCursor, renderer);
}

void Cursor::changeCursor(SDL_Texture* texture, SDL_Rect* clip) {
    if (this->image != NULL) {
        SDL_DestroyTexture( this->image );
    }
    this->w = clip->w;
    this->h = clip->h;
    setImage(texture);
}

Cursor* Cursor::getCursor() {
    if (cursor == 0) {
        return cursor = new Cursor();
    }
    return cursor;
}

Cursor::Cursor(): AnimatedSprite() {
    SDL_ShowCursor(0);
    tag = Constants::SpriteModal;
    type = Constants::SpriteTypes::MOUSE_CURSOR;
    name = "MouseCursor";

    setX(0);
    setY(0);
}

void Cursor::setPath(string &pathCursor) {
    Cursor::pathCursor = pathCursor;
}

Cursor::~Cursor() {
}

Cursor* Cursor::cursor = 0;
string Cursor::pathCursor = "";
