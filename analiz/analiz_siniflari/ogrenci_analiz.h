#ifndef OGRENCI_ANALIZ_H
#define OGRENCI_ANALIZ_H

#include <QObject>

class ogrenci_analiz : public QObject
{
    Q_OBJECT
public:
    explicit ogrenci_analiz(QObject *parent = nullptr);
    void Hesapla();
signals:

};

#endif // OGRENCI_ANALIZ_H
