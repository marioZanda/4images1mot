#include "meilleursscore.h"
#include "ui_meilleursscore.h"

meilleursscore::meilleursscore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::meilleursscore)
{
    ui->setupUi(this);
    QSqlDatabase mydb;
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("../4images1mot/base.db");
    mydb.open();
    QLabel *labels[10][3];

    labels[0][0]=ui->label_j1;
    labels[0][1]=ui->label_s1;
    labels[0][2]=ui->label_t1;

    labels[1][0]=ui->label_j2;
    labels[1][1]=ui->label_s2;
    labels[1][2]=ui->label_t2;

    labels[2][0]=ui->label_j3;
    labels[2][1]=ui->label_s3;
    labels[2][2]=ui->label_t3;

    labels[3][0]=ui->label_j4;
    labels[3][1]=ui->label_s4;
    labels[3][2]=ui->label_t4;

    labels[4][0]=ui->label_j5;
    labels[4][1]=ui->label_s5;
    labels[4][2]=ui->label_t5;

    labels[5][0]=ui->label_j6;
    labels[5][1]=ui->label_s6;
    labels[5][2]=ui->label_t6;

    labels[6][0]=ui->label_j7;
    labels[6][1]=ui->label_s7;
    labels[6][2]=ui->label_t7;

    labels[7][0]=ui->label_j8;
    labels[7][1]=ui->label_s8;
    labels[7][2]=ui->label_t8;

    labels[8][0]=ui->label_j9;
    labels[8][1]=ui->label_s9;
    labels[8][2]=ui->label_t9;

    labels[9][0]=ui->label_j10;
    labels[9][1]=ui->label_s10;
    labels[9][2]=ui->label_t10;
    QSqlQuery query;
    query.exec("SELECT nom_joueur,score,temps FROM Partie ORDER BY score DESC,temps LIMIT 10");
    int i=0;
    if(query.exec())
    {
        while (query.next())
        {
            labels[i][0]->setText(query.value(0).toString());
            labels[i][1]->setText(query.value(1).toString());
            labels[i][2]->setText(query.value(2).toString());
            ++i;
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),query.lastError().text());
    }

}

meilleursscore::~meilleursscore()
{
    delete ui;
}

void meilleursscore::on_pushButton_fermer_clicked()
{
    this->close();
}

void meilleursscore::on_pushButton_precedent_clicked()
{
    MainWindow *acceuil = new MainWindow;
    acceuil->show();
    this->close();
}
