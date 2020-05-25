#include "ana_pencere.h"
#include<veritabani.h>
#include "ui_ana_pencere.h"
#include<QFile>
#include<QFileDialog>
#include<qstring.h>
#include <QMessageBox>  //kapatırken mesaj;
#include <formlar/veriGiris/dersgiris.h>
#include <formlar/veriGiris/notgiris.h>
#include <formlar/veriGiris/ogretmengiris.h>
#include <formlar/veriGiris/yeniogrencigiris.h>
#include <formlar/veriGiris/sinifgiris.h>
#include <formlar/listeleme/ogretmenlistesi.h>



Ana_Pencere::Ana_Pencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ana_Pencere)
{
    ui->setupUi(this);
}
Ana_Pencere::~Ana_Pencere()
{
    delete ui;
}
void Ana_Pencere::close()
{
    //close yapınca pat diye kapatılmasın diye yazıldı

    auto cevap= QMessageBox::question(this,tr("çıkış onayı"),tr("çıkacak mısın"),
                                      QMessageBox::Yes | QMessageBox::No,QMessageBox::No );

    if(cevap==QMessageBox::Yes){
        //ata sınıfa ulasabilmek için;
        QMainWindow::close();
    }
}

//yeni orgren giris sıgnal yerinde sağ tus yapıp goto slot sonra triggerd a cift tıkladım geldi burası
//void Ana_Pencere::on_actionyeni_ogrenci_ekle_triggered()
//{
//    yeniOgrenciGiris form;
//    //diyalogların görünebilmesi için
//    form.exec();
//}


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
//asağıdaki islemlerin aynısını sınıf sayısı için de yap yapılmadı TODO
void Ana_Pencere::on_actionnotEkle_triggered()
{//bu ikisi 0 ise hata vermeli
    auto OgrenciSayisi = VeriTabani::veritabani().ogrenci().filtreyeUyanElemanSayisi(
                [](OgrenciProfil::ptr){return true;});

    auto SinifSayisi = VeriTabani::veritabani().okulSinif().filtreyeUyanElemanSayisi(
                [](Okul_sinif::ptr){return true;});

    while (OgrenciSayisi==0) {
        auto cevap= QMessageBox::question(this,tr("müsteri yok"),tr("yeni müsteri tanımla"),
                                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );

        if(cevap==QMessageBox::No){
            QMessageBox::critical(this,tr("kapatılıyor"),tr("müsteri yok"),
                                  QMessageBox::Ok,
                                  QMessageBox::Ok);
            return;
        }
        on_actionOgrenciEkle_triggered();

        //ogrenci sayısını güncellemeden kapatmasın diye yeniden güncelliyorum
        auto OgrenciSayisi = VeriTabani::veritabani().ogrenci().filtreyeUyanElemanSayisi(
                    [](OgrenciProfil::ptr){return true;});
    }

    notGiris form;
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

void Ana_Pencere::on_actionkaydet_triggered()
{
    QString DosyaAdi=QFileDialog::getSaveFileName(this,tr("dosya seç"),
                                                  qApp->applicationDirPath(),
                                                  tr("veri dos(...)")); //TODO
}

void Ana_Pencere::on_actionac_triggered()
{
    QString DosyaAdi=QFileDialog::getOpenFileName(this,tr("dosya seç"),
                                                  qApp->applicationDirPath(),
                                               tr("veri dos()"));  //TODO
    if(DosyaAdi!=""){
        VeriTabani::veritabani().yukle(DosyaAdi);
    }

}

void Ana_Pencere::on_actionogretmen_listesi_triggered()
{
    OgretmenListesi form;
    form.exec();
}
