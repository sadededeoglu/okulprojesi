#ifndef OGRENCIYONETIM_H
#define OGRENCIYONETIM_H
#include <QObject>
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/ogrenciprofil.h"

class KUTUPHANE_EXPORT Ogrenciyonetim : public QObject, public Veriyonetim<OgrenciProfil>
{
    Q_OBJECT
public:
    explicit Ogrenciyonetim(QObject *parent = nullptr);

signals:

};

#endif // OGRENCIYONETIM_H
