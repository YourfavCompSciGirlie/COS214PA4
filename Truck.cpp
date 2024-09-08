// Class implementation for Component 4 - Observer (Observer)

/**
 * @file Truck.cpp
 * @brief Implementation of the Truck class (Observer in the Observer Pattern).
 */

#include "Truck.h"

#include <iostream>

using namespace std;

/**
 * @brief Constructor for the Truck class.
 * 
 * Initializes a new Truck object with a message indicating its readiness for service.
 */
Truck::Truck() {
    cout << "🚛 A new Truck is being built! Ready to serve the farm with power and reliability! ⚙️" << endl;
}

/**
 * @brief Destructor for the Truck class.
 * 
 * Cleans up the Truck object with a message indicating its retirement.
 */
Truck::~Truck() {
    cout << "🏁 The Truck has completed its duties and is now retiring from the fleet. Goodbye, old friend! 🛠️" << endl;
}
