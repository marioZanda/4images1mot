#ifndef PARTIEFINIE_H
#define PARTIEFINIE_H

#include <QDialog>
#include <QString>
#include <QTime>

namespace Ui {
class PartieFinie;
}

class PartieFinie : public QDialog
{
    Q_OBJECT

public:
    explicit PartieFinie(QWidget *parent = nullptr,int scr=0,int tmps=0);
    ~PartieFinie();

private:
    Ui::PartieFinie *ui;
    int score;
    int temps;
};

#endif // PARTIEFINIE_H
