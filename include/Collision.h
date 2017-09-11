#ifndef COLLISION
#define COLLISION
#include "AnimatedSprite.h"

#define SDL_COLLIDE_MAX(a,b)	((a > b) ? a : b)
#define SDL_COLLIDE_MIN(a,b)	((a < b) ? a : b)

class Collision
{
    public:
        Collision();
        ~Collision();
        //колизия на анимиранo и анимиранo духче
        static int SDL_CollidePixelAA(AnimatedSprite *as , int ax , int ay , AnimatedSprite *bs , int bx , int by, int skip=4);
        //колизия на анимиранo и статично духче
        static int SDL_CollidePixelAS(AnimatedSprite *as , int ax , int ay , AnimatedSprite *bs , int bx , int by, int skip=4);
        static int SDL_CollideTransparentPixel(SDL_Surface *surface , int u , int v);

        static int SDL_CollideBoundingBox(SDL_Surface *sa , int ax , int ay , SDL_Surface *sb , int bx , int by);
        static int SDL_CollideBoundingBox(SDL_Rect a , SDL_Rect b);
        static int SDL_CollideBoundingCircle(int x1 , int y1 , int r1 , int x2 , int y2 , int r2 , int offset);
        static int SDL_CollideBoundingCircle(SDL_Surface *a , int x1 , int y1 , SDL_Surface *b , int x2 , int y2 , int offset);
    protected:
    private:
};

#endif // COLLISION

