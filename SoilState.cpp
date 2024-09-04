// Class implementation for Component 2 - State (State)

#include "SoilState.h"

#include <iostream>

using namespace std;

// Constructor
SoilState::SoilState() {
    cout << "[SoilState] The foundation of soil has been laid." << endl;
}

// Destructor
SoilState::~SoilState() {
    cout << "[SoilState] The soil state is being relinquished, and its essence fades away." << endl;
}

void SoilState::setContext(CropField* ctx) {
    context = ctx;
}