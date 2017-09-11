#ifndef ABSTRACTSPRITE_H
#define ABSTRACTSPRITE_H

#include "ImageInstruments.h"

class AbstractSprite : public ImageInstruments
{
    public:
        AbstractSprite();
        virtual ~AbstractSprite();
        //име на спрайта
        void setName(string name){this->name = name;}
        string getName(){return this->name;}
        void setRotationAngle(double rotationAngle){this->rotationAngle = rotationAngle;}
        double getRotationAngle(){return this->rotationAngle;}
        void setRotationCenter(SDL_Point *rotationCenter){this->rotationCenter = rotationCenter;}
        SDL_Point* getRotationCenter(){return this->rotationCenter;}
        void setFlipMode(SDL_RendererFlip flipMode){this->flipMode = flipMode;}
        //void setRenderer(SDL_Renderer *renderer) {this->renderer = renderer; }
        SDL_RendererFlip getFlipMode(){return this->flipMode;}
        void setClip(SDL_Rect* clip){this->clip = clip;}
        SDL_Rect* getClip(){return this->clip;}

        //тип на спрайта
        void setType(string type){this->type = type;}
        string getType(){return this->type;}
        void setVisible(bool visible){this->visible = visible;}
        bool getVisible(){return this->visible;}
        //група на спрайта
        void setGroup(string group){this->group = group;}
        string getGroup(){return this->group;}
        //установява позиция по X
        void setX( Sint16 cx ){oldPosition = position; position.x = cx; }
        Sint16 getX(){ return position.x; }
        //установява позиция по Y
        void setY( Sint16 cy ){oldPosition = position; position.y = cy; }
        Sint16 getY(){ return position.y; }
        void setTag(string tag) {this->tag = tag;}
        string getTag() {return tag;}
        void setScaleType(Constants::ScaleTypes scaleType) {this->scaleType = scaleType;}
        //установява позиция
        void setPosition (Sint16 xp, Sint16 yp){oldPosition = position; position.x = xp;position.y = yp;}
        SDL_Rect getOldPosition(){return oldPosition;}
        SDL_Rect getPosition (){return position;}
        //преместване по X
        void moveX(int);
        //преместване по Y
        void moveY(int);
        //посока на движение по остта X
        int getXDirection(){return position.x - oldPosition.x;}
        //посока на движение по остта Y
        int getYDirection(){return position.y - oldPosition.y;}

        //рендване
        void render();
        //скриване
        void setScale(double);
        void setAsActiveSprite();
        string getActiveSprite();
        int getScaledWidth();
        int getScaledHeight();

        virtual void setMousePosX(int)=0;
        virtual void setMousePosY(int)=0;
        virtual void setMousePosXY(int,int)=0;
        virtual bool isMouseButtonDown(string)=0;
        virtual bool isMouseButtonUp(string)=0;
        virtual bool isMouseButtonClick(string)=0;
        virtual void setKeyReleased(bool)=0;
        virtual bool isKeyReleased()=0;
        virtual void setTypeKeyReleased(string)=0;
    protected:
        string name;
        string type;
        string group;
        bool visible;
        //SDL_Renderer *renderer;
        SDL_Rect oldPosition;
        SDL_Rect position;
        string activeName;
        double scaleCoefficient;
        double rotationAngle;
        SDL_Point* rotationCenter;
        SDL_RendererFlip flipMode;
        Constants::ScaleTypes scaleType;
        int scaledWidth;
        int scaledHeight;
        SDL_Rect* clip;
        string tag;
    private:
};

#endif // AbstractSprite_H
