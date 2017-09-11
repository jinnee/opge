#ifndef CONSTANTS_H
#define CONSTANTS_H

struct Message {
    string from;
    string to;
    string type;
    string data;
};

namespace Constants {
    const string RESOURCE_DIR = "resources";
    namespace SpriteTypes {
        const string ABSTRACT_SPRITE = "ABSTRACT_SPRITE";
        const string ANIMATED_SPRITE = "ANIMATED_SPRITE";
        const string STATIC_SPRITE = "STATIC_SPRITE";
        const string MOUSE_CURSOR = "MOUSE_CURSOR";
        const string UI_BUTTON = "UI_BUTTON";
        const string UI_CHECKBOX = "UI_CHECKBOX";
        const string UI_BUTTONX = "UI_BUTTONX";
        const string UI_LABEL = "UI_LABEL";
        const string TEXT_BUTTON = "TEXT_BUTTON";
        const string LINE_TEXT = "LINE_TEXT";
        const string BACKGROUND = "BACKGROUND";
        const string TTF_FONT = "TTF_FONT";
        const string BMP_FONT = "BMP_FONT";
    }

    namespace MessageBox {
        const string BUTTON_1 = "BUTTON_1";
        const string BUTTON_2 = "BUTTON_2";
    }

    namespace DialogMessages {
        const string BUTTON_CLOSE = "BUTTON_CLOSE";
        const string BUTTON_SAVE = "BUTTON_SAVE";
    }

    enum BaseDialogPositions{CENTER, TOP_LEFT, TOP_RIGHT, TOP_CENTER };

    enum KeyboardCustomCodes{KEY_ALTL_S = 10000, KEY_CTRL_S = 10100};

    enum ScaleTypes{WIDTH, HEIGHT, BOTH, BOTH_XY};

    enum KeyState{UP, DOWN, PRESSED};

    const string SpriteModal = "MODAL";

    namespace MessageTypes {
        const string MOUSE_LEFT_DOWN = "MOUSE_LEFT_DOWN";
        const string MOUSE_LEFT_UP = "MOUSE_LEFT_UP";
        const string MOUSE_RIGHT_DOWN = "MOUSE_RIGHT_DOWN";
        const string MOUSE_RIGHT_UP = "MOUSE_RIGHT_UP";
        const string MOUSE_LEFT_CLICK = "MOUSE_LEFT_CLICK";
        const string MOUSE_RIGHT_CLICK = "MOUSE_RIGHT_CLICK";
        const string MOVE = "MOVE";
        const string SWAP = "SWAP";
    }

    const string pathSeparator =
    #ifdef _WIN32
        "\\";
    #else
        "/";
    #endif
}
#endif // CONSTANTS_H
