#include "Car.h"
#include <iostream>

Car::Car() : Status(&speed, &heading_angle, &location, &steering_angle)
{   
    driverinput = new DriverInput(speed_ptr, heading_angle_ptr, location_ptr, steering_angle_ptr);
    lkas = new LKAS(speed_ptr, heading_angle_ptr, location_ptr, steering_angle_ptr);
    std::cout<<"Car Constructor\n";
};

Car::~Car()
{
    delete driverinput;
    delete lkas;
    std::cout<<"Car Destructor\n";
};