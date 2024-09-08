// Class implementation for Component 3 - Decorator (ConcreteDecorator)

/**
 * @file ExtraBarn.cpp
 * @brief Implementation of the ExtraBarn class, a concrete decorator for the CropField class.
 */

#include "ExtraBarn.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs an ExtraBarn with a given crop field and additional storage capacity.
 * @param field Pointer to the CropField object being decorated.
 * @param extraCapacity Additional storage capacity provided by the ExtraBarn.
 */
ExtraBarn::ExtraBarn(CropField* field, int extraCapacity) {
    this->field = field;
    this->extraStorageCapacity = extraCapacity;

    std::cout << "[ExtraBarn] A new extra barn is built, ready to boost your farm's storage by " 
              << extraCapacity << " units!" << std::endl;
}

/**
 * @brief Destructor for the ExtraBarn class.
 */
ExtraBarn::~ExtraBarn() {
    cout << "[ExtraBarn] The extra barn is being torn down. Farewell to the days of extra storage!" << endl;
}

/**
 * @brief Increases production in the crop field by utilizing the extra storage capacity of the barn.
 */
void ExtraBarn::increaseProduction() {
    std::cout << "Increasing production with extra barn capacity...\n";
    
  
    field->increaseProduction();
    std::cout << "The extra barn provides additional space, reducing waste and optimizing storage.\n";
    
   
    if (field->getLeftoverCapacity() > 0) {
        std::cout << "The extra barn's capacity allows for a boost in production.\n";
        
       
        field->increaseProduction();
        std::cout << "Production boosted by the optimized storage space in the extra barn!\n";
        
       
        int efficiencyBoost = rand() % 20 + 10; // Random boost between 10 and 30
        int currentAmount = field->getCurrentAmount();
        field->setCurrentAmount(currentAmount + efficiencyBoost);
        std::cout << "Production efficiency increased, adding " << efficiencyBoost << " units to the total production.\n";
    } else {
        std::cout << "The barn is at full capacity. No further production increase possible.\n";
    }

    
    std::string currentSoilState = field->getSoilStateName();
    if (currentSoilState == "FloodedSoil") {
        std::cout << "The extra barn has a draining system, preventing further flooding and stabilizing the soil.\n";
    } else {
        std::cout << "The barn helps maintain optimal soil conditions.\n";
    }
}

/**
 * @brief Harvests crops from the field, utilizing the extra storage capacity provided by the barn.
 */
void ExtraBarn::harvest() {
    std::cout << "Harvesting from the field with extra barn storage...\n";
    field->harvest();
    std::cout << "Extra barn provides additional storage for harvested crops.\n";
}

/**
 * @brief Gets the remaining storage capacity of the crop field, including the extra storage provided by the barn.
 * @return The total leftover storage capacity.
 */
int ExtraBarn::getLeftoverCapacity() {
    int baseCapacity = field->getLeftoverCapacity();
    std::cout << "Extra barn adds " << extraStorageCapacity << " units to the leftover capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

/**
 * @brief Adds a truck to the crop field, utilizing the extra storage capacity of the barn.
 * @param truck Pointer to the Truck object to be added.
 */
void ExtraBarn::buyTruck(Truck* truck) {
    std::cout << "Adding a truck to the field with extra barn storage...\n";
    field->buyTruck(truck);
    std::cout << "Extra barn's enhanced storage can now be utilized with additional transportation.\n";
}

/**
 * @brief Removes a truck from the crop field, adjusting the storage capacity of the barn accordingly.
 * @param truck Pointer to the Truck object to be removed.
 */
void ExtraBarn::sellTruck(Truck* truck) {
    std::cout << "Removing a truck from the field with extra barn storage...\n";
    field->sellTruck(truck);
    std::cout << "Extra barn's transportation capacity adjusted.\n";
}

/**
 * @brief Gets the total storage capacity of the crop field, including the extra storage provided by the barn.
 * @return The total storage capacity.
 */
int ExtraBarn::getTotalCapacity() {
    int baseCapacity = field->getTotalCapacity();
    std::cout << "Extra barn provides " << extraStorageCapacity << " units of additional total capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

/**
 * @brief Gets the crop type stored in the field with the extra barn.
 * @return The crop type.
 */
std::string ExtraBarn::getCropType() {
    std::string baseCropType = field->getCropType();
    std::cout << "Crop type in the extra barn is: " << baseCropType << ".\n";
    return baseCropType;
}

/**
 * @brief Gets the soil state name of the crop field with the extra barn.
 * @return The soil state name.
 */
std::string ExtraBarn::getSoilStateName() {
    std::string baseSoilState = field->getSoilStateName();
    std::cout << "Soil state with extra barn: " << baseSoilState << ".\n";
    return baseSoilState;
}

/**
 * @brief Gets the current amount of crops stored in the field with the extra barn.
 * @return The current amount of crops.
 */
int ExtraBarn::getCurrentAmount() {
    int baseAmount = field->getCurrentAmount();
    std::cout << "Current amount in the field with extra barn: " << baseAmount << ".\n";
    return baseAmount;
}

/**
 * @brief Sets the current amount of crops stored in the field with the extra barn.
 * @param amount The amount to be set.
 */
void ExtraBarn::setCurrentAmount(int amount) {
    std::cout << "Setting current amount in the field with extra barn to: " << amount << ".\n";
    field->setCurrentAmount(amount);
}

/**
 * @brief Creates a breadth-first search (BFS) iterator for the crop field with the extra barn.
 * @return Pointer to a new FarmIterator for BFS.
 */
FarmIterator* ExtraBarn::createBFSIterator() {
    return new BFFarmIterator(this);
}

/**
 * @brief Creates a depth-first search (DFS) iterator for the crop field with the extra barn.
 * @return Pointer to a new FarmIterator for DFS.
 */
FarmIterator* ExtraBarn::createDFSIterator() {
    return new DFFarmIterator(this);
}

/**
 * @brief Gets the sub-units of the ExtraBarn.
 * @return A vector of pointers to the sub-units. Since ExtraBarn has no sub-units, an empty vector is returned.
 */
std::vector<FarmUnit*> ExtraBarn::getSubUnits() {
    cout << "[ExtraBarn] This barn does not have any sub-units." << endl;
    return vector<FarmUnit*>();
}

/**
 * @brief Sets the name of the ExtraBarn.
 * @param name The name to be set.
 */
void ExtraBarn::setName(const std::string& name) {
    this->name = name;
}

/**
 * @brief Gets the name of the ExtraBarn.
 * @return The name of the ExtraBarn.
 */
std::string ExtraBarn::getName() const {
    return this->name;
}

/**
 * @brief Adds a FarmUnit to the ExtraBarn. This operation is not supported.
 * @param unit Pointer to the FarmUnit to be added.
 */
void ExtraBarn::add(FarmUnit* unit) {
    cout << "[ExtraBarn] Cannot add units to the barn. Barn cannot store units." << endl;
}

/**
 * @brief Removes a FarmUnit from the ExtraBarn. This operation is not supported.
 * @param unit Pointer to the FarmUnit to be removed.
 */
void ExtraBarn::remove(FarmUnit* unit) {
    cout << "[ExtraBarn] Cannot remove units from the barn. Barn does not store units." << endl;
}
