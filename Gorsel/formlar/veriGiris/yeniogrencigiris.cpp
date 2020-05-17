#include "yeniogrencigiris.h"
#include "ui_yeniogrencigiris.h"

#include <veritabani.h>
#include <QMessageBox>

yeniOgrenciGiris::yeniOgrenciGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yeniOgrenciGiris)
{
    ui->setupUi(this);

    _ogrenci = VeriTabani::veritabani().ogrenci().yeni();

    _degisiklikVar = false;
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
        auto cevap = QMessageBox::question(this , "Bilgi Değişikliği Algılandı" , "Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
        if (cevap == QMessageBox::No) {
            return;
        }
    }
    QDialog::reject();
}


void yeniOgrenciGiris::on_pushButton_Ekle_clicked()
{
    VeriGuncelle();
    VeriTabani::veritabani().ogrenci().ekle(this->_ogrenci);
    auto cevap = QMessageBox::question(this , "Öğrenci Kaydı Tamamlandı" , "Yeni Bir Öğrenci Tanımlamak İster Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
    if (cevap == QMessageBox::Yes) {
        _ogrenci = VeriTabani::veritabani().ogrenci().yeni();
        GorselGuncelle();
        ui->lineEdit_OgrenciAdi->setFocus();
        setDegisiklikVar(false);
    } else {
        accept();
    }
}
