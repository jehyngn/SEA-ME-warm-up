#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person(QString name, QString phone, QString email, QString address, bool bookmark);
    ~Person();
    QString name;
    QString phone;
    QString email;
    QString address;
    bool bookmark;
};

#endif // PERSON_H
