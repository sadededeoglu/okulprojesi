#ifndef OGRENCIYONETIM_H
#define OGRENCIYONETIM_H
#include "Siniflar/ogrenciprofil.h"
#include "veriyonetim.h"
#include <QDataStream>
#include <QObject>

class KUTUPHANE_EXPORT Ogrenciyonetim : public QObject,
                                        public Veriyonetim<OgrenciProfil> {
  Q_OBJECT
public:
  explicit Ogrenciyonetim(QObject *parent = nullptr);

signals:
  void Eklendi(Pointer ptr);
  void Silindi(Pointer ptr);
  void Degisti(Pointer eski, Pointer yeni);
};
QDataStream &operator<<(
    QDataStream &dosya,
    const OgrenciProfil::ptr
        &OgrenciProfil); // müşteri alıp q tada ya aktarılacaını söylüuorum
// bu fonk okumak için;
QDataStream &operator>>(QDataStream &dosya, OgrenciProfil::ptr &OgrenciProfil);

#endif // OGRENCIYONETIM_H
