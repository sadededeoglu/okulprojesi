#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <veritabani.h>
#include "ana_pencere.h"
#include "ui_ana_pencere.h"
#include <formlar/veriGiris/notgiris.h>
#include <formlar/veriGiris/dersgiris.h>
#include <formlar/veriGiris/sinifgiris.h>
#include <formlar/veriGiris/ogretmengiris.h>
#include <formlar/listeleme/ogrencilistesi.h>
#include <formlar/listeleme/ogretmenlistesi.h>
#include <formlar/veriGiris/yeniogrencigiris.h>

Ana_Pencere::Ana_Pencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ana_Pencere)
{
    ui->setupUi(this);

    QString varsayilanDosyaAdi="veri.movd";
    VeriTabani::veritabani().Yukle(varsayilanDosyaAdi);
}

Ana_Pencere::~Ana_Pencere()
{
    QString varsayilanDosyaAdi="veri.movd";
    VeriTabani::veritabani().Kaydet(varsayilanDosyaAdi);
    delete ui;
}

void Ana_Pencere::close()
{
    //close yapınca aniden kapatılmasın diye yazıldı

    auto cevap= QMessageBox::question(this,tr("çıkış onayı"),tr("çıkacak mısın"),
                                      QMessageBox::Yes | QMessageBox::No,QMessageBox::No );
    if(cevap==QMessageBox::Yes){
        //ata sınıfa ulasabilmek için;
        QMainWindow::close();
    }
}

void Ana_Pencere::on_actionnotEkle_triggered()
{//bu ikisi 0 ise hata vermeli
    auto OgrenciSayisi = VeriTabani::veritabani().ogrenci().filtreyeUyanElemanSayisi(
                [](OgrenciProfil::ptr){return true;});

    auto SinifSayisi = VeriTabani::veritabani().okulSinif().filtreyeUyanElemanSayisi(
                [](Okul_sinif::ptr){return true;});

    while (OgrenciSayisi==0) {
        auto cevap= QMessageBox::question(this,tr("öğrenci yok"),tr("yeni öğrenci tanımla"),
                                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );
        if(cevap==QMessageBox::No){
            QMessageBox::critical(this,tr("kapatılıyor"),tr("öğrenci yok"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);
            return;
        }
        on_actionOgrenciEkle_triggered();

        //ogrenci sayısını güncellemeden kapatmasın diye yeniden güncelliyorum
        auto OgrenciSayisi = VeriTabani::veritabani().ogrenci().filtreyeUyanElemanSayisi(
                    [](OgrenciProfil::ptr){return true;});
    }
    while (SinifSayisi==0) {
        auto cevap= QMessageBox::question(this,tr("sınıf yok"),tr("yeni sınıf tanımla"),
                                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );
        if(cevap==QMessageBox::No){
            QMessageBox::critical(this,tr("kapatılıyor"),tr("sınıf yok"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);
            return;
        }
        on_actionsinifEkle_triggered();

        auto SinifSayisi = VeriTabani::veritabani().okulSinif().filtreyeUyanElemanSayisi(
                    [](Okul_sinif::ptr){return true;});
    }
    notGiris form;
    form.exec();
}

void Ana_Pencere::on_actionkaydet_triggered()
{
    QString DosyaAdi=QFileDialog::getSaveFileName(this,tr("Dosya Seç"),
                                                  qApp->applicationDirPath(),
                                                  tr("Okul Otomasyonu Veri Dosyası(*.oovd)"));
    if(DosyaAdi != ""){
        VeriTabani::veritabani().Kaydet(DosyaAdi);
    }
}

void Ana_Pencere::on_actionac_triggered()
{
    QString DosyaAdi=QFileDialog::getOpenFileName(this,tr("Dosya Seç"),
                                                  qApp->applicationDirPath(),
                                                  tr("Okul Otomasyonu Veri Dosyası(*.oovd)"));
    if(DosyaAdi != ""){
        VeriTabani::veritabani().Yukle(DosyaAdi);
    }
}

void Ana_Pencere::on_actionogretmen_listesi_triggered()
{
    OgretmenListesi form;
    form.exec();
}
void Ana_Pencere::on_actionOgrenci_Listesi_triggered()
{
    ogrenciListesi form;
    form.exec();
}
void Ana_Pencere::on_actionogretmenEkle_triggered()
{
    ogretmenGiris form;
    form.exec();
}
void Ana_Pencere::on_actionsinifEkle_triggered()
{
    sinifGiris form;
    form.exec();
}
void Ana_Pencere::on_actionOgrenciEkle_triggered()
{
    yeniOgrenciGiris form;
    form.exec();
}
void Ana_Pencere::on_actiondersEkle_triggered()
{
    dersGiris form;
    form.exec();
}
