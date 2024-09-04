// Class definition for Component 2 - State (ConcreteState)

#include "FloodedSoil.h"

#include <iostream>

using namespace std;

FloodedSoil::FloodedSoil() {
    cout << "[FloodedSoil] Created flooded soil, saturated and unyielding." << endl;
}

FloodedSoil::~FloodedSoil() {
    cout << "[FloodedSoil] Destroyed flooded soil, waterlogged and unproductive." << endl;
}

int FloodedSoil::harvestCrops() const {
    cout << "[FloodedSoil] The waterlogged soil yields no crops; it's a watery grave for the harvest." << endl;
    return 0; // No yield
}

void FloodedSoil::rain() {
    cout << "[FloodedSoil] The soil is already drenched, and more rain only deepens the flood." << endl;
    // FloodedSoil remains in the same state
}

string FloodedSoil::getName() const {
    return "Flooded";
}
