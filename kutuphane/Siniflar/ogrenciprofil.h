#ifndef OGRENCIPROFIL_H
#define OGRENCIPROFIL_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT OgrenciProfil : public TemelVeriSinifi
{
    Q_OBJECT
public:
    typedef std::shared_ptr<OgrenciProfil>ptr;
public:
    explicit OgrenciProfil(QObject *parent = nullptr);

signals:

};

#endif // OGRENCIPROFIL_H
