#include "okul_sinifyonetim.h"
#include <QDataStream>

Okul_sinifyonetim::Okul_sinifyonetim(QObject *parent) : QObject(parent)
{

}

QDataStream & operator << (QDataStream &dosya , const Okul_sinif::ptr &Okul_sinif) {
    dosya << Okul_sinif->sinifId() << Okul_sinif->ogretmenId() << Okul_sinif->Yil() << Okul_sinif->SinifAdi();
    return dosya;
}

QDataStream & operator >> (QDataStream &dosya , Okul_sinif::ptr &Okul_sinif) {
    Okul_sinif::IdTuru sinifId , ogretmenId;
    Okul_sinif::PozitifTamsayi yil;
    Okul_sinif::Metin sinifAdi;

    dosya >> sinifId >> ogretmenId >> yil >> sinifAdi;

    auto yeniOkulSinif = Okul_sinif::yeni();

    yeniOkulSinif->setSinifId(sinifId);
    yeniOkulSinif->setOgretmenId(ogretmenId);
    yeniOkulSinif->setYil(yil);
    yeniOkulSinif->setSinifAdi(sinifAdi);

    Okul_sinif = yeniOkulSinif;
    return dosya;
}
