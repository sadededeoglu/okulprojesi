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
    void NotDegisti(const PozitifTamsayi &ogrenciNo);

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

signals:

};

#endif // NOTLAR_H
