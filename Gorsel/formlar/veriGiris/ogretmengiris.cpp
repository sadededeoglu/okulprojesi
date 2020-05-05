#include "ogretmengiris.h"
#include "ui_ogretmengiris.h"
#include <veritabani.h>

ogretmenGiris::ogretmenGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ogretmenGiris)
{
    ui->setupUi(this);


}

ogretmenGiris::~ogretmenGiris()
{
    delete ui;
}
