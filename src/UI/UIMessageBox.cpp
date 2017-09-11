#include "include/UI/UIMessageBox.h"

UIMessageBox::UIMessageBox() {
    name = "EXIT_BOX";
    fontName = "";
    show = false;
    result = {"","","",""};
    tag = Constants::SpriteModal;
    buttonDistanceFromWall = 5;
    button1 = new Button();
    button1->setTag( Constants::SpriteModal);
    button1->setName("btnExitGameQuestionOk");
    SpriteManager::addSprite(button1);

    button2 = new Button();
    button2->setTag( Constants::SpriteModal);

    button2->setName("btnExitGameQuestioncancel");
    SpriteManager::addSprite(button2);

    ttfFont = new TtfFont();
    ttfFont->setSize(24);

    label1 = new UILabel();
    SDL_Color color1;
    color1.r = 254;
    color1.g = 254;
    color1.b = 254;

    label1->setTextColor(color1);
    label2 = new UILabel();
    label2->setTextColor(color1);
}

int UIMessageBox::close(){

}

void UIMessageBox::open(){

}

void UIMessageBox::init(){
    button2->setVisible(false);
    button1->setVisible(false);

    cursor = Cursor::getCursor();

    button1->setX(this->getX() + getScaledWidth() - button1->w - buttonDistanceFromWall);
    button1->setY(this->getY() + getScaledHeight()
                   - button1->h/2 - buttonDistanceFromWall);

    button2->setX(this->getX() + buttonDistanceFromWall);
    button2->setY(this->getY() + getScaledHeight()
                   - button2->h/2 - buttonDistanceFromWall);

    label1->setX(this->getX()+10);
    label1->setY(this->getY()+50);
    label1->setText(text1);
    if(!ttfFont->loadFont()) {
        cout << "Cannot load ttf font." << endl;
    }
    label1->setFont(ttfFont);

}

void UIMessageBox::initResult() {
    result = {"","","",""};
}

void UIMessageBox::render(){
    if (!show) return;
    AbstractSprite::render();
    button1->render();
    button2->render();
    label1->render();

    if (button2->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
        result.data = Constants::MessageBox::BUTTON_1;
        result.from = name;
        result.to = "";
        result.type = "BOX_MSG";
        show = false;
    }
    if (button1->isMouseButtonDown(Constants::MessageTypes::MOUSE_LEFT_DOWN)) {
        result.data = Constants::MessageBox::BUTTON_2;
        result.from = name;
        result.to = "";
        result.type = "BOX_MSG";
        show = false;
    }
}

Message UIMessageBox::getResult() {
    return result;
}

void UIMessageBox::setImageAndClipForButtons(int btnNumber, SDL_Texture* image , SDL_Rect* clip) {
    if (btnNumber == 1) {
        button1->w = clip->w;
        button1->h = clip->h;
        button1->setImage(image);
        button1->setClip(clip);
    } else {
        button2->w = clip->w;
        button2->h = clip->h;
        button2->setImage(image);
        button2->setClip(clip);
    }
}

void UIMessageBox::setRenderer(SDL_Renderer *renderer) {
    AbstractSprite::setRenderer(renderer);
    button1->setRenderer(renderer);
    button2->setRenderer(renderer);
    label1->setRenderer(renderer);
}

void UIMessageBox::setFontName(string fontName){
    this->fontName = fontName;
    ttfFont->setPath(fontName);
}

void UIMessageBox::setTextLines(string text1, string text2){
    this->text1 = text1;
    this->text2 = text2;
}

void UIMessageBox::setShow(bool show){
    this->show = show;
}

bool UIMessageBox::getShow(){
    return this->show;
}

UIMessageBox::~UIMessageBox(){
    delete button1;
    button1 = 0;
    delete button2;
    button2 = 0;
    delete ttfFont;
    ttfFont = 0;
    delete label1;
    label1 = 0;
    delete label2;
    label2 = 0;
}
