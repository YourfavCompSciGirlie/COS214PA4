#include "ExtraBarn.h"
#include <iostream>

ExtraBarn::ExtraBarn(CropField* field, int extraCapacity) 
{
    this->field = field;
    this->extraStorageCapacity = extraCapacity;
}

void ExtraBarn::increaseProduction()  
{
    std::cout << "Increasing production with extra barn capacity...\n";
    
    // Initial production increase
    field->increaseProduction();
    std::cout << "The extra barn provides additional space, reducing waste and optimizing storage.\n";
    
    // Check if the current capacity allows for extra production
    if (field->getLeftoverCapacity() > 0) {
        std::cout << "The extra barn's capacity allows for a boost in production.\n";
        
        // Additional boost in production due to improved storage
        field->increaseProduction();
        std::cout << "Production boosted by the optimized storage space in the extra barn!\n";
        
        // Implementing a further increase in production due to increased efficiency
        int efficiencyBoost = rand() % 20 + 10; // Random boost between 10 and 30
        int currentAmount = field->getCurrentAmount();
        field->setCurrentAmount(currentAmount + efficiencyBoost);
        std::cout << "Production efficiency increased, adding " << efficiencyBoost << " units to the total production.\n";
    } else {
        std::cout << "The barn is at full capacity. No further production increase possible.\n";
    }

    // Simulate the barn having an effect on the soil state, e.g., preventing over-flooding
    std::string currentSoilState = field->getSoilStateName();
    if (currentSoilState == "FloodedSoil") {
        std::cout << "The extra barn has a draining system, preventing further flooding and stabilizing the soil.\n";
    } else {
        std::cout << "The barn helps maintain optimal soil conditions.\n";
    }
}

void ExtraBarn::harvest()
{
    std::cout << "Harvesting from the field with extra barn storage...\n";
    field->harvest();
    std::cout << "Extra barn provides additional storage for harvested crops.\n";
}

int ExtraBarn::getLeftoverCapacity()
{
    int baseCapacity = field->getLeftoverCapacity();
    std::cout << "Extra barn adds " << extraStorageCapacity << " units to the leftover capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

void ExtraBarn::buyTruck(Truck* truck)
{
    std::cout << "Adding a truck to the field with extra barn storage...\n";
    field->buyTruck(truck);
    std::cout << "Extra barn's enhanced storage can now be utilized with additional transportation.\n";
}

void ExtraBarn::sellTruck(Truck* truck)
{
    std::cout << "Removing a truck from the field with extra barn storage...\n";
    field->sellTruck(truck);
    std::cout << "Extra barn's transportation capacity adjusted.\n";
}

int ExtraBarn::getTotalCapacity()
{
    int baseCapacity = field->getTotalCapacity();
    std::cout << "Extra barn provides " << extraStorageCapacity << " units of additional total capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

std::string ExtraBarn::getCropType()
{
    std::string baseCropType = field->getCropType();
    std::cout << "Crop type in the extra barn is: " << baseCropType << ".\n";
    return baseCropType;
}

std::string ExtraBarn::getSoilStateName()
{
    std::string baseSoilState = field->getSoilStateName();
    std::cout << "Soil state with extra barn: " << baseSoilState << ".\n";
    return baseSoilState;
}

int ExtraBarn::getCurrentAmount()
{
    int baseAmount = field->getCurrentAmount();
    std::cout << "Current amount in the field with extra barn: " << baseAmount << ".\n";
    return baseAmount;
}

void ExtraBarn::setCurrentAmount(int amount)
{
    std::cout << "Setting current amount in the field with extra barn to: " << amount << ".\n";
    field->setCurrentAmount(amount);
}


FarmIterator* ExtraBarn::createBFSIterator() {
    return new BFFarmIterator(this);
}

FarmIterator* ExtraBarn::createDFSIterator() {
    return new DFFarmIterator(this);
}

std::vector<FarmUnit*> ExtraBarn::getSubUnits() {
    // Return the sub-units of the extra barn
    return units;
}

void ExtraBarn::setName(const std::string& name) {
    this->name = name;
}

std::string ExtraBarn::getName() const {
    return this->name;
}
