#ifndef DERSLER_H
#define DERSLER_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Dersler : public TemelVeriSinifi
{
    Q_OBJECT

public:
    typedef std::shared_ptr<Dersler>ptr;

public:
    explicit Dersler(QObject *parent = nullptr);

signals:

};

#endif // DERSLER_H
