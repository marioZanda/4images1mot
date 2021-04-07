#ifndef CONNEXION_H
#define CONNEXION_H
#include "mainwindow.h"
#include "enregistrer_sous.h"

#include <QDialog>

namespace Ui {
class Connexion;
}

class Connexion : public QDialog
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = 0);
    ~Connexion();

private slots:
    void on_pushButton_precedent_2_clicked();

    void on_pushButton_valider_clicked();

private:
    Ui::Connexion *ui;
    void keyPressEvent(QKeyEvent *event);
};

#endif // CONNEXION_H
