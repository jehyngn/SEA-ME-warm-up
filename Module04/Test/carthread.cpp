#include "carthread.h"
#include <QDebug>

CarThread::CarThread(Car *car) : car(car)
{

}
void CarThread::keymapping(bool* key1, bool* key2, bool* key3, bool* key4)
{
    Wkey = key1;
    Akey = key2;
    Skey = key3;
    Dkey = key4;
}
void CarThread::update()
{
    bool keys[4] = {*Wkey, *Akey, *Skey, *Dkey};
    car->update(keys);
}

void CarThread::run()
{
//    mutex.lock();
    car->move();
//    qDebug()<<car->getX();
//    mutex.unlock();
    msleep(1000.0f/60.0f);
    update();
}
