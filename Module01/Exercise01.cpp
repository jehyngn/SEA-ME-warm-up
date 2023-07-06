#include <iostream>
#include <string>

class Car
{
public:
    std::string make;
    std::string name;
    int year;

    Car();

    Car(std::string make, std::string name, int year);

    Car(const Car& origin);

    Car& operator=(const Car& origin);

    ~Car();

    void drive();
};

Car::Car()
{
    this->make = "HYUNDAI";
    this->name = "AVANTE";
    this->year = 2014;
}

Car::Car(std::string make, std::string name, int year)
{
    this->make = make;
    this->name = name;
    this->year = year;
}

Car::Car(const Car& origin)
{
    this->make = origin.make;
    this->name = origin.name;
    this->year = origin.year;
}

Car& Car::operator=(const Car& origin)
{
    this->make = origin.make;
    this->name = origin.name;
    this->year = origin.year;
}

Car::~Car()
{
}

void Car::drive()
{
    std::cout << "Make: " << this->make << "\tName: " << this->name << "\tYear: " << this->year;
}

class SportsCar : public Car{
    public:
        int top_speed;
        SportsCar(std::string make, std::string name, int year, int top_speed);
        void drive();

};

// SportsCar::SportsCar(std::string make, std::string name, int year, int top_speed) : Car(make, name, year)
// {
//     this->top_speed = top_speed;
// };

SportsCar::SportsCar(std::string make, std::string name, int year, int top_speed) : Car(make, name, year)
{
    this->top_speed = top_speed;
};

void SportsCar::drive()
{
    std::cout<<'\n';
    Car::drive();
    std::cout << "\tTop Speed: " << this->top_speed << '\n';
}

int main(){
    // Car car("BMW", "X5", 2023);
    // car.drive();
    SportsCar Scar("BMW", "X5", 2023, 300);

    Scar.drive();

}