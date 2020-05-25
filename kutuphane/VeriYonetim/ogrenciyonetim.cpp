#include "ogrenciyonetim.h"

Ogrenciyonetim::Ogrenciyonetim(QObject *parent) : QObject(parent)
{

}
QDataStream &operator<<(QDataStream&dosya,const OgrenciProfil::ptr &OgrenciProfil)
{
    return dosya; //buraları dolduracak mıyız TODO
}

QDataStream &operator<<(QDataStream&dosya,OgrenciProfil::ptr &OgrenciProfil)
{
   return dosya;
}
