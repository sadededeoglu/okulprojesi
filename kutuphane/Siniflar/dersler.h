#ifndef DERSLER_H
#define DERSLER_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Dersler : public TemelVeriSinifi
{
    Q_OBJECT
private:
    IdTuru _DersId;
    PozitifTamsayi _yil;
    Metin _DersAdi;
    Metin _dönem;
signals:
    void YilDegisti(const PozitifTamsayi &ogrenciNo);
    void DersAdiDegisti(const Metin &ogrenciAdi);
    void DonemDegisti(const Metin &ogrenciSoyadi);

public:
    typedef std::shared_ptr<Dersler>ptr;

public:
    explicit Dersler(QObject *parent = nullptr);

    IdTuru DersId() const;
    void setDersId(const IdTuru &DersId);

    PozitifTamsayi yil() const;
    void setYil(const PozitifTamsayi &yil);

    Metin DersAdi() const;
    void setDersAdi(const Metin &DersAdi);

    Metin dönem() const;
    void setDönem(const Metin &dönem);

signals:

};

#endif // DERSLER_H
