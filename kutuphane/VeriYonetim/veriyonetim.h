#ifndef VERIYONETIM_H
#define VERIYONETIM_H
#include <QVector>
#include <functional>
#include "kutuphane_global.h"

template <class T> class KUTUPHANE_EXPORT Veriyonetim
{
public:
    typedef T Veri;
    typedef typename T::ptr Pointer;
    typedef typename T::IdTuru IdTuru;
    typedef typename T::PozitifTamsayi PozitifTamsayi;
    typedef typename T::tamsayi tamsayi;
    typedef QVector<Pointer> Liste;
    typedef std::function<bool(Pointer)> Filtre;

public:
    Veriyonetim() { _sonId = 0; }

    Pointer yeni() { return T::yeni(); }

    PozitifTamsayi filtreyeUyanElemanSayisi(Filtre f) const {
        PozitifTamsayi sonuc = 0;
        for(auto eleman : _veriler){
            if (f(eleman)){
                sonuc++;
            }
        }
        return sonuc;
    }

    void ekle(Pointer veri) {

        Filtre fonksiyon = [veri](Pointer v) ->bool {
            return v->id() == veri->id();
        };

        PozitifTamsayi elemanSayisi = this->filtreyeUyanElemanSayisi(fonksiyon);
        if (elemanSayisi == 0 ) {
            auto gecici = veri->kopyala();
            _sonId++;
            gecici->setId(_sonId);
            _veriler.append(gecici);
            elemanEklendi(veri);
        }
    }

    void duzenle(Pointer eski, Pointer yeni){
        for(int i=0 ; i < _veriler.size() ; i++){
            if(eski->id() == _veriler[i]->id()) {
                this->_veriler[i] = yeni;
                elemanDegisti(eski, yeni);
            }
        }
    }

    void sil(Pointer silinecek) {
        for(int i=0 ; i < _veriler.size() ; i++){
            if(silinecek->id() == _veriler[i]->id()){
                sil(i);
                return;
            }
        }
    }

    void sil(PozitifTamsayi idx) {
        Pointer ptr = _veriler.takeAt(idx);
        elemanSilindi(ptr);
    }

    Liste ara(Filtre f) const{
        Liste sonuc;
        for(auto eleman : _veriler){
            if(f(eleman)){
                sonuc.append(eleman->kopyala());
            }
        }
        return sonuc;
    }

    Pointer ilkiniBul(Filtre f) const {
        for (auto eleman : _veriler) {
            if(f(eleman)){
                return eleman->kopyala();
            }
        }
        Pointer sonuc(nullptr);
    }



protected:
    Liste _veriler;
    IdTuru _sonId;
    //burdaki erorlar büyük harf yüzündenmiş hallettim

};

#endif // VERIYONETIM_H
