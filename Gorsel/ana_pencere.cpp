#include "ana_pencere.h"
#include "ui_ana_pencere.h"
#include <QMessageBox>  //kapatırken mesaj;
#include <formlar/veriGiris/dersgiris.h>
#include <formlar/veriGiris/notgiris.h>
#include <formlar/veriGiris/ogretmengiris.h>
#include <formlar/veriGiris/yeniogrencigiris.h>
#include <formlar/veriGiris/sinifgiris.h>


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

void Ana_Pencere::on_actionnotEkle_triggered()
{
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
