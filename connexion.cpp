#include "connexion.h"
#include "ui_connexion.h"
#include <QPixmap>

Connexion::Connexion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);
    QPixmap image(":logo/image/logo.jpg");
    ui->label_logo->setPixmap(image.scaled(300,300,Qt::KeepAspectRatio));
    ui->lineEdit_login->setFocus();

}

Connexion::~Connexion()
{
    delete ui;
}

void Connexion::on_pushButton_precedent_2_clicked()
{
    MainWindow *acceuil = new MainWindow;
    acceuil->show();
    this->close();
}

void Connexion::on_pushButton_valider_clicked()
{
    if(ui->lineEdit_login->text()=="")
        QMessageBox::warning(this,"connexion","Entrez un login");
    else if(ui->lineEdit_pwd->text()=="")
        QMessageBox::warning(this,"connexion","Entrez un mot de passe");
    else{


        QString login=ui->lineEdit_login->text();
        QString pwd=ui->lineEdit_pwd->text();


        QSqlDatabase mydb;
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("../4images1mot/base.db");
        mydb.open();
        QSqlQuery query;
        query.exec("SELECT * FROM admin");


        if(query.exec())
        {
            while (query.next())
            {
                if(login==query.value(0) && pwd==query.value(1))
                {
                    enregistrer_sous *enregistrer=new enregistrer_sous;
                    enregistrer->show();
                    this->close();
                }
                else
                {
                    QMessageBox::warning(this,"connexion","informations invalides");
                }
            }
        }
        else
        {
            QMessageBox::warning(this,tr("Error"),query.lastError().text());
        }
    }
}
void Connexion::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
        emit ui->pushButton_valider->clicked(true);
}

