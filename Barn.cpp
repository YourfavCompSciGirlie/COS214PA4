// Class implementation for Component 1 - Composite (Leaf)

#include "Barn.h"

#include <iostream>

using namespace std;

Barn::Barn(int totalCapacity) : totalCapacity(totalCapacity), currentAmount(0) {
    cout << "[Barn] Constructing a new barn with a total capacity of " << totalCapacity << " units. 🏠🚜" << endl;
}

Barn::~Barn() {
    cout << "[Barn] The barn with a capacity of " << totalCapacity << " units has been demolished. 🏚️💥" << endl;
}

int Barn::getTotalCapacity() {
    return totalCapacity;
}

std::string Barn::getCropType() {
    return "N/A"; // Barns don't hold crops directly, so return "N/A"
}

std::string Barn::getSoilStateName() {
    return "N/A"; // Barns don't have soil states, so return "N/A"
}

int Barn::getCurrentAmount() {
    return currentAmount; // Return the current amount of stored crops
}

void Barn::setCurrentAmount(int amount) {
    if (amount >= 0 && amount <= totalCapacity) {
        currentAmount = amount; // Set the current amount if within valid range
        cout << "[Barn] Current amount set to " << currentAmount << " units. 📦" << endl;
    } else {
        cout << "[Barn] Error: Amount must be between 0 and " << totalCapacity << " units. 🚫" << endl;
    }
}