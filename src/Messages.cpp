#include "include/Messages.h"

void Messages::addMessage(Message message){
    letters.push_back(message);
}

bool Messages::messageExistsAndRemove(string messageType, string from, bool cursorInSprite) {
    std::vector<Message>::iterator it = letters.begin();
    // delete all messages for 'from' if cursor not in sprite
    if (!cursorInSprite) {
        while (it != letters.end()) {
            if ((*it).from == from) {
                it = letters.erase(it);
            } else {
                ++it;
            }
        }
    } else {
        // TODO
        for (it = letters.begin(); it != letters.end(); it++) {
            if ((*it).type == messageType && (*it).from == from) {
                letters.erase(it);
                return true;
            }
        }
    }

    return false;
}

bool Messages::messageExists(string messageType, string from, bool cursorInSprite) {
    std::vector<Message>::iterator it = letters.begin();
    for (it = letters.begin(); it != letters.end(); it++) {
        if ((*it).type == messageType && (*it).from == from
                && cursorInSprite) {
            return true;
        }
    }

    return false;
}

vector<Message> Messages::letters;
