#ifndef NOTLAR_H
#define NOTLAR_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT Notlar : public QObject
{
    Q_OBJECT
public:
    explicit Notlar(QObject *parent = nullptr);

signals:

};

#endif // NOTLAR_H
