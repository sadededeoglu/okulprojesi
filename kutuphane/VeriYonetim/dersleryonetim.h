#ifndef DERSLERYONETIM_H
#define DERSLERYONETIM_H
#include "Siniflar/dersler.h"
#include "kutuphane_global.h"
#include "veriyonetim.h"
#include <QDataStream>
#include <QObject>

class KUTUPHANE_EXPORT DerslerYonetim : public QObject,
                                        public Veriyonetim<Dersler> {
  Q_OBJECT
public:
  explicit DerslerYonetim(QObject *parent = nullptr);

signals:
  void Eklendi(Pointer ptr);
  void Silindi(Pointer ptr);
  void Degisti(Pointer eski, Pointer yeni);
};

QDataStream & operator << (QDataStream &dosya , const Dersler::ptr &Dersler);
QDataStream & operator >> (QDataStream &dosya , Dersler::ptr &Dersler);


#endif // DERSLERYONETIM_H
