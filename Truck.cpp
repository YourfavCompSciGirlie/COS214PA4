// Class implementation for Component 4 - Observer (Observer)

#include "Truck.h"

#include <iostream>

using namespace std;


Truck::Truck() {
    cout << "🚛 A new Truck is being built! Ready to serve the farm with power and reliability! ⚙️" << endl;
}


Truck::~Truck() {
    cout << "🏁 The Truck has completed its duties and is now retiring from the fleet. Goodbye, old friend! 🛠️" << endl;
}
