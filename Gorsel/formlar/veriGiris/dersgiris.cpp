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
    //TODO gorsel guncelle kısmındaki ders yılı olmuyor, yapılacak.
    //ui->lineEdit_DersYili->setText(_ders->yil());
    ui->lineEdit_Donem->setText(_ders->donem());
}

void dersGiris::VeriGuncelle()
{
    _ders->setDersAdi(ui->lineEdit_DersAdi->text());
    //TODO ders yılının veri güncelleme kodu yapılacak , hata veriyor.
    //_ders->setYil(ui->lineEdit_DersYili->text());
    _ders->setDonem(ui->lineEdit_Donem->text());
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

