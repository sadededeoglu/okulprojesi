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
    return dosya;
}
