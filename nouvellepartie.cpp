#include "mainwindow.h"
#include "nouvellepartie.h"
#include "ui_nouvellepartie.h"

NouvellePartie::NouvellePartie(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NouvellePartie)
{
    ui->setupUi(this);
    QPixmap image(":logo/image/logo.jpg");
    ui->label_logo->setPixmap(image.scaled(200,200,Qt::KeepAspectRatioByExpanding));
    ui->lineEdit_nom_joueur->setFocus();
}

NouvellePartie::~NouvellePartie()
{
    delete ui;
}

void NouvellePartie::on_pushButton_precedent_clicked()
{
    MainWindow *acceuil = new MainWindow;
    acceuil->show();
    this->close();
}

void NouvellePartie::on_pushButton_play_clicked()
{
    if (ui->lineEdit_nom_joueur->text()!="")
    {
        partie *nouvellepartie = new partie(nullptr,ui->lineEdit_nom_joueur->text()) ;
        nouvellepartie->show();
        this->close();
    }
    else
    {
        QMessageBox::warning(this,"","Entrez un nom");
    }
}
void NouvellePartie::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
        emit ui->pushButton_play->clicked(true);
}
