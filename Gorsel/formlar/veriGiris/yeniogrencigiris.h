#ifndef YENIOGRENCIGIRIS_H
#define YENIOGRENCIGIRIS_H
#include <Siniflar/ogrenciprofil.h>
#include <QDialog>

namespace Ui {
class yeniOgrenciGiris;
}

class yeniOgrenciGiris : public QDialog
{
    Q_OBJECT

public:
    explicit yeniOgrenciGiris(QWidget *parent = nullptr , OgrenciProfil::ptr Ogrenci=nullptr);
    ~yeniOgrenciGiris();

    OgrenciProfil::ptr ogrenci() const;
    void setOgrenci(const OgrenciProfil::ptr &ogrenci);

    bool degisiklikVar() const;
    void setDegisiklikVar(bool degisiklikVar);

    OgrenciProfil::ptr eskiOgrenci() const;
    void setEskiOgrenci(const OgrenciProfil::ptr &eskiOgrenci);

public slots:
    void GorselDegisti();
    void reject() override;

private slots:
    void on_pushButton_Ekle_clicked();

private:
    Ui::yeniOgrenciGiris *ui;
    OgrenciProfil::ptr _ogrenci;
    OgrenciProfil::ptr _eskiOgrenci;

    void GorselGuncelle();
    void VeriGuncelle();
    bool _degisiklikVar;
};

#endif // YENIOGRENCIGIRIS_H
