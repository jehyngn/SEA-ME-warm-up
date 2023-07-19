/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSTART;
    QAction *actionPAUSE;
    QAction *actionRESUME;
    QAction *actionEXIT;
    QWidget *centralwidget;
    QLabel *CAR0;
    QLabel *CAR1;
    QLabel *CAR2;
    QLabel *CAR3;
    QPushButton *startButton;
    QMenuBar *menubar;
    QMenu *menuSetting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(576, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/images/images/bg2.png);\n"
"border: 0px \n"
""));
        MainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionSTART = new QAction(MainWindow);
        actionSTART->setObjectName(QString::fromUtf8("actionSTART"));
        actionPAUSE = new QAction(MainWindow);
        actionPAUSE->setObjectName(QString::fromUtf8("actionPAUSE"));
        actionRESUME = new QAction(MainWindow);
        actionRESUME->setObjectName(QString::fromUtf8("actionRESUME"));
        actionEXIT = new QAction(MainWindow);
        actionEXIT->setObjectName(QString::fromUtf8("actionEXIT"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CAR0 = new QLabel(centralwidget);
        CAR0->setObjectName(QString::fromUtf8("CAR0"));
        CAR0->setGeometry(QRect(20, 580, 40, 70));
        CAR0->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color : none;\n"
"color : blue;"));
        CAR1 = new QLabel(centralwidget);
        CAR1->setObjectName(QString::fromUtf8("CAR1"));
        CAR1->setGeometry(QRect(50, 580, 40, 70));
        CAR1->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color : none;\n"
"color : red;"));
        CAR2 = new QLabel(centralwidget);
        CAR2->setObjectName(QString::fromUtf8("CAR2"));
        CAR2->setGeometry(QRect(100, 1000, 40, 70));
        CAR2->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color : none;\n"
"color : green;"));
        CAR3 = new QLabel(centralwidget);
        CAR3->setObjectName(QString::fromUtf8("CAR3"));
        CAR3->setGeometry(QRect(190, 1000, 40, 70));
        CAR3->setStyleSheet(QString::fromUtf8("background-image: url();\n"
"background-color : none;\n"
"color : yellow;"));
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(0, 0, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 576, 21));
        menuSetting = new QMenu(menubar);
        menuSetting->setObjectName(QString::fromUtf8("menuSetting"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSetting->menuAction());
        menuSetting->addAction(actionSTART);
        menuSetting->addAction(actionPAUSE);
        menuSetting->addAction(actionRESUME);
        menuSetting->addAction(actionEXIT);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSTART->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        actionPAUSE->setText(QCoreApplication::translate("MainWindow", "PAUSE", nullptr));
        actionRESUME->setText(QCoreApplication::translate("MainWindow", "RESUME", nullptr));
        actionEXIT->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        CAR0->setText(QCoreApplication::translate("MainWindow", "CAR0", nullptr));
        CAR1->setText(QCoreApplication::translate("MainWindow", "CAR1", nullptr));
        CAR2->setText(QCoreApplication::translate("MainWindow", "CAR2", nullptr));
        CAR3->setText(QCoreApplication::translate("MainWindow", "CAR3", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
        menuSetting->setTitle(QCoreApplication::translate("MainWindow", "Setting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
