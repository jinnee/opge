#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "inc_files.h"

namespace ConvertFunctions
{
    string charToString(char*);
    string intToString(int);
    int doubleToInt(double x);
}

namespace GenerateFunctions
{
    string uuid();
}

namespace SDLFunctions {
    int saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer);
}

#endif // FUNCTIONS_H_INCLUDED
