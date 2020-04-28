#include "ana_pencere.h"
#include "ui_ana_pencere.h"
#include <formlar/veriGiris/yeniogrencigiris.h>
//kapatırken mesaj;
#include <QMessageBox>


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

   auto cevap= QMessageBox::question(this,"çıkış onayı","çıkacak mısın",
                          QMessageBox::Yes | QMessageBox::No,QMessageBox::No );

    if(cevap==QMessageBox::Yes){
        //ata sınıfa ulasabilmek için;
        QMainWindow::close();
    }
}

//yeni orgren giris sıgnal yerinde sağ tus yapıp goto slot sonra triggerd a cift tıkladım geldi burası
void Ana_Pencere::on_actionyeni_ogrenci_ekle_triggered()
{
    yeniOgrenciGiris form;
    //diyalogların görünebilmesi için
    form.exec();
}
