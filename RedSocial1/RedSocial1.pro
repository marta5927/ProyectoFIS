TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
           src/message.cpp \
    src/servercontroller.cpp

HEADERS += \
    include/servercontroller.h \
    include/history.h \
    include/profile.h \
    include/message.h
