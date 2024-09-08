// Class definition for Component 2 - State (ConcreteState)

#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "CropField.h" // Include the full definition of CropField

#include <iostream>

using namespace std;


/**
 * @brief Constructs a new FruitfulSoil.
 * 
 * Initializes the FruitfulSoil with a message indicating it is rich and ready for a bountiful harvest.
 */
FruitfulSoil::FruitfulSoil() {
    cout << "[FruitfulSoil] Created fruitful soil, rich and ready for a bountiful harvest." << endl;
}


/**
 * @brief Destructs the FruitfulSoil.
 * 
 * Outputs a message when the FruitfulSoil is destroyed, indicating it was once lush and fertile.
 */
FruitfulSoil::~FruitfulSoil() {
    cout << "[FruitfulSoil] Destroyed fruitful soil, once lush and fertile." << endl;
}


/**
 * @brief Harvests crops from the FruitfulSoil.
 * 
 * Indicates that the rich, fertile soil yields a high amount of crops, representing a bountiful harvest.
 * 
 * @return int The amount of crops harvested, which is 3.
 */
int FruitfulSoil::harvestCrops() const {
    cout << "[FruitfulSoil] The rich, fertile soil bursts with an abundant harvest, like a bountiful feast." << endl;
    return 3; // High yield
}


/**
 * @brief Simulates the effect of rain on the FruitfulSoil.
 * 
 * Transitions the soil state to FloodedSoil as the rain nurtures it to its peak vitality.
 */
void FruitfulSoil::rain() {
    cout << "[FruitfulSoil] The soil has been blessed with rain, nurturing it to its peak vitality." << endl;
    // Transition to FloodedSoil
    context->setSoilState(new FloodedSoil());
}


/**
 * @brief Gets the name of the FruitfulSoil state.
 * 
 * @return string The name of the soil state, which is "Fruitful".
 */
string FruitfulSoil::getName() const {
    return "Fruitful";
}

