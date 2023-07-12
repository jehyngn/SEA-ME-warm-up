#include <iostream>


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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class DriverInput : public Status
{
public:
    DriverInput(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr);
    ~DriverInput();

    void Driver_SteeringAngle(int driver_steering_angle);
    void Driver_Speed(int driver_speed);
};

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



////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class LKAS : public Status
{
public:
    LKAS(int *speed_ptr, int *heading_angle_ptr, int *location_ptr, int *steering_angle_ptr);
    ~LKAS();

    void LKAS_SteeringAngle(int lkas_steering_angle);
    void LKAS_Speed(int lkas_speed); 
};


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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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