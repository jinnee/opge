#include "include/Music.h"

Music::Music(){
    path = "";
    music = NULL;
    volume = MIX_MAX_VOLUME/2;
}

bool Music::play() {
    bool result = true;

    if( Mix_PlayingMusic() == 0 ) {
        if( Mix_PlayMusic( music, -1 ) == -1 ) {
            result = false;
        }
    }

    return result;
}

void Music::stop() {
    Mix_HaltMusic();
}

void Music::setVolume(int volume) {
    Mix_VolumeMusic(volume);
    this->volume = Mix_VolumeMusic(-1);
}

int Music::getVolume() {
    return this->volume;
}

bool Music::loadMusic() {
    bool result = true;

    music = Mix_LoadMUS( path.c_str() );
    if( music == NULL ) {
        result = false;
    }

    return result;
}

void Music::setMusic(Mix_Music *music) {
    this->music = music;
}

Music::~Music(){
    Mix_FreeMusic( music );
    music = NULL;
}

void Music::setPath(string path) {
    this->path = path;
}
