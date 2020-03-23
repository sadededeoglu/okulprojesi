#include "okul_sinif.h"

IdTuru Okul_sinif::sinifId() const
{
    return _sinifId;
}

void Okul_sinif::setSinifId(const IdTuru &sinifId)
{
    _sinifId = sinifId;
}

IdTuru Okul_sinif::ogretmenId() const
{
    return _ogretmenId;
}

void Okul_sinif::setOgretmenId(const IdTuru &ogretmenId)
{
    _ogretmenId = ogretmenId;
}

PozitifTamsayi Okul_sinif::Yil() const
{
    return _Yil;
}

void Okul_sinif::setYil(const PozitifTamsayi &Yil)
{
    _Yil = Yil;
}

Metin Okul_sinif::SinifAdi() const
{
    return _SinifAdi;
}

void Okul_sinif::setSinifAdi(const Metin &SinifAdi)
{
    _SinifAdi = SinifAdi;
}

Okul_sinif::Okul_sinif(QObject *parent) : QObject(parent)
{
    
}
