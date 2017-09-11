#ifndef GAMESETTINGS_H
#define GAMESETTINGS_H

#include "include/inc_files.h"

class GameSettings
{
public:
    GameSettings(string);
    void putValue(string, string);
    string getValue(string);
    void save();
    ~GameSettings();

private:
    XMLDocument* xmlDoc;
    XMLElement* root;
    string fileName;
};

#endif // GAMESETTINGS_H
