#ifndef OKUL_SINIFYONETIM_H
#define OKUL_SINIFYONETIM_H
#include <QObject>
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/okul_sinif.h"

class KUTUPHANE_EXPORT Okul_sinifyonetim : public QObject, public Veriyonetim<Okul_sinif>
{
    Q_OBJECT
public:
    explicit Okul_sinifyonetim(QObject *parent = nullptr);

signals:

};

#endif // OKUL_SINIFYONETIM_H
