#include <iostream>
#include <string>
#include <cmath>

// Abstraction(Parents) class
class Car
{
public:
    // member variables
    std::string make;
    std::string name;
    int year;

    // construcrtor & destructor
    Car() : make("HYUNDAR"), name("AVENTE"), year(2014) {}
    Car(std::string make, std::string name, int year) : make(make), name(name), year(year) {}
    ~Car() {}

    // member function
    void drive();

    // virtual member functions
    virtual void accel(int power)=0;

};

void Car::drive()
{
    std::cout << "Make: " << this->make << "\tName: " << this->name << "\tYear: " << this->year;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Son Class1 
class SportsCar : public Car{
    public:
        // member variable
        int top_speed;
        int speed;

        // constructor
        SportsCar(std::string make, std::string name, int year, int top_speed, int speed) 
            :  Car(make, name, year), top_speed(top_speed), speed(speed) {}
        ~SportsCar() {}

        // member function
        void drive();

        // virtual member functions
        virtual void accel(int power);
};

// Define member function
void SportsCar::drive()
{
    std::cout<<'\n';
    Car::drive();
    std::cout << "\tTop Speed: " << this->top_speed << '\n';
}

// Define memver function
void SportsCar::accel(int power)
{
    std::cout << this->name << " is accelling!!\n";
    this->speed = power + sin(power);
    std::cout << this->name << "'s Speed is: " << this->speed << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Son Class2
class SUV : public Car{
    public:
        // member variable
        double speed;
        int torque;

        // constructor & destructor
        SUV(std::string make, std::string name, int year, int speed, int torque)
            : Car(make, name, year), speed(speed), torque(torque) {}
        ~SUV() {}

        // member function
        void drive();

        // virtual member functions
        virtual void accel(int power);
};

// Define member function
void SUV::drive()
{
    std::cout<<'\n';
    Car::drive();
    std::cout << "\tTorque: " << this->torque << '\n';
}


// Define memver function
void SUV::accel(int power)
{
    std::cout << this->name << " is accelling!!\n";
    this->speed =  0.5 * power + sin(power);
    std::cout << this->name << "'s Speed is: " << this->speed << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SportSUV : public Car{
    protected:
        SportsCar Scar;
        SUV Suv;

    public:
        int speed;

        // constructor & destructor
        SportSUV(std::string make, std::string name, int year, int top_speed, int speed, int torque)
            : Car(make, name, year), Scar(make, name, year, top_speed, speed), Suv(make, name, year, speed, torque) {}

        ~SportSUV() {}

        virtual void accel(int power);
};


void SportSUV::accel(int power)
{
    std::cout << this->name << " is accelling!!\n";
    this->speed =  0.5 * power + sin(power);
    std::cout << this->name << "'s Speed is: " << this->speed << "\n";
}


int main(){
    // // Declare Object of SportsCar
    // SportsCar Audi("Audi", "X5", 2023, 300);
    // // Acceleration
    // Audi.accel(200);
    // Audi.drive();

    // // Declare Object of SUV
    // SUV Landrover("Landrover", "Rover", 2024, 250);
    // // Acceleration
    // Landrover.accel(200);
    // Audi.drive();
    
    // Declare Object of SportSUV(Combinated Class)
    SportSUV Urus("Rambo", "Urus", 2023, 400, 0, 100);
    std::cout << Urus.name <<'\n';
}