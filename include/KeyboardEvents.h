#ifndef KEYBOARDEVENTS
#define KEYBOARDEVENTS

class KeyboardEvents
{
    public:
    virtual void onKeyDown(Sint16 key) = 0;
    virtual void onKeyUp(Sint16 key) = 0;

};

#endif // KEYBOARDEVENTS

