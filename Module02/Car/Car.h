#pragma once
#include "Status.h"
#include "DriverInput.h"
#include "LKAS.h"

class Car : public Status
{
public:    
    int speed=0;
    int heading_angle=0;
    int location=0;
    int steering_angle=0;
    DriverInput *driverinput;
    LKAS *lkas;
    Car();
    ~Car(); 
};