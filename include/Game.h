#ifndef GAME_H
#define GAME_H

#include "SpriteManager.h"
#include "AbstractGame.h"
#include "MouseEvents.h"
#include "Background.h"
#include "KeyboardEvents.h"
#include "SdlApplication.h"
#include "Messages.h"

class Game : public SpriteManager, public AbstractGame, public MouseEvents, public KeyboardEvents
{
    public:
        double deltaTime;
        bool avoidEvents;
        // delete
        SDL_Surface* screen;
        Game();
        virtual ~Game();
        void start(int,int);
        SDL_PixelFormat* getPixelFormat();
        void setTitle(char* title);
        void setIcon(string);
        void setWindowSize(int,int);
        void setDone(bool);
        int getWidth();
        int getHeight();
        SDL_Renderer* appRender;
        SDL_Window* getWindow();

    private:
        bool done;
        double thisTime;
        double lastTime;
        Message message1;
        Message message2;
        SDL_Event event;
        SDL_Window* window;
        char* title;
        set<int> multiKeysCombination;
        SdlApplication *mSdlApplication;
        int mouse_x, mouse_y;
        int old_mouse_x, old_mouse_y;
        Constants::KeyState mKeyState;

        void g_events();
        void g_update();
        void g_render();
protected:
        bool isCursorInWindow;

};

#endif // GAME_H
