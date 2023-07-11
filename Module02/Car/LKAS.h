#pragma once
#include "Status.h"

class LKAS : public Status
{
public:
    LKAS(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr);
    ~LKAS();

    void LKAS_SteeringAngle(int lkas_steering_angle);
    void LKAS_Speed(int lkas_speed); 
};