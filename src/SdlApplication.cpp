#include "../include/SdlApplication.h"
#include <iostream>

SdlApplication::SdlApplication() {
    this->title = "Application";
    this->width = 640;
    this->height = 480;
    this->appWindow = NULL;
    this->render = NULL;
    this->imageFlags = IMG_INIT_PNG;
}

void SdlApplication::setIcon(string iconPath){
    SDL_Surface* iconSurface = IMG_Load(iconPath.c_str());

    if (iconSurface == NULL) {
        printf("Unable to load image %s! SDL_image Error: %s\n", iconPath.c_str(), IMG_GetError());
    } else {
        SDL_SetWindowIcon(appWindow, iconSurface);
        SDL_FreeSurface(iconSurface);
    }
}

SdlApplication::~SdlApplication() {
}

bool SdlApplication::init() {
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) {
        return false;
    } else {
        if (!(IMG_Init(imageFlags) & imageFlags)) {
            return false;
        }
        //Initialize SDL_mixer
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            return false;
        }
        if( TTF_Init() == -1 )
        {
            printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
            return false;
        }
        return true;
    }
}

void SdlApplication::create() {
    //Установяване на видео режима
    this->appWindow = SDL_CreateWindow(this->title // заглавие на прозореца
            // x координата на прозореца.
            // Освен SDL_WINDOWPOS_UNDEFINED може да се използва конкратно число или SDL_WINDOWPOS_CENTERED
            , SDL_WINDOWPOS_UNDEFINED
            // y координата на прозореца.
            , SDL_WINDOWPOS_UNDEFINED
            , this->width // ширина на екрана
            , this->height // височина на екрана
            // флагове определящи характеристики на прозореца
            // пълният списък може да се види тук https://wiki.libsdl.org/SDL_CreateWindow#flags
            , SDL_WINDOW_SHOWN
            );

}

SDL_Renderer* SdlApplication::getRender(){
    render = SDL_CreateRenderer(this->appWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

    if (this->render == NULL) {
        render = SDL_GetRenderer(this->appWindow);
        return render;
    }

    SDL_SetRenderDrawColor( render, 0x00, 0x00, 0x00, 0x00 );
    return render;
}

void SdlApplication::close() {
    cout << "app close" << endl;
    SDL_DestroyRenderer(this->render);
    SDL_DestroyWindow(this->appWindow);
    this->appWindow = NULL;
    this->render = NULL;
    Mix_CloseAudio();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void SdlApplication::setTitle(char* title) {
    this->title = title;
    SDL_SetWindowTitle(this->appWindow, title);

}

void SdlApplication::setWindowSize(int w, int h) {
    this->width = w;
    this->height = h;
    SDL_SetWindowSize(this->appWindow, w, h);
}

SDL_PixelFormat* SdlApplication::getPixelFormat() {
    return SDL_GetWindowSurface(this->appWindow)->format;
}

SDL_Window* SdlApplication::getWindow() {
    return this->appWindow;
}
