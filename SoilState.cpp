// Class implementation for Component 2 - State (State)

/**
 * @file SoilState.cpp
 * @brief Implementation of the SoilState class (State in the State Pattern).
 */

#include "SoilState.h"

#include <iostream>

using namespace std;

/**
 * @brief Constructor for the SoilState class.
 * 
 * Initializes the SoilState object with a message indicating the creation of the soil foundation.
 */
SoilState::SoilState() {
    cout << "[SoilState] The foundation of soil has been laid." << endl;
}

/**
 * @brief Destructor for the SoilState class.
 * 
 * Cleans up the SoilState object with a message indicating its destruction.
 */
SoilState::~SoilState() {
    cout << "[SoilState] The soil state is being relinquished, and its essence fades away." << endl;
}

/**
 * @brief Sets the context (CropField) for the SoilState.
 * 
 * @param ctx Pointer to the CropField object that this SoilState will be associated with.
 */
void SoilState::setContext(CropField* ctx) {
    context = ctx;
}
