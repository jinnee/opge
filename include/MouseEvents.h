#ifndef MOUSEEVENTS_H
#define MOUSEEVENTS_H
#include "AbstractSprite.h"

class MouseEvents
{
    public:
        virtual void onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as) = 0;

};

#endif // MOUSEEVENTS_H
