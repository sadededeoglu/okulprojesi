#ifndef VERIYONETIM_H
#define VERIYONETIM_H

#include <QVector>
#include <functional>

template <class T> class Veriyonetim
{

public:
    typedef T Veri;
    typedef typename T::Ptr Pointer;
    typedef typename T::IdTuru IdTuru;
    typedef typename T::PozitifTamsayi PozitifTamsayi;
    typedef typename T::Tamsayi Tamsayi;
    typedef QVector<Pointer> Liste;
    typedef std::function<bool(Pointer)> FiltreFonksiyonu;

public:
    Veriyonetim();
};

#endif // VERIYONETIM_H
