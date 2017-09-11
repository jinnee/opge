#ifndef BUTTON_H
#define BUTTON_H
#include "../StaticSprite.h"
#include "../SpriteManager.h"

class Button : public StaticSprite
{
    public:
        Button();
        virtual ~Button();
        void render();
};

#endif // BUTTON_H
