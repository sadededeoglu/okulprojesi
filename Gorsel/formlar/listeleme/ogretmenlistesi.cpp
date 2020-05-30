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
    Baslik <<tr("ogretmen adı")<<tr("soyadı")<<tr("sicil no");

    //ui->tableWidget_ogretmen->setColumnCount(3);
    //ui->tableWidget_ogretmen.setRowCount(this->_Ogretmenler.count());
    //ui->tableView_ogretmen->setHorizontalHeaderLabels(Baslik);

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

    Ogretmenyonetim::Filtre OgretmenAdifiltreleme=[](OgretmenProfil::ptr){return true;};
    Ogretmenyonetim::Filtre OgretmenSoyadifiltreleme = [](OgretmenProfil::ptr){return true;};
    Ogretmenyonetim::Filtre SicilNofiltreleme = [](OgretmenProfil::ptr){return true;};

    if(ui->checkBox_adi->isChecked()){
        QString filtrelenen=ui->lineEdit_ad->text();
        if(ui->comboBox_adiile->currentIndex()==0){

            //ile baslayanlar
            OgretmenAdifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
                return ogretmen->ogretmenAdi().toLower().startsWith(filtrelenen.toLower());
            };
        }else if(ui->comboBox_adiile->currentIndex()==1 ){

            //ile bitenler
            OgretmenAdifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
                return ogretmen->ogretmenAdi().toLower().contains(filtrelenen.toLower());
            };
        }else{

            //içerenler
    OgretmenAdifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
        return ogretmen->ogretmenAdi().toLower().startsWith(filtrelenen.toLower());

    };
    if(ui->checkBox_soyadi->isChecked()){
        QString filtrelenen=ui->lineEdit_ad->text();
        if(ui->comboBox_adiile->currentIndex()==0){

        //ile baslayanlar
            OgretmenSoyadifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
                return ogretmen->ogretmenSoyadi().toLower().startsWith(filtrelenen.toLower());
            };
        }else if(ui->comboBox_soyadiile->currentIndex()==1 ){

            //ile bitenler
            OgretmenSoyadifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
                return ogretmen->ogretmenSoyadi().toLower().contains(filtrelenen.toLower());
            };
        }else{

          //içerenler
          OgretmenSoyadifiltreleme=[filtrelenen](OgretmenProfil::ptr ogretmen){
              return ogretmen->ogretmenSoyadi().toLower().startsWith(filtrelenen.toLower());

          };


          auto filtreleme = [OgretmenAdifiltreleme,OgretmenSoyadifiltreleme,SicilNofiltreleme](OgretmenProfil::ptr ogretmen){

              return OgretmenAdifiltreleme(ogretmen) && OgretmenSoyadifiltreleme(ogretmen)&& SicilNofiltreleme(ogretmen);
          };

          this->_Ogretmenler=VeriTabani::veritabani().ogretmen().ara(filtreleme);

}}}}}

void OgretmenListesi::on_pushButton_ara_clicked()
{
    this->filtreleme();
}
