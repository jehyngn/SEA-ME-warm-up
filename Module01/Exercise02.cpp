#include <iostream>
#include <string>
#include <cmath>

// Abstraction(Parents) class
class Car
{
protected:
    // member variables
    std::string make;
    std::string name;
    int year;

public:
    // construcrtor & destructor
    Car() : make("HYUNDAI"), name("AVENTE"), year(2014) {}
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
    protected:
        // member variable
        int top_speed;
        int speed;

    public:
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
    protected:
        // member variable
        double speed;
        int torque;

    public:
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

// Colaborate Two Class(SportsCar, SUV) by using inheritance Class(Car)
class SportSUV : public Car{
    protected:
        // Declaring member variable as Object.(This is just declaring not calling the constructor)
        SportsCar Scar;
        SUV Suv;

    public:
        int speed; // need it because Car doesn't have this variable.

        // constructor & destructor
        SportSUV(std::string make, std::string name, int year, int top_speed, int speed, int torque)
            : Car(make, name, year), Scar(make, name, year, top_speed, speed), Suv(make, name, year, speed, torque) {}
            // Car: Class name, Scar, Suv: Objects name

        ~SportSUV() {}
        
        // You have to declare it because this class is abstraction class's inheritance class.
        virtual void accel(int power);

        std::string getName(){return this->name;}
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
    
    
    // std::cout << Urus.name <<'\n';
    // -> Can't Do like this because The member variable of Parent's Class can't access out of the Inherited class.
    // So I made a function access Parent's member variable in the Inherited class. 
    std::cout << Urus.getName() <<'\n';
}