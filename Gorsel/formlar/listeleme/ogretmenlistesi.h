#ifndef OGRETMENLISTESI_H
#define OGRETMENLISTESI_H
#include<VeriYonetim/ogretmenyonetim.h>
#include <QDialog>

namespace Ui {
class OgretmenListesi;
}
class OgretmenListesi : public QDialog
{ Q_OBJECT

public:
    explicit OgretmenListesi(QWidget *parent = nullptr);
    ~OgretmenListesi();
private slots:
    void on_pushButton_ara_clicked();
    void filtreleme();

private:
    void TabloGuncelle();

    Ui::OgretmenListesi *ui;
    Ogretmenyonetim::Liste _Ogretmenler;
};

#endif // OGRETMENLISTESI_H
