#include "notlar.h"
#include <math.h>
#include <iostream>

Notlar::IdTuru Notlar::dersId() const
{
    return _DersId;
}
void Notlar::setDersId(const IdTuru &DersId)
{
    _DersId = DersId;
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
Notlar::IdTuru Notlar::sinifId() const
{
    return _sinifId;
}

void Notlar::setSinifId(const IdTuru &sinifId)
{
    _sinifId = sinifId;
}

Notlar::PozitifTamsayi Notlar::ogrenciNotSayisi() const
{
    return _ogrenciNotSayisi;
}

void Notlar::setOgrenciNotSayisi(const PozitifTamsayi &ogrenciNotSayisi)
{
    _ogrenciNotSayisi = ogrenciNotSayisi;
}

Notlar::Notlar(QObject *parent) :TemelVeriSinifi(parent)
{
    this->_ogrenciNot=0;
    this->_ogrenciId=0;
    this->_DersId=0;
    this->_sinifId = 0;
    this->_ogrenciNotSayisi = 0;
}

