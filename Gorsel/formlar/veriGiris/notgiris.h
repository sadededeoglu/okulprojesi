#ifndef NOTGIRIS_H
#define NOTGIRIS_H
#include <Siniflar/notlar.h>
#include<Siniflar/ogrenciprofil.h>
#include <QDialog>

namespace Ui {
class notGiris;
}

class notGiris : public QDialog
{
    Q_OBJECT

public:
    explicit notGiris(QWidget *parent = nullptr);
    ~notGiris();

    bool Degisiklik() const;
    void setDegisiklik(bool Degisiklik);

public slots:
    void GorselDegisti();
    void reject() override;

private slots:
    void on_label_siniflink_linkActivated(const QString &link);    
    void on_label_ogrencilink_linkActivated(const QString &link);

    void on_QPushButton_ekle_clicked();

    void on_label_derslink_linkActivated(const QString &link);

private:
    void GorselGuncelle(); //pointer daki bilgileri tex box lara aktarır.
    void VeriGuncelle();
    bool _Degisiklik;
    void Ogrencicomboboxdoldur();
    void SinifComboboxDoldur();
    void DersComboboxDoldur();

    Ui::notGiris *ui;
    Notlar::ptr _Notlar;

};

#endif // NOTGIRIS_H
