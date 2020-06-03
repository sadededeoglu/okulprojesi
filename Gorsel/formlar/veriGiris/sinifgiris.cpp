#include <QMessageBox>
#include <veritabani.h>
#include "sinifgiris.h"
#include "ui_sinifgiris.h"
#include <Siniflar/okul_sinif.h>

sinifGiris::sinifGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sinifGiris)
{
    ui->setupUi(this);
    _degisiklikVarMi = false;
}
sinifGiris::~sinifGiris()
{
    delete ui;
}
void sinifGiris::on_pushButton_ekle_clicked()
{
    VeriGuncelle();
    if(_sinif->ogretmenId()==0 || _sinif->SinifAdi()==0 || _sinif->Yil()==0){

        QMessageBox::critical(this,tr("hata"),
                              tr("eksik bilgi girişi"),
                   QMessageBox::Ok);
        return;
    }

    VeriTabani::veritabani().okulSinif().ekle(this->_sinif);
    auto cevap = QMessageBox::question(this , "Öğrenci Kaydı Tamamlandı" , "Yeni Bir Öğrenci Tanımlamak İster Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
    if (cevap == QMessageBox::Yes) {
        _sinif = VeriTabani::veritabani().okulSinif().yeni();
        GorselGuncelle();
        ui->lineEdit_SinifAdi->setFocus();
        //degisiklikVarMi(false);
    } else {
        accept();  }
}
void sinifGiris::gorselDegisti()
{
    setDegisiklikVarMi(true);
}
void sinifGiris::reject()
{
    if(_degisiklikVarMi) {
        auto cevap = QMessageBox::question(this , "Bilgi Değişikliği Algılandı" , "Kaydetmeden Çıkmak İstediğinize Emin Misiniz?" , QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
        if (cevap == QMessageBox::No) {
            return;
    }}
    QDialog::reject();
}
void sinifGiris::GorselGuncelle()
{
    ui->lineEdit_SinifAdi->setText(_sinif->SinifAdi());
    ui->spinBox_yil->setValue(_sinif->Yil());

    if (_sinif->ogretmenId() == 0) {
        ui->comboBox_ogretmen->setCurrentIndex(0);
    }else {
        for (int i = 1 ; i<ui->comboBox_ogretmen->count() ; i++){
            Okul_sinif::IdTuru gizliId = ui->comboBox_ogretmen->itemData(i).toInt();
            if (gizliId == _sinif->ogretmenId()){
                ui->comboBox_ogretmen->setCurrentIndex(i);
                break;
            }}}}

void sinifGiris::VeriGuncelle()
{
    _sinif->setSinifAdi(ui->lineEdit_SinifAdi->text());
    _sinif->setYil(ui->spinBox_yil->value());
}

void sinifGiris::OgretmenComboboxDoldur()
{   
    auto tumOgretmenler=
            VeriTabani::veritabani().ogretmen().ara([](OgretmenProfil::ptr){return true;});

    //alfabe sırası
    std::sort(tumOgretmenler.begin(),tumOgretmenler.end(),[](OgretmenProfil::ptr a, OgretmenProfil::ptr b){

        if(a->ogretmenAdi() == b->ogretmenAdi()){
            return a->ogretmenSoyadi() < b->ogretmenSoyadi();}
        return a->ogretmenAdi()<b->ogretmenAdi();
    });

    ui->comboBox_ogretmen->clear();//önceden olanları siliyor
    ui->comboBox_ogretmen->addItem(tr("-- ÖĞRETMEN SEÇİN --"),0);
    for(auto OgretmenProfil:tumOgretmenler){  //adıtem 2 parametre ister. gösterilecek metin,veri
        ui->comboBox_ogretmen->addItem(OgretmenProfil->ogretmenAdi()+" "+OgretmenProfil->ogretmenSoyadi(),OgretmenProfil->ogretmenId());
   }}

Okul_sinif::ptr sinifGiris::sinif() const
{
    return _sinif;
}
void sinifGiris::setSinif(const Okul_sinif::ptr &sinif)
{
    _sinif = sinif;
}
bool sinifGiris::degisiklikVarMi() const
{
    return _degisiklikVarMi;
}
void sinifGiris::setDegisiklikVarMi(bool degisiklikVarMi)
{
    _degisiklikVarMi = degisiklikVarMi;
}
