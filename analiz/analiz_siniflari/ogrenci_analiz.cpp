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
        auto notlar = VeriTabani::veritabani().notlar().ara([ogrenci](Notlar::ptr notlar){
                return notlar->ogrenciId() == ogrenci->Id();});
        int elemanSayisi = 0;
        OgrenciProfil::ondalikli toplam = 0.0;
        OgrenciProfil::ondalikli ortalama = 0.0;
        OgrenciProfil::ondalikli standartSapma = 0.0;

        for (auto Notlar: notlar) {
            elemanSayisi++;
            toplam += Notlar->toplamNot();
        }
        if (elemanSayisi >= 1) {
            ortalama = toplam / elemanSayisi;
        }
        if(elemanSayisi > 1) {
            for (auto Notlar: notlar) {
                standartSapma += (Notlar->toplamNot() - ortalama) * (Notlar->toplamNot() - ortalama);
            }
            standartSapma = standartSapma / (elemanSayisi - 1);
            standartSapma = qSqrt(standartSapma);
        }
        AnalizSonucu sonuc;
        sonuc.setOgrenciId(ogrenci->Id());
        sonuc.setOgrenciAdi(ogrenci->ogrenciAdi());
        sonuc.setOgrenciSoyadi(ogrenci->ogrenciSoyadi());
        sonuc.setNotSayisi(elemanSayisi);
        sonuc.setNotToplami(toplam);
        sonuc.setNotOrtalamasi(ortalama);
        sonuc.setNotStandartSapmasi(standartSapma);
        _analizSonucListesi.append(sonuc);
    }
}
