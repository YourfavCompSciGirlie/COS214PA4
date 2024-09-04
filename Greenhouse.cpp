// Class implementation for Component 1 - Composite (Leaf)

#include "Greenhouse.h"

#include <iostream>

using namespace std;

Greenhouse::Greenhouse(int totalCapacity) : totalCapacity(totalCapacity), currentAmount(0) {
    // Set a default crop type for the greenhouse, could be customized as needed
    cropType = "Tomatoes Crop";

    cout << "[Greenhouse] A new greenhouse with a total capacity of " << totalCapacity << " units and has been established. 🌿🌡️" << endl;
}

Greenhouse::~Greenhouse() {
    cout << "[Greenhouse] The greenhouse has been closed down. 🌿❄️" << endl;
}

int Greenhouse::getTotalCapacity() {
    return totalCapacity;
}

std::string Greenhouse::getCropType() {
    return cropType; // Return the type of crop grown in the greenhouse
}

std::string Greenhouse::getSoilStateName() {
    return "N/A"; // Greenhouses may not directly handle soil states; return "N/A"
}

int Greenhouse::getCurrentAmount() {
    return currentAmount; // Return the current amount of crops in the greenhouse
}

void Greenhouse::setCurrentAmount(int amount) {
    if (amount >= 0 && amount <= totalCapacity) {
        currentAmount = amount; // Set the current amount if within valid range
        cout << "[Greenhouse] Current amount set to " << currentAmount << " units. 🌿📦" << endl;
    } else {
        cout << "[Greenhouse] Error: Amount must be between 0 and " << totalCapacity << " units. 🚫" << endl;
    }
}
