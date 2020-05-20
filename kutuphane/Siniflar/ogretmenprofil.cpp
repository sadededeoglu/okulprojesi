#include "ogretmenprofil.h"

OgretmenProfil::IdTuru OgretmenProfil::ogretmenId() const
{
    return _ogretmenId;
}
void OgretmenProfil::setOgretmenId(const IdTuru &ogretmenId)
{
    _ogretmenId = ogretmenId;
}
OgretmenProfil::PozitifTamsayi OgretmenProfil::sicilNo() const
{
    return _sicilNo;
}
void OgretmenProfil::setSicilNo(const PozitifTamsayi &sicilNo)
{
    if(this->_sicilNo != sicilNo){
        _sicilNo = sicilNo;
        sicilNoDegisti(this->_sicilNo);
    }
}
OgretmenProfil::Metin OgretmenProfil::ogretmenAdi() const
{
    return _ogretmenAdi;
}
void OgretmenProfil::setOgretmenAdi(const Metin &ogretmenAdi)
{
    if(this->_ogretmenAdi != ogretmenAdi){
        _ogretmenAdi = ogretmenAdi;
        OgretmenAdiDegisti(this->_ogretmenAdi);
    }
}

OgretmenProfil::Metin OgretmenProfil::ogretmenSoyadi() const
{
    return _ogretmenSoyadi;
}
void OgretmenProfil::setOgretmenSoyadi(const Metin &ogretmenSoyadi)
{
    if(this->_ogretmenSoyadi != ogretmenSoyadi){
        _ogretmenSoyadi = ogretmenSoyadi;
        OgretmenSoyadiDegisti(this->_ogretmenSoyadi);
    }
}
OgretmenProfil::Metin OgretmenProfil::ogretmenAdresi() const
{
    return _ogretmenAdresi;
}
void OgretmenProfil::setOgretmenAdresi(const Metin &ogretmenAdresi)
{
    if(this->_ogretmenAdresi != ogretmenAdresi){
        _ogretmenAdresi = ogretmenAdresi;
        OgretmenAdresiDegisti(this->_ogretmenAdresi);
    }
}
OgretmenProfil::OgretmenProfil(QObject *parent) :TemelVeriSinifi(parent)
{
    this->_sicilNo=0;
    this->_ogretmenAdi="";
    this->_ogretmenSoyadi="";
    this->_ogretmenAdresi="";
}
