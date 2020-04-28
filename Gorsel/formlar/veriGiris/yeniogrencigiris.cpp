#include "yeniogrencigiris.h"
#include "ui_yeniogrencigiris.h"

yeniOgrenciGiris::yeniOgrenciGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::yeniOgrenciGiris)
{
    ui->setupUi(this);
}

yeniOgrenciGiris::~yeniOgrenciGiris()
{
    delete ui;
}
