#include "ana_pencere.h"
#include "ui_ana_pencere.h"

Ana_Pencere::Ana_Pencere(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Ana_Pencere)
{
    ui->setupUi(this);
}

Ana_Pencere::~Ana_Pencere()
{
    delete ui;
}

