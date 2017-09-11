#ifndef UIMESSAGEBOX
#define UIMESSAGEBOX

#include "../StaticSprite.h"
#include "../TtfFont.h"
#include "Button.h"
#include "UILabel.h"
#include "../Cursor.h"

class UIMessageBox : public StaticSprite {
public:
    void open();
    int close();
    void setFontName(string fontName);
    void setTextLines(string text1, string text2);
    void setCornersImage(string corners);
    void setShow(bool show);
    void initResult();
    bool getShow();
    void setImageAndClipForButtons(int, SDL_Texture*, SDL_Rect*);
    Message getResult();
    void init();
    void render();
    void setRenderer(SDL_Renderer *renderer);

    UIMessageBox();
    ~UIMessageBox();
private:
    string fontName;
    string text1;
    string text2;
    Message result;
    UILabel* label1;
    UILabel* label2;
    TtfFont* ttfFont;
    Button* button1;
    Button* button2;
    bool show;
    int buttonDistanceFromWall;
    Cursor* cursor;
};

#endif // UIMESSAGEBOX

