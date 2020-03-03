#ifndef TEMELVERISINIFI_H
#define TEMELVERISINIFI_H
#include <memory>
#include "kutuphane_global.h"
#include <QObject>


class KUTUPHANE_EXPORT TemelVeriSinifi : public QObject
{
    Q_OBJECT

public:
    typedef QString Metin;
    typedef unsigned long long IdTuru;
    typedef unsigned int PozitifTamsayi;
    typedef int tamsayi;



public:
    explicit TemelVeriSinifi(QObject *parent = nullptr);

signals:

};

#endif // TEMELVERISINIFI_H
