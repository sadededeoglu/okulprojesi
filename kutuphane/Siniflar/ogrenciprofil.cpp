#include "ogrenciprofil.h"
#include<qmath.h>


OgrenciProfil::IdTuru OgrenciProfil::sinifId() const
{
    return _sinifId;
}
void OgrenciProfil::setSinifId(const IdTuru &sinifId)
{
    _sinifId = sinifId;
}
OgrenciProfil::IdTuru OgrenciProfil::ogrenciId() const
{
    return _ogrenciId;
}
void OgrenciProfil::setOgrenciId(const IdTuru &ogrenciId)
{
    _ogrenciId = ogrenciId;
}
OgrenciProfil::PozitifTamsayi OgrenciProfil::ogrenciNo() const
{
    return _ogrenciNo;
}
void OgrenciProfil::setOgrenciNo(const PozitifTamsayi &ogrenciNo)
{
    if(this->_ogrenciNo !=ogrenciNo){
    _ogrenciNo = ogrenciNo;
    OgrenciNoDegisti(_ogrenciNo);}
}
OgrenciProfil::Metin OgrenciProfil::ogrenciAdi() const
{
    return _ogrenciAdi;
}
void OgrenciProfil::setOgrenciAdi(const Metin &ogrenciAdi)
{
    if(this->_ogrenciAdi !=ogrenciAdi){
    _ogrenciAdi = ogrenciAdi;
    OgrenciAdiDegisti(_ogrenciAdi);}
}
OgrenciProfil::Metin OgrenciProfil::ogrenciSoyadi() const
{
    return _ogrenciSoyadi;
}
void OgrenciProfil::setOgrenciSoyadi(const Metin &ogrenciSoyadi)
{
    if(this->_ogrenciSoyadi !=ogrenciSoyadi){
    _ogrenciSoyadi = ogrenciSoyadi;
    OgrenciSoyadiDegisti(_ogrenciSoyadi);}
}
OgrenciProfil::Metin OgrenciProfil::ogrenciAdresi() const
{
    return _ogrenciAdresi;
}
void OgrenciProfil::setOgrenciAdresi(const Metin &ogrenciAdresi)
{
    if(this->_ogrenciAdresi !=ogrenciAdresi){
    _ogrenciAdresi = ogrenciAdresi;
    OgrenciAdiDegisti(_ogrenciAdresi);}
}
OgrenciProfil::OgrenciProfil(QObject *parent) :TemelVeriSinifi(parent)
{
    this->_ogrenciNo=0;
    this->_ogrenciAdi="";
    this->_ogrenciSoyadi="";
    this->_ogrenciAdresi="";
}
