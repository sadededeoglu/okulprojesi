#include "notgiris.h"
#include "ui_notgiris.h"
#include <veritabani.h>
#include <algorithm>
#include <QMessageBox>
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

    _Notlar= VeriTabani::veritabani().notlar().yeni();
    _Degisiklik=false;

    //tüm sınıflar kısmı yapılacak TODO ve link kısmı da yapılacak


}

notGiris::~notGiris()
{
    delete ui;
}


void notGiris::GorselDegisti()
{
    setDegisiklik(true);
}

void notGiris::reject()
{
    if(_Degisiklik) {
                auto cevap = QMessageBox::question(this , "Bilgi Değişikliği Algılandı" , "Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
                if (cevap == QMessageBox::No) {
                    return;
                }
    }
     QDialog::reject();
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
    auto tumSiniflar = VeriTabani::veritabani().okulSinif().ara([](Okul_sinif::ptr){return true;});

    std::sort(tumSiniflar.begin() , tumSiniflar.end() , [](Okul_sinif::ptr a, Okul_sinif::ptr b){
        if (a->SinifAdi() > b->SinifAdi()) {
            return a->SinifAdi()>b->SinifAdi();
        }
    });
    ui->comboBox_sinif->clear();
    ui->comboBox_sinif->addItem(tr("-- SINIF SEÇ --") , -1);
    for (auto Okul_sinif:tumSiniflar) {
        ui->comboBox_sinif->addItem(Okul_sinif->SinifAdi() , Okul_sinif->sinifId());
    }
};

void notGiris::on_label_siniflink_linkActivated(const QString &link)
{
    sinifGiris form;
    form.exec();
    this->Ogrencicomboboxdoldur();
}

void notGiris::GorselGuncelle()
{
    //TODO not giriş yapılacak
}

void notGiris::VeriGuncelle()
{

}

bool notGiris::Degisiklik() const
{
    return _Degisiklik;
}

void notGiris::setDegisiklik(bool Degisiklik)
{
    _Degisiklik = Degisiklik;
}


void notGiris::on_QPushButton_ekle_clicked()
{
    setDegisiklik(true);
}
