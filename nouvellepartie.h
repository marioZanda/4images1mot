#ifndef NOUVELLEPARTIE_H
#define NOUVELLEPARTIE_H
#include <QPixmap>
#include <QSize>
#include "partie.h"
#include <QDialog>
#include "QKeyEvent"

namespace Ui {
class NouvellePartie;
}

class NouvellePartie : public QDialog
{
    Q_OBJECT

public:
    explicit NouvellePartie(QWidget *parent = nullptr);
    ~NouvellePartie();

private slots:
    void on_pushButton_precedent_clicked();

    void on_pushButton_play_clicked();

private:
    Ui::NouvellePartie *ui;

    void keyPressEvent(QKeyEvent *event);
};

#endif // NOUVELLEPARTIE_H
