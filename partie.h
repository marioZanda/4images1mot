#ifndef PARTIE_H
#define PARTIE_H
#include <QDialog>
#include <QPixmap>
#include <QSize>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPushButton>
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QToolButton>
#include <QTimer>
#include <time.h>
#include "partiefinie.h"
#include "mainwindow.h"
#include "QKeyEvent"


namespace Ui {
class partie;
}

class partie : public QDialog
{
    Q_OBJECT

public:
    explicit partie(QWidget *parent = nullptr , QString nom="joueur");
    int score=0;
    int nbPartie=0;
    void resetCount();
    void updateCount();
    void LancerPartie();
    void PreparerPartie();
    void FermerPartie(QSqlDatabase mybd);
    QString mot,img1,img2,img3,img4;
    QString alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString nom;



    ~partie();
private slots:
    void onTimer_Tick();
    void onButton_Start();
    void onButton_Reset();
    void on_toolButton_1_clicked();

    void on_toolButton_2_clicked();

    void on_toolButton_3_clicked();

    void on_toolButton_4_clicked();

    void on_toolButton_5_clicked();

    void on_toolButton_6_clicked();

    void on_toolButton_7_clicked();

    void on_toolButton_8_clicked();

    void on_toolButton_9_clicked();

    void on_toolButton_10_clicked();

    void effacer1();

    void effacer2();

    void effacer3();

    void effacer4();

    void effacer5();

    void effacer6();

    void effacer7();

    void effacer8();

    void effacer9();

    void effacer10();

    void on_pushButton_valider_clicked();


    void on_pushButton_quitter_clicked();

    void on_pushButton_passer_clicked();

private:
    Ui::partie *ui;
    QSqlDatabase mydb;
    QTimer *timer_chrono;
    int countTimer;
    void keyPressEvent(QKeyEvent *event);
};

#endif // PARTIE_H
