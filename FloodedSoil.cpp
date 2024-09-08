// Class definition for Component 2 - State (ConcreteState)

#include "FloodedSoil.h"

#include <iostream>

using namespace std;


/**
 * @brief Constructs a new FloodedSoil.
 * 
 * Initializes the FloodedSoil with a message indicating it is saturated and unyielding.
 */
FloodedSoil::FloodedSoil() {
    cout << "[FloodedSoil] Created flooded soil, saturated and unyielding." << endl;
}


/**
 * @brief Destructs the FloodedSoil.
 * 
 * Outputs a message when the FloodedSoil is destroyed, indicating it is waterlogged.
 */
FloodedSoil::~FloodedSoil() {
    cout << "[FloodedSoil] Destroyed flooded soil, waterlogged and unproductive." << endl;
}


/**
 * @brief Harvests crops from the FloodedSoil.
 * 
 * Indicates that the waterlogged soil yields no crops and returns 0.
 * 
 * @return int The amount of crops harvested, which is 0.
 */
int FloodedSoil::harvestCrops() const {
    cout << "[FloodedSoil] The waterlogged soil yields no crops; it's a watery grave for the harvest." << endl;
    return 0; // No yield
}


/**
 * @brief Simulates the effect of rain on the FloodedSoil.
 * 
 * Since the soil is already drenched, additional rain deepens the flood but does not change the state.
 */
void FloodedSoil::rain() {
    cout << "[FloodedSoil] The soil is already drenched, and more rain only deepens the flood." << endl;
    // FloodedSoil remains in the same state
}

/**
 * @brief Gets the name of the FloodedSoil state.
 * 
 * @return string The name of the soil state, which is "Flooded".
 */
string FloodedSoil::getName() const {
    return "Flooded";
}
