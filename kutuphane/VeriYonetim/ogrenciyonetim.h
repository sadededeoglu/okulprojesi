#ifndef OGRENCIYONETIM_H
#define OGRENCIYONETIM_H
#include <QObject>
#include <QDataStream>
#include "veriyonetim.h"
#include "Siniflar/ogrenciprofil.h"

class KUTUPHANE_EXPORT Ogrenciyonetim : public QObject, public Veriyonetim<OgrenciProfil>
{
    Q_OBJECT
public:
    explicit Ogrenciyonetim(QObject *parent = nullptr);

signals:
    void OgrencinEklendi(Pointer ptr);
    void OgrenciSilindi(Pointer ptr);
    void OgrenciDegisti(Pointer eski, Pointer yeni);

};
QDataStream &operator<<(QDataStream&dosya,const OgrenciProfil::ptr &OgrenciProfil);//müşteri alıp q tada ya aktarılacaını söylüuorum
//bu fonk okumak için;
QDataStream &operator<<(QDataStream&dosya,OgrenciProfil::ptr &OgrenciProfil);


#endif // OGRENCIYONETIM_H
