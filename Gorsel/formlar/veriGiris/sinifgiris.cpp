#include "sinifgiris.h"
#include "ui_sinifgiris.h"
#include <veritabani.h>
#include <QMessageBox>

sinifGiris::sinifGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sinifGiris)
{
    ui->setupUi(this);
    _degisiklikVarMi = false;
}
sinifGiris::~sinifGiris()
{
    delete ui;
}
void sinifGiris::on_pushButton_ekle_clicked()
{
    VeriGuncelle();
    VeriTabani::veritabani().okulSinif().ekle(this->_sinif);
    auto cevap = QMessageBox::question(this , "Öğrenci Kaydı Tamamlandı" , "Yeni Bir Öğrenci Tanımlamak İster Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
    if (cevap == QMessageBox::Yes) {
        _sinif = VeriTabani::veritabani().okulSinif().yeni();
        GorselGuncelle();
        ui->lineEdit_SinifAdi->setFocus();
        //degisiklikVarMi(false);
    } else {
        accept();
    }
}
void sinifGiris::gorselDegisti()
{
    setDegisiklikVarMi(true);
}
void sinifGiris::reject()
{
    if(_degisiklikVarMi) {
        auto cevap = QMessageBox::question(this , "Bilgi Değişikliği Algılandı" , "Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
        if (cevap == QMessageBox::No) {
            return;
        }
    }
    QDialog::reject();
}
void sinifGiris::GorselGuncelle()
{
    ui->lineEdit_SinifAdi->setText(_sinif->SinifAdi());
    ui->spinBox_yil->setValue(_sinif->Yil());
}
void sinifGiris::VeriGuncelle()
{
    _sinif->setSinifAdi(ui->lineEdit_SinifAdi->text());
    _sinif->setYil(ui->spinBox_yil->value());
}
Okul_sinif::ptr sinifGiris::sinif() const
{
    return _sinif;
}
void sinifGiris::setSinif(const Okul_sinif::ptr &sinif)
{
    _sinif = sinif;
}
bool sinifGiris::degisiklikVarMi() const
{
    return _degisiklikVarMi;
}
void sinifGiris::setDegisiklikVarMi(bool degisiklikVarMi)
{
    _degisiklikVarMi = degisiklikVarMi;
}
