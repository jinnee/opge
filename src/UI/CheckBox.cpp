#include "include/UI/CheckBox.h"

CheckBox::CheckBox(){
    name = "CHECKBOX";
    type = Constants::SpriteTypes::UI_CHECKBOX;
    setX(0);
    setY(0);
    this->setTilesXY(2,1);
    checked = false;
    text = "check box";
    labelText = new UILabel();
    labelText->setText(text);
}

void CheckBox::init(){
    labelText->setX(this->getX() + this->w/2 + 5);
    labelText->setY(this->getY());
}

void CheckBox::render(){
    SDL_Rect* src = new SDL_Rect();

    if ( this->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN) ) {
        cout << "click BUG"<< endl;
        SpriteManager::mouseEventFrom = this->getName();
        checked = !checked;
    }
    if (checked) {
        src->x = 0;
        src->y = 0;
        src->w = this->w/2;
        src->h = this->h;
    } else {
        src->x = this->w/2;
        src->y = 0;
        src->w = this->w/2;
        src->h = this->h;
    }

    setClip(src);
    StaticSprite::render();
    labelText->render();
    delete src;
    src = 0;
}

void CheckBox::setChecked(bool checked){
    this->checked = checked;
}

bool CheckBox::isChecked(){
    return this->checked;
}

void CheckBox::setText(string text){
    this->text = text;
    labelText->setText(text);
}

void CheckBox::setFont(TtfFont *ttf){
    this->ttf = ttf;
    labelText->setRenderer(renderer);
    labelText->setFont(ttf);
}

CheckBox::~CheckBox(){
    delete labelText;
    labelText = 0;
}
