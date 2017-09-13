#include "include/UI/TextButton.h"

TextButton::TextButton(SDL_Renderer* appRender) : Button() {
    textColor = { 220, 1, 70 };
    text = "Text";
    type = Constants::SpriteTypes::TEXT_BUTTON;
    this->appRender = appRender;
    this->font = nullptr;

    label = new UILabel();
}

TextButton::~TextButton() {
    if(label != nullptr) {
        delete label;
        label = 0;
    }
}

void TextButton::render() {
    Button::render();
    label->render();
}

void TextButton::setFont(TtfFont *font) {
    this->font = font;
}

void TextButton::setTextColor(SDL_Color textColor){
    this->textColor = textColor;
}

void TextButton::setText(string text, int xoff, int yoff) {
    if (this->font != nullptr) {
        this->text = text;
        label->setTextColor(textColor);
        label->setName("label_TextButton_" + GenerateFunctions::uuid());
        label->setSkipMouseEventFrom(true);
        label->setRenderer(appRender);
        // TODO offsets
        int xx,yy;
        TTF_SizeText(font->getFont(), text.c_str(), &xx,&yy);
        label->setX(this->position.x + (this->w - xx)/2 + xoff);
        label->setY(this->position.y + (this->h/tilesY - yy)/2 +yoff);
        label->setText(this->text);
        label->setFont(font);
        SpriteManager::addSprite(label);
    }
}
