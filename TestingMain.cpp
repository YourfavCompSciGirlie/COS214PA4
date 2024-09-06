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
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

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

    delete drySoil;
    delete fruitfulSoil;
    delete floodedSoil;

    cout << endl;
}

void testingState() {
    // Create SoilState instances
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    cout << endl;

    // Create CropField with initial soil state
    string cropType = "Wheat";
    CropField wheatField(cropType, 500, drySoil);

    // Test harvesting crops and soil state name
    cout << "Harvesting crops from Wheat Field with Dry Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    cout << endl;

    // Change soil state to Fruitful
    wheatField.setSoilState(fruitfulSoil);
    cout << "Harvesting crops from Wheat Field with Fruitful Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    cout << endl;

    // Change soil state to Flooded
    wheatField.setSoilState(floodedSoil);
    cout << "Harvesting crops from Wheat Field with Flooded Soil: " << wheatField.getSoilState()->harvestCrops() << endl;
    cout << "Current soil state: " << wheatField.getSoilStateName() << endl;

    cout << endl;

    delete floodedSoil;

    cout << endl;
}

void testingDecorator() {
    // Create SoilState instances
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();

    cout << endl;

    // Create a basic CropField
    CropField* wheatField = new CropField("Wheat", 500, drySoil);

    cout << endl;

    // Apply fertilizer to the CropField to transition from DrySoil to FruitfulSoil
    cout << "Initial Soil State: " << wheatField->getSoilStateName() << endl;

    cout << endl;

    FertilizedField* fertilizedWheatField = new FertilizedField(wheatField);
    cout << endl;
    fertilizedWheatField->increaseProduction();
    cout << "Soil State after fertilization: " << wheatField->getSoilStateName() << endl;

    cout << endl;

    // Harvest crops after applying fertilizer
    cout << "Harvesting after fertilization: ";
    fertilizedWheatField->harvest();

    cout << endl;

    // Add an ExtraBarn to increase storage capacity
    ExtraBarn* barnEnhancedField = new ExtraBarn(wheatField, 200); // Adding 200 units of extra storage
    cout << endl;
    cout << "Original Capacity: " << wheatField->getTotalCapacity() << endl;
    cout << "Increased Capacity after adding ExtraBarn: " << barnEnhancedField->getTotalCapacity() << endl;

    cout << endl;

    // Test leftover capacity after using some storage
    cout << "Remaining Capacity after storing 450 units: " << barnEnhancedField->getLeftoverCapacity() << endl;

    cout << endl;

    // Clean up
    delete fruitfulSoil;
    delete wheatField;
    delete fertilizedWheatField; 
    delete barnEnhancedField;
}

void testingObserver() {
    // Create SoilState instances
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();

    cout << endl;

    // Create a basic CropField
    CropField* wheatField = new CropField("Wheat", 500, drySoil);

    cout << endl;

    // Create trucks
    FertilizerTruck* fertilizerTruck = new FertilizerTruck();
    DeliveryTruck* deliveryTruck = new DeliveryTruck();

    // Attach trucks to the CropField (subject)
    wheatField->addObserver(fertilizerTruck);
    wheatField->addObserver(deliveryTruck);

    cout << endl;

    // Simulate fertilization event
    cout << "Triggering fertilization event..." << endl;
    wheatField->setSoilState(fruitfulSoil); // Transition to FruitfulSoil should trigger fertilizer delivery
    wheatField->notifyAll(); // Manually notify for testing purposes

    cout << endl;

    // Simulate harvest event and check if storage capacity triggers delivery truck
    cout << "Simulating harvest and checking storage capacity..." << endl;
    wheatField->setCurrentAmount(480); // Near the capacity
    wheatField->notifyAll(); // Should trigger delivery truck due to nearing capacity

    cout << endl;

    // Simulate buying and selling trucks
    wheatField->buyTruck(fertilizerTruck);
    cout << endl;
    wheatField->sellTruck(deliveryTruck);

    cout << endl;

    // Start trucks' operations
    fertilizerTruck->startEngine();
    deliveryTruck->startEngine();

    cout << endl;

    // Clean up
    delete fruitfulSoil;
    delete fertilizerTruck;
    delete deliveryTruck;
    delete wheatField;
}

void testingIterator() {
    // Create some FarmUnit objects and a farmland
    Farmland* farm1 = new Farmland();
    Farmland* farm2 = new Farmland();
    Farmland* farm3 = new Farmland();
    FarmUnit* field1 = new CropField();
    FarmUnit* field2 = new CropField();

    cout << endl;

    // Assign names to the farms and crop fields for display purposes
    farm1->setName("Main Farm");
    farm2->setName("North Farm");
    farm3->setName("East Farm");
    field1->setName("Wheat Field");
    field2->setName("Corn Field");

    // Build the farm hierarchy
    farm1->add(farm2);
    farm1->add(field1);
    farm2->add(farm3);
    farm2->add(field2);

    // Test BFS iterator
    FarmIterator* bfsIterator = farm1->createBFSIterator();
    cout << endl;
    std::cout << "Breadth-First Traversal:" << std::endl;
    for (FarmUnit* currentFarm = bfsIterator->firstFarm(); !bfsIterator->isDone(); currentFarm = bfsIterator->next()) {
        std::cout << "Visiting farm/field: " << currentFarm->getName() << std::endl;
    }

    cout << endl;

    // Test DFS iterator
    FarmIterator* dfsIterator = farm1->createDFSIterator();
    std::cout << "\nDepth-First Traversal:" << std::endl;
    for (FarmUnit* currentFarm = dfsIterator->firstFarm(); !dfsIterator->isDone(); currentFarm = dfsIterator->next()) {
        std::cout << "Visiting farm/field: " << currentFarm->getName() << std::endl;
    }

    cout << endl;

    // Clean up
    delete bfsIterator;
    delete dfsIterator;
    delete farm1;
    delete farm2;
    delete farm3;
    delete field1;
    delete field2;
}

// ------------------------------------- //

void testFarmland() {

    // Create some SoilState instances
    SoilState* dryState = new DrySoil();
    SoilState* fruitfulState = new FruitfulSoil();

    cout << endl;

    // Create a Farmland instance
    Farmland* farmland = new Farmland();
    farmland->setName("Main Farmland");
    
    cout << endl;

    // Create some CropField instances
    CropField* field1 = new CropField("Wheat", 100, dryState);
    CropField* field2 = new CropField("Corn", 150, fruitfulState);

    // Add units to the farmland
    farmland->add(field1);
    farmland->add(field2);

    cout << endl;

    // Test basic methods
    cout << "Testing Farmland methods:" << endl;
    cout << "Name: " << farmland->getName() << endl;
    cout << "Total Capacity: " << farmland->getTotalCapacity() << endl;
    cout << "Current Amount: " << farmland->getCurrentAmount() << endl;
    cout << "Leftover Capacity: " << farmland->getLeftoverCapacity() << endl;

    cout << endl;

    // Set current amount and test again
    farmland->setCurrentAmount(120);
    cout << "Updated Current Amount: " << farmland->getCurrentAmount() << endl;
    cout << "Updated Leftover Capacity: " << farmland->getLeftoverCapacity() << endl;

    cout << endl;

    // Test iterators
    FarmIterator* bfsIterator = farmland->createBFSIterator();

    cout << "\nBreadth-First Traversal:" << endl;
    for (FarmUnit* current = bfsIterator->firstFarm(); !bfsIterator->isDone(); current = bfsIterator->next()) {
        cout << "Visiting farm/field: " << current->getName() << endl;
    }

    cout << endl;

    FarmIterator* dfsIterator = farmland->createDFSIterator();
    cout << "\nDepth-First Traversal:" << endl;
    for (FarmUnit* current = dfsIterator->firstFarm(); !dfsIterator->isDone(); current = dfsIterator->next()) {
        cout << "Visiting farm/field: " << current->getName() << endl;
    }

    cout << endl;

    // Test adding and removing units
    CropField* field3 = new CropField("Barley", 200, fruitfulState);
    farmland->add(field3);
    cout << "\nAfter Adding Field 3:" << endl;
    cout << "Total Capacity: " << farmland->getTotalCapacity() << endl;

    farmland->remove(field1);
    cout << "\nAfter Removing Field 1:" << endl;
    cout << "Total Capacity: " << farmland->getTotalCapacity() << endl;

    cout << endl;

    // Clean up
    delete bfsIterator;
    delete dfsIterator;
    delete field1;
    delete field2;
    delete field3;
    delete dryState;
    delete fruitfulState;
    delete farmland;
}

void testBarn() {
    // Create a Barn instance
    Barn* barn = new Barn(500); // Initialize barn with a total capacity of 500 units
    barn->setName("Main Barn");

    cout << endl;

    // Test basic methods
    cout << "Testing Barn methods:" << endl;
    cout << "Name: " << barn->getName() << endl;
    cout << "Total Capacity: " << barn->getTotalCapacity() << endl;
    cout << "Current Amount: " << barn->getCurrentAmount() << endl;
    cout << "Leftover Capacity: " << barn->getLeftoverCapacity() << endl;

    cout << endl;

    // Set current amount and test again
    barn->setCurrentAmount(200);
    cout << "Updated Current Amount: " << barn->getCurrentAmount() << endl;
    cout << "Updated Leftover Capacity: " << barn->getLeftoverCapacity() << endl;

    cout << endl;

    // Test Decorator pattern methods
    barn->increaseProduction();
    barn->harvest();

    cout << endl;

    // Test Observer pattern methods
    Truck* truck = new DeliveryTruck(); // Assuming Truck class is defined
    cout << endl;
    barn->buyTruck(truck);
    barn->sellTruck(truck);

    cout << endl;

    SoilState* dryState = new DrySoil();

    cout << endl;

    // Test Composite pattern methods
    CropField* field = new CropField("Wheat", 100, dryState);
    barn->add(field); // Should indicate that adding units is not allowed
    barn->remove(field); // Should indicate that removing units is not allowed

    cout << endl;

    // Test Iterator pattern methods
    FarmIterator* bfsIterator = barn->createBFSIterator();
    cout << endl;
    cout << "\nBreadth-First Traversal:" << endl;
    for (FarmUnit* current = bfsIterator->firstFarm(); !bfsIterator->isDone(); current = bfsIterator->next()) {
        cout << "Visiting unit: " << current->getName() << endl;
    }

    FarmIterator* dfsIterator = barn->createDFSIterator();
    cout << "\nDepth-First Traversal:" << endl;
    for (FarmUnit* current = dfsIterator->firstFarm(); !dfsIterator->isDone(); current = dfsIterator->next()) {
        cout << "Visiting unit: " << current->getName() << endl;
    }

    cout << endl;

    // Clean up
    delete bfsIterator;
    delete dfsIterator;
    delete field;
    delete barn;
    delete truck;
    delete dryState;
}





int main() {

    // cout << "\n========================== Component 1: Composite ===========================\n" << endl;
    // testingComposite();

    // cout << endl;

    // cout << "\n========================== Component 2: State ================================\n" << endl;
    // testingState();

    // cout << endl;

    // cout << "\n========================== Component 3: Decorator =============================\n" << endl;
    // testingDecorator();

    // cout << endl;

    // cout << "\n========================== Component 4: Observer ===============================\n" << endl;
    // testingObserver();

    // cout << endl;

    // cout << "\n========================== Component 5: Iterator ===============================\n" << endl;
    // testingIterator();

    // cout << endl;

    cout << "\n========================== Additional Testing for Coverage =======================\n" << endl;
    // testFarmland();
    cout << endl;
    // testBarn();
    cout << endl;

    
    return 0;
}

