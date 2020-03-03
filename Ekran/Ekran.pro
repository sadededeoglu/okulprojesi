TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../kutuphane/ -lkutuphane
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../kutuphane/ -lkutuphaned
else:unix: LIBS += -L$$OUT_PWD/../kutuphane/ -lkutuphane

INCLUDEPATH += $$PWD/../kutuphane
DEPENDPATH += $$PWD/../kutuphane
