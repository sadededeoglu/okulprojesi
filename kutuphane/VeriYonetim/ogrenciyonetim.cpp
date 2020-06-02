#include "ogrenciyonetim.h"

Ogrenciyonetim::Ogrenciyonetim(QObject *parent) : QObject(parent)
{

}
QDataStream &operator<<(QDataStream&dosya,const OgrenciProfil::ptr &OgrenciProfil)
{
    dosya<<OgrenciProfil->ogrenciId()<<OgrenciProfil->ogrenciAdi()<<OgrenciProfil->ogrenciSoyadi()<<
    OgrenciProfil->ogrenciAdresi()<<OgrenciProfil->ogrenciNo();
    return dosya;
}

QDataStream &operator>>(QDataStream&dosya,OgrenciProfil::ptr &OgrenciProfil)
{
    OgrenciProfil::IdTuru Id;
    OgrenciProfil::Metin _OgrenciAdi, _ogrenciSoyadi,_OgrenciAdresi;
    OgrenciProfil::PozitifTamsayi _OgrenciNo;

    dosya>>Id>>_OgrenciAdi>>_ogrenciSoyadi>>_OgrenciAdresi>>_OgrenciNo;

    auto YeniOgrenci=OgrenciProfil::yeni();
    YeniOgrenci->setId(Id);
    YeniOgrenci->setOgrenciAdi(_OgrenciAdi);
    YeniOgrenci->setOgrenciSoyadi(_ogrenciSoyadi);
    YeniOgrenci->setOgrenciAdresi(_OgrenciAdresi);
    YeniOgrenci->setOgrenciNo(_OgrenciNo);

    OgrenciProfil=YeniOgrenci;

   return dosya;
}
