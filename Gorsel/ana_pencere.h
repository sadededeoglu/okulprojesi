#ifndef ANA_PENCERE_H
#define ANA_PENCERE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Ana_Pencere; }
QT_END_NAMESPACE

class Ana_Pencere : public QMainWindow
{
    Q_OBJECT

public:
    Ana_Pencere(QWidget *parent = nullptr);
    ~Ana_Pencere();

public slots:
    virtual void close(); //isyan edilecek kısım alt enter ilk secenek

private slots:



    void on_actionOgrenciEkle_triggered();

    void on_actiondersEkle_triggered();

    void on_actionnotEkle_triggered();

    void on_actionogretmenEkle_triggered();

    void on_actionsinifEkle_triggered();

private:
    Ui::Ana_Pencere *ui;
};
#endif // ANA_PENCERE_H
