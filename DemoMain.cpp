// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// #include <vector>
// #include <string>

// #include "Farmland.h"
// #include "CropField.h"
// #include "Barn.h"
// #include "FarmUnit.h"

// #include "DrySoil.h"
// #include "FruitfulSoil.h"
// #include "FloodedSoil.h"
// #include "SoilState.h"

// #include "CropFieldDecorator.h"
// #include "FertilizedField.h"
// #include "ExtraBarn.h"
// #include "Truck.h"
// #include "FertilizerTruck.h"
// #include "DeliveryTruck.h"
// #include "NotificationSystem.h"

// #include "FarmIterator.h"

// using namespace std;

// int main() {
//     // Seed the random number generator
//     std::srand(std::time(nullptr));

//     SoilState* drySoil = new DrySoil();

//     // Create a basic CropField
//     CropField wheatField("Wheat", 500, drySoil);

//     // Decorate the CropField with FertilizedField
//     CropFieldDecorator* fertilizedField ;

//     // Further decorate the fertilized field with ExtraBarn
//     CropFieldDecorator* extraBarnField ;

//     // Test the functionalities of the decorated CropField
//     std::cout << "Testing the CropField with FertilizedField and ExtraBarn:\n";

//     // Increase production
//     extraBarnField->increaseProduction();
//     std::cout << std::endl;

//     // Harvest crops
//     extraBarnField->harvest();
//     std::cout << std::endl;

//     // Check leftover capacity
//     int capacity = extraBarnField->getLeftoverCapacity();
//     std::cout << "Leftover Capacity after operations: " << capacity << " units\n";
//     std::cout << std::endl;

//     // Additional creative testing
//     std::cout << "Running additional creative tests:\n";
//     for (int i = 0; i < 5; ++i) {
//         std::cout << "Cycle " << (i + 1) << ":\n";
//         extraBarnField->increaseProduction();
//         extraBarnField->harvest();
//         capacity = extraBarnField->getLeftoverCapacity();
//         std::cout << "Leftover Capacity: " << capacity << " units\n";
//         std::cout << std::endl;
//     }

//     // Clean up dynamically allocated memory
//     delete extraBarnField;
//     delete fertilizedField;

//     return 0;
// }
