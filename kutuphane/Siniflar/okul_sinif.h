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
    void YilDegisti(const PozitifTamsayi &Yil);
    void SinifAdiDegisti(const Metin &SinifAdi);

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


    static ptr yeni() {return std::make_shared<Okul_sinif>();}

    ptr Kopyala(){
        ptr kopyalanan = Okul_sinif::yeni();
        kopyalanan->_Yil = this->_Yil;
        kopyalanan->_sinifId = this->_sinifId;
        kopyalanan->_SinifAdi = this->_SinifAdi;
        kopyalanan->_ogretmenId = this->_ogretmenId;
     return kopyalanan;}

    void VeriAktar(ptr diger){
        this->_Yil = diger->_Yil;
        this->_sinifId = diger->_sinifId;
        this->_SinifAdi = diger->_SinifAdi;
        this->_ogretmenId = diger->_ogretmenId;
    }
};

#endif // OKUL_SINIF_H
