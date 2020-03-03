#ifndef NOTLAR_H
#define NOTLAR_H
#include <QObject>
#include <memory>
#include "kutuphane_global.h"
#include "temelverisinifi.h"

class KUTUPHANE_EXPORT Notlar : public TemelVeriSinifi
{
    Q_OBJECT

public:
    typedef std::shared_ptr<Notlar>ptr;

public:
    explicit Notlar(QObject *parent = nullptr);

signals:

};

#endif // NOTLAR_H
