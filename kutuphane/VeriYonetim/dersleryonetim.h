#ifndef DERSLERYONETIM_H
#define DERSLERYONETIM_H
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/dersler.h"
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT DerslerYonetim : public QObject, public Veriyonetim<Dersler>
{
    Q_OBJECT
public:
    explicit DerslerYonetim(QObject *parent = nullptr);

signals:
    void DersEklendi(Pointer ptr);
    void DersSilindi(Pointer ptr);
    void DersDegisti(Pointer eski, Pointer yeni);


};

#endif // DERSLERYONETIM_H
