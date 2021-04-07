#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPixmap>
#include <QPushButton>
#include <QColor>
#include <QMainWindow>
#include "nouvellepartie.h"
#include "partie.h"
#include "meilleursscore.h"
#include "connexion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_play_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_bs_clicked();

    void on_pushButton_admin_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
