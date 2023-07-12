#include "person.h"

Person::Person(): Person("", "", "", "", false) {}

Person::Person(QString name, QString phone, QString email, QString address, bool bookmark)
    : name(name), phone(phone), email(email), address(address), bookmark(bookmark) {}

Person::~Person() {}
