#ifndef YENIOGRENCIGIRIS_H
#define YENIOGRENCIGIRIS_H

#include <QDialog>

namespace Ui {
class yeniOgrenciGiris;
}

class yeniOgrenciGiris : public QDialog
{
    Q_OBJECT

public:
    explicit yeniOgrenciGiris(QWidget *parent = nullptr);
    ~yeniOgrenciGiris();

private:
    Ui::yeniOgrenciGiris *ui;
};

#endif // YENIOGRENCIGIRIS_H
