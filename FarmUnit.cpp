// FarmUnit.cpp
#include "FarmUnit.h"
#include <algorithm> // for std::remove

void FarmUnit::buyTruck(Truck* truck) {
    trucks.push_back(truck);
}

void FarmUnit::sellTruck(Truck* truck) {
    trucks.erase(std::remove(trucks.begin(), trucks.end(), truck), trucks.end());
}

void FarmUnit::callTruck() {
    for (Truck* truck : trucks) {
        truck->startEngine();
    }
}
// Class implementation for Component 1 - Composite (Component)

#include "FarmUnit.h"

#include <iostream>

using namespace std;

FarmUnit::FarmUnit() {
    cout << "[FarmUnit] A new farm unit has been established. 🌱" << endl;
}

FarmUnit::~FarmUnit() {
    cout << "[FarmUnit] A farm unit has been decommissioned. 🌾" << endl;
}