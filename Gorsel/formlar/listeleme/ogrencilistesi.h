#ifndef OGRENCILISTESI_H
#define OGRENCILISTESI_H

#include <QDialog>
#include <VeriYonetim/ogrenciyonetim.h>

namespace Ui {
class ogrenciListesi;
}

class ogrenciListesi : public QDialog
{
    Q_OBJECT

public:
    explicit ogrenciListesi(QWidget *parent = nullptr);
    ~ogrenciListesi();

private slots:

private:
    Ui::ogrenciListesi *ui;

    void TabloGuncelle();
    Ogrenciyonetim::Liste _ogrenciler;

    void Filtrele();
};

#endif // OGRENCILISTESI_H
