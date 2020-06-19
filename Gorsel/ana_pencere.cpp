#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <veritabani.h>
#include "ana_pencere.h"
#include "ui_ana_pencere.h"
#include <QStandardPaths>
#include <formlar/veriGiris/notgiris.h>
#include <formlar/veriGiris/dersgiris.h>
#include <formlar/veriGiris/sinifgiris.h>
#include <formlar/veriGiris/ogretmengiris.h>
#include <formlar/listeleme/ogrencilistesi.h>
#include <formlar/listeleme/ogretmenlistesi.h>
#include <formlar/veriGiris/yeniogrencigiris.h>
#include <formlar/analizFormlari/analizformlari.h>

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

    auto cevap= QMessageBox::question(this,tr("ÇIKIŞ ONAYI"),tr("Çıkmak İstediğine Emin Misin?"),
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
        auto cevap= QMessageBox::question(this,tr("ÖĞRENCİ BULUNAMADI"),tr("Yeni Öğrenci Tanımlamak İster Misin?"),
                                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );
        if(cevap==QMessageBox::No){
            QMessageBox::critical(this,tr("HATA!"),tr("Öğrenci Bulunamadı"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);
            return;
        }
        on_actionOgrenciEkle_triggered();

        //ogrenci sayısını güncellemeden kapatmasın diye yeniden güncelliyorum
        OgrenciSayisi = VeriTabani::veritabani().ogrenci().filtreyeUyanElemanSayisi(
                    [](OgrenciProfil::ptr){return true;});
    }
    while (SinifSayisi==0) {
        auto cevap= QMessageBox::question(this,tr("SINIF BULUNAMADI"),tr("Yeni Sınıf Tanımlamak İster Misin?"),
                                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );
        if(cevap==QMessageBox::No){
            QMessageBox::critical(this,tr("HATA!"),tr("Sınıf Bulunamadı"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);
            return;
        }
        on_actionsinifEkle_triggered();

        SinifSayisi = VeriTabani::veritabani().okulSinif().filtreyeUyanElemanSayisi(
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

void Ana_Pencere::on_actionistatistikler_triggered()
{
    analizFormlari form;
    form.exec();
}

