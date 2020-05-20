#include "notgiris.h"
#include "ui_notgiris.h"
#include <veritabani.h>
#include <algorithm>
#include <qmessagebox.h>
#include<Siniflar/notlar.h>
#include<Siniflar/ogrenciprofil.h>
#include<formlar/veriGiris/notgiris.h>
#include<formlar/veriGiris/sinifgiris.h>
#include<formlar/veriGiris/yeniogrencigiris.h>
#include <Siniflar/okul_sinif.h>

notGiris::notGiris(QWidget *parent) :QDialog(parent),ui(new Ui::notGiris)
{
    ui->setupUi(this);

    this->Ogrencicomboboxdoldur();

    auto _Notlar= VeriTabani::veritabani().notlar().yeni();
    _Degisiklik=false;

    //tüm sınıflar kısmı yapılacak TODO ve link kısmı da yapılacak


}

notGiris::~notGiris()
{
    delete ui;
}

bool notGiris::Degisiklik() const
{
    return _Degisiklik;
}

void notGiris::GorselDegisti()
{
    setDegisiklik(true);
}

void notGiris::reject()
{

}

void notGiris::on_ekle_clicked()
{

}

void notGiris::GorselGuncelle()
{

}

void notGiris::veriGuncelle()
{

}

void notGiris::Ogrencicomboboxdoldur()
{
    auto tumOgrenciler=
            VeriTabani::veritabani().ogrenci().ara([](OgrenciProfil::ptr){return true;});

    //alfabe sırası
    std::sort(tumOgrenciler.begin(),tumOgrenciler.end(),[](OgrenciProfil::ptr a, OgrenciProfil::ptr b){

        if(a->ogrenciAdi()==b->ogrenciAdi()){
            return a->ogrenciSoyadi()<b->ogrenciSoyadi();}
        return a->ogrenciAdi()<b->ogrenciAdi();
    });

    ui->comboBox_ogrenci->clear();//önceden olanları siliyor
    ui->comboBox_ogrenci->addItem(tr("-- ÖĞRENCİ SEÇ --"),-1);
    for(auto OgrenciProfil:tumOgrenciler){  //adıtem 2 parametre ister. gösterilecek metin,veri
        ui->comboBox_ogrenci->addItem(OgrenciProfil->ogrenciAdi()+" "+OgrenciProfil->ogrenciSoyadi(),OgrenciProfil->ogrenciId());
    }


}

void notGiris::SinifComboboxDoldur()
{
    auto Tumsiniflar = VeriTabani::veritabani().okulSinif().ara([](Okul_sinif::ptr){return true;});

    //std::sort(Tumsiniflar.begin() , Tumsiniflar.end() , [](Okul_sinif::ptr a , Okul_sinif::ptr b)) {
    //    if (a->SinifAdi() == b->SinifAdi()) {
    //        //TODO sinif siralamasi yapilacak.
    //    }
    //}
    ui->comboBox_sinif->clear();
    ui->comboBox_sinif->addItem(tr("-- SINIF SEÇ --"));

};

void notGiris::on_label_siniflink_linkActivated(const QString &link)
{
    sinifGiris form;
    form.exec();
    this->Ogrencicomboboxdoldur();
}
