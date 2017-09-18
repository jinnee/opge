#include "Game15.h"

Game15::Game15() {
    buttonsLeftMargin = 388;
    buttonsHeight = 30;
    buttonsTopMenu = 10;
    buttonsDistance = 5;
}

void Game15::init() {
    gameFont = new TtfFont();
    gameFont->setSize(20);
    gameFont->setPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "Karina.ttf");
    if(!gameFont->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }

    Cursor::getCursor()->changeCursorFromPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "blue_cursor.png", appRender);

    btnNewGame = new TextButton(appRender);
    btnNewGame->setFont(gameFont);
    btnNewGame->setTilesXY(1,2);
    btnNewGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "15btn.png", appRender);
    btnNewGame->setName("btnNewGame");
    btnNewGame->setX(buttonsLeftMargin);
    btnNewGame->setY(buttonsTopMenu);
    btnNewGame->setTextColor({ 255, 255, 255 });
    btnNewGame->setText("New game");
    SpriteManager::addSprite(btnNewGame);

    btnRestartGame = new TextButton(appRender);
    btnRestartGame->setFont(gameFont);
    btnRestartGame->setTilesXY(1,2);
    btnRestartGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "15btn.png", appRender);
    btnRestartGame->setName("btnRestartGame");
    btnRestartGame->setX(buttonsLeftMargin);
    btnRestartGame->setY(buttonsTopMenu+buttonsHeight+buttonsDistance);
    btnRestartGame->setTextColor({ 255, 255, 255 });
    btnRestartGame->setText("Restart");
    SpriteManager::addSprite(btnRestartGame);

    btnToMainMenu = new TextButton(appRender);
    btnToMainMenu->setFont(gameFont);
    btnToMainMenu->setTilesXY(1,2);
    btnToMainMenu->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "15btn.png", appRender);
    btnToMainMenu->setName("btnToMainMenu");
    btnToMainMenu->setX(buttonsLeftMargin);
    btnToMainMenu->setY(buttonsTopMenu+2*buttonsHeight+buttonsDistance*2);
    btnToMainMenu->setTextColor({ 255, 255, 255 });
    btnToMainMenu->setText("To menu");
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

    gameFont->close();
    delete gameFont;
    gameFont = 0;

    cout << "delete Game15" << endl;

}

void Game15::onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as) {
    cout << "gm15:" << as->getName() << endl;
}
