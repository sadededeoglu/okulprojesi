#include "ogretmenprofil.h"

IdTuru OgretmenProfil::ogretmenId() const
{
    return _ogretmenId;
}

void OgretmenProfil::setOgretmenId(const IdTuru &ogretmenId)
{
    _ogretmenId = ogretmenId;
}

PozitifTamsayi OgretmenProfil::sicilNo() const
{
    return _sicilNo;
}

void OgretmenProfil::setSicilNo(const PozitifTamsayi &sicilNo)
{
    _sicilNo = sicilNo;
}

Metin OgretmenProfil::ogretmenAdi() const
{
    return _ogretmenAdi;
}

void OgretmenProfil::setOgretmenAdi(const Metin &ogretmenAdi)
{
    _ogretmenAdi = ogretmenAdi;
}

Metin OgretmenProfil::ogretmenSoyadi() const
{
    return _ogretmenSoyadi;
}

void OgretmenProfil::setOgretmenSoyadi(const Metin &ogretmenSoyadi)
{
    _ogretmenSoyadi = ogretmenSoyadi;
}

Metin OgretmenProfil::ogretmenAdresi() const
{
    return _ogretmenAdresi;
}

void OgretmenProfil::setOgretmenAdresi(const Metin &ogretmenAdresi)
{
    _ogretmenAdresi = ogretmenAdresi;
}

OgretmenProfil::OgretmenProfil(QObject *parent) : QObject(parent)
{
    
}
