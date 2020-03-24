#ifndef OGRENCIPROFIL_H
#define OGRENCIPROFIL_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT OgrenciProfil : public TemelVeriSinifi
{
    Q_OBJECT
private:
    IdTuru _sinifId;
    IdTuru _ogrenciId;
    PozitifTamsayi _ogrenciNo;
    Metin _ogrenciAdi;
    Metin _ogrenciSoyadi;
    Metin _ogrenciAdresi;

signals:
    void OgrenciNoDegisti(const PozitifTamsayi &ogrenciNo);
    void OgrenciAdiDegisti(const Metin &ogrenciAdi);
    void OgrenciSoyadiDegisti(const Metin &ogrenciSoyadi);
    void OgrenciAdresi(const Metin &ogrenciAdresi);

public:
    typedef std::shared_ptr<OgrenciProfil>ptr;

public:
    explicit OgrenciProfil(QObject *parent = nullptr); //var sayılan ilklendirici sanırım



    static ptr yeni() {return std::make_shared<OgrenciProfil>();}

    ptr Kopyala(){
        ptr kopyalanan = OgrenciProfil::yeni();
        kopyalanan->_sinifId = this->_sinifId;
        kopyalanan->_ogrenciId = this->_ogrenciId;
        kopyalanan->_ogrenciNo = this->_ogrenciNo;
        kopyalanan->_ogrenciAdi = this->_ogrenciAdi;
        kopyalanan->_ogrenciAdresi = this->_ogrenciAdresi;
        kopyalanan->_ogrenciSoyadi = this->_ogrenciSoyadi;
     return kopyalanan;}

    void VeriAktar(ptr diger){
        this->_sinifId = diger->_sinifId;
        this->_ogrenciId = diger->_ogrenciId;
        this->_ogrenciNo = diger->_ogrenciNo;
        this->_ogrenciAdi = diger->_ogrenciAdi;
        this->_ogrenciAdresi = diger->_ogrenciAdresi;
        this->_ogrenciSoyadi = diger->_ogrenciSoyadi;  }


    IdTuru sinifId() const;
    void setSinifId(const IdTuru &sinifId);
    IdTuru ogrenciId() const;
    void setOgrenciId(const IdTuru &ogrenciId);
    PozitifTamsayi ogrenciNo() const;
    void setOgrenciNo(const PozitifTamsayi &ogrenciNo);
    Metin ogrenciAdi() const;
    void setOgrenciAdi(const Metin &ogrenciAdi);
    Metin ogrenciSoyadi() const;
    void setOgrenciSoyadi(const Metin &ogrenciSoyadi);
    Metin ogrenciAdresi() const;
    void setOgrenciAdresi(const Metin &ogrenciAdresi);
};

#endif // OGRENCIPROFIL_H
