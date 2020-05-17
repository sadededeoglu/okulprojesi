#include "ogretmengiris.h"
#include "ui_ogretmengiris.h"
#include <veritabani.h>
#include <qmessagebox.h>
#include<Siniflar/ogretmenprofil.h>

ogretmenGiris::ogretmenGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogretmenGiris)
{
    ui->setupUi(this);

    _Ogretmenprofil = VeriTabani::veritabani().ogretmen().yeni();

    _Degisiklik = false;


}

ogretmenGiris::~ogretmenGiris()
{
    delete ui;
}

void ogretmenGiris::GorselGuncelle() // nesnesindeki bilgileri ekrana aktarır. görsele ulasmak için ui. yaz
{
    ui->lineEdit_ogretmenadi->setText(_Ogretmenprofil->ogretmenAdi());
    ui->lineEdit_ogretmensoyad->setText(_Ogretmenprofil->ogretmenSoyadi());
    ui->plainTextEdit_adres->setPlainText(_Ogretmenprofil->ogretmenAdresi());
    ui->spinBox_SicilNumarasi->setValue(_Ogretmenprofil->sicilNo());
}

void ogretmenGiris::veriGuncelle()  //ekrandaki bilgiyi nesneye aktarma
{
    _Ogretmenprofil->setOgretmenAdi(ui->lineEdit_ogretmenadi->text());
    _Ogretmenprofil->setOgretmenSoyadi(ui->lineEdit_ogretmensoyad->text());
    _Ogretmenprofil->setOgretmenAdresi(ui->plainTextEdit_adres->document()->toPlainText());
    _Ogretmenprofil->setSicilNo(ui->spinBox_SicilNumarasi->value());
}

void ogretmenGiris::GorselDegisti()
{
    setDegisiklik(true);
}

bool ogretmenGiris::Degisiklik() const
{
    return _Degisiklik;
}

void ogretmenGiris::setDegisiklik(bool Degisiklik)
{
    _Degisiklik = Degisiklik;

}

void ogretmenGiris::reject()
{
    if(_Degisiklik){
        auto cevap = QMessageBox::question(this ,tr("bilgi degisikligi var"),
                                           tr( "değişiklikleri kaydetmeden çıkmakta emin misin"),
                                           QMessageBox::Yes | QMessageBox::No , QMessageBox::No);

        if(cevap==QMessageBox::No){
            return;
        }
    }
    QDialog::reject();
}

void ogretmenGiris::on_ekle_clicked()
{
    veriGuncelle();
    VeriTabani::veritabani().ogretmen().ekle(_Ogretmenprofil);

    auto cevap = QMessageBox::question(this ,tr("Ogretmen Kaydı Tamamlandı"),
                                       tr( "Yeni Bir Ogretmen Tanımlamak İster misiniz?"),
                                       QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes);

    if(cevap== QMessageBox::Yes){
        _Ogretmenprofil= VeriTabani::veritabani().ogretmen().yeni();
        GorselGuncelle();
        ui->lineEdit_ogretmenadi->setFocus();
        setDegisiklik(false);
    }else{
        accept();
    }
}
