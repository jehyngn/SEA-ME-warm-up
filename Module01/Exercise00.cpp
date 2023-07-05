// Orthodox Canonical Form

#include <iostream>
#include <string>

class Car
{
private:
    /* data */
public:
    std::string name;
    int speed;

    // Default Constructor(case1)
    Car(){
        name = "Default name";
        speed = 0;
    };

    // Default Constructor(case2)
    Car(std::string name, int speed);

    // Copy Constructor
    Car(const Car& origin_car);
    
    // Copy Assignment Operator
    Car& operator=(const Car& origin_car);

    // Destructor
    ~Car();

    void Display();
};

void Car::Display(){
    std::cout << "Car's name: " << this->name << " / Maximum Speed: " << this->speed << '\n';
}

// Default Constructor
Car::Car(std::string name, int speed)
{
    std::cout<<"Default Constructor Called!\n";
    this->name = name;
    this->speed = speed;
}

// Copy Constructor
Car::Car(const Car& origin_car)
{
    std::cout<<"Copy Constructor is Called!\n";
    this->name = origin_car.name;
    this->speed = origin_car.speed;
}

// Copy Assignment Operator
Car& Car::operator=(const Car& origin_car)
{
    std::cout<<"Copy Assignment Operator is Called!\n";
    this->name = origin_car.name;
    this->speed = origin_car.speed;
    return *this;
}

// Destructor
Car::~Car()
{
    std::cout<<"Destructor Called!\n";
}

int main(){

    // Default Constructor(case1)
    Car car0;
    car0.Display();

    // Default Constructor(case2)
    Car car1("Wolkswagen", 200);
    car1.Display();

    // Copy Constructor
    Car car2 = car1;
    car2.name = "BMW";
    car2.speed = 300;
    car2.Display();

    // Copy Assignment Operator
    Car car3;
    car3 = car1;
    car3.name = "HYUNDAI";
    car3.speed = 500;
    car3.Display();
    
    return 0;
}