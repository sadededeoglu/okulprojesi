#include "dersler.h"


Dersler::PozitifTamsayi Dersler::yil() const
{
    return _yil;
}

void Dersler::setYil(const PozitifTamsayi &yil)
{
    if(this->_yil !=yil){
        _yil=yil;
        YilDegisti(_yil);}
}

Dersler::Metin Dersler::DersAdi() const
{
    return _DersAdi;
}

void Dersler::setDersAdi(const Metin &DersAdi)
{
    if(this->_DersAdi !=DersAdi){
    _DersAdi = DersAdi;
    DersAdiDegisti(_DersAdi);}
}

Dersler::Metin Dersler::donem() const
{
    return _donem;
}

void Dersler::setDonem(const Metin &donem)
{
    if(this->_donem !=donem){
    _donem = donem;
    DonemDegisti(_donem);}
}

Dersler::IdTuru Dersler::DersId() const
{
    return _DersId;
}

void Dersler::setDersId(const IdTuru &DersId)
{
    _DersId = DersId;
}

Dersler::Dersler(QObject *parent) :TemelVeriSinifi(parent)
{
 this->_yil=0;
 this->_donem="";
 this->_DersAdi="";

}
