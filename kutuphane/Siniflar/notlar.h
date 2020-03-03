#ifndef NOTLAR_H
#define NOTLAR_H

#include <QObject>

class Notlar : public QObject
{
    Q_OBJECT
public:
    explicit Notlar(QObject *parent = nullptr);

signals:

};

#endif // NOTLAR_H
