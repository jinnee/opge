#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include "Button.h"
#include "include/TtfFont.h"
#include "include/UI/UILabel.h"
#include "include/Cursor.h"

class TextButton : public Button
{
public:
    TextButton(SDL_Renderer* appRender);
    virtual ~TextButton();
    void render();
    void setText(string, int xoff = 0, int yoff = 0);
    void setFont(TtfFont *font);
    void setTextColor(SDL_Color textColor);
private:
    TtfFont* font;
    string text;
    UILabel* label;
    SDL_Color textColor;
    SDL_Renderer* appRender;
    bool cursor_flag;
};

#endif // TEXTBUTTON_H
