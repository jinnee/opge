#include "include/GameSettings.h"

GameSettings::GameSettings(string fileName) {
    this->fileName = fileName;
    xmlDoc = new XMLDocument();
    XMLError eResult = xmlDoc->LoadFile(fileName.c_str());

    //create empty file
    if (eResult != 0) {
        // root element
        root = xmlDoc->NewElement("settings");

        // music element
//        XMLElement* music = xmlDoc->NewElement("music");
//        root->LinkEndChild(music);

        // stop element
//        XMLElement* stop = xmlDoc->NewElement("stop");
//        stop->SetText("1");
//        music->LinkEndChild(stop);

        xmlDoc->LinkEndChild(root);
        xmlDoc->SaveFile(fileName.c_str());
    }
}

void GameSettings::putValue(string key, string value){
    XMLElement* data = xmlDoc->NewElement("data");
//    data->SetAttribute(key.c_str(),value.c_str());
//    data->LinkEndChild(root);
    root->LinkEndChild(data);

//    xmlDoc->LinkEndChild(root);
    xmlDoc->SaveFile(fileName.c_str());
    cout << "putValue" << endl;
}

string GameSettings::getValue(string key){
    string result = "";

    XMLNode * root = xmlDoc->FirstChild();

//    if (key == MUSIC_STOP) {
//        result = root->FirstChildElement("music")->FirstChildElement("stop")->GetText();
//    }

    return result;
}

void GameSettings::save(){
    xmlDoc->SaveFile(this->fileName.c_str());
}

GameSettings::~GameSettings() {
    delete xmlDoc;
    xmlDoc = 0;
}
