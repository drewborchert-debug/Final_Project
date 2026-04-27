#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Player.h"
#include "GameLogic.h"
#include <QInputDialog>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // This pops up a Mac-style box for the name and team
    QString name = QInputDialog::getText(this, "New Career", "Enter Player Name:");
    QString team = QInputDialog::getText(this, "Team Select", "Enter NHL Team:");

    myPlayer = new Player(name.toStdString(), team.toStdString());

    updateDashboard();
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::updateDashboard() {
    // 1. Progress Bar for Energy
    ui->bar_energy->setValue(myPlayer->getEnergy());

    // 2. LIVE NUMBERS
    QString stats = QString(
                        "SKT: %1 | SHT: %2 | IQ: %3\n"
                        "Goals: %4 | Fights: %5\n"
                        "Record: %6-%7"
                        )
                        .arg(myPlayer->getSkating())
                        .arg(myPlayer->getShooting())
                        .arg(myPlayer->getHockeyIQ())
                        .arg(myPlayer->getGoals())
                        .arg(myPlayer->getFightsWon())
                        .arg(myPlayer->getWins())
                        .arg(myPlayer->getLosses());

    ui->lbl_stats->setText(stats);

    int displayGame = myPlayer->getGameNum();
    if (displayGame > 20) displayGame = 20;

    QString title = QString("%1 | Game %2/20")
                        .arg(QString::fromStdString(myPlayer->getTeam()))
                        .arg(displayGame);
    this->setWindowTitle(title);
}


void MainWindow::on_btn_game_clicked()
{
    if (ui->btn_game->text() == "Exit Game") {
        QApplication::quit();
        return;
    }
    // A) THE END OF SEASON / PLAYOFF LOGIC
    if (myPlayer->getGameNum() > 20) {

        ui->btn_train->setEnabled(false);
        ui->btn_film->setEnabled(false);
        ui->btn_rest->setEnabled(false);

        if (myPlayer->getWins() >= 14) {
            ui->txt_log->appendPlainText("--- PLAYOFFS ---");
            if ((rand() % 100) < 50) {
                ui->txt_log->appendPlainText("Quarterfinals: WIN! Advancing...");
                if ((rand() % 100) < 50) ui->txt_log->appendPlainText("FINALS: CHAMPIONSHIP WON!");
                else ui->txt_log->appendPlainText("FINALS: Lost in overtime.");
            } else ui->txt_log->appendPlainText("Quarterfinals: Eliminated.");
        } else {
            ui->txt_log->appendPlainText("Season Over. Missed Playoffs (Need 14 wins).");
        }

        // Final "Thanks for Playing" Summary
        ui->txt_log->appendPlainText("\n*** THANKS FOR PLAYING! ***");
        ui->txt_log->appendPlainText("Final Goals: " + QString::number(myPlayer->getGoals()));

        // Disable buttons so they can't keep clicking
        ui->btn_game->setEnabled(false);
        return;
    }

    // B) Energy Check
    if (myPlayer->getEnergy() < 100) {
        ui->txt_log->appendPlainText("[!] You aren't fresh enough! REST to 100% first.");
        return;
    }

    // C) INTERACTIVE FIGHT (2 seconds)
    if ((rand() % 100) < 15) {
        ui->txt_log->appendPlainText("!!! FIGHT BREAKS OUT: GO! !!!");

        QStringList possibleKeys = {"a", "d", "f"};
        bool fightWon = true;

        for (int i = 0; i < 3; ++i) {

            QString currentTarget = possibleKeys[rand() % 3];

            QInputDialog fightDialog(this);
            fightDialog.setWindowTitle("COMBO " + QString::number(i + 1) + "/3");
            fightDialog.setLabelText("QUICK! Type: '" + currentTarget + "'");

            // 2000ms (2 seconds) total for the prompt
            QTimer::singleShot(2000, &fightDialog, &QWidget::close);

            if (fightDialog.exec() == QDialog::Accepted && fightDialog.textValue().toLower() == currentTarget) {
                ui->txt_log->appendPlainText("Landed " + currentTarget.toUpper() + "!");
            } else {
                ui->txt_log->appendPlainText("COMBO BROKEN! You were too slow or missed the " + currentTarget.toUpper() + "!");
                fightWon = false;
                break; // Exit the loop early because they lost
            }
        }

        if (fightWon) {
            ui->txt_log->appendPlainText("VICTORY: You dropped him with the full combo!");
            myPlayer->addFightWin();
        } else {
            ui->txt_log->appendPlainText("DEFEAT: You took a heavy right hook.");
        }
    }

    // D) RUN THE GAME
    std::string report = GameLogic::playSeasonGame(*myPlayer);

    // 1. Add a break
    ui->txt_log->appendHtml("<br><hr style='border: 1px dashed #555;'><br>");

    // 2. Print the report using HTML for bolding
    // We use QString::fromStdString(report) inside the bold tags
    ui->txt_log->appendHtml("<b>GAME REPORT:</b> " + QString::fromStdString(report));

    // 3. Add a small divider at the bottom of the result
    ui->txt_log->appendHtml("<font color='#888'>--------------------------</font>");

    updateDashboard();
}


void MainWindow::on_btn_train_clicked()
{
    if (myPlayer->getEnergy() >= 60) {
        myPlayer->trainOnIce(5, 3);
        ui->txt_log->appendPlainText("[TRAIN] +5 Skating, +3 Shooting. Energy -60.");
    } else {
        ui->txt_log->appendPlainText("[!] Too exhausted to train! Hit the training room (REST).");
    }
    updateDashboard();
}


void MainWindow::on_btn_rest_clicked()
{
    myPlayer->rest();
    ui->txt_log->appendPlainText("[REST] Recovered for the next shift! Energy back to 100%.");
    updateDashboard();
}


void MainWindow::on_btn_film_clicked()
{
    if (myPlayer->getEnergy() >= 40) {
        myPlayer->studyFilm(5);
        ui->txt_log->appendPlainText("[FILM] Studied positioning. +5 IQ. Energy -40.");
    } else {
        ui->txt_log->appendPlainText("[!] Too tired for film study! You need recovery.");
    }
    updateDashboard();
}


