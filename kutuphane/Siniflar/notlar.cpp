#include "notlar.h"

Notlar::IdTuru Notlar::dersId() const
{
    return _dersId;
}

void Notlar::setDersId(const IdTuru &dersId)
{
    _dersId = dersId;
}

Notlar::IdTuru Notlar::ogrenciId() const
{
    return _ogrenciId;
}

void Notlar::setOgrenciId(const IdTuru &ogrenciId)
{
    _ogrenciId = ogrenciId;
}

Notlar::IdTuru Notlar::notId() const
{
    return _notId;
}

void Notlar::setNotId(const IdTuru &notId)
{
    _notId = notId;
}

Notlar::PozitifTamsayi Notlar::ogrenciNot() const
{
    return _ogrenciNot;
}

void Notlar::setOgrenciNot(const PozitifTamsayi &ogrenciNot)
{
    if(this->_ogrenciNot !=ogrenciNot){
    _ogrenciNot = ogrenciNot;
    OgrenciNotDegisti(_ogrenciNot);}
}

Notlar::Notlar(QObject *parent) :TemelVeriSinifi(parent)
{
    this->_ogrenciNot=0;
}
