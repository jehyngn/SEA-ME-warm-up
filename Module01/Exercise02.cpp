#include <iostream>
#include <string>
#include <cmath>

// Abstraction(Parents) class (Can not be declared this class as Object)
class Car
{
protected: // Access Specifier
    // Member variables
    std::string make;
    std::string name;
    int year;

public: // Access Specifier
    // Default construcrtor
    Car() : make("HYUNDAI"), name("AVENTE"), year(2014) {std::cout<<"Car Default constructor"<<'\n';}
    Car(std::string make, std::string name, int year) : make(make), name(name), year(year) {std::cout<<"Car Default constructor"<<'\n';}

    // Copy constructor
    Car(const Car& car)
    : make(car.make), name(car.name), year(car.year) {std::cout << "Car Copy constructor" << '\n';};

    // Copy Assignment Operator
    Car& operator=(const Car& car) {std::cout << "Car Copy Assignmnet Operator" << '\n'; return *this = car;};

    // Destructor
    ~Car() {}

    // Member function
    void drive();

    // Virtual member functions(which is for Abstraction)
    virtual void accel(int power)=0;

};

// Define member function
void Car::drive()
{
    std::cout << "Make: " << this->make << "\tName: " << this->name << "\tYear: " << this->year;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Child Class1 (By Inheritance) 
class SportsCar : public Car{
    protected: // Access Specifier
        // member variable
        int top_speed;
        int speed;

    public: // Access Specifier
        // Default Constructor
        SportsCar()
        : Car(), top_speed(0), speed(0) {std::cout<<"SportsCar Default constructor"<<'\n';};
        SportsCar(std::string make, std::string name, int year, int top_speed, int speed) 
            :  Car(make, name, year), top_speed(top_speed), speed(speed) {std::cout<<"SportsCar Default constructor"<<'\n';}

        // Copy constructor
        SportsCar(const SportsCar& sportscar)
        : Car(sportscar), top_speed(sportscar.top_speed), speed(sportscar.speed) {std::cout << "SportsCar Copy constructor" << '\n';};

        // Copy Assignment Operator
        SportsCar& operator=(const SportsCar& sportscar){std::cout << "SportsCar Copy Assignmnet Operator" << '\n'; return *this = sportscar;};

        // Distructor
        ~SportsCar() {}

        // member function
        void drive();

        // virtual member functions
        virtual void accel(int power);
};

// Define member function (by using Parent's function)
void SportsCar::drive()
{
    std::cout<<'\n';
    Car::drive();
    std::cout << "\tTop Speed: " << this->top_speed << '\n';
}

// Re-define virtual member function
void SportsCar::accel(int power)
{
    std::cout << this->name << " is accelling!!\n";
    this->speed = power + sin(power);
    std::cout << this->name << "'s Speed is: " << this->speed << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Child Class2 (By Inheritance)
class SUV : public Car{
    protected: // Access Specifier
        // member variable
        double speed;
        int torque;

    public: // Access Specifier
        // default constructor
        SUV() : Car(), torque(0), speed(0) {std::cout<<"SUV Default constructor"<<'\n';};
        SUV(std::string make, std::string name, int year, int speed, int torque)
            : Car(make, name, year), speed(speed), torque(torque) {std::cout<<"SUV Default constructor"<<'\n';}

        // Copy constructor
        SUV(const SUV& suv)
        : Car(suv), torque(suv.torque), speed(suv.speed) {std::cout << "SUV Copy constructor" << '\n';};

        // Copy Assignment Operator
        SUV& operator=(const SUV& suv) {std::cout << "SUV Copy Assignmnet Operator" << '\n'; return *this = suv;};

        // distructor
        ~SUV() {}

        // member function
        void drive();

        // virtual member functions
        virtual void accel(int power);
};

// Define member function (by using Parent's function)
void SUV::drive()
{
    std::cout<<'\n';
    Car::drive();
    std::cout << "\tTorque: " << this->torque << '\n';
}

// Re-define virtual member function
void SUV::accel(int power)
{
    std::cout << this->name << " is accelling!!\n";
    this->speed =  0.5 * power + sin(power);
    std::cout << this->name << "'s Speed is: " << this->speed << "\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Simple Class
class Trailer
{
public: // Access Specifier
    int weight;
    std::string type;

    // Default Constructor
    Trailer()
    : weight(100), type("Default"){std::cout<<"Trailer Default constructor"<<'\n';};
    Trailer(int weight, std::string type)
    : weight(weight), type(type){std::cout<<"Trailer Default constructor"<<'\n';};

    // Copy constructor
    Trailer(const Trailer& trailer)
    : weight(trailer.weight), type(trailer.type){std::cout << "Trailer Copy constructor" << '\n';};

    // Copy Assignment Operator
    Trailer& operator=(const Trailer& trailer) {std::cout << "Trailer Copy Assignmnet Operator" << '\n'; return *this = trailer;};

    // Destructor
    ~Trailer(){std::cout<<"Trailer Destructor called"<<'\n';};
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Mutiple Inheritance Class

class CampingCar : public SUV, public Trailer
{
public: // Access Specifier
    // Default Constructor
    CampingCar()
    : SUV(), Trailer() {std::cout<<"CampingCar Default constructor"<<'\n';};
    CampingCar(std::string make, std::string name, int year, int torque, int speed, int weight, std::string type)
    : SUV(make, name, year, torque, speed), Trailer(weight, type) {std::cout<<"CampingCar Default constructor"<<'\n';};

    // Copy constructor
    CampingCar(const CampingCar& campingcar)
    : SUV(campingcar), Trailer(campingcar) {std::cout << "CampingCar Copy constructor" << '\n';};

    // Copy Assignment Operator
    CampingCar& operator=(const CampingCar& campingcar) {std::cout << "CampingCar Copy Assignmnet Operator" << '\n'; return *this = campingcar;};

    // Destructor
    ~CampingCar() {std::cout<<"CampingCar Destructor called"<<'\n';};
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Colaborate Two Class(SportsCar, SUV) by using inheritance Class(Car)
class SportSUV : public Car{
    protected: // Access Specifier
        // Declare member variable as Object.(This is just declaring not calling the constructor)
        SportsCar Scar;
        SUV Suv;

    public: // Access Specifier
        int speed; // need it because Car doesn't have this variable.

        // constructor & destructor
        // Constructor of Car, Scar, Suv is called by this constructor!!!
        SportSUV(std::string make, std::string name, int year, int top_speed, int speed, int torque)
            : Car(make, name, year), Scar(make, name, year, top_speed, speed), Suv(make, name, year, speed, torque) {}
            // Car: Class name, Scar, Suv: Objects name

        ~SportSUV() {}
        
        // You have to declare it because this class is abstraction class's inheritance class.
        virtual void accel(int power);

        // Function to check accessing to parent class's member variable.(Encapsulation)
        std::string getName(){return this->name;}
};

// Re-define virtual member function
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
    
    // for checking multiple inheritance class
    CampingCar Car;

    // std::cout << Urus.name <<'\n';
    // -> Can't Do like this because The member variable of Parent's Class can't access out of the Inherited class.
    // So I made a function access Parent's member variable in the Inherited class. 
    std::cout << Urus.getName() <<'\n';
}