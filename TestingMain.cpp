#include <iostream>
#include <vector>
#include <string>

#include "Farmland.h"
#include "CropField.h"
#include "Barn.h"
#include "FarmUnit.h"

#include "DrySoil.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"
#include "SoilState.h"

#include "CropFieldDecorator.h"
#include "FertilizedField.h"
#include "ExtraBarn.h"
#include "Truck.h"
#include "FertilizerTruck.h"
#include "DeliveryTruck.h"
#include "NotificationSystem.h"

#include "FarmIterator.h"

using namespace std;

void testingComposite() {
    // Create SoilState instances (you should replace these with concrete implementations)
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    cout << endl;

    // Create individual FarmUnit instances
    CropField wheatField("Wheat", 500, drySoil);
    CropField cornField("Corn", 300, fruitfulSoil);
    Barn storageBarn(1000); // Capacity for 1000 units   

    cout << endl;   

    // Create composite Farmland
    Farmland mainFarmland;

    // Add CropFields, Greenhouse, and Barn to Farmland
    mainFarmland.add(&wheatField);
    mainFarmland.add(&cornField);
    mainFarmland.add(&storageBarn);

    // Add a nested Farmland to test hierarchy
    Farmland nestedFarmland;
    cout << endl;
    CropField riceField("Rice", 400, drySoil);
    nestedFarmland.add(&riceField);
    mainFarmland.add(&nestedFarmland);

    cout << endl;

    // Test getTotalCapacity() for Farmland and individual units
    cout << "Total Capacity of Main Farmland: " << mainFarmland.getTotalCapacity() << endl;
    cout << "Total Capacity of Wheat Field: " << wheatField.getTotalCapacity() << endl;

    cout << endl;

    // Test getCropType() for CropFields and Greenhouse
    cout << "Crop Type of Wheat Field: " << wheatField.getCropType() << endl;
    cout << "Crop Type of Corn Field: " << cornField.getCropType() << endl;
    cout << "Crop Type of Rice Field: " << riceField.getCropType() << endl;

    cout << endl;

    // Test getSoilStateName() for CropFields
    cout << "Soil State of Wheat Field: " << wheatField.getSoilStateName() << endl;
    cout << "Soil State of Corn Field: " << cornField.getSoilStateName() << endl;
    cout << "Soil State of Rice Field: " << riceField.getSoilStateName() << endl;

    cout << endl;

    // Test getCurrentAmount() and setCurrentAmount() for CropField and Greenhouse
    cout << "Current Amount of Wheat Field: " << wheatField.getCurrentAmount() << endl;
    wheatField.setCurrentAmount(100); // Set new amount
    cout << "Updated Amount of Wheat Field: " << wheatField.getCurrentAmount() << endl;

    cout << endl;

    // Test removal and getTotalCapacity() after removal
    mainFarmland.remove(&cornField);
    cout << "Total Capacity of Main Farmland after removing Corn Field: " << mainFarmland.getTotalCapacity() << endl;

    cout << endl;

    // Test nested Farmland capacity
    cout << "Total Capacity of Nested Farmland: " << nestedFarmland.getTotalCapacity() << endl;

    cout << endl;
}

void testingState() {
    // // Create SoilState instances
    // SoilState* drySoil = new DrySoil();
    // SoilState* fruitfulSoil = new FruitfulSoil();
    // SoilState* floodedSoil = new FloodedSoil();

    // // Create CropField with initial soil state
    // string cropType = "Wheat";
    // CropField wheatField(cropType, 500, drySoil);

    // // Test harvesting crops and soil state name
    // cout << "Harvesting crops from Wheat Field with Dry Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    // cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // // Change soil state to Fruitful
    // wheatField.setSoilState(fruitfulSoil);
    // cout << "Harvesting crops from Wheat Field with Fruitful Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    // cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // // Change soil state to Flooded
    // wheatField.setSoilState(floodedSoil);
    // cout << "Harvesting crops from Wheat Field with Flooded Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    // cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    // // Clean up
    // delete drySoil;
    // delete fruitfulSoil;
    // delete floodedSoil;
}

void testingDecorator() {
    // // Create SoilState instances
    // SoilState* drySoil = new DrySoil();
    // SoilState* fruitfulSoil = new FruitfulSoil();

    // // Create a basic CropField
    // CropField* wheatField = new CropField("Wheat", 500, drySoil);

    // // Apply fertilizer to the CropField to transition from DrySoil to FruitfulSoil
    // cout << "Initial Soil State: " << wheatField->getSoilStateName() << endl;
    // FertilizedField* fertilizedWheatField = new FertilizedField(wheatField);
    // fertilizedWheatField->increaseProduction();
    // cout << "Soil State after fertilization: " << wheatField->getSoilStateName() << endl;

    // // Harvest crops after applying fertilizer
    // cout << "Harvesting after fertilization: " << fertilizedWheatField->harvest() << endl;

    // // Add an ExtraBarn to increase storage capacity
    // ExtraBarnD* barnEnhancedField = new ExtraBarn(wheatField, 200); // Adding 200 units of extra storage
    // cout << "Original Capacity: " << wheatField->getTotalCapacity() << endl;
    // cout << "Increased Capacity after adding ExtraBarn: " << barnEnhancedField->getTotalCapacity() << endl;

    // // Test leftover capacity after using some storage
    // cout << "Remaining Capacity after storing 100 units: " << barnEnhancedField->getLeftoverCapacity() << endl;

    // // Clean up
    // delete drySoil;
    // delete fruitfulSoil;
    // delete fertilizedWheatField; // Also deletes wheatField
    // delete barnEnhancedField; // Also deletes fertilizedWheatField
}

void testingObserver() {
    // // Create SoilState instances
    // SoilState* drySoil = new DrySoil();
    // SoilState* fruitfulSoil = new FruitfulSoil();

    // // Create a basic CropField
    // CropField* wheatField = new CropField("Wheat", 500, drySoil);

    // // Create trucks
    // FertilizerTruck* fertilizerTruck = new FertilizerTruck();
    // DeliveryTruck* deliveryTruck = new DeliveryTruck();

    // // Attach trucks to the CropField (subject)
    // wheatField->attach(fertilizerTruck);
    // wheatField->attach(deliveryTruck);

    // // Simulate fertilization event
    // cout << "Triggering fertilization event..." << endl;
    // wheatField->setSoilState(fruitfulSoil); // Transition to FruitfulSoil should trigger fertilizer delivery
    // wheatField->notifyTrucks(); // Manually notify for testing purposes

    // // Simulate harvest event and check if storage capacity triggers delivery truck
    // cout << "Simulating harvest and checking storage capacity..." << endl;
    // wheatField->setCurrentAmount(480); // Near the capacity
    // wheatField->notifyTrucks(); // Should trigger delivery truck due to nearing capacity

    // // Simulate buying and selling trucks
    // wheatField->buyTruck(fertilizerTruck);
    // wheatField->sellTruck(deliveryTruck);

    // // Start trucks' operations
    // fertilizerTruck->startEngine();
    // deliveryTruck->startEngine();

    // // Clean up
    // delete drySoil;
    // delete fruitfulSoil;
    // delete fertilizerTruck;
    // delete deliveryTruck;
    // delete wheatField;
}



int main() {

    cout << "\n========================== Component 1: Composite ===========================\n" << endl;
    testingComposite();

    cout << endl;

    cout << "\n========================== Component 2: State ================================\n" << endl;
    testingState();

    cout << endl;

    cout << "\n========================== Component 3: Decorator =============================\n" << endl;
    testingDecorator();

    cout << endl;

    cout << "\n========================== Component 4: Observer ===============================\n" << endl;
    testingObserver();

    cout << endl;

    
    return 0;
}

