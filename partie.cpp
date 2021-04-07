#include "partie.h"
#include "ui_partie.h"

QToolButton *lettredispo[10];
QPushButton *btn;
QPushButton *lettreChoisie[10]={btn,btn,btn,btn,btn,btn,btn,btn,btn,btn};
int nbgroupe=0;
bool plein = false;
QHBoxLayout * layoutt = new QHBoxLayout;
partie::partie(QWidget *parent,  QString nomJ) :
    QDialog(parent),
    ui(new Ui::partie)
{
    ui->setupUi(this);
    nbPartie=0;
    nom=nomJ;
    srand(time(NULL));
    timer_chrono=new QTimer();
    resetCount();

    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("../4images1mot/base.db");
    mydb.open();

    ui->groupBox_btn->setLayout(layoutt);

    lettredispo[0]= ui->toolButton_1;
    lettredispo[1]= ui->toolButton_2;
    lettredispo[2]= ui->toolButton_3;
    lettredispo[3]= ui->toolButton_4;
    lettredispo[4]= ui->toolButton_5;
    lettredispo[5]= ui->toolButton_6;
    lettredispo[6]= ui->toolButton_7;
    lettredispo[7]= ui->toolButton_8;
    lettredispo[8]= ui->toolButton_9;
    lettredispo[9]= ui->toolButton_10;

    PreparerPartie();
    LancerPartie();
    connect( timer_chrono, SIGNAL(timeout()), this, SLOT(onTimer_Tick()));
    onButton_Start();


}
//=========================================================================
void partie::PreparerPartie()
{
    QSqlQuery req;
    req.prepare("SELECT COUNT(*) FROM Groupe");
    req.exec();
    if(req.exec())
    {
        while (req.next())
        {
            nbgroupe=req.value(0).toInt();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),req.lastError().text());
    }
    int selecteur =(((rand()%nbgroupe)+1));
    ui->lcdNumber_score->display(score);
    if (!mydb.isOpen())
    {
        QMessageBox::warning(this,"Erreur","erreur connection");
    }
    QSqlQuery query;
    query.prepare("SELECT * FROM Groupe where id= ?");
    query.exec();
    query.addBindValue(selecteur);
    if(query.exec())
    {
        while (query.next())
        {
            mot  = query.value(1).toString();
            img1 = query.value(2).toString();
            img2 = query.value(3).toString();
            img3 = query.value(4).toString();
            img4 = query.value(5).toString();
        }
    }
    else
    {
        QMessageBox::warning(this,tr("Error"),query.lastError().text());
    }
    ui->label_img1->setText("image_1");
    ui->label_img2->setText("image_2");
    ui->label_img3->setText("image_3");
    ui->label_img4->setText("image_4");
    for(int i=0;i<10;i++)
    {
        lettredispo[i]->show();
        lettredispo[i]->setText("");
    }
    int BtnExistants = layoutt->count();
    for (int i=0;i<BtnExistants;i++)
    {
        layoutt->removeWidget(lettreChoisie[i]);
        lettreChoisie[i]->hide();
    }
}
partie::~partie()
{
    delete ui;
}
//=========================================================================
void partie::LancerPartie()
{
    ui->lcdNumber_score->display(score);
    ui->lcdNumber_numero->display(nbPartie+1);
    for (int i = 0; i < mot.length() ; i++)
    {
        lettreChoisie[i] = new QPushButton(this);
        layoutt->addWidget(lettreChoisie[i]);
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
        lettreChoisie[i]->setText("");
        lettreChoisie[i]->setMinimumSize(40,40);
    }

    connect(lettreChoisie[0],SIGNAL(clicked()),SLOT(effacer1()));
    connect(lettreChoisie[1],SIGNAL(clicked()),SLOT(effacer2()));
    connect(lettreChoisie[2],SIGNAL(clicked()),SLOT(effacer3()));
    connect(lettreChoisie[3],SIGNAL(clicked()),SLOT(effacer4()));
    connect(lettreChoisie[4],SIGNAL(clicked()),SLOT(effacer5()));
    connect(lettreChoisie[5],SIGNAL(clicked()),SLOT(effacer6()));
    connect(lettreChoisie[6],SIGNAL(clicked()),SLOT(effacer7()));
    connect(lettreChoisie[7],SIGNAL(clicked()),SLOT(effacer8()));
    connect(lettreChoisie[8],SIGNAL(clicked()),SLOT(effacer9()));
    connect(lettreChoisie[9],SIGNAL(clicked()),SLOT(effacer10()));

    QSize taille;
    taille=ui->label_img1->size();
    QPixmap image1(img1);
    QPixmap image2(img2);
    QPixmap image3(img3);
    QPixmap image4(img4);
    ui->label_img1->setPixmap(image1);
    ui->label_img1->setScaledContents(true);
    ui->label_img1->adjustSize();
    ui->label_img2->setPixmap(image2);
    ui->label_img2->setScaledContents(true);
    ui->label_img2->adjustSize();
    ui->label_img3->setPixmap(image3);
    ui->label_img3->setScaledContents(true);
    ui->label_img3->adjustSize();
    ui->label_img4->setPixmap(image4);
    ui->label_img4->setScaledContents(true);
    ui->label_img4->adjustSize();




    for (int j=0;j < mot.length();j++)
    {
        QString lettre(mot[j]);
        int i = (rand()%10);
        if (lettredispo[i]->text()!="")
        {
            while (lettredispo[i]->text()!="")
            {
                i = (rand()%10);
            }
            lettredispo[i]->setText(lettre);

        }
        else
        {
            lettredispo[i]->setText(lettre);
        }
    }
    for (int i=0;i<10;i++)
    {
        if (lettredispo[i]->text()=="")
        {
            int k = (rand()%26);
            QString ltr(alphabet[k]);
            lettredispo[i]->setText(ltr);
        }
    }
}
//=========================================================================
void partie::on_toolButton_1_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_1->text());
            ui->toolButton_1->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[0],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_2_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_2->text());
            ui->toolButton_2->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[1],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_3_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_3->text());
            ui->toolButton_3->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[2],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_4_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_4->text());
            ui->toolButton_4->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[3],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_5_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_5->text());
            ui->toolButton_5->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[4],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_6_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_6->text());
            ui->toolButton_6->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[5],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_7_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_7->text());
            ui->toolButton_7->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[6],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_8_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_8->text());
            ui->toolButton_8->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[7],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_9_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_9->text());
            ui->toolButton_9->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[8],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::on_toolButton_10_clicked()
{
    for (int j=0;j<mot.length();j++)
    {
        if (lettreChoisie[j]->text()=="")
        {
            lettreChoisie[j]->setText(ui->toolButton_10->text());
            ui->toolButton_10->setVisible(0);
            connect(lettreChoisie[j],SIGNAL(clicked()),lettredispo[9],SLOT(show()));
            break;
        }
    }
}
//=========================================================================
void partie::effacer1()
{
    lettreChoisie[0]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer2()
{
    lettreChoisie[1]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer3()
{
    lettreChoisie[2]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer4()
{
    lettreChoisie[3]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer5()
{
    lettreChoisie[4]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer6()
{
    lettreChoisie[5]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer7()
{
    lettreChoisie[6]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer8()
{
    lettreChoisie[7]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer9()
{
    lettreChoisie[8]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::effacer10()
{
    lettreChoisie[9]->setText("");
    for(int i=0;i<mot.length();i++)
    {
        lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:white;");
    }
}
//=========================================================================
void partie::on_pushButton_valider_clicked()
{
    QString proposition;
    for (int i=0;i<mot.length();i++)
    {
        if(lettreChoisie[i]->text()=="")
        {
            for (int i=0;i<mot.length();i++)
            {
                lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px;border:1px solid black;border-radius:20px;color:white;");
            }
        }
        else
        {
            proposition += lettreChoisie[i]->text();
        }
    }
    if(proposition==mot)
    {

        for (int i=0;i<mot.length();i++)
        {
            lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:green;");
        }
        score++;
        if(nbPartie<10)
        {
            ++nbPartie;
            PreparerPartie();
            LancerPartie();
        }
        if(nbPartie==10)
        {
            timer_chrono->stop();
            PartieFinie *fin = new PartieFinie;
            fin->show();
            QTimer::singleShot(2000,fin,SLOT(close()));
        }
        if(nbPartie==10)
        {
            timer_chrono->stop();
            QSqlQuery req;
            req.prepare("INSERT INTO Partie(nom_joueur,score,temps)VALUES(?,?,?)") ;
            req.exec();
            req.addBindValue(nom);
            req.addBindValue(score);
            req.addBindValue(ui->lcdNumber_chrono->intValue());
            if(req.exec())
            {
                while (req.next())
                {
                }
            }
            else
            {
                QMessageBox::warning(this,tr("Error"),req.lastError().text());
            }
            PartieFinie *fin = new PartieFinie(nullptr,score,ui->lcdNumber_chrono->intValue());
            fin->show();
            MainWindow *acceuil=new MainWindow;
            QTimer::singleShot(5000,fin,SLOT(close()));
            QTimer::singleShot(5000,acceuil,SLOT(show()));
            this->close();
        }
    }
    else
    {
        for (int i=0;i<mot.length();i++)
        {
            lettreChoisie[i]->setStyleSheet("background-color:black;font-size:20px; border:1px solid black;border-radius:20px;color:red;");

        }

    }
}
//=========================================================================
void partie::on_pushButton_quitter_clicked()
{
    MainWindow *acceuil = new MainWindow;
    acceuil->show();
    this->close();
}
//=========================================================================
void partie::on_pushButton_passer_clicked()
{
    if(nbPartie<10)
    {
        ++nbPartie;
        PreparerPartie();
        LancerPartie();
    }
    if(nbPartie==10)
    {
        timer_chrono->stop();
        QSqlQuery req;
        req.prepare("INSERT INTO Partie(nom_joueur,score,temps)VALUES(?,?,?)") ;
        req.exec();
        req.addBindValue(nom);
        req.addBindValue(score);
        req.addBindValue(ui->lcdNumber_chrono->intValue());
        if(req.exec())
        {
        }
        else
        {
            QMessageBox::warning(this,tr("Error"),req.lastError().text());
        }
        PartieFinie *fin = new PartieFinie(nullptr,score,ui->lcdNumber_chrono->intValue());
        fin->show();
        MainWindow *acceuil=new MainWindow;
        QTimer::singleShot(5000,fin,SLOT(close()));
        QTimer::singleShot(5000,acceuil,SLOT(show()));
        this->close();
    }
}
//=========================================================================
void partie::resetCount()
{
    countTimer=0;
}
//=========================================================================
void partie::updateCount()
{
    countTimer++;
}
//=========================================================================
void partie::onButton_Start()
{
    timer_chrono -> start(1000); // 1000 ms
}
//=========================================================================
void partie::onButton_Reset()
{
    resetCount();
    ui->lcdNumber_chrono -> display(countTimer);
}
//=========================================================================
void partie::onTimer_Tick()
{
    updateCount();
    ui->lcdNumber_chrono -> display(countTimer);
}
//=========================================================================
void partie::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        emit ui->pushButton_passer->clicked(true);
    }
    else if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        emit ui->pushButton_valider->clicked(true);
    }
    else if (event->key() == Qt::Key_Backspace)
    {
        for (int i = mot.length()-1;i>=0;i--)
        {
            if (lettreChoisie[i]->text() != "")
            {
                emit lettreChoisie[i]->clicked(true);
                break;
            }
        }
    }
    for (int i = 0;i<10;i++)
    {
        if(event->text().toUpper() == lettredispo[i]->text() && lettredispo[i]->isVisible())
        {
            emit lettredispo[i]->clicked(true);
            break;
        }
    }
}

