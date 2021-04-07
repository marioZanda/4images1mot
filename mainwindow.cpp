#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QRect"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  surface = screen->geometry();
    int x = surface.width()/2 - width()/2;
    int y = surface.height()/2 - height()/2;
    move(x,y);
    QPixmap image(":logo/image/logo.jpg");
    ui->label_logo->setPixmap(image.scaled(200,200,Qt::KeepAspectRatioByExpanding));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_play_clicked()
{
    NouvellePartie *p = new NouvellePartie;
    p->show();
    this->close();
}

void MainWindow::on_pushButton_quit_clicked()
{
    this->close();

}

void MainWindow::on_pushButton_bs_clicked()
{
    meilleursscore *scores=new meilleursscore;
    scores->show();
    this->close();
}

void MainWindow::on_pushButton_admin_clicked()
{
    Connexion *connect = new Connexion;
    connect->show();
    this->close();
}

