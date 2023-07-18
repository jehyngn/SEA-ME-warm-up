#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QKeyEvent>
#include <QDebug>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    Set Initial enable
    ui->actionSTART->setEnabled(true);
    ui->actionPAUSE->setEnabled(false);
    ui->actionRESUME->setEnabled(false);
    ui->actionEXIT->setEnabled(true);

//    Load Car Image
    CAR_img[0].load(":/images/images/car0_.png");
    CAR_img[1].load(":/images/images/car1_.png");
//    CAR_img[2].load(":/images/images/car2_.png");
//    CAR_img[3].load(":/images/images/car3_.png");

//    Set Pointer
    CAR_ptr[0] = ui->CAR0;
    CAR_ptr[1] = ui->CAR1;
//    CAR_ptr[2] = ui->CAR2;
//    CAR_ptr[3] = ui->CAR3;

//    Initialize Car's position by Label geometry
    for (int i=0; i<CAR_count; i++)
    {
        CAR_ang[i] = 90.0;
        CAR_rot[i].rotate(0);
        CAR_ptr[i]->setPixmap(CAR_img[i].transformed(CAR_rot[i]));
        test_game.carList[i]->setX(CAR_ptr[i]->geometry().x());
        test_game.carList[i]->setY(CAR_ptr[i]->geometry().y());
        CAR_ptr[i]->setGeometry(test_game.carList[i]->getX(),test_game.carList[i]->getY(),80,80);
        connect(test_game.carList[i], SIGNAL(racefinish()), this, SLOT(raceover()));
    }

//    Update By Qtimer(60fps)
    connect(test_game.m_timer, SIGNAL(timeout()), this, SLOT(gui_update()));

//    connect(ui->actionSTART,  SIGNAL(triggered()), this, SLOT(start()));
    connect(ui->actionPAUSE,  SIGNAL(triggered()), this, SLOT(pause()));
    connect(ui->actionRESUME,  SIGNAL(triggered()), this, SLOT(resume()));
    connect(ui->actionEXIT,  SIGNAL(triggered()), this, SLOT(exit()));

    connect(ui->pushButton,  SIGNAL(clicked()), this, SLOT(start()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    now_pause = false;
    ui->actionSTART->setEnabled(false);
    ui->actionPAUSE->setEnabled(true);

    test_game.startRace();
}

void MainWindow::pause()
{
    now_pause = true;
    ui->actionPAUSE->setEnabled(false);
    ui->actionRESUME->setEnabled(true);

    test_game.pauseRace();
}

void MainWindow::resume()
{
    now_pause = false;
    ui->actionPAUSE->setEnabled(true);
    ui->actionRESUME->setEnabled(false);

    test_game.resumeRace();
}

void MainWindow::exit()
{
    close();
}

void MainWindow::raceover()
{
    now_pause = true;
    ui->actionPAUSE->setEnabled(false);
    ui->actionRESUME->setEnabled(true);
    test_game.pauseRace();

    int WIN;
    int len=999;
    for (int i=0; i<CAR_count; i++)
    {
        int X = CAR_ptr[i]->geometry().x();
        int Y = CAR_ptr[i]->geometry().y();
        int nowlen = (95-X)*(95-X)+(650-Y)*(650-Y);
        if (nowlen<len)
        {
            nowlen = len;
            WIN = i;
        }
    }
    QString color[4] = {"Black","Red","Blue","Yellow"};
    QMessageBox::information(this,
            tr("Race Finish"),
            tr("%1 is Winner").arg(color[WIN]));
    close();
}

void MainWindow::gui_update()
{
    for (int i=0; i<CAR_count; i++)
    {
        CAR_rot[i].rotate(-(test_game.carList[i]->getAngle()-CAR_ang[i]));
        CAR_ang[i] = test_game.carList[i]->getAngle();
        CAR_ptr[i]->setPixmap(CAR_img[i].transformed(CAR_rot[i]));
        CAR_ptr[i]->setGeometry(test_game.carList[i]->getX(),test_game.carList[i]->getY(),70,70);
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (now_pause)
    {
        keyReleaseEvent(event);
        return;
    }
    switch (event->key()) {
//    For CAR0
    case Qt::Key_W:
        test_game.keys[0][0] = true;
        break;
    case Qt::Key_A:
        test_game.keys[0][1] = true;
        break;
    case Qt::Key_S:
        test_game.keys[0][2] = true;
        break;
    case Qt::Key_D:
        test_game.keys[0][3] = true;
        break;


//    For CAR1
    case Qt::Key_Up:
        test_game.keys[1][0] = true;
        break;
    case Qt::Key_Left:
        test_game.keys[1][1] = true;
        break;
    case Qt::Key_Down:
        test_game.keys[1][2] = true;
        break;
    case Qt::Key_Right:
        test_game.keys[1][3] = true;
        break;

//    For CAR2
    case Qt::Key_Y:
        test_game.keys[2][0] = true;
        break;
    case Qt::Key_G:
        test_game.keys[2][1] = true;
        break;
    case Qt::Key_H:
        test_game.keys[2][2] = true;
        break;
    case Qt::Key_J:
        test_game.keys[2][3] = true;
        break;

//    For CAR3
    case Qt::Key_P:
        test_game.keys[3][0] = true;
        break;
    case Qt::Key_L:
        test_game.keys[3][1] = true;
        break;
    case Qt::Key_Semicolon:
        test_game.keys[3][2] = true;
        break;
    case Qt::Key_Apostrophe:
        test_game.keys[3][3] = true;
        break;
    }
}
void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    switch (event->key()) {
//    For CAR0
    case Qt::Key_W:
        test_game.keys[0][0] = false;
        break;
    case Qt::Key_A:
        test_game.keys[0][1] = false;
        break;
    case Qt::Key_S:
        test_game.keys[0][2] = false;
        break;
    case Qt::Key_D:
        test_game.keys[0][3] = false;
        break;

//    For CAR1
    case Qt::Key_Up:
        test_game.keys[1][0] = false;
        break;
    case Qt::Key_Left:
        test_game.keys[1][1] = false;
        break;
    case Qt::Key_Down:
        test_game.keys[1][2] = false;
        break;
    case Qt::Key_Right:
        test_game.keys[1][3] = false;
        break;

//    For CAR2
    case Qt::Key_Y:
        test_game.keys[2][0] = false;
        break;
    case Qt::Key_G:
        test_game.keys[2][1] = false;
        break;
    case Qt::Key_H:
        test_game.keys[2][2] = false;
        break;
    case Qt::Key_J:
        test_game.keys[2][3] = false;
        break;

//    For CAR3
    case Qt::Key_P:
        test_game.keys[3][0] = false;
        break;
    case Qt::Key_L:
        test_game.keys[3][1] = false;
        break;
    case Qt::Key_Semicolon:
        test_game.keys[3][2] = false;
        break;
    case Qt::Key_Apostrophe:
        test_game.keys[3][3] = false;
        break;
    }
}
