#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include "Player.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_game_clicked();

    void on_btn_train_clicked();

    void on_btn_film_clicked();

    void on_btn_rest_clicked();

private:
    Ui::MainWindow *ui;
    Player *myPlayer;
    void updateDashboard();
};
#endif // MAINWINDOW_H
