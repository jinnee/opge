#include "../include/AnimatedSprite.h"

AnimatedSprite::AnimatedSprite():StaticSprite()
{
    type = Constants::SpriteTypes::ANIMATED_SPRITE;
    name = "AnimatedSprite";
    position.x = 0;
    position.y = 0;
    frameBegin = 1;
    frameEnd = 1;
    frame = 1;
    frameCount = 1;
    frameInterval = 0.1;
    frameTimeRemaining = 0.1;
    speed = 0;
    oldSpeed = 0;
    directionCollide = "";
    collidetWith = "";
}

AnimatedSprite::~AnimatedSprite() {
}

void AnimatedSprite::setFrameBeginEnd(int begin, int end) {
    frameBegin = begin;
    frameEnd = end;
}

void AnimatedSprite::calculate(double frameRate) {
    this->tileWidth = this->w / tilesX;
    this->tileHeight = this->h / tilesY;
	this->frame = frameBegin;
	this->frameCount = tilesX;
	this->frameInterval = 1 / frameRate;
	this->frameTimeRemaining = frameInterval;
}

void AnimatedSprite::update(double deltaTime) {
    this->deltaTime = deltaTime;
	frameTimeRemaining -= deltaTime;
    if(frameTimeRemaining < 0) {
		this->frame++;
	    if (this->frame > this->frameEnd) {
	        this->frame = this->frameBegin;
	    }
		this->frameTimeRemaining = this->frameInterval;
	}
}

double AnimatedSprite::getDeltaTime() {
    return this->deltaTime;
}

void AnimatedSprite::setSpeed(int speed) {
    this->oldSpeed = this->speed;
    this->speed = speed;
}

void AnimatedSprite::render(int debug) {
    if (frame >= frameBegin && frame <= frameEnd) {
        this->setClip(GetFrameBounds());
        StaticSprite::render();
    } else {
       frame = frameBegin;
    }
}

SDL_Rect* AnimatedSprite::GetFrameBounds() {
    SDL_Rect* frameBounds = new SDL_Rect();

    frameBounds->x = (Sint16)(frame % tilesX * tileWidth);
    frameBounds->y = (Sint16)(frame / tilesX * tileHeight);
    frameBounds->w = (Sint16)(tileWidth);
    frameBounds->h = (Sint16)(tileHeight);

    return frameBounds;
}

void AnimatedSprite::setDirectionCollide(string dc) {
    this->directionCollide = dc;
}

string AnimatedSprite::getDirectionCollide() {
    return this->directionCollide;
}

