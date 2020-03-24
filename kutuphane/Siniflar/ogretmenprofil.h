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
    void sicilNoDegisti(const PozitifTamsayi &sicilNo);
    void OgretmenAdiDegisti(const Metin &ogretmenAdi);
    void OgretmenSoyadiDegisti(const Metin &ogretmenSoyadi);
    void OgretmenAdresiDegisti(const Metin &ogretmenAdresi);
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


    static ptr yeni() {return std::make_shared<OgretmenProfil>();}

    ptr Kopyala (){
        ptr kopyalanan = OgretmenProfil::yeni();
        kopyalanan->_sicilNo = this->_sicilNo;
        kopyalanan->_ogretmenId = this->_ogretmenId;
        kopyalanan->_ogretmenAdi = this->_ogretmenAdi;
        kopyalanan->_ogretmenAdresi = this->_ogretmenAdresi;
        kopyalanan->_ogretmenSoyadi = this->_ogretmenSoyadi;
    return kopyalanan; }

    void VeriAktar(ptr diger){
        this->_sicilNo = diger->_sicilNo;
        this->_ogretmenId = diger->_ogretmenId;
        this->_ogretmenAdi = diger->_ogretmenAdi;
        this->_ogretmenAdresi = diger->_ogretmenAdresi;
        this->_ogretmenSoyadi = diger->_ogretmenSoyadi;
    }
};

#endif // OGRETMENPROFIL_H
