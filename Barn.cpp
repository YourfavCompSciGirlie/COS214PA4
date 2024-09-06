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

// Decorator pattern methods
void Barn::increaseProduction() {
    cout << "[Barn] Increase production is not applicable for a barn. No change in production. 🚫" << endl;
}

void Barn::harvest() {
    cout << "[Barn] Harvesting is not applicable for a barn. No crops to harvest. 🚫" << endl;
}

int Barn::getLeftoverCapacity() {
    return totalCapacity - currentAmount;
}

// Observer pattern methods
void Barn::buyTruck(Truck* truck) {
    // Implementation for buying a truck, if applicable
    cout << "[Barn] Buying a truck is not typically associated with barns. 🚛" << endl;
}

void Barn::sellTruck(Truck* truck) {
    // Implementation for selling a truck, if applicable
    cout << "[Barn] Selling a truck is not typically associated with barns. 🚛" << endl;
}

// Iterator pattern methods
FarmIterator* Barn::createBFSIterator() {
    return new BFFarmIterator(this);
}

FarmIterator* Barn::createDFSIterator() {
    return new DFFarmIterator(this);
}

vector<FarmUnit*> Barn::getSubUnits() {
    // Return the sub-units of the barn
    return units;
}

void Barn::setName(const std::string& name) {
    this->name = name;
}

std::string Barn::getName() const {
    return this->name;
}