#include <iostream>
#include "xMemoryManager.h"
#include "Car.h"

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    xMemoryManager *xM = new xMemoryManager();
    Car *myCar = new Car("BMW");

    return 0;
}