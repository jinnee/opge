#ifndef TTFFONT
#define TTFFONT

#include <string>
#include <SDL2/SDL_ttf.h>

using namespace std;

class TtfFont {
public:
    bool loadFont();
    void setSize(int size);
    void setStyle(int style);
    int getSize();
    void setPath(string path);
    TTF_Font* getFont();
    void close();
    ~TtfFont();
    TtfFont();
private:
    int size;
    string path;
    TTF_Font *font;
};

#endif // TTFFONT

