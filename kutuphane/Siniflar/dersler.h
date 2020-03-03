#ifndef DERSLER_H
#define DERSLER_H

#include <QObject>

class Dersler : public QObject
{
    Q_OBJECT
public:
    explicit Dersler(QObject *parent = nullptr);

signals:

};

#endif // DERSLER_H
