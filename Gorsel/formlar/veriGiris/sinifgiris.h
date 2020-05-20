#ifndef SINIFGIRIS_H
#define SINIFGIRIS_H

#include <Siniflar/okul_sinif.h>
#include <QDialog>

namespace Ui {
class sinifGiris;
}

class sinifGiris : public QDialog
{
    Q_OBJECT

public:
    explicit sinifGiris(QWidget *parent = nullptr);
    ~sinifGiris();

    bool degisiklikVarMi() const;
    void setDegisiklikVarMi(bool degisiklikVarMi);

    Okul_sinif::ptr sinif() const;
    void setSinif(const Okul_sinif::ptr &sinif);

private slots:
    void on_pushButton_ekle_clicked();

public slots:
    void gorselDegisti();
    void reject() override;

private:
    Ui::sinifGiris *ui;

    Okul_sinif::ptr _sinif;

    void GorselGuncelle();
    void VeriGuncelle();

    bool _degisiklikVarMi;
};

#endif // SINIFGIRIS_H
