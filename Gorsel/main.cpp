#include "ana_pencere.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ana_Pencere w;
    w.show();
    return a.exec();

    //TODO sınıf tanımlama kısmında öğretmen komboboxu çalışmıyor.

    //TODO ders ekle kısmı çalışmıyor.

    //TODO öğrenci listesi kısmında düzenleme yapılabiliyor , yapılamaması lazım.

    //TODO öğrenci listesinde çık butonu çalışmıyor.

    //TODO öğrenci eklenemiyor.

    //TODO öğretmen eklendiği zaman 2 tane ekleniyor.

    //TODO öğrenci ekleme ekranının adı değişecek.
}
