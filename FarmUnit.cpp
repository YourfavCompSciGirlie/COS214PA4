// Class implementation for Component 1 - Composite (Component) 

#include "FarmUnit.h"

#include <iostream>

using namespace std;

FarmUnit::FarmUnit() {
    cout << "[FarmUnit] A new farm unit has been established. 🌱" << endl;
}

FarmUnit::~FarmUnit() {
    cout << "[FarmUnit] A farm unit has been decommissioned. 🌾" << endl;
}