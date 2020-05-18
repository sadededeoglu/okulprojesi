#include "notlar.h"
#include <math.h>
#include <iostream>

Notlar::IdTuru Notlar::dersId() const
{
    return _DersId;
}

void Notlar::setDersId(const IdTuru &DersId)
{
    _DersId = DersId;
}

Notlar::IdTuru Notlar::ogrenciId() const
{
    return _ogrenciId;
}

void Notlar::setOgrenciId(const IdTuru &ogrenciId)
{
    _ogrenciId = ogrenciId;
}

Notlar::IdTuru Notlar::notId() const
{
    return _notId;
}

void Notlar::setNotId(const IdTuru &notId)
{
    _notId = notId;
}

Notlar::PozitifTamsayi Notlar::ogrenciNot() const
{
    return _ogrenciNot;
}

void Notlar::setOgrenciNot(const PozitifTamsayi &ogrenciNot)
{
    if(this->_ogrenciNot !=ogrenciNot){
    _ogrenciNot = ogrenciNot;
    OgrenciNotDegisti(_ogrenciNot);}
}

Notlar::Notlar(QObject *parent) :TemelVeriSinifi(parent)
{
    this->_ogrenciNot=0;
}

/*

//Adım 1: Ortalamayı bulun.
//Adım 2: Her veri noktasının ortalamaya uzaklığının karesini bulun.
//Adım 3: 2. Adımdaki değerleri toplayın.
//Adım 4: Veri noktası sayısına bölün.
//Adım 5: Karekök alın.

using namespace std;

int main()
{

    int n;
    int veri[n];
    cout <<"kac not girilecek : ";
    cin>>n;
    float toplam = 0;
    float ortalama = 0;
    bool gecersiz;
    for(int i=0 ; i<n ; i++){
        cout<<i+1<<". notu girin : ";
        cin>>veri[i];
        if(veri[i] > 0 && veri[i] < 100){
            toplam += veri[i];
            ortalama = toplam/n;
        }
        else{
            cout<<"gecersiz not girildi!!!"<<endl;
            break;
        }
    }
    cout<<"ORTALAMA : "<<ortalama<<endl;
    float adim2;
    for(int i = 0;i<n;i++){
        adim2 += powf((ortalama-veri[i]),2);
    }
    cout<<"ADIM 2 : "<<adim2<<endl;
    float adim4;
    adim4 = adim2/n;
    float adim5;
    adim5 = sqrt(adim4);
    cout<<"SONUC : "<<adim5<<endl;

} */
