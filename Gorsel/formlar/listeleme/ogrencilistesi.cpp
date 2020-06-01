#include "ogrencilistesi.h"
#include "ui_ogrencilistesi.h"
#include <veritabani.h>
#include<QStringList>
#include<QTableWidgetItem>

ogrenciListesi::ogrenciListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogrenciListesi)
{
    ui->setupUi(this);

    this->_ogrenciler = VeriTabani::veritabani().ogrenci().ara([](OgrenciProfil::ptr) {
            return true;
    });
    TabloGuncelle();
}

ogrenciListesi::~ogrenciListesi()
{
    delete ui;
}

void ogrenciListesi::TabloGuncelle()
{
    QStringList Baslik;
    Baslik << tr("No") << tr("Öğrenci Numarası") <<tr("Adı") << tr("Soyadı");
    ui->tableWidget_ogrenci->setColumnCount(4);
    ui->tableWidget_ogrenci->setRowCount(_ogrenciler.count());
    ui->tableWidget_ogrenci->setHorizontalHeaderLabels(Baslik);

    for(int i = 0 ; i < _ogrenciler.count() ; i++) {

        auto hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(this->_ogrenciler[i]->ogrenciId()));
        hucre->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_ogrenci->setItem(i , 0 , hucre);

        hucre = new QTableWidgetItem();
        hucre->setText(tr("%1").arg(this->_ogrenciler[i]->ogrenciNo()));
        hucre->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_ogrenci->setItem(i , 1 , hucre);

        hucre= new QTableWidgetItem();
        hucre->setText(_ogrenciler[i]->ogrenciAdi());
        hucre->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_ogrenci->setItem(i , 2 , hucre);

        hucre= new QTableWidgetItem();
        hucre->setText(_ogrenciler[i]->ogrenciSoyadi());
        hucre->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget_ogrenci->setItem(i , 3 , hucre);
    }
}

void ogrenciListesi::Filtrele()
{
    Ogrenciyonetim::Filtre adFiltreFonksiyonu = [](OgrenciProfil::ptr) {return true;};
    Ogrenciyonetim::Filtre soyadFiltreFonksiyonu = [](OgrenciProfil::ptr) {return true;};
    Ogrenciyonetim::Filtre numaraFiltreFonksiyonu = [](OgrenciProfil::ptr) {return true;};

    if (ui->checkBox_adi->isChecked()) {
        QString aranan = ui->lineEdit_adi->text();
        if (ui->comboBox_adiile->currentIndex() == 0) {
            //ile başlayanlar
            adFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciAdi().toLower().startsWith(aranan.toLower());};
        }
        else if (ui->comboBox_adiile->currentIndex() == 1) {
            //ile bitenler
            adFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciAdi().toLower().endsWith(aranan.toLower());};
        } else {
            //içerenler
            adFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciAdi().toLower().contains(aranan.toLower());};
        }
    }

    if (ui->checkBox_soyadi->isChecked()) {
        QString aranan = ui->lineEdit_adi->text();
        if (ui->comboBox_soyadiile->currentIndex() == 0) {
            //ile başlayanlar
            soyadFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciSoyadi().toLower().startsWith(aranan.toLower());};
        }
        else if (ui->comboBox_soyadiile->currentIndex() == 1) {
            //ile bitenler
            soyadFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciSoyadi().toLower().endsWith(aranan.toLower());};
        } else {
            //içerenler
            adFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman){return eleman->ogrenciAdi().toLower().contains(aranan.toLower());};
        }
    }

    //TODO numara filtre fonksiyonunda sorun labilir emin değilim.
    if (ui->checkBox_numara->isChecked()) {
        auto aranan = ui->spinBox_numara->value();
        numaraFiltreFonksiyonu = [aranan](OgrenciProfil::ptr eleman) {return eleman->ogrenciNo();};
    }

    auto filtreFonksiyonu = [adFiltreFonksiyonu , soyadFiltreFonksiyonu , numaraFiltreFonksiyonu](OgrenciProfil::ptr eleman) {
        return adFiltreFonksiyonu(eleman) && soyadFiltreFonksiyonu(eleman) && numaraFiltreFonksiyonu(eleman);
    };
    this->_ogrenciler=VeriTabani::veritabani().ogrenci().ara(filtreFonksiyonu);
    this->TabloGuncelle();
}

void ogrenciListesi::on_pushButton_ara_clicked()
{
    this->Filtrele();
}
