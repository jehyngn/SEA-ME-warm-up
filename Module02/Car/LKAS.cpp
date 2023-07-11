#include "LKAS.h"
#include <iostream>

LKAS::LKAS(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr) : Status(speed_ptr, heading_angle_ptr, location_ptr, steering_angle_ptr) 
{
    std::cout<<"LKAS Constructor\n";
};

LKAS::~LKAS() {std::cout<<"LKAS Destructor\n";};

void LKAS::LKAS_SteeringAngle(int lkas_steering_angle)
{
    (*steering_angle_ptr) = lkas_steering_angle;
};

void LKAS::LKAS_Speed(int lkas_speed)
{
    (*speed_ptr) = lkas_speed;
};