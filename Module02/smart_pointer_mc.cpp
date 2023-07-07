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
    std::cout<<make<<'\t'<<model<<'\t'<<year<<'\n';
    std::cout << "Drive function of Car class is called" << '\n';
}

int main(){
    // 1. Unique Pointer
    // Without Variables
    std::unique_ptr<Car> car0_ptr = std::make_unique<Car>();
    (*car0_ptr).make = "VW";
    (*car0_ptr).model = "Golf";
    (*car0_ptr).year = 2006;
    (*car0_ptr).drive();

    // With Variables
    std::unique_ptr<Car> car1_ptr = std::make_unique<Car>("AUDI", "A6", 2018);
    (*car1_ptr).drive();

    // Move Function
    std::unique_ptr<Car> new1ptr;
    new1ptr = move(car1_ptr);
    // (*car1_ptr).drive();
    (*new1ptr).drive();
    auto new2ptr = move(new1ptr);
    (*new2ptr).drive();
    
    std::cout<<"========================================================\n";

    // 2. Shared Pointer
    // Without Variables
    std::shared_ptr<Car> car2_ptr = std::make_shared<Car>();
    std::shared_ptr<Car> car1_ptr(new Car);

    (*car2_ptr).make = "VW";
    (*car2_ptr).model = "Golf";
    (*car2_ptr).year = 2006;
    (*car2_ptr).drive();

    // With Variables
    std::shared_ptr<Car> car3_ptr = std::make_shared<Car>("AUDI", "A6", 2018);
    (*car3_ptr).drive();

    // Copy Shared Pointer
    auto new3ptr = car3_ptr;
    (*car3_ptr).drive();
    (*new3ptr).drive();

    // Copy and Erase Shared Pointer (car3_ptr not work)
    auto new4ptr = move(car3_ptr);
    (*new4ptr).drive();
    std::cout<<new4ptr.use_count()<<'\n';

    std::shared_ptr<Car> car4_ptr = std::make_shared<Car>("AUDI", "A6", 2018);
    // PORSCHE got 'Values' of *car4_ptr
    Car PORSCHE = *car4_ptr;
    PORSCHE.make = "PORSCHE";
    PORSCHE.model = "PANAMERA";
    PORSCHE.year = 2020;
    PORSCHE.drive();
    (*car4_ptr).drive(); 
    std::cout<<car4_ptr.use_count()<<'\n';    

    std::shared_ptr<Car> shared_ptr;
    // Changes in car4_ptr = Changes in shared_ptr
    shared_ptr = car4_ptr;
    (*car4_ptr).make = "PORSCHE";
    (*car4_ptr).model = "PANAMERA";
    (*car4_ptr).year = 2020;
    (*shared_ptr).drive();

    // Make Reference count 0 for Erase
    std::cout<<car4_ptr.use_count()<<'\n';
    shared_ptr.reset();
    std::cout<<car4_ptr.use_count()<<'\n';
    // Here, Car Destructor is called
    car4_ptr.reset();

    std::cout<<"========================================================\n";

    // 3. Shared Pointer

    return 0;
}