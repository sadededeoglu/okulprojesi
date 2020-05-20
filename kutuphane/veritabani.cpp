#include "veritabani.h"


VeriTabani::VeriTabani(QObject *parent) : QObject(parent)
{
connect(&_ogretmen, &Ogretmenyonetim::OgretmenEklendi, this,&VeriTabani::OgretmenEklendi);
connect(&_ogrenci, &Ogrenciyonetim::OgrencinEklendi,this,&VeriTabani::OgrenciEklendi);
//connect(&_notlar, &Notlaryonetim::NotEklendi,this,&VeriTabani::notlar)
}

Okul_sinifyonetim &VeriTabani::okulSinif()
{
    return _okulSinif;
}
Ogretmenyonetim &VeriTabani::ogretmen()
{
    return _ogretmen;
}
Ogrenciyonetim &VeriTabani::ogrenci()
{
    return _ogrenci;
}
Notlaryonetim &VeriTabani::notlar()
{
    return _notlar;
}
DerslerYonetim &VeriTabani::dersler()
{
    return _dersler;
}
