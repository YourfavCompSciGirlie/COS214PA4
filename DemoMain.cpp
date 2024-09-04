#include <iostream>
#include <cstdlib>
#include <ctime>

#include "CropField.h"
#include "FertilizedField.h"
#include "ExtraBarn.h"

int main() {
    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Create a basic CropField
    CropField* basicField = new CropField();

    // Decorate the CropField with FertilizedField
    CropFieldDecorator* fertilizedField ;

    // Further decorate the fertilized field with ExtraBarn
    CropFieldDecorator* extraBarnField ;

    // Test the functionalities of the decorated CropField
    std::cout << "Testing the CropField with FertilizedField and ExtraBarn:\n";

    // Increase production
    extraBarnField->increaseProduction();
    std::cout << std::endl;

    // Harvest crops
    extraBarnField->harvest();
    std::cout << std::endl;

    // Check leftover capacity
    int capacity = extraBarnField->getLeftoverCapacity();
    std::cout << "Leftover Capacity after operations: " << capacity << " units\n";
    std::cout << std::endl;

    // Additional creative testing
    std::cout << "Running additional creative tests:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "Cycle " << (i + 1) << ":\n";
        extraBarnField->increaseProduction();
        extraBarnField->harvest();
        capacity = extraBarnField->getLeftoverCapacity();
        std::cout << "Leftover Capacity: " << capacity << " units\n";
        std::cout << std::endl;
    }

    // Clean up dynamically allocated memory
    delete extraBarnField;
    delete fertilizedField;
    delete basicField;

    return 0;
}
