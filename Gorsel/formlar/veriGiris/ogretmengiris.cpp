#include "ogretmengiris.h"
#include "ui_ogretmengiris.h"

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
