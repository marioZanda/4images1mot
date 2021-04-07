#include"meilleursscore.h"
#include "mainwindow.h"
#include "nouvellepartie.h"
#include "partie.h"
#include "connexion.h"
#include "partiefinie.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPixmap image(":/logo/image/fond.jpg");
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(image.scaled(1000,1000,Qt::KeepAspectRatio));
    splash->show();
    MainWindow mainwin;
    QTimer::singleShot(2500,splash,SLOT(close()));
    QTimer::singleShot(2500,&mainwin,SLOT(show()));
    return a.exec();
}
