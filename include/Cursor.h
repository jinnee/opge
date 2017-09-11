#ifndef CURSOR_H
#define CURSOR_H

#include "AnimatedSprite.h"

class Cursor : public AnimatedSprite
{
    public:
        static Cursor* getCursor();
        static void setPath(string& pathCursor);
        virtual ~Cursor();
        void changeCursorFromPath(string pathCursor, SDL_Renderer *renderer);
        void changeCursor(SDL_Texture*, SDL_Rect*);
    private:
        Cursor();
        static Cursor* cursor;
        static string pathCursor;
};

#endif // CURSOR_H
