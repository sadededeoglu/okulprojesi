#include "dersgiris.h"
#include "ui_dersgiris.h"

#include <veritabani.h>
#include <QMessageBox>

dersGiris::dersGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dersGiris)
{
    ui->setupUi(this);

    _ders = VeriTabani::veritabani().dersler().yeni();

    _degisiklikVar = false;
}

dersGiris::~dersGiris()
{
    delete ui;
}

void dersGiris::GorselGuncelle()
{
    ui->lineEdit_DersAdi->setText(_ders->DersAdi());
    ui->spinBox_Donem->setValue(_ders->donem());
    ui->spinBox_DersYili->setValue(_ders->yil());
}

void dersGiris::VeriGuncelle()
{
    _ders->setDersAdi(ui->lineEdit_DersAdi->text());
    _ders->setYil(ui->spinBox_DersYili->value());
    _ders->setDonem(ui->spinBox_Donem->value());
}

bool dersGiris::degisiklikVar() const
{
    return _degisiklikVar;
}

void dersGiris::setDegisiklikVar(bool degisiklikVar)
{
    _degisiklikVar = degisiklikVar;
}

void dersGiris::GorselDegisti()
{
    setDegisiklikVar(true);
}

void dersGiris::reject()
{
    if(_degisiklikVar){
        auto cevap = QMessageBox::question(this , "Bilgi Değişikliği Algılandı" , "Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
        if(cevap == QMessageBox::No){
            return;
        }
    }
    QDialog::reject();
}


void dersGiris::on_pushButton_Ekle_clicked()
{
    VeriGuncelle();
    VeriTabani::veritabani().dersler().ekle(this->_ders);
    auto cevap = QMessageBox::question(this , "Ders Kaydı Tamamlandı" , "Yeni Bir Ders Koymak İster Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes);
    if (cevap == QMessageBox::Yes){
        _ders = VeriTabani::veritabani().dersler().yeni();
        GorselGuncelle();
        ui->lineEdit_DersAdi->setFocus();
        setDegisiklikVar(false);
    } else {
        accept();
    }
}
