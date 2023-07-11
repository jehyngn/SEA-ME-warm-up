#include "DriverInput.h"
#include <iostream>

DriverInput::DriverInput(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr) : Status(speed_ptr, heading_angle_ptr, location_ptr, steering_angle_ptr) 
{
    std::cout<<"DriverInput Constructor\n";
};

DriverInput::~DriverInput() {std::cout<<"DriverInput Destructor\n";};

void DriverInput::Driver_SteeringAngle(int driver_steering_angle)
{
    (*steering_angle_ptr) = driver_steering_angle;
};

void DriverInput::Driver_Speed(int driver_speed)
{
    (*speed_ptr) = driver_speed;
};