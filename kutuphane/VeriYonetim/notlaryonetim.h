#ifndef NOTLARYONETIM_H
#define NOTLARYONETIM_H
#include "Siniflar/notlar.h"
#include "kutuphane_global.h"
#include "veriyonetim.h"
#include <QDataStream>
#include <QObject>

class KUTUPHANE_EXPORT Notlaryonetim : public QObject,
                                       public Veriyonetim<Notlar> {
  Q_OBJECT
public:
  explicit Notlaryonetim(QObject *parent = nullptr);

signals:
  void Eklendi(Pointer ptr);
  void Silindi(Pointer ptr);
  void Degisti(Pointer eski, Pointer yeni);
};



#endif // NOTLARYONETIM_H
