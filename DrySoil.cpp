// Class definition for Component 2 - State (ConcreteState)

#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "CropField.h" // Include the full definition of CropField

#include <iostream>

using namespace std;

DrySoil::DrySoil() {
    cout << "[DrySoil] Created dry soil, barren and in need of rain." << endl;
}

DrySoil::~DrySoil() {
    cout << "[DrySoil] Destroyed dry soil, once barren and parched." << endl;
}

int DrySoil::harvestCrops() const {
    cout << "[DrySoil] The arid soil yields only a trickle of crops, like a desert oasis." << endl;
    return 1; // Minimal yield
}

void DrySoil::rain() {
    cout << "[DrySoil] A rare rainstorm has graced the dry soil, promising future fertility." << endl;
    // Transition to FruitfulSoil
    context->setSoilState(new FruitfulSoil());
}

string DrySoil::getName() const {
    return "Dry";
}
