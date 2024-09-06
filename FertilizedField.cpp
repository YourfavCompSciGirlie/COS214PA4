#include <iostream>

#include "FertilizedField.h"
#include "CropFieldDecorator.h"
#include "CropField.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

using namespace std;

FertilizedField::FertilizedField(CropField* field)
    : CropFieldDecorator(field), field(field) {
    cout << "🌿 FertilizedField created and ready to enhance crop production!\n";
}


FertilizedField::~FertilizedField() {
    cout << "🌾 FertilizedField is being destroyed. Cleaning up...\n";
   
}

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

int FertilizedField::getLeftoverCapacity() {
    std::cout << "🔢 Checking leftover capacity in FertilizedField.\n";
    int baseCapacity = field->getLeftoverCapacity();
    int bonusCapacity = 10; // Additional capacity due to advanced storage management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of storage.\n";
    return baseCapacity + bonusCapacity;
}

void FertilizedField::buyTruck(Truck* truck) {
    std::cout << "🚚 Buying truck for FertilizedField.\n";
    field->buyTruck(truck);
    std::cout << "The field now has a new truck for enhanced harvest and transport operations.\n";
}

void FertilizedField::sellTruck(Truck* truck) {
    std::cout << "🚛 Selling truck from FertilizedField.\n";
    field->sellTruck(truck);
    std::cout << "The field no longer has the truck. Transport operations might be affected.\n";
}

int FertilizedField::getTotalCapacity() {
     std::cout << "🔢 Getting total capacity of FertilizedField.\n";
    int baseCapacity = field->getTotalCapacity();
    int bonusCapacity = 20; // Additional capacity due to improved field management

    std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of total capacity.\n";
    return baseCapacity + bonusCapacity;
}

std::string FertilizedField::getCropType() {
    std::cout << "🌾 Getting crop type of FertilizedField.\n";
    std::string baseCropType = field->getCropType();
    return baseCropType + " (Fertilized)";
}

std::string FertilizedField::getSoilStateName() {   
    std::cout << "🌱 Getting soil state name of FertilizedField.\n";
    std::string baseSoilState = field->getSoilStateName();
    return baseSoilState + " (Enhanced with fertilizer)";
}

int FertilizedField::getCurrentAmount() {
     std::cout << "🔢 Getting current amount of crops in FertilizedField.\n";
    int baseAmount = field->getCurrentAmount();
    int bonusAmount = 5; // Bonus amount due to better soil conditions

    return baseAmount + bonusAmount;
}

void FertilizedField::setCurrentAmount(int amount) {
    std::cout << "🔄 Setting current amount of crops in FertilizedField.\n";
    field->setCurrentAmount(amount);
    std::cout << "Current amount set to " << amount;
}


FarmIterator* FertilizedField::createBFSIterator() {
    std::cout << "🔄 Creating BFS iterator for FertilizedField.\n";
    return new BFFarmIterator(this);
}

FarmIterator* FertilizedField::createDFSIterator() {
    std::cout << "🔄 Creating DFS iterator for FertilizedField.\n";
    return new DFFarmIterator(this);
}

std::vector<FarmUnit*> FertilizedField::getSubUnits() {
    cout << "📦 FertilizedField has no sub-units.\n";
    return vector<FarmUnit*>();  // Return empty vector since FertilizedField has no sub-units
}

void FertilizedField::setName(const std::string& name) {
    this->name = name;
    std::cout << "📝 Set name of FertilizedField to: " << name << '\n';
}

std::string FertilizedField::getName() const {
    return this->name;
}

void FertilizedField::add(FarmUnit* unit) {
    cout << "[FertilizedField] Cannot add units. FertilizedField does not store units.\n";
}

void FertilizedField::remove(FarmUnit* unit) {
    cout << "[FertilizedField] Cannot remove units. FertilizedField does not store units.\n";
}