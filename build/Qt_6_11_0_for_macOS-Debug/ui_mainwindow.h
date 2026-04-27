/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *bar_energy;
    QProgressBar *bar_skating;
    QPushButton *btn_game;
    QPushButton *btn_train;
    QPushButton *btn_rest;
    QPlainTextEdit *txt_log;
    QLabel *lbl_record;
    QLabel *label;
    QPushButton *btn_film;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        bar_energy = new QProgressBar(centralwidget);
        bar_energy->setObjectName("bar_energy");
        bar_energy->setGeometry(QRect(20, 50, 141, 21));
        bar_energy->setValue(100);
        bar_skating = new QProgressBar(centralwidget);
        bar_skating->setObjectName("bar_skating");
        bar_skating->setGeometry(QRect(20, 70, 141, 41));
        bar_skating->setValue(50);
        btn_game = new QPushButton(centralwidget);
        btn_game->setObjectName("btn_game");
        btn_game->setGeometry(QRect(10, 110, 151, 32));
        btn_train = new QPushButton(centralwidget);
        btn_train->setObjectName("btn_train");
        btn_train->setGeometry(QRect(10, 150, 151, 32));
        btn_rest = new QPushButton(centralwidget);
        btn_rest->setObjectName("btn_rest");
        btn_rest->setGeometry(QRect(20, 230, 121, 32));
        txt_log = new QPlainTextEdit(centralwidget);
        txt_log->setObjectName("txt_log");
        txt_log->setGeometry(QRect(170, 70, 291, 441));
        txt_log->setStyleSheet(QString::fromUtf8(""));
        txt_log->setReadOnly(true);
        lbl_record = new QLabel(centralwidget);
        lbl_record->setObjectName("lbl_record");
        lbl_record->setGeometry(QRect(320, 30, 111, 16));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 0, 271, 16));
        btn_film = new QPushButton(centralwidget);
        btn_film->setObjectName("btn_film");
        btn_film->setGeometry(QRect(30, 190, 101, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bar_energy->setFormat(QCoreApplication::translate("MainWindow", "Energy:%p%", nullptr));
        btn_game->setText(QCoreApplication::translate("MainWindow", "Play Upcoming Game", nullptr));
        btn_train->setText(QCoreApplication::translate("MainWindow", "On-Ice Training", nullptr));
        btn_rest->setText(QCoreApplication::translate("MainWindow", "Recovery", nullptr));
        lbl_record->setText(QCoreApplication::translate("MainWindow", "Record: 0-0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "NHL MyPlayer: Road to the Championship", nullptr));
        btn_film->setText(QCoreApplication::translate("MainWindow", "Film Study", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
