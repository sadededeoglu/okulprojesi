#ifndef OGRENCI_ANALIZ_H
#define OGRENCI_ANALIZ_H
#include <QObject>
#include <QVector>
#include <analiz_verileri/ogrenci_analiz_verileri.h>
#include "analiz_global.h"

class ANALIZ_EXPORT ogrenci_analiz : public QObject
{
    Q_OBJECT
public:
    explicit ogrenci_analiz(QObject *parent = nullptr);

    typedef ogrenci_analiz_verileri AnalizSonucu;
    typedef QVector<AnalizSonucu> AnalizSonuclari;

    void Hesapla();    

    const AnalizSonuclari &analizSonucListesi() const;

private:
    AnalizSonuclari _analizSonucListesi;
};

#endif // OGRENCI_ANALIZ_H
