#ifndef NOTGIRIS_H
#define NOTGIRIS_H
#include <Siniflar/notlar.h>
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

private:

    void GorselGuncelle(); //pointer daki bilgileri tex box lara aktarır
    void veriGuncelle();
    bool _Degisiklik;
    Ui::notGiris *ui;
    Notlar::ptr _Notlar;
};

#endif // NOTGIRIS_H
