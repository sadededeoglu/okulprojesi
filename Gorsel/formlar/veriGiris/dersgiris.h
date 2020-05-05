#ifndef DERSGIRIS_H
#define DERSGIRIS_H
#include<Siniflar/dersler.h>
#include <QDialog>

namespace Ui {
class dersGiris;
}

class dersGiris : public QDialog
{
    Q_OBJECT

public:
    explicit dersGiris(QWidget *parent = nullptr);
    ~dersGiris();

private:
    Ui::dersGiris *ui;
};

#endif // DERSGIRIS_H
