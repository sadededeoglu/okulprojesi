#include "dersleryonetim.h"

DerslerYonetim::DerslerYonetim(QObject *parent) : QObject(parent)
{

}

QDataStream & operator << (QDataStream &dosya , const Dersler::ptr &Dersler) {
    dosya << Dersler->Id() << Dersler->DersAdi() << Dersler->yil() << Dersler->donem();
    return dosya;
}

QDataStream & operator >> (QDataStream &dosya , Dersler::ptr &Dersler) {
    Dersler::IdTuru id;
    Dersler::Metin dersAdi;
    Dersler::PozitifTamsayi yil , donem;

    dosya >> id >> dersAdi >> yil >> donem;

    auto yeniDersler = Dersler::yeni();
    yeniDersler->setId(id);
    yeniDersler->setDersAdi(dersAdi);
    yeniDersler->setYil(yil);
    yeniDersler->setDonem(donem);

    Dersler = yeniDersler;

    return dosya;
}
