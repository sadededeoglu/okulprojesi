#ifndef OGRETMENYONETIM_H
#define OGRETMENYONETIM_H
#include <QObject>
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/ogretmenprofil.h"

class KUTUPHANE_EXPORT Ogretmenyonetim : public QObject, public Veriyonetim<OgretmenProfil>
{
    Q_OBJECT
public:
    explicit Ogretmenyonetim(QObject *parent = nullptr);

signals:

};

#endif // OGRETMENYONETIM_H
