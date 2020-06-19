#include "ogrenci_analiz_verileri.h"

ogrenci_analiz_verileri::ogrenci_analiz_verileri(QObject *parent){} //TODO  QOBJECT silinmiyor.

OgrenciProfil::IdTuru ogrenci_analiz_verileri::ogrenciId() const
{
    return _ogrenciId;
}

void ogrenci_analiz_verileri::setOgrenciId(const OgrenciProfil::IdTuru &ogrenciId)
{
    _ogrenciId = ogrenciId;
}

OgrenciProfil::Metin ogrenci_analiz_verileri::ogrenciAdi() const
{
    return _ogrenciAdi;
}

void ogrenci_analiz_verileri::setOgrenciAdi(const OgrenciProfil::Metin &ogrenciAdi)
{
    _ogrenciAdi = ogrenciAdi;
}

OgrenciProfil::Metin ogrenci_analiz_verileri::ogrenciSoyadi() const
{
    return _ogrenciSoyadi;
}

void ogrenci_analiz_verileri::setOgrenciSoyadi(const OgrenciProfil::Metin &ogrenciSoyadi)
{
    _ogrenciSoyadi = ogrenciSoyadi;
}

OgrenciProfil::tamsayi ogrenci_analiz_verileri::notSayisi() const
{
    return _notSayisi;
}

void ogrenci_analiz_verileri::setNotSayisi(const OgrenciProfil::tamsayi &notSayisi)
{
    _notSayisi = notSayisi;
}

OgrenciProfil::tamsayi ogrenci_analiz_verileri::notToplami() const
{
    return _notToplami;
}

void ogrenci_analiz_verileri::setNotToplami(const OgrenciProfil::tamsayi &notToplami)
{
    _notToplami = notToplami;
}

OgrenciProfil::ondalikli ogrenci_analiz_verileri::notOrtalamasi() const
{
    return _notOrtalamasi;
}

void ogrenci_analiz_verileri::setNotOrtalamasi(const OgrenciProfil::ondalikli &notOrtalamasi)
{
    _notOrtalamasi = notOrtalamasi;
}

OgrenciProfil::ondalikli ogrenci_analiz_verileri::notStandartSapmasi() const
{
    return _notStandartSapmasi;
}

void ogrenci_analiz_verileri::setNotStandartSapmasi(const OgrenciProfil::ondalikli &notStandartSapmasi)
{
    _notStandartSapmasi = notStandartSapmasi;
}

