// Class implementation for Component 3 - Decorator (ConcreteDecorator)

/**
 * @file FertilizedField.cpp
 * @brief Class implementation for Component 3 - Decorator (ConcreteDecorator)
 */

#include <iostream>

#include "FertilizedField.h"
#include "CropFieldDecorator.h"
#include "CropField.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

using namespace std;


/**
 * @brief Constructs a new FertilizedField object.
 * 
 * Initializes a new instance of the FertilizedField class with the given CropField and outputs a message indicating its creation.
 * @param field Pointer to the CropField to be decorated.
 */
FertilizedField::FertilizedField(CropField* field)
    : CropFieldDecorator(field), field(field) {
    cout << "🌿 FertilizedField created and ready to enhance crop production!\n";
}

/**
 * @brief Destroys the FertilizedField object.
 * 
 * Cleans up resources and outputs a message indicating the destruction of the FertilizedField.
 */
FertilizedField::~FertilizedField() 
{
    std::cout << "🌾 FertilizedField is being destroyed. Cleaning up...\n";
   
}


/**
 * @brief Increases crop production in the FertilizedField.
 * 
 * Enhances crop production by transitioning soil states and adjusting crop amounts. Outputs messages about the changes.
 */
void FertilizedField::increaseProduction() {
    std::cout << "📈 Increasing production in FertilizedField.\n";
    
    // Check current soil state and transition accordingly
    std::string currentSoilState = field->getSoilStateName();

    if (currentSoilState == "Dry") {
        std::cout << "Current soil state is Dry. Transitioning to FruitfulSoil...\n";
        field->setSoilState(new FruitfulSoil());  // Transition to FruitfulSoil
    } 
    else if (currentSoilState == "Fruitful") {
        std::cout << "Current soil state is Fruitful. Transitioning to FloodedSoil...\n";
        field->setSoilState(new FloodedSoil());  // Transition to FloodedSoil
    } 
    else if (currentSoilState == "Flooded") {
        std::cout << "Soil is already in Flooded state. No further transition possible.\n";
    }

    int additionalYield = 0;
    int newAmount = 0;
    
    if (field->getLeftoverCapacity() > 0) {
        std::cout << "Field still has leftover capacity. Further increasing production.\n";
        additionalYield = 10; // Additional increase for supercharged productivity
        newAmount += additionalYield;
        
        if (newAmount > field->getTotalCapacity()) {
            std::cout << "Supercharged yield limited by field capacity. Setting to max capacity.\n";
            newAmount = field->getTotalCapacity();
        }
        
        field->setCurrentAmount(newAmount);
        std::cout << "Crop yield has been supercharged by an additional " << additionalYield << " units! Final crop amount: " << newAmount << "\n";
    } else {
        std::cout << "Field has reached maximum production capacity.\n";
    }
}


/**
 * @brief Harvests crops from the FertilizedField.
 * 
 * Performs the harvest operation and may include bonus crops based on soil conditions. Outputs messages about the harvest.
 */
void FertilizedField::harvest() {
    std::cout << "🌾 Harvesting crops from FertilizedField.\n";
    field->harvest();
    
    if (rand() % 10 < 3) 
    { 
        std::cout << "Bonus harvest! Additional high-quality crops collected due to superior soil conditions.\n";
        int bonusYield = 10;
        int currentCapacity = field->getLeftoverCapacity();
        
        if (currentCapacity >= bonusYield) {
            std::cout << "Collected " << bonusYield << " extra units of premium crops.\n";
        } else if (currentCapacity > 0) {
            std::cout << "Storage almost full. Collected " << currentCapacity << " extra units of premium crops.\n";
        } else {
            std::cout << "Storage is full. No bonus crops could be stored.\n";
        }
    } else {
        std::cout << "No bonus crops this time. Regular harvest completed.\n";
    } 
}


/**
 * @brief Gets the leftover capacity of the FertilizedField.
 * 
 * Calculates the leftover capacity including bonus capacity from advanced storage management.
 * @return The total leftover capacity including bonus.
 */
int FertilizedField::getLeftoverCapacity() {
    std::cout << "🔢 Checking leftover capacity in FertilizedField.\n";
    int baseCapacity = field->getLeftoverCapacity();
    int bonusCapacity = 10; // Additional capacity due to advanced storage management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of storage.\n";
    return baseCapacity + bonusCapacity;
}


/**
 * @brief Buys a truck for the FertilizedField.
 * 
 * Adds a truck to the FertilizedField and outputs a message about the purchase.
 * @param truck Pointer to the Truck object to be added.
 */
void FertilizedField::buyTruck(Truck* truck) {
    std::cout << "🚚 Buying truck for FertilizedField.\n";
    field->buyTruck(truck);
    std::cout << "The field now has a new truck for enhanced harvest and transport operations.\n";
}


/**
 * @brief Sells a truck from the FertilizedField.
 * 
 * Removes a truck from the FertilizedField and outputs a message about the sale.
 * @param truck Pointer to the Truck object to be removed.
 */
void FertilizedField::sellTruck(Truck* truck) {
    std::cout << "🚛 Selling truck from FertilizedField.\n";
    field->sellTruck(truck);
    std::cout << "The field no longer has the truck. Transport operations might be affected.\n";
}


/**
 * @brief Gets the total capacity of the FertilizedField.
 * 
 * Calculates the total capacity including bonus capacity from improved field management.
 * @return The total capacity including bonus.
 */
int FertilizedField::getTotalCapacity() {
     std::cout << "🔢 Getting total capacity of FertilizedField.\n";
    int baseCapacity = field->getTotalCapacity();
    int bonusCapacity = 20; // Additional capacity due to improved field management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of total capacity.\n";
    return baseCapacity + bonusCapacity;
}


/**
 * @brief Gets the crop type of the FertilizedField.
 * 
 * Retrieves the crop type of the decorated CropField and appends "(Fertilized)".
 * @return The crop type of the FertilizedField.
 */
std::string FertilizedField::getCropType() {
    std::cout << "🌾 Getting crop type of FertilizedField.\n";
    std::string baseCropType = field->getCropType();
    return baseCropType + " (Fertilized)";
}



/**
 * @brief Gets the soil state name of the FertilizedField.
 * 
 * Retrieves the soil state name of the decorated CropField and appends "(Enhanced with fertilizer)".
 * @return The soil state name of the FertilizedField.
 */
std::string FertilizedField::getSoilStateName() {   
    std::cout << "🌱 Getting soil state name of FertilizedField.\n";
    std::string baseSoilState = field->getSoilStateName();
    return baseSoilState + " (Enhanced with fertilizer)";
}


/**
 * @brief Gets the current amount of crops in the FertilizedField.
 * 
 * Retrieves the current amount of crops including a bonus amount due to better soil conditions.
 * @return The current amount of crops including bonus.
 */
int FertilizedField::getCurrentAmount() {
     std::cout << "🔢 Getting current amount of crops in FertilizedField.\n";
    int baseAmount = field->getCurrentAmount();
    int bonusAmount = 5; // Bonus amount due to better soil conditions

    return baseAmount + bonusAmount;
}


/**
 * @brief Sets the current amount of crops in the FertilizedField.
 * 
 * Updates the current amount of crops and outputs a message about the change.
 * @param amount The new amount of crops to set.
 */
void FertilizedField::setCurrentAmount(int amount) {
    std::cout << "🔄 Setting current amount of crops in FertilizedField.\n";
    field->setCurrentAmount(amount);
    std::cout << "Current amount set to " << amount;
}

/**
 * @brief Creates a BFS iterator for the FertilizedField.
 * 
 * Generates a Breadth-First Search iterator to traverse the FertilizedField.
 * @return A pointer to a new BFFarmIterator.
 */
FarmIterator* FertilizedField::createBFSIterator() {
    std::cout << "🔄 Creating BFS iterator for FertilizedField.\n";
    return new BFFarmIterator(this);
}


/**
 * @brief Creates a DFS iterator for the FertilizedField.
 * 
 * Generates a Depth-First Search iterator to traverse the FertilizedField.
 * @return A pointer to a new DFFarmIterator.
 */
FarmIterator* FertilizedField::createDFSIterator() {
    std::cout << "🔄 Creating DFS iterator for FertilizedField.\n";
    return new DFFarmIterator(this);
}


/**
 * @brief Gets the sub-units of the FertilizedField.
 * 
 * Returns an empty vector as the FertilizedField does not contain sub-units.
 * @return An empty vector of FarmUnit pointers.
 */
std::vector<FarmUnit*> FertilizedField::getSubUnits() {
    cout << "📦 FertilizedField has no sub-units.\n";
    return vector<FarmUnit*>();  // Return empty vector since FertilizedField has no sub-units
}


/**
 * @brief Sets the name of the FertilizedField.
 * 
 * Updates the name of the FertilizedField and outputs a message about the change.
 * @param name The new name to set for the FertilizedField.
 */
void FertilizedField::setName(const std::string& name) {
    this->name = name;
    std::cout << "📝 Set name of FertilizedField to: " << name << '\n';
}


/**
 * @brief Gets the name of the FertilizedField.
 * 
 * Retrieves the name of the FertilizedField.
 * @return The name of the FertilizedField.
 */
std::string FertilizedField::getName() const {
    return this->name;
}


/**
 * @brief Adds a FarmUnit to the FertilizedField.
 * 
 * This method does not perform any action as the FertilizedField does not store units.
 * @param unit Pointer to the FarmUnit to be added.
 */
void FertilizedField::add(FarmUnit* unit) {
    cout << "[FertilizedField] Cannot add units. FertilizedField does not store units.\n";
}


/**
 * @brief Removes a FarmUnit from the FertilizedField.
 * 
 * This method does not perform any action as the FertilizedField does not store units.
 * @param unit Pointer to the FarmUnit to be removed.
 */
void FertilizedField::remove(FarmUnit* unit) {
    cout << "[FertilizedField] Cannot remove units. FertilizedField does not store units.\n";
}