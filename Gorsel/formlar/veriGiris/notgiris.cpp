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


notGiris::notGiris(QWidget *parent) :QDialog(parent),ui(new Ui::notGiris)
{
    ui->setupUi(this);

    this->Ogrencicomboboxdoldur();

    _Notlar= VeriTabani::veritabani().notlar().yeni();
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
    ui->comboBox_ogrenci->addItem(tr("ogrenci sec"),-1);
    for(auto OgrenciProfil:tumOgrenciler){  //adıtem 2 parametre ister. gösterilecek metin,veri
        ui->comboBox_ogrenci->addItem(OgrenciProfil->ogrenciAdi()+" "+OgrenciProfil->ogrenciSoyadi(),OgrenciProfil->ogrenciId());
    }
}

void notGiris::on_label_siniflink_linkActivated(const QString &link)
{
    sinifGiris form;
    form.exec();
    this->Ogrencicomboboxdoldur();
}
