// Class implementation for Component 1 - Composite (Composite)
// Class implementation for Component 5 - Iterator (ConcreteAggregate)

#include "Farmland.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"
#include <iostream>
#include <algorithm> // For std::find

using namespace std;

/**
 * @brief Constructs a new Farmland object.
 * 
 * Initializes a new instance of Farmland, creating a container for farm units.
 */
Farmland::Farmland() {
    cout << "[Farmland] A new farmland has been created. 🌾" << endl;
}

/**
 * @brief Destroys the Farmland object.
 * 
 * Cleans up the Farmland and all associated farm units.
 */
Farmland::~Farmland() {
    cout << "[Farmland] The farmland has been destroyed. 🌾" << endl;
}

/**
 * @brief Adds a farm unit to the Farmland.
 * 
 * @param unit Pointer to the FarmUnit to be added.
 */
void Farmland::add(FarmUnit* unit) {
    units.push_back(unit);
}

/**
 * @brief Removes a farm unit from the Farmland.
 * 
 * @param unit Pointer to the FarmUnit to be removed.
 */
void Farmland::remove(FarmUnit* unit) {
    auto it = std::find(units.begin(), units.end(), unit);
    
    if (it != units.end()) {
        units.erase(it);
    }
}

/**
 * @brief Gets the total storage capacity of the Farmland.
 * 
 * @return int The sum of the capacities of all farm units in the Farmland.
 */
int Farmland::getTotalCapacity() {
    int totalCapacity = 0;
    
    for (FarmUnit* unit : units) {
        totalCapacity += unit->getTotalCapacity();
    }

    return totalCapacity;
}

/**
 * @brief Gets the crop type of the Farmland.
 * 
 * @return std::string The crop type, which is "Mixed" for Farmland.
 */
std::string Farmland::getCropType() {
    return "Mixed";
}

/**
 * @brief Gets the soil state name of the Farmland.
 * 
 * @return std::string The soil state, which is "Mixed" for Farmland.
 */
std::string Farmland::getSoilStateName() {
    return "Mixed";
}

/**
 * @brief Gets the current amount of crops in the Farmland.
 * 
 * @return int The sum of the current amounts in all farm units.
 */
int Farmland::getCurrentAmount() {
    int totalAmount = 0;
    
    for (FarmUnit* unit : units) {
        totalAmount += unit->getCurrentAmount(); 
    }

    return totalAmount;
}

/**
 * @brief Sets the current amount of crops in the Farmland.
 * 
 * Distributes the specified amount across all farm units, up to their capacities.
 * 
 * @param amount The total amount to be set across the Farmland.
 */
void Farmland::setCurrentAmount(int amount) {
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

/**
 * @brief Increases the production of all farm units in the Farmland.
 */
void Farmland::increaseProduction() {
    for (FarmUnit* unit : units) {
        unit->increaseProduction();
    }
}

/**
 * @brief Harvests all crops from the Farmland.
 */
void Farmland::harvest() {
    for (FarmUnit* unit : units) {
        unit->harvest();
    }
}

/**
 * @brief Gets the leftover capacity of the Farmland.
 * 
 * @return int The total capacity minus the current amount of crops.
 */
int Farmland::getLeftoverCapacity() {
    int totalCapacity = getTotalCapacity();
    int currentAmount = getCurrentAmount();
    return totalCapacity - currentAmount;
}

/**
 * @brief Purchases a truck and assigns it to the farm units in the Farmland.
 * 
 * @param truck Pointer to the Truck to be bought.
 */
void Farmland::buyTruck(Truck* truck) {
    for (FarmUnit* unit : units) {
        unit->buyTruck(truck);
    }
}

/**
 * @brief Sells a truck from the farm units in the Farmland.
 * 
 * @param truck Pointer to the Truck to be sold.
 */
void Farmland::sellTruck(Truck* truck) {
    for (FarmUnit* unit : units) {
        unit->sellTruck(truck);
    }
}

/**
 * @brief Creates a breadth-first search iterator for the Farmland.
 * 
 * @return FarmIterator* A pointer to a new BFFarmIterator object.
 */
FarmIterator* Farmland::createBFSIterator() {
    return new BFFarmIterator(this);
}

/**
 * @brief Creates a depth-first search iterator for the Farmland.
 * 
 * @return FarmIterator* A pointer to a new DFFarmIterator object.
 */
FarmIterator* Farmland::createDFSIterator() {
    return new DFFarmIterator(this);
}

/**
 * @brief Gets the list of sub-units (farm units) in the Farmland.
 * 
 * @return std::vector<FarmUnit*> A vector containing pointers to the sub-units.
 */
vector<FarmUnit*> Farmland::getSubUnits() {
    return units;
}

/**
 * @brief Sets the name of the Farmland.
 * 
 * @param unitName The name to be assigned to the Farmland.
 */
void Farmland::setName(const string& unitName) { 
    name = unitName; 
}

/**
 * @brief Gets the name of the Farmland.
 * 
 * @return std::string The name of the Farmland.
 */
string Farmland::getName() const { 
    return name; 
}
