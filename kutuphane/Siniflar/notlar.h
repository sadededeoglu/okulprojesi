#ifndef NOTLAR_H
#define NOTLAR_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Notlar : public TemelVeriSinifi
{
    Q_OBJECT
private:
    IdTuru _DersId;
    IdTuru _ogrenciId;
    IdTuru _notId;
    IdTuru _sinifId;
    PozitifTamsayi _ogrenciNot;
    PozitifTamsayi _ogrenciNotSayisi;

signals:
    void OgrenciNotDegisti(const PozitifTamsayi &ogrenciNot);

    void OgrenciNotSayisiDegisti(const PozitifTamsayi &ogrenciNotSayisi);

    void OgrenciDersIdDegisti(const IdTuru &DerId);

    void OgrenciIdDegisti(const IdTuru &ogrenciId);

    void OgrenciNotIdDegisti(const IdTuru &notId);

    void OgrenciSinifIdDegisti(const IdTuru &sinifId);

public:
    typedef std::shared_ptr<Notlar>ptr;

public:
    explicit Notlar(QObject *parent = nullptr);

    IdTuru dersId() const;
    void setDersId(const IdTuru &DersId);

    IdTuru ogrenciId() const;
    void setOgrenciId(const IdTuru &ogrenciId);

    IdTuru notId() const;
    void setNotId(const IdTuru &notId);

    IdTuru sinifId() const;
    void setSinifId(const IdTuru &sinifId);


    PozitifTamsayi ogrenciNot() const;
    void setOgrenciNot(const PozitifTamsayi &ogrenciNot);

    PozitifTamsayi ogrenciNotSayisi() const;
    void setOgrenciNotSayisi(const PozitifTamsayi &ogrenciNotSayisi);

    inline ondalikli toplamNot() {return _ogrenciNotSayisi * _ogrenciNot;};

     static ptr yeni() {return std::make_shared<Notlar>();}

     ptr Kopyala(){
         ptr kopyalanan=Notlar::yeni();
         kopyalanan->_notId=this->_notId;
         kopyalanan->_DersId=this->_DersId;
         kopyalanan->_ogrenciId=this->_ogrenciId;
         kopyalanan->_ogrenciNot=this->_ogrenciNot;
         kopyalanan->_sinifId = this->_sinifId;
         kopyalanan->_ogrenciNotSayisi = this->_ogrenciNotSayisi;

         return kopyalanan;
     }

     void VeriAktar(ptr diger){
         this->_notId=diger->_notId;
         this->_DersId=diger->_DersId;
         this->_ogrenciId=diger->_ogrenciId;
         this->_ogrenciNot=diger->_ogrenciNot;
         this->_sinifId = diger->_sinifId;
         this->_ogrenciNotSayisi = diger->_ogrenciNotSayisi;
     }


};

#endif // NOTLAR_H
