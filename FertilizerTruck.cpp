// Class implementation for Component 4 - Observer (ConcreteObserver)

#include "FertilizerTruck.h"
#include "Truck.h"

#include <iostream>

using namespace std;


FertilizerTruck::FertilizerTruck() {
    cout << "🌾 A new FertilizerTruck is ready to spread nutrients across the fields! 🚛" << endl;
}


FertilizerTruck::~FertilizerTruck() {
    cout << "🌱 The FertilizerTruck has completed its mission and is heading back to the barn! 🏡" << endl;
}

void FertilizerTruck::startEngine()
{
        std::cout << "Fertilizer truck engine started. Delivering fertilizer to crop field...\n";
        std::cout << "Fertilizer delivered. Crop field is now ready for increased production.\n";
}


void FertilizerTruck::callTruck()
{
   startEngine();
}

