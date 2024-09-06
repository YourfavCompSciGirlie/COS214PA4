#include "DeliveryTruck.h"
#include "Truck.h"
#include <iostream>
using namespace std;

DeliveryTruck::DeliveryTruck() : soilTexture("Unknown"), storageCapacity(0) {
    cout << "🚚 A new DeliveryTruck has been assembled and is ready to hit the road! 🚜" << endl;
    cout << "🛢️ Soil Texture: " << soilTexture << " | Storage Capacity: " << storageCapacity << " tons" << endl;
}

// Destructor
DeliveryTruck::~DeliveryTruck() {
    cout << "🔧 The DeliveryTruck is retiring from service. Time to unload and rest! 🌙" << endl;
}
void DeliveryTruck::startEngine()
{
        std::cout << "Delivery truck engine started. Heading to crop field for harvest collection...\n";
        std::cout << "Crops successfully collected and transported to storage facility.\n";
}

void DeliveryTruck::callTruck()
{
   startEngine();
}