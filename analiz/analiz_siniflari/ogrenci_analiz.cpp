#include "ogrenci_analiz.h"
#include <veritabani.h>
#include <QtMath>

ogrenci_analiz::ogrenci_analiz(QObject *parent) : QObject(parent)
{

}

void ogrenci_analiz::Hesapla()
{
    _analizSonucListesi.clear();
    auto ogrenciler = VeriTabani::veritabani().ogrenci().ara([](OgrenciProfil::ptr){return true;});

    for (auto ogrenci: ogrenciler) {

    }
}

void ogrenci_analiz::setAnalizSonucListesi(const AnalizSonuclari &analizSonucListesi)
{
    _analizSonucListesi = analizSonucListesi;
}
