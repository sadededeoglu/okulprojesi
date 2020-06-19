#include "yeniogrencigiris.h"
#include "ui_yeniogrencigiris.h"
#include <veritabani.h>
#include <QMessageBox>
#include <QFileDialog>

yeniOgrenciGiris::yeniOgrenciGiris(QWidget *parent , OgrenciProfil::ptr Ogrenci) :
    QDialog(parent),ui(new Ui::yeniOgrenciGiris)
{
    //BENİM KODLAR
    //ui->setupUi(this);
    //
    //_ogrenci = VeriTabani::veritabani().ogrenci().yeni();
    //
    //_degisiklikVar = false;

    ui->setupUi(this);

    if (Ogrenci != nullptr) {
        _eskiOgrenci = Ogrenci;
        _ogrenci = Ogrenci->Kopyala();
        ui->pushButton_Ekle->setText("Güncelle");
        GorselGuncelle();
    } else {
        _ogrenci = VeriTabani::veritabani().ogrenci().yeni();
    }
    _degisiklikVar = false;

   //QDialog(parent),ui(new Ui::ogretmenGiris){
   //ui->setupUi(this);
   //
   //if(Ogretmen !=nullptr){
   //    _EskiOgretmen= Ogretmen;
   //    _Ogretmenprofil=Ogretmen->Kopyala();
   //    ui->buton_ekle->setText("gunclle");
   //    GorselGuncelle();
   // } else {
   //    _Ogretmenprofil = VeriTabani::veritabani().ogretmen().yeni();
   //    }
   //_Degisiklik = false;
}
yeniOgrenciGiris::~yeniOgrenciGiris()
{
    delete ui;
}
OgrenciProfil::ptr yeniOgrenciGiris::ogrenci() const
{
    return _ogrenci;
}
void yeniOgrenciGiris::setOgrenci(const OgrenciProfil::ptr &ogrenci)
{
    _ogrenci = ogrenci;
}
void yeniOgrenciGiris::GorselGuncelle()
{
    ui->lineEdit_OgrenciAdi->setText(_ogrenci->ogrenciAdi());
    ui->lineEdit_OgrenciSoyadi->setText(_ogrenci->ogrenciSoyadi());
    ui->plainTextEdit_OgrenciAdresi->setPlainText(_ogrenci->ogrenciAdresi());
    ui->spinBox_OgrenciNumarasi->setValue(_ogrenci->ogrenciNo());
}
void yeniOgrenciGiris::VeriGuncelle()
{
    _ogrenci->setOgrenciAdi(ui->lineEdit_OgrenciAdi->text());
    _ogrenci->setOgrenciSoyadi(ui->lineEdit_OgrenciSoyadi->text());
    _ogrenci->setOgrenciAdresi(ui->plainTextEdit_OgrenciAdresi->document()->toPlainText());
    _ogrenci->setOgrenciNo(ui->spinBox_OgrenciNumarasi->value());
}
bool yeniOgrenciGiris::degisiklikVar() const
{
    return _degisiklikVar;
}
void yeniOgrenciGiris::setDegisiklikVar(bool degisiklikVar)
{
    _degisiklikVar = degisiklikVar;
}
void yeniOgrenciGiris::GorselDegisti()
{
    setDegisiklikVar(true);
}
void yeniOgrenciGiris::reject()
{
    if(_degisiklikVar){
        auto cevap = QMessageBox::question(this , "BİLGİ DEĞİŞİKLİĞİ ALGILANDI" , "Değişiklikleri Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
        if (cevap == QMessageBox::No) {
            return;
        }
    }
    QDialog::reject();
}

OgrenciProfil::ptr yeniOgrenciGiris::eskiOgrenci() const
{
    return _eskiOgrenci;
}

void yeniOgrenciGiris::setEskiOgrenci(const OgrenciProfil::ptr &eskiOgrenci)
{
    _eskiOgrenci = eskiOgrenci;
};


void yeniOgrenciGiris::on_pushButton_Ekle_clicked()
{
    VeriGuncelle();

    if (eskiOgrenci() == nullptr) {
        VeriTabani::veritabani().ogrenci().ekle(_ogrenci);

        if(ogrenci()->ogrenciNo() == 0 || ogrenci()->ogrenciAdi() == 0 || ogrenci()->ogrenciSoyadi() == 0 || ogrenci()->ogrenciAdresi() == 0) {
            QMessageBox::critical(this , tr("HATA!") , tr("EKSİK BİLGİ GİRİŞİ") , QMessageBox::Ok);
            return;
        }
        VeriTabani::veritabani().ogrenci().ekle(_ogrenci);
        auto cevap = QMessageBox::question(this , tr("ÖĞRENCİ KAYDI TAMAMLANDI") , tr("Yeni Bir Öğrenci Tanımlamak İster Misiniz?") , QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes);

        if(cevap == QMessageBox::Yes) {
            _ogrenci = VeriTabani::veritabani().ogrenci().yeni();
            GorselGuncelle();
            ui->lineEdit_OgrenciAdi->setFocus();
            setDegisiklikVar(false);
        } else {
            accept();
        }
    } else {
        VeriTabani::veritabani().ogrenci().duzenle(eskiOgrenci() , _ogrenci);
    }
}





