// Class definition for Component 2 - State (ConcreteState)

/**
 * @file DrySoil.cpp
 * @brief Implementation of the DrySoil class, a concrete state in the State design pattern.
 */

#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "CropField.h" // Include the full definition of CropField

#include <iostream>

using namespace std;

/**
 * @brief Constructor for the DrySoil class.
 * 
 * Initializes a dry soil state, representing a barren and arid soil condition.
 */
DrySoil::DrySoil() {
    cout << "[DrySoil] Created dry soil, barren and in need of rain." << endl;
}

/**
 * @brief Destructor for the DrySoil class.
 * 
 * Cleans up resources used by the dry soil state.
 */
DrySoil::~DrySoil() {
    cout << "[DrySoil] Destroyed dry soil, once barren and parched." << endl;
}

/**
 * @brief Harvests crops from the crop field in a dry soil state.
 * 
 * @return The amount of crops harvested, which is minimal due to the arid condition.
 */
int DrySoil::harvestCrops() const {
    cout << "[DrySoil] The arid soil yields only a trickle of crops, like a desert oasis." << endl;
    return 1; // Minimal yield
}

/**
 * @brief Simulates rain in the crop field, changing the soil state to fruitful.
 * 
 * Transitions the soil state from DrySoil to FruitfulSoil.
 */
void DrySoil::rain() {
    cout << "[DrySoil] A rare rainstorm has graced the dry soil, promising future fertility." << endl;
    // Transition to FruitfulSoil
    context->setSoilState(new FruitfulSoil());
}

/**
 * @brief Gets the name of the soil state.
 * 
 * @return A string representing the name of the soil state.
 */
string DrySoil::getName() const {
    return "Dry";
}
