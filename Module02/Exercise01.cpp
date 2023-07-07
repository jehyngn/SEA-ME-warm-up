#include <iostream>

class Part {
public:
    virtual void print() = 0; // Pure virtual function to be overridden by derived classes
};

class Engine : public Part {
public:
    void print() override {
        std::cout << "Engine part\n";
    }
};

class Wheel : public Part {
public:
    void print() override {
        std::cout << "Wheel part\n";
    }
};

class Brake : public Part {
public:
    void print() override {
        std::cout << "Brake part\n";
    }
};

class Transmission : public Part {
public:
    void print() override {
        std::cout << "Transmission part\n";
    }
};


class Car {
private:
    // Declare pointer of each classes.
    Engine* engine_;
    Wheel* wheels_;
    Brake* brakes_;
    Transmission* transmission_;
    
public:
    Car() {
        // Allocate memories to each objects
        engine_ = new Engine();
        wheels_ = new Wheel[4];
        brakes_ = new Brake[4];
        transmission_ = new Transmission();
    }
    
    void printParts() {
        engine_->print();
        // (*engine_).print();

        // (*(wheels_+1)).print();

        for (int i = 0; i < 4; ++i) {
            (*(wheels_+i)).print();
            // wheels_[i].print();
            brakes_[i].print();
        }
        transmission_->print();
    }
    
    ~Car() {
        delete engine_;
        delete [] wheels_;
        delete [] brakes_;
        delete transmission_;
    }
};

int main() {
    Car myCar;
    myCar.printParts();
    
    return 0;
}