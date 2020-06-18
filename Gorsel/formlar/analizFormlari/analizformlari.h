#ifndef ANALIZFORMLARI_H
#define ANALIZFORMLARI_H
#include <QDialog>

namespace Ui { class analizFormlari; }

class analizFormlari : public QDialog
{
    Q_OBJECT
public:
    explicit analizFormlari(QWidget *parent = nullptr);
    ~analizFormlari();

    void tabloGuncelle();

private:
    Ui::analizFormlari *ui;
};
#endif // ANALIZFORMLARI_H
