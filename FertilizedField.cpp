#include <iostream>

#include "FertilizedField.h"
#include "CropFieldDecorator.h"
#include "CropField.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

FertilizedField::FertilizedField(CropField* field) 
{
    this->field = field;
}

void FertilizedField::increaseProduction()  
{
    std::cout << "Applying premium fertilizer to the crop field...\n";
    
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

void FertilizedField::harvest()
{
    std::cout << "Harvesting enhanced crops from the fertilized field...\n";
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

int FertilizedField::getLeftoverCapacity()
{
    int baseCapacity = field->getLeftoverCapacity();
    int bonusCapacity = 10; // Additional capacity due to advanced storage management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of storage.\n";
    return baseCapacity + bonusCapacity;
}

void FertilizedField::buyTruck(Truck* truck)
{
    std::cout << "Adding a new truck to the fertilized field...\n";
    field->buyTruck(truck);
    std::cout << "The field now has a new truck for enhanced harvest and transport operations.\n";
}

void FertilizedField::sellTruck(Truck* truck)
{
    std::cout << "Removing a truck from the fertilized field...\n";
    field->sellTruck(truck);
    std::cout << "The field no longer has the truck. Transport operations might be affected.\n";
}

int FertilizedField::getTotalCapacity()
{
    int baseCapacity = field->getTotalCapacity();
    int bonusCapacity = 20; // Additional capacity due to improved field management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of total capacity.\n";
    return baseCapacity + bonusCapacity;
}

std::string FertilizedField::getCropType()
{
    std::string baseCropType = field->getCropType();
    return baseCropType + " (Fertilized)";
}

std::string FertilizedField::getSoilStateName()
{
    std::string baseSoilState = field->getSoilStateName();
    return baseSoilState + " (Enhanced with fertilizer)";
}

int FertilizedField::getCurrentAmount()
{
    int baseAmount = field->getCurrentAmount();
    int bonusAmount = 5; // Bonus amount due to better soil conditions

    return baseAmount + bonusAmount;
}

void FertilizedField::setCurrentAmount(int amount)
{
    field->setCurrentAmount(amount);
    std::cout << "Current amount set to " << amount;
}


FarmIterator* FertilizedField::createBFSIterator() {
    return new BFFarmIterator(this);
}

FarmIterator* FertilizedField::createDFSIterator() {
    return new DFFarmIterator(this);
}

std::vector<FarmUnit*> FertilizedField::getSubUnits() {
    // Return sub-units (if any) for fertilized field
    return std::vector<FarmUnit*>();
}

void FertilizedField::setName(const std::string& name) {
    this->name = name;
}

std::string FertilizedField::getName() const {
    return this->name;
}

void FertilizedField::add(FarmUnit* unit) {
    units.push_back(unit);
    cout << "[FertilizedField] Added a unit: " << unit->getName() << endl;
}

void FertilizedField::remove(FarmUnit* unit) {
    auto it = find(units.begin(), units.end(), unit);
    
    if (it != units.end()) {
        units.erase(it);
        cout << "[FertilizedField] Removed a unit: " << unit->getName() << endl;
    } else {
        cout << "[FertilizedField] Unit not found." << endl;
    }
}