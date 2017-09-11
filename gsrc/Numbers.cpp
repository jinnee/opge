#include "Numbers.h"

Numbers::Numbers(SDL_Renderer* appRender)
{
    tilePosX = 30;
    tilePosY = 30;
    tileWidth = 80;
    tileHeight = 80;

    for (int i = 0; i < 16; i++) {
        initialPosition[i] = 0;
        targetPosition[i] = i+1;
    }

    targetPosition[15] = 0;
    this->appRender = appRender;
    initVectorOfTiles(false);

}

void Numbers::setRenderer(SDL_Renderer* appRender){
    this->appRender = appRender;
}

void Numbers::render() {
    if (vectorOfTiles.size() > 0) {
        for (int m = 0; m < 16; m++) {
            if (vectorOfTiles[m]->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
                switch (moveDecision(m)) {
                case LEFT:
                    vectorOfTiles[m]->setX(vectorOfTiles[m]->getX() - tileWidth);
                    //vectorOfTiles[m]->setMouseButtonDown(false);
                    swap(vectorOfTiles[m], vectorOfTiles[m-1]);
                    break;
                case TOP:
                    vectorOfTiles[m]->setY(vectorOfTiles[m]->getY() - tileHeight);
                    swap(vectorOfTiles[m], vectorOfTiles[m-4]);
                    break;
                case RIGHT:
                    vectorOfTiles[m]->setX(vectorOfTiles[m]->getX() + tileWidth);
                    swap(vectorOfTiles[m], vectorOfTiles[m+1]);
                    break;
                case BOTTOM:
                    vectorOfTiles[m]->setY(vectorOfTiles[m]->getY() + tileHeight);
                    swap(vectorOfTiles[m], vectorOfTiles[m+4]);
                    break;
                default:
                    break;
                }

                if (isFinish(targetPosition)) {
                    cout << "Game over!" << endl;
                }
            }
            vectorOfTiles[m]->render();
        }
    }
}

Numbers::~Numbers(){
    clear();
}

int Numbers::moveDecision(int pos) {
    int left = -1;
    int right = -1;
    int top = -1;
    int bottom = -1;

    int result = 0;

    if (pos - 1 >= 0 && pos % 4 != 0) {
        left = currentPositionOfNumbers[pos - 1];
    }

    if (pos + 1 <= 15 && pos % 4 != 3) {
        right = currentPositionOfNumbers[pos + 1];
    }

    if (pos - 4 >= 0) {
        top = currentPositionOfNumbers[pos - 4];
    }

    if (pos + 4 <= 15) {
        bottom = currentPositionOfNumbers[pos + 4];
    }

    if (left == 0) {
        currentPositionOfNumbers[pos - 1] = currentPositionOfNumbers[pos];
        currentPositionOfNumbers[pos] = 0;
        result = LEFT;
    } else if (right == 0) {
        currentPositionOfNumbers[pos + 1] = currentPositionOfNumbers[pos];
        currentPositionOfNumbers[pos] = 0;
        result = RIGHT;
    } else if (top == 0) {
        currentPositionOfNumbers[pos - 4] = currentPositionOfNumbers[pos];
        currentPositionOfNumbers[pos] = 0;
        result = TOP;
    } else if (bottom == 0) {
        currentPositionOfNumbers[pos + 4] = currentPositionOfNumbers[pos];
        currentPositionOfNumbers[pos] = 0;
        result = BOTTOM;
    }

    return result;
}

int* Numbers::getValidNumbersPosition() {
    static int arr[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int inversions= 0;
    int zero = 1;

    do {
        zero = 1;
        inversions = 0;
        random_shuffle(&arr[0], &arr[16]);

        // where is 0?
        for(int i = 0; i < 16; i++) {
            if (arr[i] != 0) {
                zero++;
            } else {
                break;
            }
        }

        for (int i = 0; i < 16; i++) {
            for (int j = i+1; j < 16; j++) {
                if ( arr[i] - arr[j] > 0 && arr[j] != 0) {
                    inversions++;
                }
            }
        }
    } while ((inversions + zero + 1) % 2 != 0);

    return arr;
}

void Numbers::newGame() {
    clear();
    initVectorOfTiles(false);
}

void Numbers::restartGame(){
    clear();
    initVectorOfTiles(true);
}

void Numbers::clear() {
    for (int m = 0; m < 16; m++) {
        SpriteManager::deleteSprite("number_"+ConvertFunctions::intToString(currentPositionOfNumbers[m]-1));
    }
    vectorOfTiles.clear();
    for (int i = 0; i < vectorOfTiles.size(); i++) {
        delete vectorOfTiles[i];
    }
    delete emptyTile;
}

/**
 *
 * @brief Numbers::initVectorOfNumbers
 * @param restart
 */
void Numbers::initVectorOfTiles(bool restart) {
    emptyTile = new AnimatedSprite();
    emptyTile->setType(Constants::SpriteTypes::ANIMATED_SPRITE);
    emptyTile->setName("EMPTY");
    emptyTile->setRenderer(appRender);
    emptyTile->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "numbers.png", appRender);

    int x = 0;
    int y = 0;
    if (restart) {
        for (int i = 0; i < 16;i++) {
            currentPositionOfNumbers[i] = initialPosition[i];
        }
    } else {
        currentPositionOfNumbers = getValidNumbersPosition();
        for (int i = 0; i < 16;i++) {
            initialPosition[i] = currentPositionOfNumbers[i];
        }
    }

    for (int m = 0; m < 16; m++) {
         if (currentPositionOfNumbers[m] != 0) {
            tile = new AnimatedSprite();
            tile->w = 1200;
            tile->h = 80;
            tile->setType(Constants::SpriteTypes::ANIMATED_SPRITE);
            tile->setName("number_"+ConvertFunctions::intToString(currentPositionOfNumbers[m]-1));
            tile->setRenderer(this->appRender);
            tile->setImage(emptyTile->getImage());
            tile->setTilesXY(15, 1);
            tile->setFrameBeginEnd(currentPositionOfNumbers[m]-1, currentPositionOfNumbers[m]-1);
            tile->setGroup("numbers");
            tile->calculate(10);

            tile->setX(tilePosX + tileWidth * x);
            tile->setY(tilePosY + tileHeight * y);
            SpriteManager::addSprite(tile);
            vectorOfTiles.push_back(tile);
        } else {
            vectorOfTiles.push_back(emptyTile);
        }
        x++;

        if (x % 4 == 0) {
            x = 0;
            y++;
        }
    }

}

void Numbers::onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as){
    cout << "md" << endl;
}

/**
 *
 * @brief Numbers::finish
 * @param target
 * @return bool
 */
bool Numbers::isFinish(int* target) {
    bool result = true;

    for (int i = 0; i < 16; i++) {
        if (target[i] != currentPositionOfNumbers[i]) {
            result = false;
            break;
        }
    }

    return result;
}
