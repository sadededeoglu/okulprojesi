#ifndef OGRETMENYONETIM_H
#define OGRETMENYONETIM_H
#include <QObject>
#include <QDataStream>
#include "veriyonetim.h"
#include <kutuphane_global.h>
#include "Siniflar/ogretmenprofil.h"

class KUTUPHANE_EXPORT Ogretmenyonetim : public QObject, public Veriyonetim<OgretmenProfil>
{
    Q_OBJECT
public:
    explicit Ogretmenyonetim(QObject *parent = nullptr);

signals:

    void OgretmenEklendi(Pointer ptr);
    void OgretmenSilindi(Pointer ptr);
    void OgretmenDegisti(Pointer eski, Pointer yeni);
};

QDataStream &operator<<(QDataStream&dosya,const OgretmenProfil::ptr &OgretmenProfil);//müşteri alıp q tada ya aktarılacaını söylüuorum
//bu fonk okumak için;
QDataStream &operator<<(QDataStream&dosya,OgretmenProfil::ptr &OgretmenProfil);


#endif // OGRETMENYONETIM_H
