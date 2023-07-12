#include "person.h"

Person::Person(QString name="", QString phone="", QString email="", QString address="", bool bookmark=false)
    : name(name), phone(phone), email(email), address(address), bookmark(bookmark) {}

Person::~Person() {}
