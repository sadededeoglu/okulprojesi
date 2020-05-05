#ifndef NOTGIRIS_H
#define NOTGIRIS_H

#include <QDialog>

namespace Ui {
class notGiris;
}

class notGiris : public QDialog
{
    Q_OBJECT

public:
    explicit notGiris(QWidget *parent = nullptr);
    ~notGiris();

private:
    Ui::notGiris *ui;
};

#endif // NOTGIRIS_H
