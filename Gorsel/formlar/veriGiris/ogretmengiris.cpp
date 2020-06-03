#include <QFileDialog>
#include <veritabani.h>
#include <QMessageBox>
#include "ogretmengiris.h"
#include "ui_ogretmengiris.h"


ogretmenGiris::ogretmenGiris(QWidget *parent,OgretmenProfil::ptr Ogretmen)

    :QDialog(parent),ui(new Ui::ogretmenGiris){
     ui->setupUi(this);

     if(Ogretmen !=nullptr){
         _EskiOgretmen= Ogretmen;
         _Ogretmenprofil=Ogretmen->Kopyala();
         ui->buton_ekle->setText("gunclle");
         GorselGuncelle();
     }else {
    _Ogretmenprofil = VeriTabani::veritabani().ogretmen().yeni();
   } _Degisiklik = false;
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
        }}
    QDialog::reject();
}
void ogretmenGiris::ekle(){
    veriGuncelle();//altta ki hata okul sınıf i notlar içinde tanımlamamısız neden

    if(_EskiOgretmen == nullptr){
       VeriTabani::veritabani().ogretmen().ekle(_Ogretmenprofil) ;

       if(_Ogretmenprofil->ogretmenAdi()==0 || _Ogretmenprofil->ogretmenSoyadi()==0 || _Ogretmenprofil->sicilNo()==0 || _Ogretmenprofil->ogretmenAdresi()==0)
       {
           QMessageBox::critical(this,tr("hata"),
                                 tr("eksik bilgi girişi"),
                      QMessageBox::Ok);
           return;
       }
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
    } else {
        VeriTabani::veritabani().ogretmen().duzenle(_EskiOgretmen,_Ogretmenprofil);

}
}

