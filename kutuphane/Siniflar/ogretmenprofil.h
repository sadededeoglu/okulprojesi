#ifndef OGRETMENPROFIL_H
#define OGRETMENPROFIL_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT OgretmenProfil : public TemelVeriSinifi
{
    Q_OBJECT
private:
    IdTuru _ogretmenId;
    PozitifTamsayi _sicilNo;
    Metin _ogretmenAdi;
    Metin _ogretmenSoyadi;
    Metin _ogretmenAdresi;
signals:
    void sicilNoDegisti(const PozitifTamsayi &ogrenciNo);
    void OgretmenAdiDegisti(const Metin &ogrenciAdi);
    void OgretmenSoyadiDegisti(const Metin &ogrenciSoyadi);
    void OgretmenAdresi(const Metin &ogrenciAdresi);
public:
    typedef std::shared_ptr<OgretmenProfil>ptr;
public:
    explicit OgretmenProfil(QObject *parent = nullptr);



    IdTuru ogretmenId() const;
    void setOgretmenId(const IdTuru &ogretmenId);
    PozitifTamsayi sicilNo() const;
    void setSicilNo(const PozitifTamsayi &sicilNo);
    Metin ogretmenAdi() const;
    void setOgretmenAdi(const Metin &ogretmenAdi);
    Metin ogretmenSoyadi() const;
    void setOgretmenSoyadi(const Metin &ogretmenSoyadi);
    Metin ogretmenAdresi() const;
    void setOgretmenAdresi(const Metin &ogretmenAdresi);
};

#endif // OGRETMENPROFIL_H
