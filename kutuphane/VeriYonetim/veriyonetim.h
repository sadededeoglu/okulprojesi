#ifndef VERIYONETIM_H
#define VERIYONETIM_H
#include "kutuphane_global.h"
#include <QDataStream>
#include <QVector>
#include <functional>

template <class T> class Veriyonetim {
public:
  typedef T Veri;
  typedef typename T::ptr Pointer;
  typedef typename T::IdTuru IdTuru;
  typedef typename T::PozitifTamsayi PozitifTamsayi;
  typedef typename T::tamsayi tamsayi;
  typedef QVector<Pointer> Liste;
  typedef std::function<bool(Pointer)> Filtre;

protected:
  Liste _veriler;
  IdTuru _sonId;

public:
  virtual void Eklendi(Pointer ptr) = 0;
  virtual void Silindi(Pointer ptr) = 0;
  virtual void Degisti(Pointer eski, Pointer yeni) = 0;

  Veriyonetim() { _sonId = 0; }

  Pointer yeni() { return T::yeni(); }

  PozitifTamsayi filtreyeUyanElemanSayisi(Filtre f) const {
    PozitifTamsayi sonuc = 0;
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        sonuc++;
      }
    }
    return sonuc;
  }

  void ekle(Pointer veri) {

    Filtre fonksiyon = [veri](Pointer gecici) -> bool {
      return gecici->Id() == veri->Id();
    };

    PozitifTamsayi elemanSayisi = this->filtreyeUyanElemanSayisi(fonksiyon);
    if (elemanSayisi == 0) {
      auto gecici = veri->Kopyala();
      _sonId++;
      gecici->setId(_sonId);
      _veriler.append(gecici);
      ekle(veri);
    }
  }

  void duzenle(Pointer eski, Pointer yeni) {
    for (int i = 0; i < _veriler.size(); i++) {
      if (eski->Id() == _veriler[i]->Id()) {
        this->_veriler[i] = yeni;
        Degisti(eski, yeni);
      }
    }
  }

  void sil(Pointer silinecek) {
    for (int i = 0; i < _veriler.size(); i++) {
      if (silinecek->Id() == _veriler[i]->Id()) {
        sil(i);
        return;
      }
    }
  }

  void sil(PozitifTamsayi idx) {
    Pointer ptr = _veriler.takeAt(idx);
    Silindi(ptr);
  }

  Liste ara(Filtre f) const {
    Liste sonuc;
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        sonuc.append(eleman->Kopyala());
      }
    }
    return sonuc;
  }

  Pointer ilkiniBul(Filtre f) const {
    for (auto eleman : _veriler) {
      if (f(eleman)) {
        return eleman->Kopyala();
      }
    }
    Pointer sonuc(nullptr);
    return sonuc;
  }

  Pointer sonuncuyuBul(Filtre f) const {
    for (auto eleman = _veriler.rbegin(); eleman != _veriler.rend(); eleman++) {
      if (f(*eleman)) {
        return (*eleman)->Kopyala();
      }
    }
    Pointer sonuc(nullptr);
    return sonuc;
  }

  void Kaydet(QDataStream &dosya) { // kaydedilecek iki bilgi var
    // en son kaydettiği ıd 2. veriler
    dosya << this->_sonId << _veriler; // vektor
  }

  void Yukle(QDataStream &dosya) {
      dosya >> _sonId >> _veriler;
  }
};
#endif // VERIYONETIM_H
