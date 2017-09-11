#ifndef IMAGENSTRUMENTS_H
#define IMAGENSTRUMENTS_H

#include "include/inc_files.h"
#include "Functions.h"

class ImageInstruments {
public:
    ImageInstruments();
    virtual ~ImageInstruments();
    SDL_Texture* getImage();
    void setImage(string, SDL_Renderer *renderer);
    void setImage(SDL_Texture*, SDL_Rect* clip = NULL);
    int w;
    int h;
    void setBlendMode(SDL_BlendMode blendMode);
    void setAlpha(int alpha);
    void setRenderer(SDL_Renderer *renderer) {this->renderer = renderer; }
    SDL_Surface* loadSpriteSheet(string filename);
    void setSpriteSheet(SDL_Surface*);
    SDL_Texture* getSpriteFromSpriteSheet(SDL_Rect* rr);
    static void setPixelFormat(SDL_PixelFormat* pixelFormat) {
        pixFormat = pixelFormat;
    }
protected:
    SDL_Texture* image;
    SDL_Renderer* renderer;
    int alpha;
    SDL_BlendMode blendMode;
private:
    static SDL_PixelFormat* pixFormat;
    SDL_Surface* spriteSheet;
    Uint32 rmask, gmask, bmask, amask;
};

#endif // IMAGENSTRUMENTS_H
