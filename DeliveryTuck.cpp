// Class implementation for Component 4 - Observer (ConcreteObserver)

/**
 * @file DeliveryTruck.cpp
 * @brief Implementation of the DeliveryTruck class.
 */

#include "DeliveryTruck.h"
#include "Truck.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor. Initializes the delivery truck with unknown soil texture and zero storage capacity.
 */
DeliveryTruck::DeliveryTruck() : soilTexture("Unknown"), storageCapacity(0) {
    cout << "🚚 A new DeliveryTruck has been assembled and is ready to hit the road! 🚜" << endl;
    cout << "Storage Capacity: " << storageCapacity << " tons" << endl;
}

/**
 * @brief Destructor. Indicates the retirement of the delivery truck.
 */
DeliveryTruck::~DeliveryTruck() {
    cout << "🔧 The DeliveryTruck is retiring from service. Time to unload and rest! 🌙" << endl;
}

/**
 * @brief Starts the engine of the delivery truck and simulates the collection and transportation of crops.
 */
void DeliveryTruck::startEngine() {
    std::cout << "Delivery truck engine started. Heading to crop field for harvest collection...\n";
    std::cout << "Crops successfully collected and transported to storage facility.\n";
}

/**
 * @brief Calls the truck to start the engine and begin the harvest collection process.
 */
void DeliveryTruck::callTruck() {
   startEngine();
}
