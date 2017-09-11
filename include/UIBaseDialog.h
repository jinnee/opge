#ifndef UIBASEDIALOG
#define UIBASEDIALOG

#include "StaticSprite.h"
#include "TtfFont.h"
#include "UI/Button.h"
#include "UI/UILabel.h"
#include "ObjectToImageMapping.h"

class UIBaseDialog : public StaticSprite {
public:
    void setFontName(string fontName);
    void setShow(bool show);
    bool getShow();
    Message getResult();
    void initResult();
    void render();
    void setTitle(string title);
    void setWindowWidthHeight(int,int);
    void setPosition(Constants::BaseDialogPositions);
    void setRenderer(SDL_Renderer *renderer);
    void setSpriteSheet(ObjectToImageMapping* spriteSheet);

    void init();

    UIBaseDialog();
    ~UIBaseDialog();
protected:
    string fontName;
    string title;
    UILabel* labelTitle;
    Message result;
    TtfFont* ttfFont;
    ObjectToImageMapping* spriteSheet;
    bool show;
    int windowWidth;
    int windowHeight;
};
#endif // UIBASEDIALOG

