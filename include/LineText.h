#ifndef LINETEXT_H
#define LINETEXT_H
#include "BmpFont.h"
#include "StaticSprite.h"

class LineText : public StaticSprite
{
    public:
        LineText();
        virtual ~LineText();
        void render();
        void setFont(BmpFont*);
        void setText(wstring);
        int getHeight();
        int getWidth();
    protected:
        wstring text;
    private:
        BmpFont* bmpFont;
        int width;
        int height;
        int numberOfLetters;
        map<int, int> programFontMap;
        unsigned int textLength;
};

#endif // LINETEXT_H
