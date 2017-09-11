#include "Game15.h"

Game15::Game15() {
    buttonsLeftMargin = 388;
    buttonsHeight = 30;
    buttonsTopMenu = 10;
    buttonsDistance = 5;
}

void Game15::init() {
    btnNewGame = new Button();
    btnNewGame->setX(buttonsLeftMargin);
    btnNewGame->setY(buttonsTopMenu);
    btnNewGame->setTilesXY(1,2);
    btnNewGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "newGame.png", this->appRender);
    btnNewGame->setName("btnNewGame");
    SpriteManager::addSprite(btnNewGame);

    btnRestartGame = new Button();
    btnRestartGame->setX(buttonsLeftMargin);
    btnRestartGame->setY(buttonsTopMenu+buttonsHeight+buttonsDistance);
    btnRestartGame->setTilesXY(1,2);
    btnRestartGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "restart.png", this->appRender);
    btnRestartGame->setName("btnRestartGame");
    SpriteManager::addSprite(btnRestartGame);

    btnToMainMenu = new Button();
    btnToMainMenu->setX(buttonsLeftMargin);
    btnToMainMenu->setY(buttonsTopMenu+2*buttonsHeight+buttonsDistance*2);
    btnToMainMenu->setTilesXY(1,2);
    btnToMainMenu->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "toMainMenu.png", this->appRender);
    btnToMainMenu->setName("btnToMainMenu");
    SpriteManager::addSprite(btnToMainMenu);

    mBackground = new Background();
    mBackground->setName("background_board");
    mBackground->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "board.png", this->appRender);
    SpriteManager::addSprite(mBackground);

    mNumbers = new Numbers(appRender);

}

void Game15::setRenderer(SDL_Renderer* appRender){
    this->appRender = appRender;
}

void Game15::render() {
    if( GameState::inGame == 1 ) {
        mBackground->render();
        btnToMainMenu->render();
        btnNewGame->render();
        btnRestartGame->render();

        if (mNumbers) {
            mNumbers->render();
        }

        if (btnToMainMenu->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
            GameState::inGame = 0;

            SpriteManager::deleteSprite("background_board");
            SpriteManager::deleteSprite("btnToMainMenu");
            SpriteManager::deleteSprite("btnNewGame");
            SpriteManager::deleteSprite("btnRestartGame");
        } else if (btnNewGame->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
            mNumbers->newGame();
        } else if (btnRestartGame->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
            mNumbers->restartGame();
        }
    }
}

void Game15::update(double deltaTime) {
}

void Game15::freeResources() {

}

Game15::~Game15() {
    delete mBackground;
    mBackground = 0;
    delete btnToMainMenu;
    btnToMainMenu = 0;
    delete btnNewGame;
    btnNewGame = 0;
    delete btnRestartGame;
    btnRestartGame = 0;
    delete mNumbers;
    mNumbers = 0;

    cout << "delete Game15" << endl;

}

void Game15::onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as) {
    cout << "gm15:" << as->getName() << endl;
}
