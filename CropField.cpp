// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)
// Class definition for Component 4 - Observer (ConcreteSubject)

/**
 * @file CropField.cpp
 * @brief Implementation of the CropField class.
 */

#include "CropField.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor for the CropField class.
 * 
 * Initializes a crop field with the specified crop type, total capacity, and initial soil state.
 * 
 * @param cropType The type of crop in the field.
 * @param totalCapacity The total capacity of the field.
 * @param initialState The initial soil state of the field.
 */
CropField::CropField(const string& cropType, int totalCapacity, SoilState* initialState) 
    : cropType(cropType), totalCapacity(totalCapacity), currentAmount(0), soilState(initialState) {
    cout << "[CropField] Created a crop field for " << cropType << " with total capacity " << totalCapacity 
         << " and initial soil state: " << (soilState ? soilState->getName() : "None") << "." << endl;
}

/**
 * @brief Destructor for the CropField class.
 */
CropField::~CropField() {
    cout << "[CropField] Destroyed the crop field for " << cropType << "." << endl;
}

/**
 * @brief Gets the total capacity of the crop field.
 * 
 * @return The total capacity of the crop field.
 */
int CropField::getTotalCapacity() {
    return totalCapacity;
}

/**
 * @brief Gets the type of crop in the field.
 * 
 * @return The type of crop in the field.
 */
string CropField::getCropType() {
    return cropType;
}

/**
 * @brief Gets the name of the current soil state.
 * 
 * @return The name of the current soil state.
 */
string CropField::getSoilStateName() {
    return soilState ? soilState->getName() : "None";
}

/**
 * @brief Sets a new soil state for the crop field.
 * 
 * @param newState The new soil state to be applied to the field.
 */
void CropField::setSoilState(SoilState* newState) {
    if (soilState) {
        delete soilState; // Clean up old soil state
    }

    soilState = newState;
    if (soilState) {
        soilState->setContext(this); // Set the new context
    }
    cout << "[CropField] Soil state updated to: " << (soilState ? soilState->getName() : "None") << "." << endl;
}

/**
 * @brief Harvests crops from the field based on the current soil state.
 * 
 * @return The amount of crops harvested.
 */
int CropField::harvestCrops() {
    return soilState->harvestCrops();
}

/**
 * @brief Simulates rain, affecting the soil state.
 */
void CropField::rain() {
    soilState->rain();
}

/**
 * @brief Gets the current amount of crops in the field.
 * 
 * @return The current amount of crops in the field.
 */
int CropField::getCurrentAmount() {
    return currentAmount;
}

/**
 * @brief Sets the current amount of crops in the field.
 * 
 * Ensures that the amount does not exceed the field's total capacity.
 * 
 * @param amount The amount of crops to be set.
 */
void CropField::setCurrentAmount(int amount) {
    if (amount > totalCapacity) {
        cout << "[CropField] Warning: Amount exceeds capacity. Setting to max capacity." << endl;
        currentAmount = totalCapacity;
    } else {
        currentAmount = amount;
    }
    cout << "[CropField] Current amount set to: " << currentAmount << endl;
}

/**
 * @brief Gets the current soil state of the crop field.
 * 
 * @return The current soil state of the crop field.
 */
SoilState* CropField::getSoilState() const {
    return soilState;
}

/**
 * @brief Registers a truck as an observer to the crop field.
 * 
 * @param truck The truck to be added as an observer.
 */
void CropField::buyTruck(Truck* truck) {
    NotificationSystem::addObserver(truck);
    cout << "Truck purchased! This " << cropType << " field now has a new truck." << endl;
}

/**
 * @brief Removes a truck as an observer from the crop field.
 * 
 * @param truck The truck to be removed as an observer.
 */
void CropField::sellTruck(Truck* truck) {
    NotificationSystem::removeObserver(truck);
    cout << "Truck sold! This " << cropType << " field has one less truck now." << endl;
}

/**
 * @brief Increases production in the crop field.
 */
void CropField::increaseProduction() {
    cout << "Increasing production in the crop field...\n";
}

/**
 * @brief Harvests crops from the field.
 */
void CropField::harvest() {
    cout << "Harvesting crops from the field...\n";
}

/**
 * @brief Gets the leftover capacity of the crop field.
 * 
 * @return The leftover capacity of the crop field.
 */
int CropField::getLeftoverCapacity() {
    return 50; // Assume a base capacity of 50 units
}

/**
 * @brief Sets the name of the crop field.
 * 
 * @param unitName The name to be assigned to the crop field.
 */
void CropField::setName(const string& unitName) { 
    name = unitName; 
}

/**
 * @brief Gets the name of the crop field.
 * 
 * @return The name of the crop field.
 */
string CropField::getName() const { 
    return name; 
}

/**
 * @brief Creates a Breadth-First Search (BFS) iterator for the crop field.
 * 
 * @return A pointer to a BFS iterator.
 */
FarmIterator* CropField::createBFSIterator() {
    return new BFFarmIterator(this);
}

/**
 * @brief Creates a Depth-First Search (DFS) iterator for the crop field.
 * 
 * @return A pointer to a DFS iterator.
 */
FarmIterator* CropField::createDFSIterator() {
    return new DFFarmIterator(this);
}

/**
 * @brief Gets the sub-units of the crop field (if any).
 * 
 * @return A vector of pointers to sub-units.
 */
std::vector<FarmUnit*> CropField::getSubUnits() {
    return std::vector<FarmUnit*>();
}

/**
 * @brief Adds a sub-unit to the crop field.
 * 
 * Note: CropField does not support adding sub-units.
 * 
 * @param unit The sub-unit to be added.
 */
void CropField::add(FarmUnit* unit) {
    cout << "[CropField] Cannot add unit. CropField does not support sub-units." << endl;
}

/**
 * @brief Removes a sub-unit from the crop field.
 * 
 * Note: CropField does not support removing sub-units.
 * 
 * @param unit The sub-unit to be removed.
 */
void CropField::remove(FarmUnit* unit) {
    cout << "[CropField] Cannot remove unit. CropField does not support sub-units." << endl;
}
