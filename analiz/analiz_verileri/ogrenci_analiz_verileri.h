#ifndef OGRENCI_ANALIZ_VERILERI_H
#define OGRENCI_ANALIZ_VERILERI_H
#include <QObject>
#include <Siniflar/notlar.h>
#include <Siniflar/ogrenciprofil.h>
#include <analiz_global.h>

class ANALIZ_EXPORT ogrenci_analiz_verileri {
public:
    explicit ogrenci_analiz_verileri(QObject *parent = nullptr);

    OgrenciProfil::IdTuru ogrenciId() const;
    void setOgrenciId(const OgrenciProfil::IdTuru &ogrenciId);

    OgrenciProfil::Metin ogrenciAdi() const;
    void setOgrenciAdi(const OgrenciProfil::Metin &ogrenciAdi);

    OgrenciProfil::Metin ogrenciSoyadi() const;
    void setOgrenciSoyadi(const OgrenciProfil::Metin &ogrenciSoyadi);

    OgrenciProfil::tamsayi notSayisi() const;
    void setNotSayisi(const OgrenciProfil::tamsayi &notSayisi);

    OgrenciProfil::tamsayi notToplami() const;
    void setNotToplami(const OgrenciProfil::tamsayi &notToplami);

    OgrenciProfil::ondalikli notOrtalamasi() const;
    void setNotOrtalamasi(const OgrenciProfil::ondalikli &notOrtalamasi);

    OgrenciProfil::ondalikli notStandartSapmasi() const;
    void setNotStandartSapmasi(const OgrenciProfil::ondalikli &notStandartSapmasi);

private:

    OgrenciProfil::IdTuru _ogrenciId;
    OgrenciProfil::Metin _ogrenciAdi;
    OgrenciProfil::Metin _ogrenciSoyadi;
    OgrenciProfil::tamsayi _notSayisi;
    OgrenciProfil::tamsayi _notToplami;
    OgrenciProfil::ondalikli _notOrtalamasi;
    OgrenciProfil::ondalikli _notStandartSapmasi;

signals:

};

#endif // OGRENCI_ANALIZ_VERILERI_H
