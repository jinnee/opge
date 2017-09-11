#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include "Button.h"
#include "include/TtfFont.h"
#include "include/UI/UILabel.h"

class TextButton : public Button
{
public:
    TextButton(SDL_Renderer* appRender);
    virtual ~TextButton();
    void render();
    void setText(string);
private:
    TtfFont* font;
    string text;
    UILabel* label;
    SDL_Color textColor;
    SDL_Renderer* appRender;
};

#endif // TEXTBUTTON_H
