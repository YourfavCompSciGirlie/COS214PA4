// Class definition for Component 2 - State (ConcreteState)

#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "CropField.h" // Include the full definition of CropField

#include <iostream>

using namespace std;

FruitfulSoil::FruitfulSoil() {
    cout << "[FruitfulSoil] Created fruitful soil, rich and ready for a bountiful harvest." << endl;
}

FruitfulSoil::~FruitfulSoil() {
    cout << "[FruitfulSoil] Destroyed fruitful soil, once lush and fertile." << endl;
}

int FruitfulSoil::harvestCrops() const {
    cout << "[FruitfulSoil] The rich, fertile soil bursts with an abundant harvest, like a bountiful feast." << endl;
    return 3; // High yield
}

void FruitfulSoil::rain() {
    cout << "[FruitfulSoil] The soil has been blessed with rain, nurturing it to its peak vitality." << endl;
    // Transition to FloodedSoil
    context->setSoilState(new FloodedSoil());
}

string FruitfulSoil::getName() const {
    return "Fruitful";
}

