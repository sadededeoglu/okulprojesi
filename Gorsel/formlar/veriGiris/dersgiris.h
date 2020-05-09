#ifndef DERSGIRIS_H
#define DERSGIRIS_H

#include<Siniflar/dersler.h>
#include <QDialog>

namespace Ui {
class dersGiris;
}

class dersGiris : public QDialog
{
    Q_OBJECT

public:
    explicit dersGiris(QWidget *parent = nullptr);
    ~dersGiris();


    bool degisiklikVar() const;
    void setDegisiklikVar(bool degisiklikVar);

public slots:
    void GorselDegisti();
    void reject() override;

private:
    Ui::dersGiris *ui;

    Dersler::ptr _ders;

    void GorselGuncelle();
    void VeriGuncelle();

    bool _degisiklikVar;
};

#endif // DERSGIRIS_H
