#include "notgiris.h"
#include "ui_notgiris.h"

notGiris::notGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notGiris)
{
    ui->setupUi(this);

    /*9. ders 21.47 ye kadar izledim

    //ara pointer isteyip bool döndürür

    auto tumOgretmenler=
            VeriTabani::veritabani().ogretmen().ara([](OgretmenProfil::ptr){return true;});

    for(auto Ogretmen:tumOgretmenler){
     //burda combobox kullanıor neden?
        //1 gösterilecek metin ve ekstra veri isteyebilir
       // ui->comboboxogretmen

    } */
}

notGiris::~notGiris()
{
    delete ui;
}
