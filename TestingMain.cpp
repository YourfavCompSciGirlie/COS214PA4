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

void testFertilizedField() {
    // Step 1: Create a base CropField
    cout << "=== Step 1: Create a base CropField ===\n";
    CropField* baseField = new CropField("Corn", 200, new DrySoil());

    cout << "Crop Type: " << baseField->getCropType() << endl;
    cout << "Soil State: " << baseField->getSoilStateName() << endl;
    cout << "Total Capacity: " << baseField->getTotalCapacity() << endl;

    // Step 2: Decorate with FertilizedField
    cout << "\n=== Step 2: Decorate with FertilizedField ===\n";
    FertilizedField* fertilizedField = new FertilizedField(baseField);

    cout << "Crop Type (FertilizedField): " << fertilizedField->getCropType() << endl;
    cout << "Soil State (FertilizedField): " << fertilizedField->getSoilStateName() << endl;
    cout << "Total Capacity (FertilizedField): " << fertilizedField->getTotalCapacity() << endl;

    // Step 3: Test increaseProduction and harvest
    cout << "\n=== Step 3: Test increaseProduction and harvest ===\n";
    fertilizedField->increaseProduction();
    fertilizedField->harvest();

    // Step 4: Test add() and remove() (should be non-functional)
    cout << "\n=== Step 4: Test add() and remove() ===\n";
    FarmUnit* dummyUnit = nullptr;  // Simulate a farm unit
    fertilizedField->add(dummyUnit);
    fertilizedField->remove(dummyUnit);

    // Step 5: Test Truck logistics (buy and sell truck)
    cout << "\n=== Step 5: Test Truck Logistics ===\n";
    Truck* fertilizerTruck = new FertilizerTruck();
    fertilizedField->buyTruck(fertilizerTruck);
    fertilizedField->sellTruck(fertilizerTruck);

    // Step 6: Test setting and getting crop amounts
    cout << "\n=== Step 6: Test setting and getting crop amounts ===\n";
    fertilizedField->setCurrentAmount(100);
    cout << "Current Crop Amount: " << fertilizedField->getCurrentAmount() << endl;

    // Step 7: Test leftover capacity
    cout << "\n=== Step 7: Test getLeftoverCapacity() ===\n";
    cout << "Leftover Capacity: " << fertilizedField->getLeftoverCapacity() << endl;

    // Step 8: Test soil state transition after rain
    cout << "\n=== Step 8: Test soil state transition after rain ===\n";
    baseField->rain();  // Transition DrySoil to FruitfulSoil
    cout << "New Soil State: " << fertilizedField->getSoilStateName() << endl;

    // Step 9: Test Iterator methods (BFS and DFS)
    cout << "\n=== Step 9: Test BFS and DFS Iterators ===\n";
    FarmIterator* bfsIterator = fertilizedField->createBFSIterator();
    FarmIterator* dfsIterator = fertilizedField->createDFSIterator();

    // Iterate over the fields using BFS iterator
    cout << "Iterating with BFS Iterator:\n";
    for (bfsIterator->firstFarm(); !bfsIterator->isDone(); bfsIterator->next()) {
        cout << "Farm Unit: " << bfsIterator->currentFarm()->getName() << endl;
    }

    // Iterate over the fields using DFS iterator
    cout << "Iterating with DFS Iterator:\n";
    for (dfsIterator->firstFarm(); !dfsIterator->isDone(); dfsIterator->next()) {
        cout << "Farm Unit: " << dfsIterator->currentFarm()->getName() << endl;
    }

    // Step 10: Clean up
    cout << "\n=== Step 10: Clean up ===\n";
    delete baseField;
    delete fertilizedField;
    delete fertilizerTruck;
    delete bfsIterator;
    delete dfsIterator;
 
}

void testExtraBarn() {
    // Create a base CropField with a FruitfulSoil
    CropField* baseField = new CropField("Wheat", 100, new FruitfulSoil());
    
    // Wrap the baseField with an ExtraBarn
    ExtraBarn* extraBarn = new ExtraBarn(baseField, 50);
    
    // Output test header
    std::cout << "\nTesting ExtraBarn functionality...\n";

    cout << endl;
    
    // Test increaseProduction
    std::cout << "Testing increaseProduction:\n";
    extraBarn->increaseProduction();

    cout << endl;
    
    // Test harvest
    std::cout << "Testing harvest:\n";
    extraBarn->harvest();

    cout << endl;
    
    // Test getLeftoverCapacity
    std::cout << "Testing getLeftoverCapacity:\n";
    int leftoverCapacity = extraBarn->getLeftoverCapacity();
    std::cout << "Leftover capacity: " << leftoverCapacity << std::endl;

    cout << endl;
    
    // Test buyTruck
    Truck* truck = new DeliveryTruck();
    std::cout << "Testing buyTruck:\n";
    extraBarn->buyTruck(truck);

    cout << endl;
    
    // Test sellTruck
    std::cout << "Testing sellTruck:\n";
    extraBarn->sellTruck(truck);

    cout << endl;
    
    // Test getTotalCapacity
    std::cout << "Testing getTotalCapacity:\n";
    int totalCapacity = extraBarn->getTotalCapacity();
    std::cout << "Total capacity: " << totalCapacity << std::endl;

    cout << endl;
    
    // Test getCropType
    std::cout << "Testing getCropType:\n";
    std::string cropType = extraBarn->getCropType();
    std::cout << "Crop type: " << cropType << std::endl;

    cout << endl;
    
    // Test getSoilStateName
    std::cout << "Testing getSoilStateName:\n";
    std::string soilState = extraBarn->getSoilStateName();
    std::cout << "Soil state: " << soilState << std::endl;

    cout << endl;
    
    // Test getCurrentAmount
    std::cout << "Testing getCurrentAmount:\n";
    int currentAmount = extraBarn->getCurrentAmount();
    std::cout << "Current amount: " << currentAmount << std::endl;

    cout << endl;
    
    // Test setCurrentAmount
    std::cout << "Testing setCurrentAmount:\n";
    extraBarn->setCurrentAmount(150);
    currentAmount = extraBarn->getCurrentAmount();
    std::cout << "Current amount after setting: " << currentAmount << std::endl;

    cout << endl;
    
    // Test getSubUnits
    std::cout << "Testing getSubUnits:\n";
    std::vector<FarmUnit*> subUnits = extraBarn->getSubUnits();
    std::cout << "Number of sub-units: " << subUnits.size() << std::endl;

    cout << endl;

    // Test Iterator pattern methods
    FarmIterator* bfsIterator = extraBarn->createBFSIterator();
    FarmIterator* dfsIterator = extraBarn->createDFSIterator();

    // Test setName and getName
    extraBarn->setName("My Extra Barn");
    cout << "Barn Name: " << extraBarn->getName() << endl;

    cout << endl;
    
    // Test add and remove functionality
    std::cout << "Testing add and remove:\n";
    FarmUnit* unit = new CropField("Corn", 200, new FloodedSoil());  // Dummy unit for testing
    extraBarn->add(unit);
    extraBarn->remove(unit);

    cout << endl;
    
    // Clean up
    delete bfsIterator;
    delete dfsIterator;
    delete baseField;
    delete extraBarn;
    delete truck;
    delete unit;

    cout << "Finished testing ExtraBarn.\n";
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

    cout << "\n========================== Component 5: Iterator ===============================\n" << endl;
    testingIterator();

    cout << endl;

    cout << "\n========================== Additional Testing for Coverage =======================\n" << endl;
    testFarmland();
    cout << endl;
    
    testBarn();
    cout << endl;
    
    testFertilizedField();
    cout << endl;
    
    testExtraBarn();
    cout << endl;

    return 0;
}

