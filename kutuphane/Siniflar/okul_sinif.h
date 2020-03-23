#ifndef OKUL_SINIF_H
#define OKUL_SINIF_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Okul_sinif : public TemelVeriSinifi
{
    Q_OBJECT
private:
    IdTuru _sinifId;
    IdTuru _ogretmenId;
    PozitifTamsayi _Yil;
    Metin _SinifAdi;

signals:
    void YilDegisti(const PozitifTamsayi &ogrenciNo);
    void SinifAdiDegisti(const Metin &ogrenciAdi);

public:
    typedef std::shared_ptr<Okul_sinif>ptr;
public:
    explicit Okul_sinif(QObject *parent = nullptr);

    IdTuru sinifId() const;
    void setSinifId(const IdTuru &sinifId);

    IdTuru ogretmenId() const;
    void setOgretmenId(const IdTuru &ogretmenId);

    PozitifTamsayi Yil() const;
    void setYil(const PozitifTamsayi &Yil);

    Metin SinifAdi() const;
    void setSinifAdi(const Metin &SinifAdi);

signals:

};

#endif // OKUL_SINIF_H
