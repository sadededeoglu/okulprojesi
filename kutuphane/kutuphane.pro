QT -= gui

TEMPLATE = lib
DEFINES += KUTUPHANE_LIBRARY

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
    Siniflar/dersler.cpp \
    Siniflar/notlar.cpp \
    Siniflar/ogrenciprofil.cpp \
    Siniflar/ogretmenprofil.cpp \
    Siniflar/okul_sinif.cpp \
    Siniflar/temelverisinifi.cpp \
    VeriYonetim/dersleryonetim.cpp \
    VeriYonetim/notlaryonetim.cpp \
    VeriYonetim/ogrenciyonetim.cpp \
    VeriYonetim/ogretmenyonetim.cpp \
    VeriYonetim/okul_sinifyonetim.cpp \
    VeriYonetim/veriyonetim.cpp \
    kutuphane.cpp \
    veritabani.cpp

HEADERS += \
    Siniflar/dersler.h \
    Siniflar/notlar.h \
    Siniflar/ogrenciprofil.h \
    Siniflar/ogretmenprofil.h \
    Siniflar/okul_sinif.h \
    Siniflar/temelverisinifi.h \
    VeriYonetim/dersleryonetim.h \
    VeriYonetim/notlaryonetim.h \
    VeriYonetim/ogrenciyonetim.h \
    VeriYonetim/ogretmenyonetim.h \
    VeriYonetim/okul_sinifyonetim.h \
    VeriYonetim/veriyonetim.h \
    kutuphane_global.h \
    kutuphane.h \
    veritabani.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
