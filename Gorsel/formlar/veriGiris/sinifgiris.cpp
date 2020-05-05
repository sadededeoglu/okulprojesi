#include "sinifgiris.h"
#include "ui_sinifgiris.h"

sinifGiris::sinifGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sinifGiris)
{
    ui->setupUi(this);
}

sinifGiris::~sinifGiris()
{
    delete ui;
}
