// Class implementation for Component 1 - Composite (Component) 
// Class implementation for Component 5 - Iterator (Aggregate)

/**
 * @file FarmUnit.cpp
 * @brief Class implementation for Component 1 - Composite (Component) and Component 5 - Iterator (Aggregate)
 */

#include "FarmUnit.h"

#include <iostream>

using namespace std;


/**
 * @brief Constructs a new FarmUnit object.
 * 
 * Initializes a new instance of the FarmUnit class and outputs a message indicating its creation.
 */
FarmUnit::FarmUnit() {
    cout << "[FarmUnit] A new farm unit has been established. 🌱" << endl;
}


/**
 * @brief Destroys the FarmUnit object.
 * 
 * Cleans up resources and outputs a message indicating the decommissioning of the FarmUnit.
 */
FarmUnit::~FarmUnit() {
    cout << "[FarmUnit] A farm unit has been decommissioned. 🌾" << endl;
}