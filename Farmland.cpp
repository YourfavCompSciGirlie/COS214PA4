// Class implementation for Component 1 - Composite (Composite)

#include "Farmland.h"

#include <iostream>
#include <algorithm> // For std::find

using namespace std;

Farmland::Farmland() {
    cout << "[Farmland] A new farmland has been created. 🌾" << endl;
}

Farmland::~Farmland() {
    // Clean up dynamically allocated FarmUnit objects
    for (FarmUnit* unit : units) {
        delete unit;
    }
    cout << "[Farmland] The farmland has been destroyed. 🌾" << endl;
}

void Farmland::add(FarmUnit* unit) {
    units.push_back(unit);
}

void Farmland::remove(FarmUnit* unit) {
    auto it = std::find(units.begin(), units.end(), unit);
    
    if (it != units.end()) {
        units.erase(it);
    }
}

int Farmland::getTotalCapacity() {
    int totalCapacity = 0;
    
    for (FarmUnit* unit : units) {
        totalCapacity += unit->getTotalCapacity();
    }

    return totalCapacity;
}

std::string Farmland::getCropType() {
    // Return "Mixed" as a placeholder or implement a specific approach
    return "Mixed";
}

std::string Farmland::getSoilStateName() {
    // Return "Mixed" as a placeholder or implement a specific approach
    return "Mixed";
}

int Farmland::getCurrentAmount() {
    int totalAmount = 0;
    
    for (FarmUnit* unit : units) {
        totalAmount += unit->getCurrentAmount(); 
    }

    return totalAmount;
}

void Farmland::setCurrentAmount(int amount) {
    // This method should delegate setting the amount to child units as necessary
    int remainingAmount = amount;
    
    for (FarmUnit* unit : units) {
        int unitCapacity = unit->getTotalCapacity();
        
        if (remainingAmount > unitCapacity) {
            unit->setCurrentAmount(unitCapacity);
            remainingAmount -= unitCapacity;
        } else {
            unit->setCurrentAmount(remainingAmount);
            remainingAmount = 0;
            break;
        }
    }

    if (remainingAmount > 0) {
        cout << "[Farmland] Warning: Not enough capacity to set the desired amount. Excess amount left: " << remainingAmount << endl;
    }
}

void Farmland::increaseProduction() {
    // Implement or delegate to child units if needed
    for (FarmUnit* unit : units) {
        unit->increaseProduction();
    }
}

void Farmland::harvest() {
    // Implement or delegate to child units if needed
    for (FarmUnit* unit : units) {
        unit->harvest();
    }
}

int Farmland::getLeftoverCapacity() {
    int totalCapacity = getTotalCapacity();
    int currentAmount = getCurrentAmount();
    return totalCapacity - currentAmount;
}

void Farmland::buyTruck(Truck* truck) {
    // Implement or delegate to child units if needed
    for (FarmUnit* unit : units) {
        unit->buyTruck(truck);
    }
}

void Farmland::sellTruck(Truck* truck) {
    // Implement or delegate to child units if needed
    for (FarmUnit* unit : units) {
        unit->sellTruck(truck);
    }
}


// // Implementation of the iterator creation is deferred to subclasses
// FarmIterator* Farmland::createBFSIterator() {
//     return new BFFarmIterator(this);
// }

// FarmIterator* Farmland::createDFSIterator() {
//     return new DFFarmIterator(this);
// }

// std::vector<FarmUnit*> Farmland::getSubUnits() {
//     return units;
// }