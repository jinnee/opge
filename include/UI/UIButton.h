#ifndef UIBUTTON
#define UIBUTTON

#include "../StaticSprite.h"
#include "../TtfFont.h"
#include "../UI/UILabel.h"

class UIButton : public StaticSprite {
public:
    void render();
    void init();
    void setAreaWorld(SDL_Rect*);
    UIButton();
    ~UIButton();
private:
    SDL_Rect* areaWorld;
};

#endif // UIBUTTON

