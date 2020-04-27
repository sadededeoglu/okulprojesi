#include "ana_pencere.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ana_Pencere w;
    w.show();
    return a.exec();
}
