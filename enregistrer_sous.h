#ifndef ENREGISTRER_SOUS_H
#define ENREGISTRER_SOUS_H

#include <QLabel>
#include <QMainWindow>
#include<QDir>
#include <QFileDialog>
#include <QUrl>
#include <QStringList>
#include <QWidget>
#include <QProcess>
#include <QTextEdit>
#include "QFile"
#include "QFileInfo"
#include <QSqlDatabase>
#include <QSql>
#include <QMessageBox>
#include <QSqlQuery>
#include "mainwindow.h"
#include "QKeyEvent"


namespace Ui {
class enregistrer_sous;
}

class enregistrer_sous : public QMainWindow
{
    Q_OBJECT

public:
    explicit enregistrer_sous(QWidget *parent = 0);
    ~enregistrer_sous();

private slots:


    void on_b1_clicked();

    void on_b2_clicked();

    void on_b3_clicked();

    void on_b4_clicked();

    void on_pushButton_clicked();

    void on_submit_clicked();

    void control(QString p);

private:
    Ui::enregistrer_sous *ui;
    QString a,a1,a2,a3,b,b1,b2,b3;
    QString fichier,fichier1,fichier2,fichier3;
    void keyPressEvent(QKeyEvent *event);

};

#endif // ENREGISTRER_SOUS_H
