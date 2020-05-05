#ifndef OGRETMENGIRIS_H
#define OGRETMENGIRIS_H

#include <QDialog>

namespace Ui {
class ogretmenGiris;
}

class ogretmenGiris : public QDialog
{
    Q_OBJECT

public:
    explicit ogretmenGiris(QWidget *parent = nullptr);
    ~ogretmenGiris();

private:
    Ui::ogretmenGiris *ui;
};

#endif // OGRETMENGIRIS_H
