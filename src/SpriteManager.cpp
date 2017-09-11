#include "../include/SpriteManager.h"

SpriteManager::SpriteManager()
{

}

void SpriteManager::addSprite(AbstractSprite* ss){
    vectorOfSprites.push_back(ss);
}

void SpriteManager::swap(string ss1, string ss2){
    //vectorOfSprites.swap(ss1, ss2);
    int i1 = SpriteManager::getSpriteIndex(ss1);
    int i2 = SpriteManager::getSpriteIndex(ss2);
    std::swap(vectorOfSprites[i1],vectorOfSprites[i2]);
//    std::swap(ss1, ss2);
}

void SpriteManager::deleteSprite(string name){
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();

//    for (it = vectorOfSprites.begin(); it != vectorOfSprites.end(); it++) {
//        if ((*it)->getName() == name) {
//            vectorOfSprites.erase(it);
//            cout << "delete sprite:" << (*it)->getName() << endl;
//            break;
//        }
//    }

    int v_size = vectorOfSprites.size();
    for (int i = 0; i < v_size; i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            it = vectorOfSprites.begin()+i;
            cout << "delete sprite (from manager):" << (*it)->getName() << endl;
            vectorOfSprites.erase(it);
            break;
        }
    }
}

void SpriteManager::deleteSpritesByGroup(string name){
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    int v_size = vectorOfSprites.size();
    for (int i = 0; i < v_size; i++) {
        if ( vectorOfSprites[i]->getGroup() == name ) {
            it = vectorOfSprites.begin()+i;
            vectorOfSprites.erase(it);
            cout << "delete group: " << name << endl;
        }
    }
}

AbstractSprite* SpriteManager::getSprite(string &name){
    //std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    for (unsigned int i = 0; i < vectorOfSprites.size(); i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            //it = vectorOfSprites.begin()+i;
            return vectorOfSprites[i];
        }
    }
    return 0;
}

int SpriteManager::getSpriteIndex(string &name){
    for (unsigned int i = 0; i < vectorOfSprites.size(); i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            return i;
        }
    }
    return -1;
}

SpriteManager::~SpriteManager()
{
    //dtor
}

string SpriteManager::getEventFrom(){
    return SpriteManager::mouseEventFrom;
}

void SpriteManager::setEventFrom(string &mouseEventFrom){
    SpriteManager::mouseEventFrom = mouseEventFrom;
}

vector<AbstractSprite*> SpriteManager::vectorOfSprites ;
string SpriteManager::mouseEventFrom = "";
