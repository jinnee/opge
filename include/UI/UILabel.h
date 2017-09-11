#ifndef UILABEL
#define UILABEL

#include "../StaticSprite.h"
#include "../TtfFont.h"

class UILabel : public StaticSprite {
public:
    void setTextColor(SDL_Color textColor);
    void setFont(TtfFont *font);
    TtfFont* getFont();
    void setText(string text);
    UILabel();
    ~UILabel();
private:
    TtfFont* font;
    string text;
    SDL_Color textColor;
};

#endif // UILABEL

