#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "StaticSprite.h"

class AnimatedSprite :  public StaticSprite
{
	public:
		AnimatedSprite();
        virtual ~AnimatedSprite();

		SDL_Rect origin;

		int frame;
		int frameCount;
		double frameInterval;
		double frameTimeRemaining;

		void update(double deltaTime);
        void render(int debug = 0);
        void calculate(double frameRate);
        void setFrameBeginEnd(int, int);
        SDL_Rect getClip();
		double getDeltaTime();
		void setSpeed(int speed);
        int getOldSpeed(){return oldSpeed;}

		void setDirectionCollide(string);
		string getDirectionCollide();
        void setCollidetWith(string collide){this->collidetWith = collide;}
        string getCollidetWith(){return this->collidetWith;}
	protected:
        //от кой фрайм да започва анимацията
		int frameBegin;
        //при кой фрайм да свършва анимацията
		int frameEnd;
		//скорост на движение на духчето
		int speed;
		//скоростта преди промяна
		int oldSpeed;
        double deltaTime;
		//на коя страна на правоъгълника на духчето е настъпила колизия
		string directionCollide;
		//Флаг за спрайта с какъв точно обект е последната колизия
		string collidetWith;
    private:
        SDL_Rect* GetFrameBounds();
};

#endif // ANIMATEDSPRITE_H
