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
    PozitifTamsayi _donem;
signals:
    void YilDegisti(const PozitifTamsayi &yil);
    void DersAdiDegisti(const Metin &DersAdi);
    void DonemDegisti(const Metin &Donem);

public:
    typedef std::shared_ptr<Dersler>ptr;

public:
    explicit Dersler(QObject *parent = nullptr);

    IdTuru Id() const;
    void setId(const IdTuru &DersId);
    PozitifTamsayi yil() const;
    void setYil(const PozitifTamsayi &yil);
    Metin DersAdi() const;
    void setDersAdi(const Metin &DersAdi);
    PozitifTamsayi donem() const;
    void setDonem(const PozitifTamsayi &donem);

    static ptr yeni() {return std::make_shared<Dersler>();}

    ptr kopyala(){
        ptr kopyalanan=Dersler::yeni();
        kopyalanan->_yil=this->_yil;
        kopyalanan->_donem=this->_donem;
        kopyalanan->_DersId=this->_DersId;
        kopyalanan->_DersAdi=this->_DersAdi;
     return kopyalanan; }

    void VeriAktar(ptr diger){
        this->_yil=diger->_yil;
        this->_donem=diger->_donem;
        this->_DersId=diger->_DersId;
        this->_DersAdi=diger->_DersAdi;

    }
};

#endif // DERSLER_H
