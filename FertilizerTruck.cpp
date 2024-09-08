// Class implementation for Component 4 - Observer (ConcreteObserver)

#include "FertilizerTruck.h"
#include "Truck.h"

#include <iostream>

using namespace std;


/**
 * @brief Constructs a new FertilizerTruck.
 * 
 * Initializes the FertilizerTruck with a message indicating readiness to operate.
 */
FertilizerTruck::FertilizerTruck() {
    cout << "🌾 A new FertilizerTruck is ready to spread nutrients across the fields! 🚛" << endl;
}

/**
 * @brief Destructs the FertilizerTruck.
 * 
 * Outputs a message when the FertilizerTruck is decommissioned and heading back.
 */
FertilizerTruck::~FertilizerTruck() {
    cout << "🌱 The FertilizerTruck has completed its mission and is heading back to the barn! 🏡" << endl;
}


/**
 * @brief Starts the engine of the FertilizerTruck.
 * 
 * Delivers fertilizer to the crop field and prepares it for increased production.
 */
void FertilizerTruck::startEngine()
{
        std::cout << "Fertilizer truck engine started. Delivering fertilizer to crop field...\n";
        std::cout << "Fertilizer delivered. Crop field is now ready for increased production.\n";
}

/**
 * @brief Calls the FertilizerTruck to start the engine.
 * 
 * Calls the `startEngine()` method to deliver fertilizer.
 */
void FertilizerTruck::callTruck()
{
   startEngine();
}

