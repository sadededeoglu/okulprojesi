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









