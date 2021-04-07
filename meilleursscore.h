#ifndef MEILLEURSSCORE_H
#define MEILLEURSSCORE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDialog>
#include <QMessageBox>
#include "partie.h"

namespace Ui {
class meilleursscore;
}

class meilleursscore : public QDialog
{
    Q_OBJECT

public:
    explicit meilleursscore(QWidget *parent = 0);
    ~meilleursscore();

private slots:
    void on_pushButton_fermer_clicked();

    void on_pushButton_precedent_clicked();

private:
    Ui::meilleursscore *ui;
};

#endif // MEILLEURSSCORE_H
