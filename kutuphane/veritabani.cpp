#include "veritabani.h"
//eklenecek yer var

VeriTabani::VeriTabani(QObject *parent) : QObject(parent)
{

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
