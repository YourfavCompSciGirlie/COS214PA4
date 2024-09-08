// Class implementation for Component 3 - Decorator (Decorator)

/**
 * @file CropFieldDecorator.cpp
 * @brief Implementation of the CropFieldDecorator class.
 */

#include "CropFieldDecorator.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor. Initializes the decorator with no attached CropField.
 */
CropFieldDecorator::CropFieldDecorator() : field(nullptr) {
    std::cout << "🌱 CropFieldDecorator created, no crop field attached yet.\n";
}

/**
 * @brief Destructor. Cleans up the attached CropField if necessary.
 */
CropFieldDecorator::~CropFieldDecorator() {
    std::cout << "🌾 CropFieldDecorator destroyed, releasing attached crop field.\n";
   
}

/**
 * @brief Constructor that attaches the decorator to a specific CropField.
 * @param field Pointer to the CropField to be decorated.
 */
CropFieldDecorator::CropFieldDecorator(CropField* field) : field(field) {
    std::cout << "🌿 CropFieldDecorator created, decorating a crop field.\n";
}
