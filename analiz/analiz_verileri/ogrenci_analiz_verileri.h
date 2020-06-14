#ifndef OGRENCI_ANALIZ_VERILERI_H
#define OGRENCI_ANALIZ_VERILERI_H

#include <QObject>
#include <Siniflar/dersler.h>
#include <Siniflar/ogrenciprofil.h>

class ogrenci_analiz_verileri
{
    Q_OBJECT
public:
    explicit ogrenci_analiz_verileri(QObject *parent = nullptr);

    OgrenciProfil::IdTuru ogrenciId() const;
    void setOgrenciId(const OgrenciProfil::IdTuru &ogrenciId);

    OgrenciProfil::Metin ogrenciAdi() const;
    void setOgrenciAdi(const OgrenciProfil::Metin &ogrenciAdi);

    OgrenciProfil::Metin ogrenciSoyadi() const;
    void setOgrenciSoyadi(const OgrenciProfil::Metin &ogrenciSoyadi);

    OgrenciProfil::tamsayi dersSayisi() const;
    void setDersSayisi(const OgrenciProfil::tamsayi &dersSayisi);

    OgrenciProfil::tamsayi dersToplami() const;
    void setDersToplami(const OgrenciProfil::tamsayi &dersToplami);

    OgrenciProfil::ondalikli dersOrtalamasi() const;
    void setDersOrtalamasi(const OgrenciProfil::ondalikli &dersOrtalamasi);

    OgrenciProfil::ondalikli dersStandartSapmasi() const;
    void setDersStandartSapmasi(const OgrenciProfil::ondalikli &dersStandartSapmasi);

private:

    OgrenciProfil::IdTuru _ogrenciId;
    OgrenciProfil::Metin _ogrenciAdi;
    OgrenciProfil::Metin _ogrenciSoyadi;
    OgrenciProfil::tamsayi _dersSayisi;
    OgrenciProfil::tamsayi _dersToplami;
    OgrenciProfil::ondalikli _dersOrtalamasi;
    OgrenciProfil::ondalikli _dersStandartSapmasi;

signals:

};

#endif // OGRENCI_ANALIZ_VERILERI_H
