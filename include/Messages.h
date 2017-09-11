#ifndef MESSAGES_H
#define MESSAGES_H

#include "inc_files.h"

class Messages {
public:
    static void addMessage(Message message);
    static vector<Message> letters;
    static bool messageExistsAndRemove(string messageType, string from, bool cursorInSprite);
    static bool messageExists(string messageType, string from, bool cursorInSprite);
};

#endif // MESSAGES_H
