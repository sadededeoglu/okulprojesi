#ifndef OKUL_SINIF_H
#define OKUL_SINIF_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Okul_sinif : public TemelVeriSinifi
{
    Q_OBJECT

public:
    typedef std::shared_ptr<Okul_sinif>ptr;
public:
    explicit Okul_sinif(QObject *parent = nullptr);

signals:

};

#endif // OKUL_SINIF_H
