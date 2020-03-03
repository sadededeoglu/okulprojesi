#ifndef OGRETMENPROFIL_H
#define OGRETMENPROFIL_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT OgretmenProfil : public QObject
{
    Q_OBJECT
public:
    explicit OgretmenProfil(QObject *parent = nullptr);

signals:

};

#endif // OGRETMENPROFIL_H
