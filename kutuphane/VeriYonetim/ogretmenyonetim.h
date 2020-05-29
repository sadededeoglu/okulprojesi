#ifndef OGRETMENYONETIM_H
#define OGRETMENYONETIM_H
#include "Siniflar/ogretmenprofil.h"
#include "veriyonetim.h"
#include <QDataStream>
#include <QObject>
#include <kutuphane_global.h>

class KUTUPHANE_EXPORT Ogretmenyonetim : public QObject,
                                         public Veriyonetim<OgretmenProfil> {
  Q_OBJECT
public:
  explicit Ogretmenyonetim(QObject *parent = nullptr);

signals:

  void Eklendi(Pointer ptr);
  void Silindi(Pointer ptr);
  void Degisti(Pointer eski, Pointer yeni);
};

QDataStream &operator<<(QDataStream &dosya , const OgretmenProfil::ptr &OgretmenProfil); // müşteri alıp q tada ya aktarılacaını söylüuorum
// bu fonk okumak için;
QDataStream &operator >> (QDataStream &dosya , OgretmenProfil::ptr &OgretmenProfil);

#endif // OGRETMENYONETIM_H
