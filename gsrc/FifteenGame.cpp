#include "FifteenGame.h"

FifteenGame::FifteenGame() {
}

void FifteenGame::init() {
    this->setTitle((char*)"Fifteen game");
    this->setIcon(Constants::RESOURCE_DIR + Constants::pathSeparator + "icon.png");
    gameSettings = new GameSettings("test.xml");

    mainMenuFont = new TtfFont();
    mainMenuFont->setSize(20);
    mainMenuFont->setPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "Karina.ttf");
    if(!mainMenuFont->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }
    mainMenuFont->setStyle(TTF_STYLE_BOLD);


    gameSettings->putValue("key","val");

    background = new Background();
    background->setVisible(true);
    background->setName("background");
    background->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "background.png", appRender);
    addSprite(background);

    cursor = Cursor::getCursor();
    cursor->changeCursorFromPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "blue_cursor.png", appRender);
    cursor->setVisible(true);
    cursor->setRenderer(appRender);

    addSprite(cursor);

    btnExitGame = new TextButton(appRender);
    btnExitGame->setFont(mainMenuFont);
    btnExitGame->setTilesXY(1,2);
    btnExitGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "Game15Buttons80.png", appRender);
    btnExitGame->setName("btnExitGame");
    btnExitGame->setX((getWidth() - btnExitGame->getSpriteWidth())/2);
    int exitBtnBottom = getHeight() - btnExitGame->getSpriteHeight() - 25;
    btnExitGame->setY(exitBtnBottom);
    btnExitGame->setText("Exit");
    addSprite(btnExitGame);

    btnAboutGame = new TextButton(appRender);
    btnAboutGame->setFont(mainMenuFont);
    btnAboutGame->setTilesXY(1,2);
    btnAboutGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "Game15Buttons80.png", appRender);
    btnAboutGame->setName("btnAboutGame");
    btnAboutGame->setX((getWidth() - btnAboutGame->getSpriteWidth())/2);
    btnAboutGame->setY(exitBtnBottom - btnAboutGame->getSpriteHeight() - 15);
    btnAboutGame->setText("About game");
    addSprite(btnAboutGame);

    btnGoGame = new TextButton(appRender);
    btnGoGame->setFont(mainMenuFont);
    btnGoGame->setTilesXY(1,2);
    btnGoGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "Game15Buttons80.png", appRender);
    btnGoGame->setName("btnGoGame");
    btnGoGame->setX((getWidth() - btnGoGame->getSpriteWidth())/2);
    btnGoGame->setY(exitBtnBottom - 2*btnGoGame->getSpriteHeight() - 30);
    btnGoGame->setText("Play game");
    addSprite(btnGoGame);

    ttff = new TtfFont();
    ttff->setSize(70);
    ttff->setPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "Karina.ttf");
    if(!ttff->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }

    title = new UILabel();
    SDL_Color color1;
    color1.r = 254;
    color1.g = 70;
    color1.b = 194;

    title->setTextColor(color1);
    title->setVisible(true);
    title->setName("title_game");
    title->setRenderer(appRender);
    title->setX(170);
    title->setY(190);
    title->setText("Game");
    title->setFont(ttff);
    addSprite(title);
}

void FifteenGame::update(double deltaTime) {
    if (mGame15 && GameState::inGame == 1) {
        mGame15->update(deltaTime);
    }
}

void FifteenGame::render() {
    if( GameState::inGame == 0 ) {
        if (mGame15) {
            delete mGame15;
            mGame15 = 0;
        }
        background->render();
        title->render();
        btnGoGame->render();
        btnAboutGame->render();
        btnExitGame->render();

        if ( btnGoGame ->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
            GameState::inGame = 1;
            mGame15 = new Game15();
            mGame15->setRenderer(appRender);
            mGame15->init();
        } else if (btnAboutGame->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
        }
        if (btnExitGame->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
            this->setDone(true);
        }
    } else {
        mGame15->render();
    }

    if(isCursorInWindow)
        cursor->StaticSprite::render();
}

void FifteenGame::freeResources() {
}

FifteenGame::~FifteenGame() {
    delete gameSettings;
    gameSettings = 0;

    delete background;
    background = 0;

    delete cursor;
    cursor = 0;

    delete btnExitGame;
    btnExitGame = 0;

    delete btnGoGame;
    btnGoGame = 0;

    delete btnAboutGame;
    btnAboutGame = 0;

    mainMenuFont->close();
    delete mainMenuFont;
    mainMenuFont = 0;

    ttff->close();
    delete ttff;
    ttff = 0;

    delete title;
    title = 0;
}

void FifteenGame::onKeyUp(Sint16 key){
}

void FifteenGame::onKeyDown(Sint16 key){
    if (key == Constants::KeyboardCustomCodes::KEY_ALTL_S) {
        cout << "key down:" << key << endl;
    }
}

void FifteenGame::onMouseDown(Sint16 x, Sint16 y, AbstractSprite* as){
    if (mGame15) {
        mGame15->onMouseDown(x, y, as);
    } else {
        cout << "main key down:" << as->getName() << endl;
    }
}

