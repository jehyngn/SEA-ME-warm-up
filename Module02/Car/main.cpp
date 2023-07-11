#include "Status.h"
#include "DriverInput.h"
#include "LKAS.h"
#include "Car.h"
#include <iostream>

int main()
{   
    // Declare Object
    Car Ferrari;
    std::cout<<Ferrari.speed_ptr<<'\n';
    std::cout<<&(Ferrari.speed)<<'\n';
    std::cout<<Ferrari.lkas->speed_ptr<<'\n';
    std::cout<<Ferrari.driverinput->speed_ptr<<'\n';
    std::cout<<"=================================================\n";
    
    // Change Speed
    Ferrari.speed = 100;
    std::cout<<Ferrari.speed<<'\n';
    std::cout<<*(Ferrari.speed_ptr)<<'\n';
    std::cout<<*(Ferrari.lkas->speed_ptr)<<'\n';
    std::cout<<"=================================================\n";

    // Use Function
    Ferrari.lkas->LKAS_Speed(1000);
    std::cout<<Ferrari.speed<<'\n';
    std::cout<<*(Ferrari.speed_ptr)<<'\n';
    std::cout<<*(Ferrari.lkas->speed_ptr)<<'\n';
    std::cout<<"=================================================\n";

    return 0;
}