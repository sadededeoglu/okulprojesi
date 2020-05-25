#include "ogretmenlistesi.h"
#include "ui_ogretmenlistesi.h"
#include <veritabani.h>
#include<QStringList>
#include<QTableWidgetItem>

OgretmenListesi::OgretmenListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OgretmenListesi)
{
    ui->setupUi(this);
    this->_Ogretmenler=VeriTabani::veritabani().ogretmen().ara([](OgretmenProfil::ptr){return true;});
    this->TabloGuncelle();
}

OgretmenListesi::~OgretmenListesi()
{
    delete ui;
}

void OgretmenListesi::TabloGuncelle()
{
 QStringList Baslik;
 Baslik <<tr("ogretmen adı")<<tr("soyadı")<<tr("adresi")<<tr("sicil no");

 /*
 ui->tableView_ogretmen->setColumnCount(5);
 ui->tableView_ogretmen.setRowCount(this->_Ogretmenler.count());
 ui->tableView_ogretmen->setHorizontalHeaderLabels(Baslik);*/

 for(int i=0;i<this->_Ogretmenler.count();i++){
    auto hucre=new QTableWidgetItem();
    hucre->setText(tr("%1").arg(this->_Ogretmenler[i]->Id()));
    hucre->setTextAlignment(Qt::AlignCenter);

    //ui->tableView_ogretmen.setItem(i,0,hucre);
 }
 //TODO yukarısı calısmıyor dosyaları tam yapmadıgımdan büyük ihtimalle
}
