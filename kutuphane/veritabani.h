#ifndef VERITABANI_H
#define VERITABANI_H
#include <QObject>
#include <kutuphane_global.h>
#include <VeriYonetim/dersleryonetim.h>
#include <VeriYonetim/notlaryonetim.h>
#include <VeriYonetim/ogrenciyonetim.h>
#include <VeriYonetim/ogretmenyonetim.h>
#include <VeriYonetim/okul_sinifyonetim.h>


class KUTUPHANE_EXPORT VeriTabani : public QObject
{
    Q_OBJECT
    private:
    explicit VeriTabani(QObject *parent = nullptr);

    DerslerYonetim _dersler;
    Notlaryonetim _notmlar;
    Ogrenciyonetim _ogrenci;
    Ogretmenyonetim _ogretmen;
    Okul_sinifyonetim _okulSinif;

    //alt enter yapıp getter yapılacak sadece

public:
    static VeriTabani & veritabani();

    DerslerYonetim &dersler();
    Notlaryonetim &notlar();
    Ogrenciyonetim &ogrenci();
    Ogretmenyonetim &ogretmen();
    Okul_sinifyonetim &okulSinif();

signals:
    void OgretmenEklendi(OgretmenProfil::ptr ogretmeneklendi);
    void OgretmenSilindi(OgretmenProfil::ptr ogretmensilindi);
    void OgrenciEklendi(OgrenciProfil::ptr ogrenciEklendi);
    void OgrenciSilindi(OgrenciProfil::ptr ogrenciSilindi);

    /*const lar vardı silindi basına & geldi sonrasına sınyalleri eklenecek

benden notlar;
 virtual demek kodlar bende değil diğer cocuk sınıfında, bu fnksıyona isyan edilebilir =0 dersek

bir sınıftan 1 tane nesne olusturulsun baska olusturulmasın.

1=var sayılan ilk publıc den private a al ki bu sınıfı kendinden baska kımse olusturamasın

2=sınıf olmadan sınıf olusturmak için statik kullanıyorum
kendisi dönüştürücüsü olacak paramerte almayacak

3=bu fonk içinde 2 satı yazılacak
1. si statik nesne olusacak birden fazla kodun nesneye olsmasını saglar

connect (kaynak nesnenin adresi,kaynak nesnenin fonksiyonu, hedef nesne, onun fonksiyonu)
---------


#include <iostream>
#include <math.h>

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

}
standart sapma bu
------
görsel kısım ;

kaynaklara sağ tuş yap open in editor e tıkla ordan yeni simge ekleniyor

çalısmanın üstünde sağ tusa basıp add tool bar a tıklayınca menülerden birini istersek bir
kısa yol butonu yapabiliyoruz

window modal: kendisi açıkken diğer sekmelerle erişimi engelliyor
aplıcal modal: bununla islem yapana kadar diğerlerine dokunmak yok
non modal: diğerlerine karsmıyo
enable: bunu acmadıgımız surece içindeki seyler pasıf hale geçiyor
geometri:sekli
font:yazı tipi
cursor: nesnenin üstüne gelince mause değişiyor
focus: bilgi girşinin aktif oldugu nesneyi gösterir bilgi girişinin nasıl girileceğini seçtirir
contex meni: sağ tus menüsü
custom:kodu bizim yazmamız
accept drop: sürükle bırak ı destekliyor mu? bunun için kod yazman lazım
opacidy: saydamlık
ttool tip: fareyle ürerine gelince üstünde cıkaracak metin falan
short cut: ctrl a ya basınca mesela ac yapar. kısa yol


shift+f4 tasarım ve header arası geçiş yapar


*/
};

#endif // VERITABANI_H
