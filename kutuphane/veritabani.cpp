#include "veritabani.h"
#include <qdatastream.h>
#include <qfile.h>

VeriTabani::VeriTabani(QObject *parent) : QObject(parent) {
    connect(&_ogretmen, &Ogretmenyonetim::Eklendi, this,
            &VeriTabani::OgretmenEklendi);
    connect(&_ogrenci, &Ogrenciyonetim::Eklendi, this,
            &VeriTabani::OgrenciEklendi);
    connect(&_notlar, &Notlaryonetim::Eklendi, this, &VeriTabani::NotEklendi);
    connect(&_dersler, &DerslerYonetim::Eklendi, this, &VeriTabani::DersEklendi);
    connect(&_okulSinif, &Okul_sinifyonetim::Eklendi, this,
            &VeriTabani::SinifEklendi);
}

VeriTabani &VeriTabani::veritabani()
{
    static VeriTabani nesne;
    return nesne;
}

Okul_sinifyonetim &VeriTabani::okulSinif() { return _okulSinif; }

Ogretmenyonetim &VeriTabani::ogretmen() { return _ogretmen; }
Ogrenciyonetim &VeriTabani::ogrenci() { return _ogrenci; }
Notlaryonetim &VeriTabani::notlar() { return _notlar; }
DerslerYonetim &VeriTabani::dersler() { return _dersler; }

void VeriTabani::Kaydet(QString dosyaAdi) {
    QFile dosya(dosyaAdi);                  //önce dosya nesnesi olustur
    if (dosya.open(QIODevice::WriteOnly)) { // dosya kayıt yaparken acamama
        // sansımız var o yüzden if içinde
        QDataStream datastream(&dosya); // dosyayla ilişkilendirdik
        _ogretmen.Kaydet(datastream);
        _ogrenci.Kaydet(datastream);
        _dersler.Kaydet(datastream);
        _okulSinif.Kaydet(datastream);
        _notlar.Kaydet(datastream);
        dosya.close();
    }
}

void VeriTabani::Yukle(QString dosyaAdi) {
    QFile dosya(dosyaAdi);                  //önce dosya nesnesi olustur
    if (dosya.open(QIODevice::ReadOnly)) { // dosya kayıt yaparken acamama

        QDataStream datastream(&dosya); // dosyayla ilişkilendirdik
        _ogretmen.Yukle(datastream);
        _ogrenci.Yukle(datastream);
        _dersler.Yukle(datastream);
        _okulSinif.Yukle(datastream);
        _notlar.Yukle(datastream);
        dosya.close();
    }
}
