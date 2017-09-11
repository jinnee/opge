#ifndef OBJECTTOIMAGEMAPPING
#define OBJECTTOIMAGEMAPPING

#include "include/inc_files.h"
#include "include/StaticSprite.h"

class ObjectToImageMapping :public StaticSprite {
public:
    virtual SDL_Rect* getRectForObject (string object) = 0;
};


#endif // OBJECTTOIMAGEMAPPING

