#include "notgiris.h"
#include "ui_notgiris.h"
#include <veritabani.h>
#include <qmessagebox.h>
#include<Siniflar/notlar.h>

notGiris::notGiris(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::notGiris)
{
    ui->setupUi(this);
    _Notlar= VeriTabani::veritabani().notlar().yeni();
    _Degisiklik=false;
}

notGiris::~notGiris()
{
    delete ui;
}

bool notGiris::Degisiklik() const
{
    return _Degisiklik;
}

void notGiris::GorselDegisti()
{
    setDegisiklik(true);
}

void notGiris::reject()
{

}

void notGiris::on_ekle_clicked()
{

}

void notGiris::GorselGuncelle()
{


}

void notGiris::veriGuncelle()
{

}

//ıd isteme burda olmaya baslıyor sonundaaaaaa

/*9. ders 21.47 ye kadar izledim

//ara pointer isteyip bool döndürür

auto tumOgretmenler=
        VeriTabani::veritabani().ogretmen().ara([](OgretmenProfil::ptr){return true;});

for(auto Ogretmen:tumOgretmenler){
 //burda combobox kullanıor neden?
    //1 gösterilecek metin ve ekstra veri isteyebilir
   // ui->comboboxogretmen

} */
