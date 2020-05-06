#include "veritabani.h"


VeriTabani::VeriTabani(QObject *parent) : QObject(parent)
{
connect(&_ogretmen, &Ogretmenyonetim::OgretmenEklendi, this,&VeriTabani::OgretmenEklendi);

//hepsi için tek tek aynı connect mi acılacak?
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
    return _notmlar;
}

DerslerYonetim &VeriTabani::dersler()
{
    return _dersler;
}
