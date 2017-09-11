#ifndef SDLAPPLICATION_H
#define	SDLAPPLICATION_H

#include "include/inc_files.h"

class SdlApplication
{
public:
    SdlApplication();
    bool init();
    void create();
    SDL_Renderer *getRender();
    void close();
    
    void setTitle(char*);
    void setWindowSize(int,int);
    char* getTitle();
    void setIcon(string);
    SDL_PixelFormat* getPixelFormat();
    SDL_Window* getWindow();
    virtual ~SdlApplication();
    int getWidth() {return width;}
    int getHeight() {return height;}
private:
    SDL_Window* appWindow;
    char* title;
    int imageFlags;
    int width;
    int height;
    SDL_Renderer *render;
};

#endif	/* SDLAPPLICATION_H */
