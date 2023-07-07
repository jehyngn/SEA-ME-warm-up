#include <iostream>

class Point{
    public:
        int x, y;
        Point():x(0), y(0) {};
        Point(int X, int Y): x(X), y(Y) {};
        ~Point(){}
        
        void Print() const
        {
            std::cout << "(" << x << ", " << y << ")\n";
        }
};

class SmartPtr{
    protected:
        Point *ptr;

    public:
        SmartPtr(Point *p): ptr(p) {};
        ~SmartPtr()        
        {
            delete ptr;
        }
        
        Point *operator->() const
        {
            return ptr;
        }
};

int main(){
    SmartPtr p1 = new Point(2, 3);
    SmartPtr p2 = new Point(4, 4);
    std::cout << p1->x;

    p1 -> Print();
    p2 -> Print();

    return 0;
}