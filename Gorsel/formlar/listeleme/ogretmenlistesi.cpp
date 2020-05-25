#include "ogretmenlistesi.h"
#include "ui_ogretmenlistesi.h"

OgretmenListesi::OgretmenListesi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OgretmenListesi)
{
    ui->setupUi(this);
}

OgretmenListesi::~OgretmenListesi()
{
    delete ui;
}
