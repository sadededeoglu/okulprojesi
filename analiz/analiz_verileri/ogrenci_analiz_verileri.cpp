#include "ogrenci_analiz_verileri.h"

ogrenci_analiz_verileri::ogrenci_analiz_verileri(QObject *parent)
{

}

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

OgrenciProfil::tamsayi ogrenci_analiz_verileri::dersSayisi() const
{
    return _dersSayisi;
}

void ogrenci_analiz_verileri::setDersSayisi(const OgrenciProfil::tamsayi &dersSayisi)
{
    _dersSayisi = dersSayisi;
}

OgrenciProfil::tamsayi ogrenci_analiz_verileri::dersToplami() const
{
    return _dersToplami;
}

void ogrenci_analiz_verileri::setDersToplami(const OgrenciProfil::tamsayi &dersToplami)
{
    _dersToplami = dersToplami;
}

OgrenciProfil::ondalikli ogrenci_analiz_verileri::dersOrtalamasi() const
{
    return _dersOrtalamasi;
}

void ogrenci_analiz_verileri::setDersOrtalamasi(const OgrenciProfil::ondalikli &dersOrtalamasi)
{
    _dersOrtalamasi = dersOrtalamasi;
}

OgrenciProfil::ondalikli ogrenci_analiz_verileri::dersStandartSapmasi() const
{
    return _dersStandartSapmasi;
}

void ogrenci_analiz_verileri::setDersStandartSapmasi(const OgrenciProfil::ondalikli &dersStandartSapmasi)
{
    _dersStandartSapmasi = dersStandartSapmasi;
}
