#include <algorithm>
#include "notgiris.h"
#include <QMessageBox>
#include <veritabani.h>
#include "ui_notgiris.h"
#include<Siniflar/notlar.h>
#include <Siniflar/okul_sinif.h>
#include<Siniflar/ogrenciprofil.h>
#include<formlar/veriGiris/notgiris.h>
#include <formlar/veriGiris/sinifgiris.h>
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
    ui->comboBox_ogrenci->addItem(tr("-- ÖĞRENCİ SEÇ --"),0);
    for(auto OgrenciProfil:tumOgrenciler){  //adıtem 2 parametre ister. gösterilecek metin,veri
        ui->comboBox_ogrenci->addItem(OgrenciProfil->ogrenciAdi()+" "+OgrenciProfil->ogrenciSoyadi(),OgrenciProfil->ogrenciId());
    }
}
void notGiris::SinifComboboxDoldur()
{
    auto tumSiniflar = VeriTabani::veritabani().okulSinif().ara([](Okul_sinif::ptr){return true;});

    std::sort(tumSiniflar.begin() , tumSiniflar.end() , [](Okul_sinif::ptr a, Okul_sinif::ptr b){
        if (a->SinifAdi() > b->SinifAdi()) {
            return a->SinifAdi()>b->SinifAdi();}});
    ui->comboBox_sinif->clear();
    ui->comboBox_sinif->addItem(tr("-- SINIF SEÇ --"),0);
    for (auto Okul_sinif:tumSiniflar) {
        ui->comboBox_sinif->addItem(Okul_sinif->SinifAdi() , Okul_sinif->sinifId());
    }}

void notGiris::DersComboboxDoldur()
{
    auto tumDersler=
            VeriTabani::veritabani().dersler().ara([](Dersler::ptr){return true;});

    //alfabe sırası
    std::sort(tumDersler.begin(),tumDersler.end(),[](Dersler::ptr a, Dersler::ptr b){

        if (a->DersAdi() > b->DersAdi()) {
            return a->DersAdi()>b->DersAdi();}});
    ui->comboBox_ders->clear();
    ui->comboBox_ders->addItem(tr("-- DERS SEÇ --"),0);
    for(auto Dersler:tumDersler){
        ui->comboBox_ders->addItem(Dersler->DersAdi(), Dersler->Id());
    }}

void notGiris::on_label_siniflink_linkActivated(const QString &link)
{
    sinifGiris form;
    form.exec();
    this->Ogrencicomboboxdoldur();
}
void notGiris::GorselGuncelle()//baska yerlerden bilgi aktarımı için bu iyi

//okul sınıf için de yapılacak TODO
{

    //if (_siparis->musteriId == 0)
    //                        //ilk eleman seçili hale gelsin
    //                        ui->comboboxMusteri->setcurrentIndex(0);
    //                else
    //                        for(int i = 1 ; i<ui.comboboxMusteri.count() ; i++)
    //                        siparis::ıdTuru gizliId = ui.comboboxMusteri.itemData(i).toInt();
    //                        if(gizliId == _siparis()->musteriId())
    //                                ui->comboboxMusteri->setcurrentIndex(i);
    //                                break;

    if (_Notlar->ogrenciId()==0){
        //ilk eleman seçili olacak
        ui->comboBox_ogrenci->setCurrentIndex(0);
    }else{

        for(int i=1; i<ui->comboBox_ogrenci->count();i++){
            Notlar::IdTuru gizliId=ui->comboBox_ogrenci->itemData(i).toInt();
            if(gizliId==_Notlar->ogrenciId()){//gizli ıd ye erisme
                ui->comboBox_ogrenci->setCurrentIndex(i);
                break;

                /*ui->comboBox_ogrenci->count();//içindeki eleman sayısını verir
                //görünen değerleri;
                ui->comboBox_ogrenci->itemText(2);
                //gizli değerleri
                //ui->spinbox ortalama falan buraya
                //begin oladıgı ıcın for ile*/
            }}}}
void notGiris::VeriGuncelle()
{
_Notlar->setOgrenciId(ui->comboBox_ogrenci->currentData().toInt());
//TODO okul için de

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
    VeriGuncelle();//altta ki hata okul sınıf i notlar içinde tanımlamamısız neden
    if(_Notlar->ogrenciId()==0 || _Notlar->sinifId()==0 || _Notlar->dersId()==0){//bu diğer taraflarda da yapılacak
       QMessageBox::critical(this,tr("HATALI GİRİŞ"),
                             tr("Ögrenci, sınıf veya ders seçilmedi"),
                  QMessageBox::Ok);
       return;
    }
    VeriTabani::veritabani().notlar().ekle(this->_Notlar);
    auto cevap = QMessageBox::question(this , "Ders Kaydı Tamamlandı" , "Yeni Bir Ders Koymak İster Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes);
    if (cevap == QMessageBox::Yes){
        _Notlar = VeriTabani::veritabani().notlar().yeni();
        GorselGuncelle();
       ui->comboBox_ogrenci->setFocus();
        setDegisiklik(false);
    } else {
        accept();
    }
}
