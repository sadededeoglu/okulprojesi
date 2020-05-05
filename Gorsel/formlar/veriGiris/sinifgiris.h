#ifndef SINIFGIRIS_H
#define SINIFGIRIS_H

#include <QDialog>

namespace Ui {
class sinifGiris;
}

class sinifGiris : public QDialog
{
    Q_OBJECT

public:
    explicit sinifGiris(QWidget *parent = nullptr);
    ~sinifGiris();

private:
    Ui::sinifGiris *ui;
};

#endif // SINIFGIRIS_H
