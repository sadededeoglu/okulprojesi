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
    Notlaryonetim _notlar;
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

    void Kaydet(QString dosyaAdi);
    void Yukle(QString dosyaAdi);

signals: //TODO burası da diğer sinyallerdeki gibi mi
    void OgretmenEklendi(OgretmenProfil::ptr ogretmeneklendi);
    void OgretmenSilindi(OgretmenProfil::ptr ogretmensilindi);
    void OgrenciEklendi(OgrenciProfil::ptr ogrenciEklendi);
    void OgrenciSilindi(OgrenciProfil::ptr ogrenciSilindi);
    void DersEklendi(Dersler::ptr derseklendi);
    void DersSilindi( Dersler::ptr derssilindi);
    void NotEklendi( Notlar::ptr noteklendi);
    void NotSilindi( Notlar::ptr notsilindi);
    void SinifEklendi(Okul_sinif::ptr sinifeklendi);
    void SinifSilindi( Okul_sinif::ptr sinifsilindi);



/*11. video

ilk 23 dkka birim fiyat kısmını anlatıyor bizim oyle bir seye ihtiyacımız yok sanırım
*/


    /*const lar vardı silindi basına & geldi sonrasına sınyalleri eklenecek

8. video notlar

simdi sanırım görsel kısım su sekılde olacak

öğretmen gir ,bilgilerini gir ,cıkarken sor: baska eklemek istiyor musunuz? okul sınıf kısmında
ismi tutuluyor

dersler gir, ders adı ve dönemi girince onu neyle baglayacağiz bir fikrim yok

öğrenci gir, bilgilerini gir,girilen bilgiler diğer ogreci görselde saklanıyor. sonra eğer not
girmek istersek onun için ayrı pencere acıyoruz. önce ogrencinin kayıtlı olması gerekiyor

notlar gir, girerken kayıtlı olan öğrencinin ismini cagırabiliyoruz zaten sadece not giriliyor bu sınıfa

okul sınıf da sadece sınıfın adını, sorumlu hocanın adını ve yıl  tutuyor bi olayı yok


      yani burdan yola cıkarsak

  öğretmen gir ,bilgilerini gir ,cıkarken sor: baska eklemek istiyor musunuz? hayır

  öğrenci gir, bilgilerini gir, sor= not eklemek istiyormusunuz? evet= dersler kısmına baglanacak

  dersin ismi eklenince not kısmına geçiş olacak? dersi hangi öğrenci alıyor hangisi almıyor gibi bir sorunumuz var mı?

  notunu gir . burdan standart sapma regresyon buraya mı eklenecek? yoksa ilerleyen yerlerde mi göreceğiz?

  yada hiç bunları eklemeyız

  ana sayfaya hepsi için ayrı bir yer ekledik . önce öğrenci kaydı, sonra sınıfı, (sınıf bilinince
  öğretmeni ve aldıgı dersleri de belli olacak) cıkan ders ismine göre de notu girilecek.

  girilen notlar listede kayıtta oldugu için standart s. kısmı orda yapılacak. ama bunlar nasıl cıktı olarak verilecek.


hocanın projesindeki ürün =notlar oluyor sanırım*/


/* virtual demek kodlar bende değil diğer cocuk sınıfında, bu fnksıyona isyan edilebilir =0 dersek

bir sınıftan 1 tane nesne olusturulsun baska olusturulmasın.

1=var sayılan ilk publıc den private a al ki bu sınıfı kendinden baska kımse olusturamasın

2=sınıf olmadan sınıf olusturmak için statik kullanıyorum
kendisi dönüştürücüsü olacak paramerte almayacak

3=bu fonk içinde 2 satı yazılacak
1. si statik nesne olusacak birden fazla kodun nesneye olsmasını saglar

connect (kaynak nesnenin adresi,kaynak nesnenin fonksiyonu, hedef nesne, onun fonksiyonu)

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
