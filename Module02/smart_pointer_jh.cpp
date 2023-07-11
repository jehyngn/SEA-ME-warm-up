#include <iostream>
#include <memory>

class Car
{
// public access specifier
public:
    // member variable 
    std::string make;
    std::string model;
    int year;
    // Default constructor
    Car()
    : make("Default"), model("Default"), year(0) {std::cout<<"Car Default constructor"<<'\n';};
    Car(std::string make, std::string model, int year) 
    : make(make), model(model), year(year) {{std::cout<<"Car Default constructor(with parameters)"<<'\n';}};

    // Copy constructor
    Car(const Car& car)
    : make(car.make), model(car.model), year(car.year) {std::cout << "Car Copy constructor" << '\n';};

    // Copy Assignment Operator
    Car& operator=(const Car& car) {std::cout << "Car Copy Assignmnet Operator" << '\n'; return *this = car;};

    // Destructor
    ~Car(){std::cout<<"Car Destructor called"<<'\n';};
    
    // member function
    void drive();
};

// Define member function
void Car::drive(){
    std::cout << "Drive function of Car class is called" << '\n';
    std::cout<<make<<'\t'<<model<<'\t'<<year<<'\n';
}

int main(){

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 1. Unique Pointer

    // Two form of declare unique pointer
    // std::unique_ptr<Car> car_ptr1(new Car());
    std::unique_ptr<Car> car_ptr2 = std::make_unique<Car>("KIA", "EV6", 2022); // its recommended 

    // Same means but upper one is better(brief, readability)
    // car_ptr1->drive(); 
    (*car_ptr2).drive();

    // Move function
    // std::unique_ptr<Car> car_move_ptr;
    // car_move_ptr = move(car_ptr);
    // car_move_ptr->drive();
    // Below two line is not work because 'car_ptr1' is not a pointer anymore(the ownership is moved to 'car_move_ptr')
     // car_ptr1->drive()
    // std::cout << car_ptr1->make; 

    auto copy_ptr = move(car_ptr2);
    // copy_ptr->drive();
    car_ptr2->drive();

    std::cout << "=======================================\n";

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // 2. Shared Pointer

    // Without Variables
    std::shared_ptr<Car> shared_car_ptr1 = std::make_shared<Car>();
    shared_car_ptr1->make = "VolksWagen";
    shared_car_ptr1->model = "Golf";
    shared_car_ptr1->year = 2010;
    shared_car_ptr1->drive();

    // With Variables
    std::shared_ptr<Car> shared_car_ptr2 = std::make_shared<Car>("HYUNDAI", "IONIC6", 2022);
    // Copy shared pointer(2 -> 3)
    auto shared_car_ptr3 = shared_car_ptr2;


    shared_car_ptr2->drive();
    std::cout << "Btween\n";
    shared_car_ptr3->drive();

    std::cout << shared_car_ptr3.use_count() << '\n'; // 2
    std::cout << shared_car_ptr2.use_count() << '\n'; // 2

    // Move pointer(2 -> 4) (Copy and Erase)
    // then, the ownership is move 2 to 4, pointer 2 is empty.
    auto shared_car_ptr4 = move(shared_car_ptr2);
    std::cout << shared_car_ptr4.use_count() << '\n'; // 2

    // PROSCHE got 'Variables" of shared_car_ptr1, Not share address.
    Car PORSCHE = *shared_car_ptr1;
    PORSCHE.make = "PORSCHE";
    PORSCHE.model = "PANAMERA";
    PORSCHE.year = 2020;
    PORSCHE.drive(); // PORSCHE PANAMERA 2020
    shared_car_ptr1->drive(); // VoklsWagen Golf 2010
    std::cout << shared_car_ptr1.use_count() << '\n'; // 1

    // 'copy_shared_ptr' got adress of 'shared_car_ptr1', They are sharing the address.
    std::shared_ptr<Car> copy_shared_ptr;
    copy_shared_ptr = shared_car_ptr1;
    std::cout << shared_car_ptr1.use_count() << '\n'; // 2
    std::cout << "before: ";
    shared_car_ptr1->drive();
    copy_shared_ptr->drive();
    shared_car_ptr1->make = "PORSCHE";
    shared_car_ptr1->model = "PANAMERA";
    shared_car_ptr1->year = 2020;
    std::cout << "after: ";
    shared_car_ptr1->drive();
    copy_shared_ptr->drive();

    // Make reference count 0 for Erasing
    std::cout << shared_car_ptr1.use_count() << '\n'; // 2
    shared_car_ptr1.reset();
    std::cout << copy_shared_ptr.use_count() << '\n'; // 1 
    // Here, Car Destructor is called
    copy_shared_ptr.reset();

    return 0;
}