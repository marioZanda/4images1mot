#include "partiefinie.h"
#include "ui_partiefinie.h"

PartieFinie::PartieFinie(QWidget *parent,int scr,int tmps) :
    QDialog(parent),
    ui(new Ui::PartieFinie)
{
    ui->setupUi(this);
    score=scr;
    temps=tmps;
    ui->label_score->setText(QString::number(score)+" points");
    QTime *tempss=new QTime;
    tempss->setHMS((temps/ 3600),((temps % 3600) / 60),((temps % 3600) % 60));
    ui->label_temps->setText(tempss->toString());
}

PartieFinie::~PartieFinie()
{
    delete ui;
}
