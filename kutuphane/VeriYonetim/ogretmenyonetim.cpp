#include "ogretmenyonetim.h"

Ogretmenyonetim::Ogretmenyonetim(QObject *parent) : QObject(parent)
{

}

QDataStream &operator<<(QDataStream &dosya, const OgretmenProfil::ptr &OgretmenProfil)
{
   //ogretmeni dosyaya yazabilmek için;

    dosya<<OgretmenProfil->ogretmenId()<<OgretmenProfil->ogretmenAdi()<<OgretmenProfil->ogretmenSoyadi()<<
           OgretmenProfil->ogretmenAdresi() <<OgretmenProfil->sicilNo();
    return dosya;
}

QDataStream &operator<<(QDataStream &dosya, OgretmenProfil::ptr &OgretmenProfil)
{
    //5 adet değişkene ihtiyac var
    OgretmenProfil::IdTuru Id;
    OgretmenProfil::Metin _OgretmenAdi,_ogretmenSoyadi,OgretmenAdresi;
    OgretmenProfil::PozitifTamsayi _SicilNo;

    //bunları okuması için

    dosya>>Id>>_OgretmenAdi>>_ogretmenSoyadi>>OgretmenAdresi>>_SicilNo;

    //bu değişkenleri saklayacagım nesneyi olustur;

    auto YeniOgretmen = OgretmenProfil::yeni();

    YeniOgretmen->setId(Id);
    YeniOgretmen->setOgretmenAdi(_OgretmenAdi);
    YeniOgretmen->setOgretmenSoyadi(_ogretmenSoyadi);
    YeniOgretmen->setOgretmenAdresi(OgretmenAdresi);
    YeniOgretmen->setSicilNo(_SicilNo);
//bu fonk dosyadaki bilgileri ogretmene aktarır

    //bilgileri okudugunu göstermek için;
    OgretmenProfil=YeniOgretmen;

    return dosya;
}
