#include <iostream>

class Status {
    private:
        int speed;

    public:
        int& getSpeed(){ // return address of speed
            return speed;
        }
};

class LKAS {
    private:
        Status& status // 
}