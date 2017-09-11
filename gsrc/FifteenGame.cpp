#include "FifteenGame.h"

FifteenGame::FifteenGame() {
}

void FifteenGame::init() {
    this->setTitle((char*)"Fifteen game");
    this->setIcon(Constants::RESOURCE_DIR + Constants::pathSeparator + "icon.png");
    gameSettings = new GameSettings("test.xml");

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

    btnTextButton = new TextButton(appRender);
//    btnTextButton->setTilesXY(1,2);
//    btnTextButton->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "Game15Buttons80.png", appRender);
//    btnTextButton->setName("btnTextButton");
//    btnTextButton->setX(10);
//    btnTextButton->setY(10);
//    btnTextButton->setText("Към играта");
//    addSprite(btnTextButton);


    btnExitGame = new Button();
    btnExitGame->setTilesXY(1,2);
    btnExitGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "exitGame.png", appRender);
    btnExitGame->setName("btnExitGame");
    btnExitGame->setX((getWidth() - btnExitGame->getSpriteWidth())/2);
    int exitBtnBottom = getHeight() - btnExitGame->getSpriteHeight() - 25;
    btnExitGame->setY(exitBtnBottom);
    addSprite(btnExitGame);

    btnAboutGame = new Button();
    btnAboutGame->setTilesXY(1,2);
    btnAboutGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "aboutGame.png", appRender);
    btnAboutGame->setName("btnAboutGame");
    btnAboutGame->setX((getWidth() - btnAboutGame->getSpriteWidth())/2);
    btnAboutGame->setY(exitBtnBottom - btnAboutGame->getSpriteHeight() - 15);
    addSprite(btnAboutGame);

    btnGoGame = new TextButton(appRender);
    btnGoGame->setTilesXY(1,2);
    btnGoGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "Game15Buttons80.png", appRender);
    btnGoGame->setName("btnGoGame");
    btnGoGame->setX((getWidth() - btnGoGame->getSpriteWidth())/2);
    btnGoGame->setY(exitBtnBottom - 2*btnGoGame->getSpriteHeight() - 30);
    btnGoGame->setText("Към играта");
    addSprite(btnGoGame);
//    btnGoGame = new Button();
//    btnGoGame->setTilesXY(1,2);
//    btnGoGame->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "goGame.png", appRender);
//    btnGoGame->setName("btnGoGame");
//    btnGoGame->setX((getWidth() - btnGoGame->getSpriteWidth())/2);
//    btnGoGame->setY(exitBtnBottom - 2*btnGoGame->getSpriteHeight() - 30);
//    addSprite(btnGoGame);

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
    title->setText("Игра");
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
//        btnTextButton->render();
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

    delete ttff;
    ttff = 0;

    delete title;
    title = 0;

    delete btnTextButton;
    btnTextButton = 0;
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

