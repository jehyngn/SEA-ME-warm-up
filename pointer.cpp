#include <iostream>
using namespace std;
 
void swapNums(int* &x, int* &y) {

  cout << x << ' ' << y << "\n";  
  int* z = x;
  x = y;
  y = z;
  cout << x <<' ' << y << "\n";
}

int main() {
  int firstNum = 10;
  int secondNum = 20;

  cout << "Before swap: " << "\n";
  cout << firstNum << secondNum << "\n";
// cout << &firstNum <<' '<< &secondNum << "\n";


  int* a_num1 = &firstNum;
  int* a_num2 = &secondNum;

// cout << a_num1 <<' '<< a_num2 << "\n";
  
//   int* z = a_num1;
//   a_num1 = a_num2;
//   a_num2 = z;

  swapNums(a_num1, a_num2);

// cout << a_num1 <<' '<< a_num2 << "\n";

  cout << "After swap: " << "\n";
//   cout << &firstNum <<' '<< &secondNum << "\n";
  cout << firstNum << secondNum << "\n";

  return 0;
}