#include "../include/Game.h"

Game::Game():SpriteManager()
{
    mSdlApplication = new SdlApplication();
    isCursorInWindow = false;
    done =false;
    thisTime = 0.0;
    lastTime = 0.0;
    deltaTime = 0.0;
    avoidEvents = false;
    mKeyState = Constants::KeyState::UP;
}

Game::~Game() {
    SDL_FreeSurface(screen);
    mSdlApplication->close();
}

SDL_PixelFormat* Game::getPixelFormat() {
    return mSdlApplication->getPixelFormat();
}

void Game::setTitle(char* title) {
    this->title = title;
    mSdlApplication->setTitle(this->title);
}

void Game::setIcon(string path) {
    mSdlApplication->setIcon(path);
}

void Game::start(int sw, int sh){
    mSdlApplication->setTitle("SDL Application");
    mSdlApplication->setWindowSize(sw, sh);
    mSdlApplication->init();
    mSdlApplication->create();
    ImageInstruments::setPixelFormat(this->getPixelFormat());
    window = mSdlApplication->getWindow();

    appRender = mSdlApplication->getRender();

    if (appRender == NULL){
        std::cout << "appRender is NULL" << std::endl;
    }

    this->init();
    done = false;
    while (!done)
    {
        this->g_events();
        this->g_update();
        this->g_render();
    }
    this->freeResources();
}

// sdl event manager
void Game::g_events() {
    //control of FPS
    SDL_Delay(20);

    // catch events
    while (SDL_PollEvent(&event)) {
        int vectorOfSpritesSize = vectorOfSprites.size();
        for (int i = 0; i < vectorOfSpritesSize; i++) {
            if (avoidEvents) {
                // cursor must be always available
                if (vectorOfSprites[i]->getTag() != Constants::SpriteModal) {
                    continue;
                }
            }

            // message type
            switch (event.type)
            {
                case SDL_MOUSEMOTION:
                    old_mouse_x = event.motion.xrel;
                    old_mouse_y = event.motion.yrel;
                    mouse_x = event.motion.x;
                    mouse_y = event.motion.y;

                    if ( vectorOfSprites[i]->getType() == Constants::SpriteTypes::MOUSE_CURSOR ) {
                        vectorOfSprites[i]->setPosition(mouse_x, mouse_y);
                    }
                    if (vectorOfSprites[i]->getType() != Constants::SpriteTypes::BACKGROUND)
                    {
                        vectorOfSprites[i]->setMousePosXY(mouse_x, mouse_y);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:

                    if (vectorOfSprites[i]->getName() == SpriteManager::mouseEventFrom  ) {

                        if(event.button.button == SDL_BUTTON_LEFT) {
                            message1.from = SpriteManager::mouseEventFrom;
                            message1.to = SpriteManager::mouseEventFrom;
                            message1.type = Constants::MessageTypes::MOUSE_LEFT_DOWN;
                            message1.data = "";
                            this->onMouseDown(event.button.x, event.button.y, vectorOfSprites[i]);
                            Messages::addMessage(message1);

//                            message2.from = SpriteManager::mouseEventFrom;
//                            message2.to = SpriteManager::mouseEventFrom;
//                            message2.type = Constants::MessageTypes::MOUSE_LEFT_CLICK;
//                            message2.data = SpriteManager::mouseEventFrom;

//                            Messages::addMessage(message2);

                            vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        } else if (event.button.button == SDL_BUTTON_RIGHT) {
                            message1.from = SpriteManager::mouseEventFrom;
                            message1.to = SpriteManager::mouseEventFrom;
                            message1.type = Constants::MessageTypes::MOUSE_RIGHT_DOWN;
                            message1.data = "";

                            Messages::addMessage(message1);
                            vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        }
                    }
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (vectorOfSprites[i]->getName() == SpriteManager::mouseEventFrom) {
                        if(event.button.button == SDL_BUTTON_LEFT) {
                            message1.from = SpriteManager::mouseEventFrom;
                            message1.to = SpriteManager::mouseEventFrom;
                            message1.type = Constants::MessageTypes::MOUSE_LEFT_UP;
                            message1.data = "";

                            Messages::addMessage(message1);

//                            message2.from = SpriteManager::mouseEventFrom;
//                            message2.to = SpriteManager::mouseEventFrom;
//                            message2.type = Constants::MessageTypes::MOUSE_LEFT_CLICK;
//                            message2.data = SpriteManager::mouseEventFrom;

//                            Messages::addMessage(message2);

                            vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        } else if (event.button.button == SDL_BUTTON_RIGHT) {
                                message1.from = SpriteManager::mouseEventFrom;
                                message1.to = SpriteManager::mouseEventFrom;
                                message1.type = Constants::MessageTypes::MOUSE_RIGHT_UP;
                                message1.data = "";

                                Messages::addMessage(message1);
                                vectorOfSprites[i]->setMousePosXY(event.button.x, event.button.y);
                        }
                    }
                    break;
                case SDL_MOUSEWHEEL:
                    break;
                case SDL_WINDOWEVENT:
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_LEAVE:
                            isCursorInWindow = false;
                            break;
                        case SDL_WINDOWEVENT_ENTER:
                            isCursorInWindow = true;
                            break;
                        default:
                            break;
                     }
                    break;
                // Изход при затваряне на прозореца
                case SDL_QUIT:
                    done = true;
                    break;
                case SDL_KEYUP:{
                    multiKeysCombination.erase(event.key.keysym.sym);
                    vectorOfSprites[i]->setKeyReleased(true);
                    vectorOfSprites[i]->setTypeKeyReleased("");
                    int key = event.key.keysym.sym;
                    mKeyState = Constants::KeyState::UP;
                    this->onKeyUp(key);
                    break;
                }
                case SDL_KEYDOWN:
                {
                    //регистрира клавиатурно събитие
                    vectorOfSprites[i]->setKeyReleased(true);
                    //ако е избран с мишката спрайта, то реагира на клавишите
                    //може да се манипулира !!!!!!!!!!!!!
                    int key = event.key.keysym.sym;
                    multiKeysCombination.insert(key);

                    if (vectorOfSprites[i]->getName() == vectorOfSprites[i]->getActiveSprite()) {
                        // arrow keys
                        switch(key){
                            case SDLK_LEFT:
                                vectorOfSprites[i]->setTypeKeyReleased("SDLK_LEFT");
                                break;
                            case SDLK_RIGHT:
                                vectorOfSprites[i]->setTypeKeyReleased("SDLK_RIGHT");
                                break;
                            case SDLK_UP:
                                vectorOfSprites[i]->setTypeKeyReleased("SDLK_UP");
                                break;
                            case SDLK_DOWN:
                                vectorOfSprites[i]->setTypeKeyReleased("SDLK_DOWN");
                                break;
                            default:
                                //vectorOfSprites[i]->setTypeKeyReleased("");
                                break;
                        }
                    } else {
                        if (multiKeysCombination.find(SDLK_LALT) != multiKeysCombination.end()) {
                            switch(event.key.keysym.sym){
                                case SDLK_s: // alt + s
                                    if (mKeyState == Constants::KeyState::UP)
                                        key = Constants::KeyboardCustomCodes::KEY_ALTL_S;
                                    mKeyState = Constants::KeyState::DOWN;
                                default:
                                    break;
                            }
                        } else if (multiKeysCombination.find(SDLK_LCTRL) != multiKeysCombination.end()) {
                            switch(event.key.keysym.sym){
                                case SDLK_s: // ctrl + s
                                    if (mKeyState == Constants::KeyState::UP)
                                        key = Constants::KeyboardCustomCodes::KEY_CTRL_S;
                                    mKeyState = Constants::KeyState::DOWN;
                                default:
                                    break;
                            }
                        }


                        switch(event.key.keysym.sym){
                            case SDLK_ESCAPE:
                                done = true;
                                break;
                            default:
                                break;
                        }

                    }
                    this->onKeyDown(key);
                }
                default:
                    break;
            } // край на switch
        } // край на for

        // ако нямаме въведени спрайтове
        if (vectorOfSpritesSize == 0) {
            if (event.type == SDL_QUIT) {
                done = true;
            }
        }
    } // край на обработка на съобщенията
}

void Game::g_update() {
    lastTime = thisTime;
    thisTime = SDL_GetTicks();
    deltaTime = (thisTime - lastTime) / 1000.0;
    this->update(deltaTime);
}

void Game::g_render() {
    SDL_RenderClear( appRender );
    this->render();
    SDL_RenderPresent(appRender);
}

void Game::setDone(bool done) {
    this->done = done;
}

void Game::setWindowSize(int w,int h) {
    this->mSdlApplication->setWindowSize(w, h);
}

int Game::getWidth() {
    return mSdlApplication->getWidth();
}

int Game::getHeight() {
    return mSdlApplication->getHeight();
}

SDL_Window* Game::getWindow() {
    return this->window;
}
