#include "include/GameSettings.h"

GameSettings::GameSettings(string fileName) {

    this->fileName = fileName;
    xmlDoc = new XMLDocument();
    XMLError eResult = xmlDoc->LoadFile(fileName.c_str());

    //create empty file
    if (eResult != 0) {
        // root element
        root = xmlDoc->NewElement("settings");
        xmlDoc->LinkEndChild(root);
        xmlDoc->SaveFile(fileName.c_str());
    } else { // exists
        root = xmlDoc->FirstChildElement("settings");
    }
}

void GameSettings::putValue(string key, string value){
    XMLElement* data = xmlDoc->NewElement("data");
    data->SetAttribute(key.c_str(),value.c_str());

    root->LinkEndChild(data);

    xmlDoc->SaveFile(fileName.c_str());
}

string GameSettings::getValue(string key){
//    string result = "";
//    XMLNode * root = xmlDoc->FirstChild();
//    return result;
}

void GameSettings::save(){
    xmlDoc->SaveFile(this->fileName.c_str());
}

GameSettings::~GameSettings() {
    delete xmlDoc;
    xmlDoc = 0;
}
