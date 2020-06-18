#include "analizformlari.h"
#include "ui_analizformlari.h"
#include <analiz_verileri/ogrenci_analiz_verileri.h>
#include <analiz_siniflari/ogrenci_analiz.h>
#include <QTableWidgetItem>

analizFormlari::analizFormlari(QWidget *parent) :
    QDialog(parent),

    ui(new Ui::analizFormlari){ui->setupUi(this);}

    analizFormlari::~analizFormlari(){delete ui;}

void analizFormlari::tabloGuncelle()
{
    ogrenci_analiz analiz;
    analiz.Hesapla();

    auto analizSonucu = analiz.analizSonucListesi();

    QStringList basliklar;
    basliklar << tr ("ogrenci no") << tr ("adı") << tr ("soyadı")
              << tr ("not sayısı") << tr ("notlar toplamı")
              << tr ("notlar ortalaması") << tr ("notlar standart sapması");

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(analizSonucu.count());
    ui->tableWidget->setHorizontalHeaderLabels(basliklar);

    for (int i = 0; i < analizSonucu.count(); i++) {
      auto hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].ogrenciId()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 0, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].ogrenciAdi()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 1, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].ogrenciSoyadi()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 2, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].notSayisi()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 3, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].notToplami()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 4, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].notOrtalamasi()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 5, hucre);

      hucre = new QTableWidgetItem();
      hucre->setText(tr("%1").arg(analizSonucu[i].notStandartSapmasi()));
      hucre->setTextAlignment(Qt::AlignCenter);
      ui->tableWidget->setItem(i, 6, hucre);
    }
}
