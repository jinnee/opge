#include "../include/Functions.h"

namespace ConvertFunctions
{
    /**
        Конвертира char към string
        Ако искаме да конвертираме char:
        char ch = 'd';
        charToString(&ch);
    */
    string charToString(char* ch)
    {
        stringstream stringStream;
        string result;
        stringStream << ch;
        stringStream >> result;
        return result;
    }

    string intToString(int i) // convert int to string
    {
        stringstream s;
        s << i;
        return s.str();
    }

    int doubleToInt(double x)
    {
       double dx = x < 0.0 ? -0.5 : 0.5;
       return static_cast<int>(x + dx);
    }


    //    std::wstring wide( L"Wide" );
    //    std::string str( wide.begin(), wide.end() );

    //    // Will print no problemo!
    //    std::cout << str << std::endl;

//    wstring s2ws(const std::string& str)
//    {
//        typedef std::codecvt_utf8<wchar_t> convert_typeX;
//        std::wstring_convert<convert_typeX, wchar_t> converterX;

//        return converterX.from_bytes(str);
//    }

//    string ws2s(const std::wstring& wstr)
//    {
//        typedef std::codecvt_utf8<wchar_t> convert_typeX;
//        std::wstring_convert<convert_typeX, wchar_t> converterX;

//        return converterX.to_bytes(wstr);
//    }
}

namespace GenerateFunctions {
    string uuid()
    {
        string result;
        srand(time(NULL));
        // https://stackoverflow.com/questions/2174768/generating-random-uuids-in-linux
        std::ostringstream stringStream;
        stringStream << rand() << rand() << "-";
        stringStream << rand() << "-";
        stringStream << ((rand() & 0x0fff) | 0x4000) << "-";
        stringStream << rand() % 0x3fff + 0x8000 << "-";
        stringStream << rand() << rand() << rand();
        return stringStream.str();

    }
}

namespace SDLFunctions {

    int saveScreenshotBMP(std::string filepath, SDL_Window* SDLWindow, SDL_Renderer* SDLRenderer) {
        SDL_Surface* saveSurface = NULL;
        SDL_Surface* infoSurface = NULL;
        infoSurface = SDL_GetWindowSurface(SDLWindow);
        if (infoSurface == NULL) {
            std::cerr << "Failed to create info surface from window in saveScreenshotBMP(string), SDL_GetError() - " << SDL_GetError() << "\n";
        } else {
            unsigned char * pixels = new (std::nothrow) unsigned char[infoSurface->w * infoSurface->h * infoSurface->format->BytesPerPixel];
            if (pixels == 0) {
                std::cerr << "Unable to allocate memory for screenshot pixel data buffer!\n";
                return 0;
            } else {
                if (SDL_RenderReadPixels(SDLRenderer, &infoSurface->clip_rect, infoSurface->format->format, pixels, infoSurface->w * infoSurface->format->BytesPerPixel) != 0) {
                    std::cerr << "Failed to read pixel data from SDL_Renderer object. SDL_GetError() - " << SDL_GetError() << "\n";
                    pixels = NULL;
                    return 0;
                } else {
                    saveSurface = SDL_CreateRGBSurfaceFrom(pixels, infoSurface->w, infoSurface->h, infoSurface->format->BitsPerPixel, infoSurface->w * infoSurface->format->BytesPerPixel, infoSurface->format->Rmask, infoSurface->format->Gmask, infoSurface->format->Bmask, infoSurface->format->Amask);
                    if (saveSurface == NULL) {
                        std::cerr << "Couldn't create SDL_Surface from renderer pixel data. SDL_GetError() - " << SDL_GetError() << "\n";
                        return 0;
                    }
                    SDL_SaveBMP(saveSurface, filepath.c_str());
                    SDL_FreeSurface(saveSurface);
                    saveSurface = NULL;
                }
                delete[] pixels;
            }
            SDL_FreeSurface(infoSurface);
            infoSurface = NULL;
        }
        return 1;
    }
}
