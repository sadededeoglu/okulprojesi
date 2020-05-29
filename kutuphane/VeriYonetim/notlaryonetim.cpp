#include "notlaryonetim.h"
#include <QDataStream>

Notlaryonetim::Notlaryonetim(QObject *parent) : QObject(parent)
{

}

QDataStream & operator << (QDataStream &dosya , const Notlar::ptr &Notlar) {
    dosya << Notlar->dersId() << Notlar->ogrenciId() << Notlar->notId() << Notlar->sinifId() << Notlar->ogrenciNot();
    return dosya;
}

QDataStream & operator >> (QDataStream &dosya , Notlar::ptr &Notlar) {
    Notlar::IdTuru dersId , ogrenciId , notId , sinifId;
    Notlar::PozitifTamsayi ogrenciNot;

    dosya >> dersId >> ogrenciId >> notId >> sinifId >> ogrenciNot;

    auto yeniNot = Notlar::yeni();

    yeniNot->setDersId(dersId);
    yeniNot->setOgrenciId(ogrenciId);
    yeniNot->setNotId(notId);
    yeniNot->setSinifId(sinifId);
    yeniNot->setOgrenciNot(ogrenciNot);

    Notlar = yeniNot;
    return dosya;
}
