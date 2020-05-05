#ifndef OGRETMENGIRIS_H
#define OGRETMENGIRIS_H
#include<Siniflar/ogretmenprofil.h>
#include <QDialog>

namespace Ui {
class ogretmenGiris;
}

class ogretmenGiris : public QDialog
{
    Q_OBJECT

public:
    explicit ogretmenGiris(QWidget *parent = nullptr);
    ~ogretmenGiris();

private:
    Ui::ogretmenGiris *ui;

    OgretmenProfil _OgretmenProfil; //bunun ilklendiricisi cpp de eklenecek ama vt düzenlenmesi lazım
};

#endif // OGRETMENGIRIS_H
