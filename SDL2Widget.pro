QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
TARGET = SDL2Widget

DESTDIR = $$PWD/bin

HEADERS += SDL2Widget.h

SOURCES += main.cpp \
           SDL2Widget.cpp


unix|win32: LIBS += -L$$PWD/ThirdParty/lib/ -lSDL2

INCLUDEPATH += $$PWD/ThirdParty/include/SDL2
DEPENDPATH += $$PWD/ThirdParty/include/SDL2

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/ThirdParty/lib/SDL2.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/ThirdParty/lib/libSDL2.a
