#include "veritabani.h"

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

Notlaryonetim &VeriTabani::notmlar()
{
    return _notmlar;
}

DerslerYonetim &VeriTabani::dersler()
{
    return _dersler;
}
