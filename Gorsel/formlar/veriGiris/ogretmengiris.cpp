#include "ogretmengiris.h"
#include "ui_ogretmengiris.h"
#include <veritabani.h>
#include <qmessagebox.h>

ogretmenGiris::ogretmenGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogretmenGiris)
{
    ui->setupUi(this);


}

ogretmenGiris::~ogretmenGiris()
{
    delete ui;
}

void ogretmenGiris::GorselGuncelle() // nesnesindeki bilgileri ekrana aktarır. görsele ulasmak için ui. yaz
{
    ui->ogretmenadi->setText(_OgretmenProfil.ogretmenAdi());
    ui->ogretmensoyad->setText(_OgretmenProfil.ogretmenSoyadi());
    //ui->sicilno->setText(_OgretmenProfil.sicilNo()); olmadı nasıl olacak?
    ui->adres->setPlainText(_OgretmenProfil.ogretmenAdresi());
}

void ogretmenGiris::veriGuncelle()  //ekrandaki bilgiyi nesneye aktarma
{
    _OgretmenProfil.setOgretmenAdi(ui->ogretmenadi->text());
    _OgretmenProfil.setOgretmenSoyadi(ui->ogretmensoyad->text());
    _OgretmenProfil.setOgretmenAdresi(ui->adres->document()->toPlainText());
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
