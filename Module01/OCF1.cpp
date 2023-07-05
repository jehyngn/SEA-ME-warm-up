#include <iostream>
#include <string>

class Car {
    public:
        std::string name;
        int speed;

        // Constructor
        Car(std::string name, int speed);

        // Copy constructor
        Car(const Car& or_car);

        // Copy assignment operator
        Car& operator=(const Car& or_car);

        // Destructor
        ~Car();

        // For display
        void display();
};


// Default constructor
Car::Car(std::string name, int speed){
    name = name;
    speed = speed;
} 

// Copy constructor
Car::Car(const Car& or_car){
    name = or_car.name;
    speed = or_car.speed;
}

// Copy Assignment Operator
Car& Car::operator=(const Car& or_car) {
    if (this != &or_car) {
        name = or_car.name;
        speed = or_car.speed;
    }
    return *this;
}

// Destructor
Car::~Car() {}


void Car::display() {
    std::cout << "Name: " << name << ", Speed: " << speed << '\n';
}

int main() {
    // Create a Car
    Car car1("Toyota", 60);
    car1.display();

    // Create a copy of Car
    Car car2 = car1;
    car2.display();

    car1.name = "Tesla";
    car1.display();
    car2.display();


    // Create anor_car Car and use the assignment operator
    Car car3("Honda", 80);
    car3 = car1;
    car3.display();

    return 0;
}
