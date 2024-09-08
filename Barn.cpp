// Class implementation for Component 1 - Composite (Leaf)

#include "Barn.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs a Barn with a given total capacity.
 * 
 * @param totalCapacity The total capacity of the barn.
 */
Barn::Barn(int totalCapacity) : totalCapacity(totalCapacity), currentAmount(0) {
    cout << "[Barn] Constructing a new barn with a total capacity of " << totalCapacity << " units. 🏠🚜" << endl;
}

/**
 * @brief Destroys the Barn object.
 */
Barn::~Barn() {
    cout << "[Barn] The barn with a capacity of " << totalCapacity << " units has been demolished. 🏚️💥" << endl;
}

/**
 * @brief Returns the total capacity of the barn.
 * 
 * @return int The total capacity of the barn.
 */
int Barn::getTotalCapacity() {
    return totalCapacity;
}

/**
 * @brief Returns the type of crop stored in the barn.
 * 
 * @return std::string "N/A" as barns do not hold crops directly.
 */
std::string Barn::getCropType() {
    return "N/A";
}

/**
 * @brief Returns the name of the soil state.
 * 
 * @return std::string "N/A" as barns do not have soil states.
 */
std::string Barn::getSoilStateName() {
    return "N/A";
}

/**
 * @brief Returns the current amount of stored crops in the barn.
 * 
 * @return int The current amount of stored crops.
 */
int Barn::getCurrentAmount() {
    return currentAmount;
}

/**
 * @brief Sets the current amount of stored crops in the barn.
 * 
 * @param amount The amount to set.
 */
void Barn::setCurrentAmount(int amount) {
    if (amount >= 0 && amount <= totalCapacity) {
        currentAmount = amount;
        cout << "[Barn] Current amount set to " << currentAmount << " units. 📦" << endl;
    } else {
        cout << "[Barn] Error: Amount must be between 0 and " << totalCapacity << " units. 🚫" << endl;
    }
}

/**
 * @brief Placeholder method for increasing production (not applicable to barns).
 */
void Barn::increaseProduction() {
    cout << "[Barn] Increase production is not applicable for a barn. No change in production. 🚫" << endl;
}

/**
 * @brief Placeholder method for harvesting (not applicable to barns).
 */
void Barn::harvest() {
    cout << "[Barn] Harvesting is not applicable for a barn. No crops to harvest. 🚫" << endl;
}

/**
 * @brief Returns the leftover capacity of the barn.
 * 
 * @return int The amount of space left in the barn.
 */
int Barn::getLeftoverCapacity() {
    return totalCapacity - currentAmount;
}

/**
 * @brief Placeholder method for buying a truck (not applicable to barns).
 * 
 * @param truck The truck to buy.
 */
void Barn::buyTruck(Truck* truck) {
    cout << "[Barn] Buying a truck is not typically associated with barns. 🚛" << endl;
}

/**
 * @brief Placeholder method for selling a truck (not applicable to barns).
 * 
 * @param truck The truck to sell.
 */
void Barn::sellTruck(Truck* truck) {
    cout << "[Barn] Selling a truck is not typically associated with barns. 🚛" << endl;
}

/**
 * @brief Creates a breadth-first search iterator for the barn.
 * 
 * @return FarmIterator* The BFS iterator.
 */
FarmIterator* Barn::createBFSIterator() {
    return new BFFarmIterator(this);
}

/**
 * @brief Creates a depth-first search iterator for the barn.
 * 
 * @return FarmIterator* The DFS iterator.
 */
FarmIterator* Barn::createDFSIterator() {
    return new DFFarmIterator(this);
}

/**
 * @brief Returns the sub-units of the barn.
 * 
 * @return std::vector<FarmUnit*> An empty vector as barns don't have sub-units.
 */
vector<FarmUnit*> Barn::getSubUnits() {
    return vector<FarmUnit*>();
}

/**
 * @brief Sets the name of the barn.
 * 
 * @param name The name to set.
 */
void Barn::setName(const std::string& name) {
    this->name = name;
}

/**
 * @brief Gets the name of the barn.
 * 
 * @return std::string The name of the barn.
 */
std::string Barn::getName() const {
    return this->name;
}

/**
 * @brief Adds a unit to the barn (not supported).
 * 
 * @param unit The unit to add.
 */
void Barn::add(FarmUnit* unit) {
    cout << "[Barn] Cannot add units to the barn. Barn cannot store units." << endl;
}

/**
 * @brief Removes a unit from the barn (not supported).
 * 
 * @param unit The unit to remove.
 */
void Barn::remove(FarmUnit* unit) {
    cout << "[Barn] Cannot remove units from the barn. Barn does not store units." << endl;
}
