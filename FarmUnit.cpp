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
