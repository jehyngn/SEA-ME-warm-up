#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "person.h"
#include <QVector>
#include <QString>
#include <vector>

class PhoneBook
{
public:
    PhoneBook();
    ~PhoneBook();

    int size();

    void add(Person person);
    bool is_name_in_list(QString oldname);
    bool is_phone_in_list(QString oldphone);
    bool is_email_in_list(QString oldemail);
    bool is_address_in_list(QString oldaddress);
    int search(QString oldname);
    Person index_search(int index);
    void remove(int index);
    void bookmark(int index);
    bool is_bookmarked(int index);

    QVector<Person> PB;
};

#endif // PHONEBOOK_H
