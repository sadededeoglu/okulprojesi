#ifndef OGRENCIYONETIM_H
#define OGRENCIYONETIM_H
#include <QObject>
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/ogrenciprofil.h"

class Ogrenciyonetim : public QObject
{
    Q_OBJECT
public:
    explicit Ogrenciyonetim(QObject *parent = nullptr);

signals:

};

#endif // OGRENCIYONETIM_H
