#ifndef OGRETMENLISTESI_H
#define OGRETMENLISTESI_H
#include<VeriYonetim/ogretmenyonetim.h>
#include <QDialog>

namespace Ui {
class OgretmenListesi;
}

class OgretmenListesi : public QDialog
{
    Q_OBJECT

public:
    explicit OgretmenListesi(QWidget *parent = nullptr);
    ~OgretmenListesi();

    Ogretmenyonetim::Liste Ogretmenler() const;
    void setOgretmenler(const Ogretmenyonetim::Liste &Ogretmenler);

private:
    void TabloGuncelle();
    void filtreleme();

    Ui::OgretmenListesi *ui;
    Ogretmenyonetim::Liste _Ogretmenler;
};

#endif // OGRETMENLISTESI_H
