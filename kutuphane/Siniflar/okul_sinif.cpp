#include "okul_sinif.h"

Okul_sinif::IdTuru Okul_sinif::sinifId() const
{
    return _sinifId;
}
void Okul_sinif::setSinifId(const IdTuru &sinifId)
{
    _sinifId = sinifId;
}
Okul_sinif::IdTuru Okul_sinif::ogretmenId() const
{
    return _ogretmenId;
}
void Okul_sinif::setOgretmenId(const IdTuru &ogretmenId)
{
    _ogretmenId = ogretmenId;
}
Okul_sinif::PozitifTamsayi Okul_sinif::Yil() const
{
    return _Yil;
}
void Okul_sinif::setYil(const PozitifTamsayi &Yil)
{
    if(this->_Yil != Yil){
        _Yil = Yil;
        YilDegisti(this->_Yil);
    }
}
Okul_sinif::Metin Okul_sinif::SinifAdi() const
{
    return _SinifAdi;
}
void Okul_sinif::setSinifAdi(const Metin &SinifAdi)
{
    if(this->_SinifAdi != SinifAdi){
        _SinifAdi = SinifAdi;
        SinifAdiDegisti(this->_SinifAdi);
    }
}
Okul_sinif::Okul_sinif(QObject *parent) : TemelVeriSinifi(parent)
{
    this->_Yil=0;
    this->_SinifAdi="";
}
