#pragma once
#include "Status.h"
class DriverInput : public Status
{
public:
    DriverInput(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr);
    ~DriverInput();

    void Driver_SteeringAngle(int driver_steering_angle);
    void Driver_Speed(int driver_speed);
};