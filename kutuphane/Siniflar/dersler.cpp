#include "dersler.h"

std::shared_ptr<Dersler> Dersler::getPtr() const
{
    return ptr;
}

void Dersler::setPtr(const std::shared_ptr<Dersler> &value)
{
    ptr = value;
}

IdTuru Dersler::DersId() const
{
    return _DersId;
}

void Dersler::setDersId(const IdTuru &DersId)
{
    _DersId = DersId;
}

PozitifTamsayi Dersler::yil() const
{
    return _yil;
}

void Dersler::setYil(const PozitifTamsayi &yil)
{
    _yil = yil;
}

Metin Dersler::DersAdi() const
{
    return _DersAdi;
}

void Dersler::setDersAdi(const Metin &DersAdi)
{
    _DersAdi = DersAdi;
}

Metin Dersler::dönem() const
{
    return _dönem;
}

void Dersler::setDönem(const Metin &dönem)
{
    _dönem = dönem;
}

Dersler::Dersler(QObject *parent) : QObject(parent)
{
    
}
