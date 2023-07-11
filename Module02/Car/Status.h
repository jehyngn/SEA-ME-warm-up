#pragma once

class Status
{
public:
    int *speed_ptr;
    int *heading_angle_ptr;
    int *location_ptr;
    int *steering_angle_ptr;
    Status(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr);
    ~Status();

    void HeadingAngle();
    void Location();
};