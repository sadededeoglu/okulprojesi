#ifndef DERSLERYONETIM_H
#define DERSLERYONETIM_H
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/dersler.h"

class DerslerYonetim : public QObject
{
    Q_OBJECT
public:
    explicit DerslerYonetim(QObject *parent = nullptr);

signals:

};

#endif // DERSLERYONETIM_H
