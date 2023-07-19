#ifndef GAME_H
#define GAME_H

#include "car.h"
#include "carthread.h"

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QThread>

class game : public QGraphicsScene
{
    Q_OBJECT
public:
    game();
    QTimer* m_timer;
    QList<Car*> carList;
    QList<QThread*> threadList;
    bool keys[4][4] = {false};

public:
    void startRace();
    void pauseRace();
    void resumeRace();
};

#endif // GAME_H
