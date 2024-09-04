// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)

#include "CropField.h"

#include <iostream>

using namespace std;

// Constructor
CropField::CropField(const string& cropType, int totalCapacity, SoilState* initialState) : cropType(cropType), totalCapacity(totalCapacity), currentAmount(0), soilState(initialState) {
    cout << "[CropField] Created a crop field for " << cropType << " with total capacity " << totalCapacity << " and initial soil state: " << (soilState ? soilState->getName() : "None") << "." << endl;
}

// Destructor
CropField::~CropField() {
    // Note: If SoilState is managed elsewhere, avoid deleting it here.
    if (soilState) {
        delete soilState; // Clean up soilState if CropField owns it
    }

    cout << "[CropField] Destroyed the crop field for " << cropType << "." << endl;
}

// Get the total capacity of the crop field
int CropField::getTotalCapacity() 
{
    return totalCapacity;
}

// Get the type of crop in the field
string CropField::getCropType() 
{
    return cropType;
}

// Get the name of the current soil state
string CropField::getSoilStateName() 
{
    return soilState ? soilState->getName() : "None";
}

// Set a new soil state for the crop field
void CropField::setSoilState(SoilState* newState) 
{
    if (soilState) {
        delete soilState; // Clean up old soil state
    }

    soilState = newState;
    if (soilState) {
        soilState->setContext(this); // Set the new context
    }
    cout << "[CropField] Soil state updated to: " << (soilState ? soilState->getName() : "None") << "." << endl;
}

int CropField::harvestCrops() 
{
    return soilState->harvestCrops();
}

void CropField::rain() 
{
    soilState->rain();
}


// Get the current amount of crops in the field
int CropField::getCurrentAmount() 
{
    return currentAmount;
}

// Set the current amount of crops in the field
void CropField::setCurrentAmount(int amount) 
{
    if (amount > totalCapacity) {
        cout << "[CropField] Warning: Amount exceeds capacity. Setting to max capacity." << endl;
        currentAmount = totalCapacity;
    } else {
        currentAmount = amount;
    }
    cout << "[CropField] Current amount set to: " << currentAmount << "." << endl;
}

SoilState* CropField::getSoilState() const 
{
    return soilState;
}


//observer functions 
void CropField::buyTruck(Truck* truck) 
{
    NotificationSystem::addObserver(truck);
    FarmUnit::buyTruck(truck);
    std::cout << "Truck purchased! This " << cropType << " field now has a new truck." << std::endl;
}

void CropField::sellTruck(Truck* truck) 
{
    
    NotificationSystem::removeObserver(truck);
    FarmUnit::sellTruck(truck);

    std::cout << "Truck sold! This " << cropType << " field has one less truck now." << std::endl;
}

//decorator functions 
void increaseProduction() {
        std::cout << "Increasing production in the crop field...\n";
    }

void harvest() {
        std::cout << "Harvesting crops from the field...\n";
    }

int getLeftoverCapacity() {
        return 50; // Assume a base capacity of 50 units
}

