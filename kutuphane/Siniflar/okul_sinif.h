#ifndef OKUL_SINIF_H
#define OKUL_SINIF_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT Okul_sinif : public QObject
{
    Q_OBJECT
public:
    explicit Okul_sinif(QObject *parent = nullptr);

signals:

};

#endif // OKUL_SINIF_H
