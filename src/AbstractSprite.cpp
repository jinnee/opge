/* 
 * File:   AbstractSprite.cpp
 * Author: jinnee
 * 
 * Created on October 28, 2014, 2:32 PM
 */

#include "../include/AbstractSprite.h"

AbstractSprite::AbstractSprite():ImageInstruments()
{
    name = "AbstractSprite";
    type = Constants::SpriteTypes::ABSTRACT_SPRITE;
    activeName = "AbstractSprite";
    scaleCoefficient = 1;
    scaleType = Constants::ScaleTypes::BOTH;
    this->rotationAngle = 0.0;
    position = {0,0,0,0};
    oldPosition = {0,0,0,0};
    scaledWidth = 0;
    scaledHeight = 0;
    rotationCenter = NULL;
    flipMode = SDL_FLIP_NONE;
    clip = NULL;
    tag = "";
}

void AbstractSprite::setAsActiveSprite() {
    activeName = name;
}

AbstractSprite::~AbstractSprite() {
}

string AbstractSprite::getActiveSprite() {
    return activeName;
}

void AbstractSprite::render() {
    SDL_Texture* texture = this->getImage();

    if (scaleCoefficient == 1) {
        //Set rendering space and render to screen
        SDL_Rect renderQuad = { position.x, position.y, this->w, this->h };
        //Set clip rendering dimensions
        if( clip != NULL ) { renderQuad.w = clip->w; renderQuad.h = clip->h; }
        //Render to screen
        SDL_RenderCopyEx( renderer, texture, this->clip, &renderQuad, this->rotationAngle, this->rotationCenter, this->flipMode );
    } else {
        if (scaleType == Constants::BOTH) {
            SDL_Rect renderQuad = { position.x, position.y, ConvertFunctions::doubleToInt(this->w*scaleCoefficient), ConvertFunctions::doubleToInt(this->h*scaleCoefficient) };
            if( clip != NULL ) { renderQuad.w = ConvertFunctions::doubleToInt(clip->w*scaleCoefficient); renderQuad.h = ConvertFunctions::doubleToInt(clip->h*scaleCoefficient); }
            SDL_RenderCopyEx( renderer, texture, this->clip, &renderQuad, this->rotationAngle, this->rotationCenter, this->flipMode );
        } else if (scaleType == Constants::WIDTH) {
            SDL_Rect renderQuad = { position.x, position.y, ConvertFunctions::doubleToInt(this->w*scaleCoefficient), this->h };
            if( clip != NULL ) { renderQuad.w = ConvertFunctions::doubleToInt(clip->w*scaleCoefficient); renderQuad.h = clip->h; }
            SDL_RenderCopyEx( renderer, texture, this->clip, &renderQuad, this->rotationAngle, this->rotationCenter, this->flipMode );
        } else if (Constants::ScaleTypes::HEIGHT) {
            SDL_Rect renderQuad = { position.x, position.y, this->w, ConvertFunctions::doubleToInt(this->h*scaleCoefficient) };
            if( clip != NULL ) { renderQuad.w = clip->w; renderQuad.h = ConvertFunctions::doubleToInt(clip->h*scaleCoefficient); }
            SDL_RenderCopyEx( renderer, texture, this->clip, &renderQuad, this->rotationAngle, this->rotationCenter, this->flipMode );
        }
    }
}

// TODO
int AbstractSprite::getScaledWidth() {
    if (scaleType == Constants::WIDTH || scaleType == Constants::BOTH) {
        return ConvertFunctions::doubleToInt(this->w*scaleCoefficient);
    } else if (scaleType == Constants::ScaleTypes::HEIGHT) {
        return this->w;
    }
}

int AbstractSprite::getScaledHeight() {
    if (scaleType == Constants::WIDTH) {
        return this->h;
    } else if (scaleType == Constants::ScaleTypes::HEIGHT
               ||scaleType == Constants::ScaleTypes::BOTH) {
        return ConvertFunctions::doubleToInt(this->h*scaleCoefficient);
    }
}

void AbstractSprite::moveX(int dx)
{
    oldPosition.x = position.x;
    position.x +=dx;
}

void AbstractSprite::moveY(int dy)
{
    oldPosition.y = position.y;
    position.y +=dy;
}

void AbstractSprite::setScale(double scaleCoefficient){
    this->scaleCoefficient = scaleCoefficient;
}
