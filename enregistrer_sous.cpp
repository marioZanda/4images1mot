#include "enregistrer_sous.h"
#include "ui_enregistrer_sous.h"

enregistrer_sous::enregistrer_sous(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::enregistrer_sous)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("../4images1mot/base.db");
    mydb.open();

    if(mydb.open())
    {
    }
    else
        QMessageBox::warning(this,"info","echec connexion");

    connect(ui->mot,SIGNAL(textEdited(QString)),this,SLOT(control(QString)));



}



void enregistrer_sous::control(QString p){
    QString caractereSpeciaux = "&é~\"#'{([-|è`_\ç^à@)]=}€¨$£¤ù%*µ<>1234567890.,?;.:/!§+ ";
    for(int i = 0; i < caractereSpeciaux.length(); i++){
        p.replace( caractereSpeciaux.at(i),"");
    }

    if(p.length()>10)
    {
        QMessageBox::warning(this,"alert","Vous ne pouvez rentrer q'un mot ayant moins de 11 caractère");
        ui->mot->setText("");
    }
    else
    {
        ui->mot->setText(p);
    }
}


void enregistrer_sous::on_b1_clicked()
{
    fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "image(*.png *.jpg *.jpeg *.xml )");
    a=fichier;
    QFileInfo file(fichier);
    fichier=file.fileName();

    ui->img_1->setText(a);
}


void enregistrer_sous::on_b2_clicked()
{
    fichier1 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "image(*.png *.jpg *.jpeg *.xml )");
    a1=fichier1;
    QFileInfo file(fichier1);
    fichier1=file.fileName();

    ui->img_2->setText(a1);
}

void enregistrer_sous::on_b3_clicked()
{
    fichier2 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "image(*.png *.jpg *.jpeg *.xml )");
    a2=fichier2;
    QFileInfo file(fichier2);
    fichier2=file.fileName();

    ui->img_3->setText(a2);
}

void enregistrer_sous::on_b4_clicked()
{
    fichier3 = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "image(*.png *.jpg *.jpeg *.xml )");
    a3=fichier3;
    QFileInfo file(fichier3);
    fichier3=file.fileName();

    ui->img_4->setText(a3);
}

enregistrer_sous::~enregistrer_sous()
{
    delete ui;
}






void enregistrer_sous::on_pushButton_clicked()
{
    MainWindow *acceuil = new MainWindow;
    acceuil->show();
    this->close();
}

void enregistrer_sous::on_submit_clicked()
{
    if (ui->img_1->text() == "" ||ui->img_2->text() == "" ||ui->img_3->text() == "" ||ui->img_4->text() == "" || ui->mot->text() == "" )
    {
        QMessageBox::warning(this,"","Remplissez tout les champs");

    }
    else
    {
        QString word= ui->mot->text();
        QDir new_;
        new_.mkpath("..\\4images1mot\\img\\"+word);
        b="..\\4images1mot\\img\\"+word+"\\"+fichier;
        b1="..\\4images1mot\\img\\"+word+"\\"+fichier1;
        b2="..\\4images1mot\\img\\"+word+"\\"+fichier2;
        b3="..\\4images1mot\\img\\"+word+"\\"+fichier3;
        QFile::copy(a,b);
        QFile::copy(a1,b1);
        QFile::copy(a2,b2);
        QFile::copy(a3,b3);
        QSqlQuery query;
        query.prepare("INSERT INTO Groupe(mot,image1,image2,image3,image4)VALUES(?,?,?,?,?)");
        query.exec();
        query.addBindValue(word.toUpper());
        query.addBindValue(b);
        query.addBindValue(b1);
        query.addBindValue(b2);
        query.addBindValue(b3);
        if (query.exec())
        {
        }
        else
        {
            QMessageBox::warning(this,"","erreur");
        }
        QMessageBox::information(this,"Enregistrer","Ajout Effectuer");
        enregistrer_sous *nouv=new enregistrer_sous;
        nouv->show();
        this->close();
    }

}
void enregistrer_sous::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return)
        emit ui->submit->clicked(true);
}

