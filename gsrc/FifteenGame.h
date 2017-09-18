#ifndef FIFTEENGAME_H
#define FIFTEENGAME_H

#include "include/Game.h"
#include "include/GameSettings.h"
#include "include/Cursor.h"
#include "include/UI/Button.h"
#include "include/UI/TextButton.h"
#include "include/UI/UIMessageBox.h"
#include "Game15.h"
#include "GameState.h"

class FifteenGame : public Game, public MouseEvents
{
public:
    FifteenGame();
    ~FifteenGame();
    void init();
    void update(double deltaTime);
    void render();
    void freeResources();
    void onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as);
    void onKeyDown(Sint16 key);
    void onKeyUp(Sint16 key);
private:
    GameSettings* gameSettings;
    Background* background;
    Cursor* cursor;
    UILabel* title;
    TtfFont* ttff;
    TtfFont* mainMenuFont;
    AnimatedSprite* goldenBird;

    TextButton* btnGoGame;
    TextButton* btnAboutGame;
    TextButton* btnExitGame;
    Game15* mGame15;
};

#endif // FIFTEENGAME_H
