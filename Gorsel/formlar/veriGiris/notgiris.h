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
    void on_ekle_clicked();

private slots:
    void on_label_siniflink_linkActivated(const QString &link);
    void on_QPushButton_ekle_clicked();

private:

    void GorselGuncelle(); //pointer daki bilgileri tex box lara aktarır
    void VeriGuncelle();
    bool _Degisiklik;
    void Ogrencicomboboxdoldur();
    void SinifComboboxDoldur();



    Ui::notGiris *ui;
    Notlar::ptr _Notlar;
};

#endif // NOTGIRIS_H
