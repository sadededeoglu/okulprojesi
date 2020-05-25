#include "veritabani.h"
#include<qdatastream.h>
#include<qfile.h>

VeriTabani::VeriTabani(QObject *parent) : QObject(parent)
{
connect(&_ogretmen, &Ogretmenyonetim::OgretmenEklendi, this,&VeriTabani::OgretmenEklendi);
connect(&_ogrenci, &Ogrenciyonetim::OgrencinEklendi,this,&VeriTabani::OgrenciEklendi);
connect(&_notlar, &Notlaryonetim::NotEklendi,this,&VeriTabani::NotEklendi);
connect(&_dersler,&DerslerYonetim::DersEklendi,this,&VeriTabani::DersEklendi);
connect(&_okulSinif,&Okul_sinifyonetim::SinifEklendi,this,&VeriTabani::SinifEklendi);
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
void VeriTabani::kaydet(QString dosyaAdi)
{
    QFile dosya(dosyaAdi);//önce dosya nesnesi olustur
    if(dosya.open(QIODevice::WriteOnly)){//dosya kayıt yaparken acamama sansımız var o yüzden if içinde
        QDataStream datastream(&dosya);//dosyayla ilişkilendirdik
        _ogretmen.kaydet(datastream);
        _ogrenci.kaydet(datastream);
        _dersler.kaydet(datastream);
        _okulSinif.kaydet(datastream);
        _notlar.kaydet(datastream);
        dosya.close();
    }}

void VeriTabani::yukle(QString dosyaAdi)
{
//TODO yapılacak
}
