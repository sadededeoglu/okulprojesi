#ifndef NOTLARYONETIM_H
#define NOTLARYONETIM_H
#include <QObject>
#include "veriyonetim.h"
#include "Siniflar/notlar.h"
#include "kutuphane_global.h"

class KUTUPHANE_EXPORT Notlaryonetim : public QObject , public Veriyonetim<Notlar>
{
    Q_OBJECT
public:
    explicit Notlaryonetim(QObject *parent = nullptr);

signals:

};

#endif // NOTLARYONETIM_H
