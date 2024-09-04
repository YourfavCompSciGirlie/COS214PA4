#include <iostream>
#include <vector>
#include <string>

#include "Farmland.h"
#include "CropField.h"
#include "Greenhouse.h"
#include "Barn.h"
#include "FarmUnit.h"

#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "SoilState.h"

using namespace std;

void testingComposite() {
    // Create SoilState instances (you should replace these with concrete implementations)
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    // Create individual FarmUnit instances
    CropField wheatField("Wheat", 500, drySoil);
    CropField cornField("Corn", 300, fruitfulSoil);
    Greenhouse tomatoGreenhouse(200); // Capacity for 200 tomatoes
    Barn storageBarn(1000); // Capacity for 1000 units

    // Create composite Farmland
    Farmland mainFarmland;

    // Add CropFields, Greenhouse, and Barn to Farmland
    mainFarmland.add(&wheatField);
    mainFarmland.add(&cornField);
    mainFarmland.add(&tomatoGreenhouse);
    mainFarmland.add(&storageBarn);

    // Add a nested Farmland to test hierarchy
    Farmland nestedFarmland;
    CropField riceField("Rice", 400, drySoil);
    nestedFarmland.add(&riceField);
    mainFarmland.add(&nestedFarmland);

    // Test getTotalCapacity() for Farmland and individual units
    cout << "Total Capacity of Main Farmland: " << mainFarmland.getTotalCapacity() << endl;
    cout << "Total Capacity of Wheat Field: " << wheatField.getTotalCapacity() << endl;
    cout << "Total Capacity of Tomato Greenhouse: " << tomatoGreenhouse.getTotalCapacity() << endl;

    // Test getCropType() for CropFields and Greenhouse
    cout << "Crop Type of Wheat Field: " << wheatField.getCropType() << endl;
    cout << "Crop Type of Corn Field: " << cornField.getCropType() << endl;
    cout << "Crop Type of Tomato Greenhouse: " << tomatoGreenhouse.getCropType() << endl;
    cout << "Crop Type of Rice Field: " << riceField.getCropType() << endl;

    // Test getSoilStateName() for CropFields
    cout << "Soil State of Wheat Field: " << wheatField.getSoilStateName() << endl;
    cout << "Soil State of Corn Field: " << cornField.getSoilStateName() << endl;
    cout << "Soil State of Rice Field: " << riceField.getSoilStateName() << endl;

    // Test getCurrentAmount() and setCurrentAmount() for CropField and Greenhouse
    cout << "Current Amount of Wheat Field: " << wheatField.getCurrentAmount() << endl;
    wheatField.setCurrentAmount(100); // Set new amount
    cout << "Updated Amount of Wheat Field: " << wheatField.getCurrentAmount() << endl;

    cout << "Current Amount of Tomato Greenhouse: " << tomatoGreenhouse.getCurrentAmount() << endl;
    tomatoGreenhouse.setCurrentAmount(150); // Set new amount
    cout << "Updated Amount of Tomato Greenhouse: " << tomatoGreenhouse.getCurrentAmount() << endl;

    // Test removal and getTotalCapacity() after removal
    mainFarmland.remove(&cornField);
    cout << "Total Capacity of Main Farmland after removing Corn Field: " << mainFarmland.getTotalCapacity() << endl;

    // Test nested Farmland capacity
    cout << "Total Capacity of Nested Farmland: " << nestedFarmland.getTotalCapacity() << endl;

    // Clean up
    delete drySoil;         // Assuming SoilState objects are not managed elsewhere
    delete fruitfulSoil;   // If managed by another class, avoid deleting here
    delete floodedSoil;    // Avoid double deletion
}

void testingState() {
    // Create SoilState instances
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    // Create CropField with initial soil state
    string cropType = "Wheat";
    CropField wheatField(cropType, 500, drySoil);

    // Test harvesting crops and soil state name
    cout << "Harvesting crops from Wheat Field with Dry Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // Change soil state to Fruitful
    wheatField.setSoilState(fruitfulSoil);
    cout << "Harvesting crops from Wheat Field with Fruitful Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // Change soil state to Flooded
    wheatField.setSoilState(floodedSoil);
    cout << "Harvesting crops from Wheat Field with Flooded Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // Clean up
    delete drySoil;
    delete fruitfulSoil;
    delete floodedSoil;
}




int main() {

    cout << "\n========================== Component 1: Composite ===========================\n" << endl;
    testingComposite();

    cout << endl;

    cout << "\n========================== Component 2: State ================================\n" << endl;
    testingState();

    cout << endl;

    
    return 0;
}

