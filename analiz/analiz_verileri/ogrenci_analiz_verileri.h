#ifndef OGRENCI_ANALIZ_VERILERI_H
#define OGRENCI_ANALIZ_VERILERI_H

#include <QObject>
#include <Siniflar/notlar.h>
#include <Siniflar/ogrenciprofil.h>

class ogrenci_analiz_verileri : public QObject
{
    Q_OBJECT
public:
    explicit ogrenci_analiz_verileri(QObject *parent = nullptr);
private:

OgrenciProfil::IdTuru _ogrenciId;
OgrenciProfil::Metin _ogrenciAdi;
OgrenciProfil::Metin _ogrenciSoyadi;

signals:

};

#endif // OGRENCI_ANALIZ_VERILERI_H
