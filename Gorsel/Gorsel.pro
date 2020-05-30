QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    formlar/listeleme/ogrencilistesi.cpp \
    formlar/listeleme/ogretmenlistesi.cpp \
    formlar/veriGiris/dersgiris.cpp \
    formlar/veriGiris/notgiris.cpp \
    formlar/veriGiris/ogretmengiris.cpp \
    formlar/veriGiris/sinifgiris.cpp \
    formlar/veriGiris/yeniogrencigiris.cpp \
    main.cpp \
    ana_pencere.cpp

HEADERS += \
    ana_pencere.h \
    formlar/listeleme/ogrencilistesi.h \
    formlar/listeleme/ogretmenlistesi.h \
    formlar/veriGiris/dersgiris.h \
    formlar/veriGiris/notgiris.h \
    formlar/veriGiris/ogretmengiris.h \
    formlar/veriGiris/sinifgiris.h \
    formlar/veriGiris/yeniogrencigiris.h

FORMS += \
    ana_pencere.ui \
    formlar/listeleme/ogrencilistesi.ui \
    formlar/listeleme/ogretmenlistesi.ui \
    formlar/veriGiris/dersgiris.ui \
    formlar/veriGiris/notgiris.ui \
    formlar/veriGiris/ogretmengiris.ui \
    formlar/veriGiris/sinifgiris.ui \
    formlar/veriGiris/yeniogrencigiris.ui

TRANSLATIONS += \
    Gorsel_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    kaynaklar.qrc

unix|win32: LIBS += -L$$OUT_PWD/../kutuphane/ -lkutuphane

INCLUDEPATH += $$PWD/../kutuphane
DEPENDPATH += $$PWD/../kutuphane
