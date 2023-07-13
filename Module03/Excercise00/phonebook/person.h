#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
public:
    Person();
    Person(QString name, QString phone, QString email, QString address, bool bookmark);
    ~Person();
    QString name;
    QString phone;
    QString email;
    QString address;
    bool bookmark;
    friend QDataStream& operator>>(QDataStream& in, Person& person) {
        in >> person.name;
        in >> person.phone;
        in >> person.email;
        in >> person.address;
        return in;
    }

    friend QDataStream& operator<<(QDataStream& out, const Person& person) {
        out << person.name;
        out << person.phone;
        out << person.email;
        out << person.address;
        return out;
    }
};

#endif // PERSON_H
