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
 //ui->tableView_ogretmen->clear();
 QStringList Baslik;
 Baslik <<tr("ogretmen adı")<<tr("soyadı")<<tr("adresi")<<tr("sicil no");
 /*
 ui->tableView_ogretmen->setColumnCount(5);
 ui->tableView_ogretmen.setRowCount(this->_Ogretmenler.count());
 ui->tableView_ogretmen->setHorizontalHeaderLabels(Baslik);*/

 for(int i=0;i<this->_Ogretmenler.count();i++){

    auto hucre=new QTableWidgetItem();
    hucre->setText(tr("%1").arg(this->_Ogretmenler[i]->ogretmenId()));
    hucre->setTextAlignment(Qt::AlignCenter);

   // ui->tableView_ogretmen->setItem(i,0,hucre);


    hucre=new QTableWidgetItem();
    hucre->setText(this->_Ogretmenler[i]->ogretmenAdi());
    hucre->setTextAlignment(Qt::AlignCenter);

    //ui->tableView_ogretmen.setItem(i,1,hucre);

    hucre=new QTableWidgetItem();
    hucre->setText(this->_Ogretmenler[i]->ogretmenSoyadi());
    hucre->setTextAlignment(Qt::AlignCenter);

    //ui->tableView_ogretmen.setItem(i,2,hucre);

    hucre=new QTableWidgetItem();
    hucre->setText(this->_Ogretmenler[i]->ogretmenAdresi());
    hucre->setTextAlignment(Qt::AlignCenter);

    //ui->tableView_ogretmen.setItem(i,3,hucre);

    hucre=new QTableWidgetItem();
    hucre->setText(tr("%1").arg(this->_Ogretmenler[i]->sicilNo()));
    hucre->setTextAlignment(Qt::AlignCenter);

    //ui->tableView_ogretmen.setItem(i,4,hucre);
 }
 //TODO yukarısı calısmıyor dosyaları tam yapmadıgımdan büyük ihtimalle table wiew i tanımıyor
}

void OgretmenListesi::filtreleme()//ekranda yapılan seçimlere göre yapar
{
    auto OgretmenAdifiltreleme = [](OgretmenProfil::ptr){return true;};
    auto OgretmenSoyadifiltreleme = [](OgretmenProfil::ptr){return true;};
    auto SicilNofiltreleme = [](OgretmenProfil::ptr){return true;};

    auto filtreleme = [OgretmenAdifiltreleme,OgretmenSoyadifiltreleme,SicilNofiltreleme](OgretmenProfil::ptr ogretmen){

    return OgretmenAdifiltreleme(ogretmen) && OgretmenSoyadifiltreleme(ogretmen) || SicilNofiltreleme(ogretmen);
    };

    this->_Ogretmenler=VeriTabani::veritabani().ogretmen().ara(filtreleme);

}

Ogretmenyonetim::Liste OgretmenListesi::Ogretmenler() const
{
    return _Ogretmenler;
}

void OgretmenListesi::setOgretmenler(const Ogretmenyonetim::Liste &Ogretmenler)
{
    _Ogretmenler = Ogretmenler;
}
