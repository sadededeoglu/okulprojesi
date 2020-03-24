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
    IdTuru _dersId;
    IdTuru _ogrenciId;
    IdTuru _notId;
    PozitifTamsayi _ogrenciNot;
signals:
    void OgrenciNotDegisti(const PozitifTamsayi &ogrenciNot);

public:
    typedef std::shared_ptr<Notlar>ptr;

public:
    explicit Notlar(QObject *parent = nullptr);

    IdTuru dersId() const;
    void setDersId(const IdTuru &dersId);

    IdTuru ogrenciId() const;
    void setOgrenciId(const IdTuru &ogrenciId);

    IdTuru notId() const;
    void setNotId(const IdTuru &notId);

    PozitifTamsayi ogrenciNot() const;
    void setOgrenciNot(const PozitifTamsayi &ogrenciNot);

     static ptr yeni() {return std::make_shared<Notlar>();}

     ptr kopyala(){
         ptr kopyalanan=Notlar::yeni();
         kopyalanan->_notId=this->_notId;
         kopyalanan->_dersId=this->_dersId;
         kopyalanan->_ogrenciId=this->_ogrenciId;
         kopyalanan->_ogrenciNot=this->_ogrenciNot;

         return kopyalanan;
     }

     void VeriAktar(ptr diger){
         this->_notId=diger->_notId;
         this->_dersId=diger->_dersId;
         this->_ogrenciId=diger->_ogrenciId;
         this->_ogrenciNot=diger->_ogrenciNot;
     }

};

#endif // NOTLAR_H
