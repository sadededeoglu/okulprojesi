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

    //TODO öğretmen sil ve öğrenci sil fonksiyonları doğru çalışmıyor.

    //TODO eklenen öğrenci , öğrenci listesinde gözükmüyor.

    //TODO eklenen öğretmen , öğretmen listesinde gözükmüyor.

    //TODO öğretmen eklendiği zaman 2 tane ekleniyor.
}
