#include "phonebook.h"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

int PhoneBook::size()
{
    return (int)PB.size();
}

void PhoneBook::add(Person person)
{
    PB.push_back(person);
}

bool PhoneBook::is_name_in_list(QString oldname)
{
    for(int i=0;i<(int)PB.size();i++){
        if (oldname == PB[i].name) return true;
    }
    return false;
}

bool PhoneBook::is_phone_in_list(QString oldphone)
{
    for(int i=0;i<(int)PB.size();i++){
        if (oldphone == PB[i].phone) return true;
    }
    return false;
}

bool PhoneBook::is_email_in_list(QString oldemail)
{
    for(int i=0;i<(int)PB.size();i++){
        if (oldemail == PB[i].email) return true;
    }
    return false;
}

bool PhoneBook::is_address_in_list(QString oldaddress)
{
    for(int i=0;i<(int)PB.size();i++){
        if (oldaddress == PB[i].address) return true;
    }
    return false;
}

int PhoneBook::search(QString oldname)
{
    Person tempperson("","","","",false);
    for(int i=0;i<(int)PB.size();i++){
        if (oldname == PB[i].name) return i;
    }
    return -1;
}

Person PhoneBook::index_search(int index)
{
    return PB[index];
}

void PhoneBook::remove(int index)
{
    PB.erase(PB.begin()+index);
}

void PhoneBook::bookmark(int index)
{
    PB[index].bookmark = true;
}

bool PhoneBook::is_bookmarked(int index)
{
    if (PB[index].bookmark){
        return true;
    }
    else{
        return false;
    }
}
