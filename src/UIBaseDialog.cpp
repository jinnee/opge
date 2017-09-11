#include "include/UIBaseDialog.h"

UIBaseDialog::UIBaseDialog(){
    name = "UI_BASE_WINDOW";
    fontName = "";
    title = "Dialog title";
    show = false;
    result = {"","","",""};
    tag = Constants::SpriteModal;
    ttfFont = new TtfFont();
    ttfFont->setSize(24);
    windowWidth = 0;
    windowHeight = 0;

    labelTitle = new UILabel();
    SDL_Color color = {254, 254, 254};
    labelTitle->setTextColor(color);
}

void UIBaseDialog::init() {
    if(!ttfFont->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }
    int w,h;
    if(TTF_SizeUTF8(ttfFont->getFont(),title.c_str(),&w,&h)) {
        // perhaps print the current TTF_GetError()
        cout << "the string can't be rendered." << endl;
    }

    labelTitle->setX(this->getX()+(this->getScaledWidth() - w)/2);
    labelTitle->setY(this->getY()+5);
    labelTitle->setText(title);
    labelTitle->setFont(ttfFont);
}

void UIBaseDialog::render() {
    AbstractSprite::render();
    labelTitle->render();
}

void UIBaseDialog::setTitle(string title) {
    this->title = title;
}

void UIBaseDialog::setSpriteSheet(ObjectToImageMapping* spriteSheet) {
    this->spriteSheet = spriteSheet;
}

void UIBaseDialog::setPosition(Constants::BaseDialogPositions position){
    if (position == Constants::BaseDialogPositions::CENTER) {
        this->setX((windowWidth - getScaledWidth()) / 2);
        this->setY((windowHeight - getScaledHeight()) / 2);
    }
}

void UIBaseDialog::initResult() {
    result = {"","","",""};
}

void UIBaseDialog::setShow(bool show){
    this->show = show;
}

bool UIBaseDialog::getShow(){
    return this->show;
}

Message UIBaseDialog::getResult() {
    return result;
}

void UIBaseDialog::setRenderer(SDL_Renderer *renderer) {
    AbstractSprite::setRenderer(renderer);
    labelTitle->setRenderer(renderer);
}

void UIBaseDialog::setFontName(string fontName) {
    this->fontName = fontName;
    ttfFont->setPath(fontName);
}

void UIBaseDialog::setWindowWidthHeight(int w, int h) {
    windowWidth = w;
    windowHeight = h;
}

UIBaseDialog::~UIBaseDialog(){
    delete ttfFont;
    ttfFont = 0;
    delete labelTitle;
    labelTitle = 0;
}
