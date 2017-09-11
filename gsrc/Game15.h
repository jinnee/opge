#ifndef GAME15_H
#define GAME15_H

#include "../include/SpriteManager.h"
#include "../include/AbstractGame.h"
#include "../include/AnimatedSprite.h"
#include "include/UI/Button.h"
#include "../include/Background.h"
#include "GameState.h"
#include "Numbers.h"

class Game15 : public AbstractGame, public MouseEvents {
public:
    Game15();

    void init();
    void render();
    void update(double deltaTime);
    void freeResources();

    void setRenderer(SDL_Renderer* appRender);
    virtual ~Game15();
    void onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as);
private:
    Button* btnToMainMenu;
    Button* btnNewGame;
    Button* btnRestartGame;
    Background* mBackground;
    SDL_Surface* screen;
    SDL_Renderer* appRender;
    int buttonsTopMenu;
    int buttonsLeftMargin;
    int buttonsHeight;
    int buttonsDistance;
    Numbers* mNumbers;
    //Nums* mNums;
    AnimatedSprite* gold;
    AnimatedSprite* gold1;
};


#endif // GAME15_H
