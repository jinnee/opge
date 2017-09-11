#include "../include/ImageInstruments.h"

ImageInstruments::ImageInstruments() {
    image = NULL;
    spriteSheet = NULL;
    blendMode = SDL_BLENDMODE_BLEND;
    alpha = 255;
    w = 0;
    h = 0;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
    rmask = 0xff000000;
    gmask = 0x00ff0000;
    bmask = 0x0000ff00;
    amask = 0x000000ff;
#else
    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
#endif

}

void ImageInstruments::setImage(string filename, SDL_Renderer *renderer) {
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    this->renderer = renderer;
    if (loadedSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
        exit(1);
    } else {
        if( image != NULL ) {
            SDL_DestroyTexture( image );
            image = NULL;
        }
        image = SDL_CreateTextureFromSurface( renderer, loadedSurface );
        w = loadedSurface->w;
        h = loadedSurface->h;
        SDL_SetTextureBlendMode( image, blendMode );
        SDL_SetTextureAlphaMod( image, alpha);

        SDL_FreeSurface(loadedSurface);

        if (image == NULL) {
            printf("Unable to optimize image %s! SDL Error: %s\n", filename.c_str(), SDL_GetError());
            exit(1);
        }
    }
}

void ImageInstruments::setImage(SDL_Texture* image, SDL_Rect* clip) {
    if (clip != NULL) {
        this->w = clip->w;
        this->h = clip->h;
    }
    if( this->image != NULL ) {
        SDL_DestroyTexture( this->image );
        this->image = NULL;
    }
    this->image = image;
}

SDL_Surface* ImageInstruments::loadSpriteSheet(string filename){
    spriteSheet = IMG_Load(filename.c_str());

    if (spriteSheet == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", filename.c_str(), IMG_GetError());
        exit(1);
    }

    return spriteSheet;
}

SDL_Texture* ImageInstruments::getSpriteFromSpriteSheet(SDL_Rect* rr){
    SDL_Surface* txtSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, rr->w, rr->h, 32,
                                   rmask, gmask, bmask, amask);
    if(txtSurface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        exit(1);
    }

    SDL_Rect src = {rr->x, rr->y, rr->w, rr->h}; // x, y, width, height
    SDL_BlitSurface(spriteSheet, &src, txtSurface, NULL);

    image = SDL_CreateTextureFromSurface( renderer, txtSurface );
    SDL_SetTextureBlendMode( image, blendMode );
    SDL_SetTextureAlphaMod( image, alpha);

    SDL_FreeSurface(txtSurface);

    return image;
}

void ImageInstruments::setSpriteSheet(SDL_Surface* spriteSheet) {
    this->spriteSheet = spriteSheet;
}

void ImageInstruments::setAlpha(int alpha) {
    SDL_SetTextureAlphaMod( image, alpha);
    this->alpha = alpha;
}

SDL_Texture* ImageInstruments::getImage() {
    return image;
}

ImageInstruments::~ImageInstruments() {
    if(spriteSheet){
        SDL_FreeSurface(spriteSheet);
    }
    if( image != NULL ) {
        SDL_DestroyTexture( image );
        image = NULL;
    }
    //cout << "desctructor ImageInstruments:" << endl;
}

SDL_PixelFormat* ImageInstruments::pixFormat = NULL;
