#ifndef OGRETMENPROFIL_H
#define OGRETMENPROFIL_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT OgretmenProfil : public TemelVeriSinifi
{
    Q_OBJECT

public:
    typedef std::shared_ptr<OgretmenProfil>ptr;
public:
    explicit OgretmenProfil(QObject *parent = nullptr);

signals:

};

#endif // OGRETMENPROFIL_H
