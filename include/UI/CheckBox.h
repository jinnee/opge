#ifndef CHECKBOX
#define CHECKBOX

#include "../StaticSprite.h"
#include "../TtfFont.h"
#include "../UI/UILabel.h"

class CheckBox : public StaticSprite {
public:
    void render();
    void init();
    void setFont(TtfFont* ttf);
    bool isChecked();
    void setText(string text);
    void setChecked(bool checked);
    CheckBox();
    ~CheckBox();
private:
    TtfFont* ttf;
    bool checked;
    string text;
    UILabel* labelText;
};

#endif // CHECKBOX

