#ifndef OGRENCI_ANALIZ_H
#define OGRENCI_ANALIZ_H

#include <QObject>
#include <QVector>
#include <analiz_verileri/ogrenci_analiz_verileri.h>
#include "analiz_global.h"

class ogrenci_analiz : public QObject
{
    Q_OBJECT
public:
    explicit ogrenci_analiz(QObject *parent = nullptr);

    void Hesapla();    

    typedef ogrenci_analiz_verileri AnalizSonucu;
    typedef QVector<AnalizSonucu> AnalizSonuclari;

    const AnalizSonuclari &analizSonucListesi() const;

    void setAnalizSonucListesi(const AnalizSonuclari &analizSonucListesi);

private:
    AnalizSonuclari _analizSonucListesi;

signals:

};

#endif // OGRENCI_ANALIZ_H
