#ifndef NUMBERS_H
#define NUMBERS_H

#include <algorithm>
#include "include/AnimatedSprite.h"
#include "include/MouseEvents.h"

class Numbers : public MouseEvents
{
public:
    Numbers(SDL_Renderer* appRender);
    ~Numbers();
    void render();
    void restartGame();
    void newGame();
    void setRenderer(SDL_Renderer* appRender);
    void onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as);
    vector<AnimatedSprite*> vectorOfTiles;
private:
    SDL_Renderer* appRender;
    enum DIRECTIONS {
        LEFT = 1, RIGHT, TOP, BOTTOM
    } mDirections;

    int tilePosX;
    int tilePosY;
    int tileWidth;
    int tileHeight;
    int* currentPositionOfNumbers;
    int initialPosition[16];
    int targetPosition[16];

    AnimatedSprite* emptyTile;
    AnimatedSprite* tile;


    int* getValidNumbersPosition();
    int moveDecision(int);
    void clear();
    void initVectorOfTiles(bool);
    bool isFinish(int*);
};

#endif // NUMBERS_H
