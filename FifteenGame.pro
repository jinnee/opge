QT -= core
QT -= gui

CONFIG += c++11

TARGET = FifteenGame
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
LIBS += -L/usr/lib -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -ltinyxml2

SOURCES += main.cpp \
    src/AbstractSprite.cpp \
    src/AnimatedSprite.cpp \
    src/Background.cpp \
    src/BmpFont.cpp \
    src/Collision.cpp \
    src/Cursor.cpp \
    src/Functions.cpp \
    src/Game.cpp \
    src/ImageInstruments.cpp \
    src/LineText.cpp \
    src/Messages.cpp \
    src/Music.cpp \
    src/SdlApplication.cpp \
    src/SpriteManager.cpp \
    src/StaticSprite.cpp \
    src/TtfFont.cpp \
    src/UIBaseDialog.cpp \
    src/UI/Button.cpp \
    src/UI/CheckBox.cpp \
    src/UI/UIButton.cpp \
    src/UI/UILabel.cpp \
    src/UI/UIMessageBox.cpp \
    gsrc/FifteenGame.cpp \
    src/GameSettings.cpp \
    vendors/tinyxml2.cpp \
    gsrc/GameState.cpp \
    gsrc/Game15.cpp \
    gsrc/Numbers.cpp \
    src/UI/TextButton.cpp

HEADERS += \
    include/AbstractFont.h \
    include/AbstractGame.h \
    include/AbstractSprite.h \
    include/AnimatedSprite.h \
    include/Background.h \
    include/BmpFont.h \
    include/Collision.h \
    include/Constants.h \
    include/Cursor.h \
    include/Functions.h \
    include/Game.h \
    include/ImageInstruments.h \
    include/inc_files.h \
    include/KeyboardEvents.h \
    include/LineText.h \
    include/Messages.h \
    include/MouseEvents.h \
    include/Music.h \
    include/ObjectToImageMapping.h \
    include/SdlApplication.h \
    include/SpriteManager.h \
    include/StaticSprite.h \
    include/TtfFont.h \
    include/UIBaseDialog.h \
    include/UI/Button.h \
    include/UI/CheckBox.h \
    include/UI/UIButton.h \
    include/UI/UILabel.h \
    include/UI/UIMessageBox.h \
    gsrc/FifteenGame.h \
    include/GameSettings.h \
    vendors/tinyxml2.h \
    gsrc/GameState.h \
    gsrc/Game15.h \
    gsrc/Numbers.h \
    include/UI/TextButton.h
