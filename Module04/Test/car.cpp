#include "car.h"
#include <math.h>
#include <QDebug>

const double rad2deg = 3.14159265358979/180;

Car::Car()
{
    angle = 90;
    speed = 0;
    max_speed = 2;
    run_count = 1;
}

Car::~Car(){}

void Car::update(bool keys[4])
{
    if (keys[0])
    {
        change_Speed(0.1);
    }
    else if (keys[2])
    {
        change_Speed(-0.1);
    }
    else
    {
        setSpeed(speed*0.95);
    }

    if (keys[1])
    {
        change_Angle(2);
        changed_angle_in_this_period = 2;
    }
    else if (keys[3])
    {
        change_Angle(-2);
        changed_angle_in_this_period = -2;
    }
    else
    {
        changed_angle_in_this_period = 0;
    }
    //    Just use as signal
    emit positionChanged();
}

void Car::move()
{
//    Calculate location(x,y)
    x += speed*cos(angle*rad2deg);
    y -= speed*sin(angle*rad2deg);
    pass();
    collisionCheck();
}

void Car::collisionCheck()
{

//    int out_border[14] = {0,680, 0,20, 330,20, 330,155, 540,155, 540,680, 0,680};
//    int in_border[14] = {95,620, 95,75, 230,75, 230,290, 430,290, 430,620, 95,620};

//    Same x
    int dis_out = 0;
    int dis_in = 0;
    int threshold = 5;
    float speedfactor = 0.9;

    for (int i=0; i<12; i+=4)
    {
        dis_out = out_border[i]-x;
        if ((-threshold<dis_out) && (dis_out<threshold))
        {
            if (((out_border[i+1]-y)*(out_border[i+3]-y))<0)
            {
                x -= speed*cos(angle*rad2deg);
                y += speed*sin(angle*rad2deg);
                speed = speed*speedfactor;
                collisionCheck();
                return;
            }
        }
        dis_in = in_border[i]-x;
        if ((-threshold<dis_in) && (dis_in<threshold))
        {
            if (((in_border[i+1]-y)*(in_border[i+3]-y))<0)
            {
                x -= speed*cos(angle*rad2deg);
                y += speed*sin(angle*rad2deg);
                speed = speed*speedfactor;
                collisionCheck();
                return;
            }
        }
    }

//    Same y
    for (int i=3; i<14; i+=4)
    {
        dis_out = out_border[i]-y;
        if ((-threshold<dis_out) && (dis_out<threshold))
        {
            if (((out_border[i+1]-x)*(out_border[i-1]-x))<0)
            {
                x -= speed*cos(angle*rad2deg);
                y += speed*sin(angle*rad2deg);
                speed = speed*speedfactor;
                collisionCheck();
                return;
            }
        }
        dis_in = in_border[i]-y;
        if ((-threshold<dis_in) && (dis_in<threshold))
        {
            if (((in_border[i+1]-x)*(in_border[i-1]-x))<0)
            {
                x -= speed*cos(angle*rad2deg);
                y += speed*sin(angle*rad2deg);
                speed = speed*speedfactor;
                collisionCheck();
                return;
            }
        }
    }
    return;
}

void Car::change_Angle(float addition_angle)
{
    setAngle(angle + addition_angle);
}

void Car::change_Speed(float addition_speed)
{
    setSpeed(speed + addition_speed);
}

void Car::setAngle(float input_angle)
{
//    Angle Limitation
    while (input_angle<0){input_angle = input_angle+360;};
    while (input_angle>360) {input_angle = input_angle-360;};
    angle = input_angle;
}

void Car::setSpeed(float input_speed)
{
//    Speed Limitation
    if (-max_speed<input_speed && input_speed<max_speed){
        speed = input_speed;
    }
}

void Car::setX(float input_x)
{
    x = input_x;
}

void Car::setY(float input_y)
{
    y = input_y;
}

float Car::getCAITP()
{
    return changed_angle_in_this_period;
}

float Car::getAngle()
{
    return angle;
}

float Car::getSpeed()
{
    return speed;
}

float Car::getX()
{
    return x;
}

float Car::getY()
{
    return y;
}

void Car::pass()
{
    if(620<y && y<680) {
        if((95 - x-speed*cos(angle*rad2deg)) * (95 - x) < 0) {
            run_count -= 1;
        }
    }
    if (!run_count) emit racefinish();
}
