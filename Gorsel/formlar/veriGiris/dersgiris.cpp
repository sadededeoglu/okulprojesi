#include "dersgiris.h"
#include "ui_dersgiris.h"

dersGiris::dersGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dersGiris)
{
    ui->setupUi(this);
}

dersGiris::~dersGiris()
{
    delete ui;
}
