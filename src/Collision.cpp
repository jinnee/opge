#include "../include/Collision.h"

Collision::Collision()
{

}

int Collision::SDL_CollideTransparentPixel(SDL_Surface *surface , int u , int v)
{
//    if(SDL_MUSTLOCK(surface))SDL_LockSurface(surface);
//    //assert that (u,v) offsets lie within surface
////	assert((u < surface->w) && (v < surface->h));

//    int bpp = surface->format->BytesPerPixel;
//    //here p is the address to the pixel we want to retrieve
//    Uint8 *p = (Uint8 *)surface->pixels + v * surface->pitch + u * bpp;

//    Uint32 pixelcolor;
////cout<<bpp<<endl;

//    switch(bpp)
//    {
//        case(1):
//            pixelcolor = *p;
//        break;

//        case(2):
//            pixelcolor = *(Uint16 *)p;
//        break;

//        case(3):
//            if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
//                pixelcolor = p[0] << 16 | p[1] << 8 | p[2];
//            else
//                pixelcolor = p[0] | p[1] << 8 | p[2] << 16;
//        break;

//        case(4):
//            pixelcolor = *(Uint32 *)p;
//        break;
//    }

////	pixelcolor = *(Uint32 *)p;
////	cout << pixelcolor <<" - "<<surface->format->colorkey<<endl ;


//    if(SDL_MUSTLOCK(surface))SDL_UnlockSurface(surface);
//    //test whether pixels color == color of transparent pixels for that surface
//    return (pixelcolor == surface->format->colorkey);
}

/**
    Колизия между анимирано и анимирано духче, ако в долната
    SimpleSprite, конвентиран към anim, то ще се получи грешка
    при вземането на стойностите от getClip().
    Може да се получава само при tilex = 1 и tiley = 1.
    да се види, защо е така !!!!!!!!!!!!!!!!!!!!!
*/
int Collision::SDL_CollidePixelAA(AnimatedSprite *aas , int ax , int ay ,
                       AnimatedSprite *abs , int bx , int by, int skip )
{
//    SDL_Surface* as = aas->getImage();
//    SDL_Surface* bs = abs->getImage();
//    //указват кои фреймове ще се проверяват за колизия
//    SDL_Rect aclip = aas->getClip();
//    SDL_Rect bclip = abs->getClip();
//    int ax1 = (ax) + as->w/aas->getTileX() - 1;
//    int ay1 = (ay) + as->h/aas->getTileY() - 1;

//    int bx1 = (bx) + bs->w/abs->getTileX() - 1;
//    int by1 = (by) + bs->h/abs->getTileY() - 1;

//    if((bx1 < ax) || (ax1 < bx))
//        return 0;
//    if((by1 < ay) || (ay1 < by))
//        return 0;

//    int xstart = SDL_COLLIDE_MAX(ax,bx);
//    int xend = SDL_COLLIDE_MIN(ax1,bx1);

//    int ystart = SDL_COLLIDE_MAX(ay,by);
//    int yend = SDL_COLLIDE_MIN(ay1,by1);


//    for(int y = ystart ; y <= yend ; y += skip)
//    {
//        for(int x = xstart ; x <= xend ; x += skip)
//        {
//            if(!SDL_CollideTransparentPixel(as , x-ax + aclip.x , y-ay + aclip.y)
//            && !SDL_CollideTransparentPixel(bs , x-bx + bclip.x , y-by + bclip.y))
//                return 1;
//        }
//    }

    return 0;
}

int Collision::SDL_CollidePixelAS(AnimatedSprite *aas , int ax , int ay ,
                       AnimatedSprite *abs , int bx , int by, int skip )
{
//    SDL_Surface* as = aas->getImage();
//    SDL_Surface* bs = abs->getImage();
//    //указват кои фреймове ще се проверяват за колизия
//    SDL_Rect aclip = aas->getClip();
//    int ax1 = (ax) + as->w/aas->getTileX() - 1;
//    int ay1 = (ay) + as->h/aas->getTileY() - 1;

//    int bx1 = (bx) + bs->w - 1;
//    int by1 = (by) + bs->h - 1;

//    if((bx1 < ax) || (ax1 < bx))
//        return 0;
//    if((by1 < ay) || (ay1 < by))
//        return 0;

//    int xstart = SDL_COLLIDE_MAX(ax,bx);
//    int xend = SDL_COLLIDE_MIN(ax1,bx1);

//    int ystart = SDL_COLLIDE_MAX(ay,by);
//    int yend = SDL_COLLIDE_MIN(ay1,by1);


//    for(int y = ystart ; y <= yend ; y += skip)
//    {
//        for(int x = xstart ; x <= xend ; x += skip)
//        {
//            if(!SDL_CollideTransparentPixel(as , x-ax + aclip.x , y-ay + aclip.y)
//            && !SDL_CollideTransparentPixel(bs , x-bx  , y-by ))
//                return 1;
//        }
//    }

    return 0;
}

int Collision::SDL_CollideBoundingBox(SDL_Surface *sa , int ax , int ay , SDL_Surface *sb , int bx , int by)
{
    if(bx + sb->w < ax)	return 0;	//just checking if their
    if(bx > ax + sa->w)	return 0;	//bounding boxes even touch

    if(by + sb->h < ay)	return 0;
    if(by > ay + sa->h)	return 0;

    return 1;				//bounding boxes intersect
}

int Collision::SDL_CollideBoundingBox(SDL_Rect a , SDL_Rect b)
{
    if(b.x + b.w < a.x)	return 0;	//just checking if their
    if(b.x > a.x + a.w)	return 0;	//bounding boxes even touch

    if(b.y + b.h < a.y)	return 0;
    if(b.y > a.y + a.h)	return 0;

    return 1;				//bounding boxes intersect
}

int Collision::SDL_CollideBoundingCircle(int x1 , int y1 , int r1 , int x2 , int y2 , int r2 , int offset)
{
    int xdiff = x2 - x1;	// x plane difference
    int ydiff = y2 - y1;	// y plane difference

    /* distance between the circles centres squared */
    int dcentre_sq = (ydiff*ydiff) + (xdiff*xdiff);

    /* calculate sum of radiuses squared */
    int r_sum_sq = r1 + r2;	// square on seperate line, so
    r_sum_sq *= r_sum_sq;	// dont recompute r1 + r2

    return (dcentre_sq - r_sum_sq <= (offset*offset));
}

int Collision::SDL_CollideBoundingCircle(SDL_Surface *a , int x1 , int y1 , SDL_Surface *b , int x2 , int y2 , int offset)
{
    /* if radius is not specified
    we approximate them using SDL_Surface's
    width and height average and divide by 2*/
    int r1 = (a->w + a->h) / 4;	// same as / 2) / 2;
    int r2 = (b->w + b->h) / 4;

    x1 += a->w / 2;		// offset x and y
    y1 += a->h / 2;		// co-ordinates into
                // centre of image
    x2 += b->w / 2;
    y2 += b->h / 2;

    return SDL_CollideBoundingCircle(x1,y1,r1,x2,y2,r2,offset);
}


Collision::~Collision()
{

}
