#include "include/UI/TextButton.h"

TextButton::TextButton(SDL_Renderer* appRender) : Button() {
    textColor = { 220, 1, 70 };
    text = "Text";
    type = Constants::SpriteTypes::TEXT_BUTTON;
    this->appRender = appRender;

    font = new TtfFont();
    font->setSize(24);
    font->setPath(Constants::RESOURCE_DIR + Constants::pathSeparator + "Karina.ttf");
    if(!font->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }
    font->setStyle(TTF_STYLE_BOLD);

    label = new UILabel();


}

TextButton::~TextButton() {
    delete font;
    font = 0;
    delete label;
    label = 0;
}

void TextButton::render() {
    Button::render();
    label->render();
}

void TextButton::setText(string text) {
    this->text = text;
    label->setTextColor(textColor);
    label->setName("label_TextButton_" + GenerateFunctions::uuid());
    label->setSkipMouseEventFrom(true);
    label->setRenderer(appRender);
    // TODO offsets
    label->setX(this->position.x + 13);
    label->setY(this->position.y+7);
    label->setText(this->text);
    label->setFont(font);
    SpriteManager::addSprite(label);
}
