#ifndef MUSIC
#define MUSIC

#include <string>
#include <SDL2/SDL_mixer.h>

using namespace std;

class Music {
public:
    Music();
    virtual ~Music();
    bool loadMusic();
    bool play();
    void stop();
    void setPath(string path);
    void setVolume(int);
    int getVolume();
    void setMusic(Mix_Music *music);
private:
    string path;
    Mix_Music *music;
    int volume;
};

#endif // MUSIC

