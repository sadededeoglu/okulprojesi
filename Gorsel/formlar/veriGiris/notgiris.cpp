#include "notgiris.h"
#include "ui_notgiris.h"

notGiris::notGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notGiris)
{
    ui->setupUi(this);
}

notGiris::~notGiris()
{
    delete ui;
}
