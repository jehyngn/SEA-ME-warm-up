#include "Status.h"
#include <iostream>

Status::Status(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr) 
{
    this->speed_ptr = speed_ptr;
    this->heading_angle_ptr = heading_angle_ptr;
    this->location_ptr = location_ptr;
    this->steering_angle_ptr = steering_angle_ptr;
    std::cout<<"Status Contructor\n";
};

Status::~Status() {std::cout<<"Status Destructor\n";};

void Status::HeadingAngle()
{
    (*heading_angle_ptr) += (*steering_angle_ptr)*(*speed_ptr);
}

void Status::Location()
{
    (*location_ptr) += (*heading_angle_ptr)*(*speed_ptr);
};