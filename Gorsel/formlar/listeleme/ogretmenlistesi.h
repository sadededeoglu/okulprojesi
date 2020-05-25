#ifndef OGRETMENLISTESI_H
#define OGRETMENLISTESI_H

#include <QDialog>

namespace Ui {
class OgretmenListesi;
}

class OgretmenListesi : public QDialog
{
    Q_OBJECT

public:
    explicit OgretmenListesi(QWidget *parent = nullptr);
    ~OgretmenListesi();

private:
    Ui::OgretmenListesi *ui;
};

#endif // OGRETMENLISTESI_H
