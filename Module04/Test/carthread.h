#ifndef CARTHREAD_H
#define CARTHREAD_H

#include "car.h"
#include <QObject>
#include <QThread>


class CarThread : public QThread
{
    Q_OBJECT
public:
    CarThread(Car *car);
    void keymapping(bool* key1, bool* key2, bool* key3, bool* key4);

public slots:
    void run();
    void update();

private:
    Car *car;
    bool* Wkey;
    bool* Akey;
    bool* Skey;
    bool* Dkey;
    std::mutex mutex;
};

#endif // CARTHREAD_H
