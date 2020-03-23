#include "notlar.h"

IdTuru Notlar::dersId() const
{
    return _dersId;
}

void Notlar::setDersId(const IdTuru &dersId)
{
    _dersId = dersId;
}

IdTuru Notlar::ogrenciId() const
{
    return _ogrenciId;
}

void Notlar::setOgrenciId(const IdTuru &ogrenciId)
{
    _ogrenciId = ogrenciId;
}

IdTuru Notlar::notId() const
{
    return _notId;
}

void Notlar::setNotId(const IdTuru &notId)
{
    _notId = notId;
}

PozitifTamsayi Notlar::ogrenciNot() const
{
    return _ogrenciNot;
}

void Notlar::setOgrenciNot(const PozitifTamsayi &ogrenciNot)
{
    _ogrenciNot = ogrenciNot;
}

Notlar::Notlar(QObject *parent) : QObject(parent)
{
    
}
