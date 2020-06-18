#include "analizformlari.h"
#include "ui_analizformlari.h"
#include <analiz_verileri/ogrenci_analiz_verileri.h>
#include <analiz_siniflari/ogrenci_analiz.h>
#include <QTableWidgetItem>

analizFormlari::analizFormlari(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::analizFormlari)
{
    ui->setupUi(this);
}

analizFormlari::~analizFormlari()
{
    delete ui;
}

void analizFormlari::tabloGuncelle()
{
    ogrenci_analiz analiz;
    analiz.Hesapla();

    auto analizSonucu = analiz.analizSonucListesi();

    QStringList basliklar;
    basliklar << tr ("ogrenci no") << tr ("adı") << tr ("soyadı") << tr ("not sayısı") << tr ("notlar toplamı") << tr ("notlar ortalaması") << tr ("notlar standart sapması");

}
