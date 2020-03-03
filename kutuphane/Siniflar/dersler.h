#ifndef DERSLER_H
#define DERSLER_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT Dersler : public QObject
{
    Q_OBJECT
public:
    explicit Dersler(QObject *parent = nullptr);

signals:

};

#endif // DERSLER_H
