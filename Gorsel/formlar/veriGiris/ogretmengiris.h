#ifndef OGRETMENGIRIS_H
#define OGRETMENGIRIS_H
#include<Siniflar/ogretmenprofil.h>
#include <QDialog>
#include <qmessagebox.h>

namespace Ui {
class ogretmenGiris;
}

class ogretmenGiris : public QDialog
{
    Q_OBJECT

public:
    explicit ogretmenGiris(QWidget *parent = nullptr);
    ~ogretmenGiris();

    bool Degisiklik() const;
    void setDegisiklik(bool Degisiklik);

public slots:
     void GorselDegisti();
     void reject() override; //otomatik olarak rejekte isyan ediyoruz.
private:

    void GorselGuncelle(); //pointer daki bilgileri tex box lara aktarır
    void veriGuncelle();
    bool _Degisiklik;

    Ui::ogretmenGiris *ui;

    OgretmenProfil _OgretmenProfil; //bunun ilklendiricisi cpp de eklenecek ama vt düzenlenmesi lazım
};

#endif // OGRETMENGIRIS_H
