TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp

HEADERS += \
    include/servercontroller.h \
    include/history.h \
    include/profile.h \
    include/message.h
