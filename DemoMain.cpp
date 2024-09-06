#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <vector>
#include <string>

#include "Farmland.h"
#include "CropField.h"
#include "Barn.h"
#include "FarmUnit.h"
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
#include "FarmIterator.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

#include <thread>
#include <chrono>
#include <thread>
#include <chrono>

using namespace std;
using namespace std;

void printColored(const std::string &text, const std::string &colorCode)
{
    std::cout << "\033[" << colorCode << "m" << text << "\033[0m";
}
void printColored(const std::string &text, const std::string &colorCode)
{
    std::cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

// Function to add borders around headings
void printWithBorders(const std::string &heading, const std::string &colorCode)
{
    std::string border = std::string(heading.length() + 4, '-');
    printColored(border + "\n", colorCode);
    printColored("| " + heading + " |\n", colorCode);
    printColored(border + "\n", colorCode);
}
// Function to add borders around headings
void printWithBorders(const std::string &heading, const std::string &colorCode)
{
    std::string border = std::string(heading.length() + 4, '-');
    printColored(border + "\n", colorCode);
    printColored("| " + heading + " |\n", colorCode);
    printColored(border + "\n", colorCode);
}

void rainEffect() {
    std::cout << "\033[1;34m";
    for (int i = 0; i < 3; ++i) {
        std::cout << "        .     .  .       .     .  .      .   .     .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "   .    .   .    .   .    .   .    .   .    .   .    .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << " .   .   .     .      .   .     .      .   .     .   .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "\033[0m";
}
void rainEffect() {
    std::cout << "\033[1;34m";
    for (int i = 0; i < 3; ++i) {
        std::cout << "        .     .  .       .     .  .      .   .     .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << "   .    .   .    .   .    .   .    .   .    .   .    .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        std::cout << " .   .   .     .      .   .     .      .   .     .   .\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "\033[0m";
}

// Simulate a processing animation
void processingAnimation(const std::string& task) {
    std::cout << task;
    std::cout << "\033[1;33m"; // Yellow color
    for (int i = 0; i < 5; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    std::cout << "\033[0m" << std::endl;
}

// Function to print a field border with ASCII art
void printFieldBorder(const std::string &heading, const std::string &colorCode) {
    std::string border = std::string(heading.length() + 6, '=');
    printColored(border + "\n", colorCode);
    printColored("| * " + heading + " * |\n", colorCode);
    printColored(border + "\n", colorCode);
    std::cout << "   ( \\(\\ " << "       ( \\(\\ \n"
              << "   (-.- )" << "      (-.- )\n"
              << "o_(\")(\")" << " o_(\")(\")" << std::endl;
    std::cout << std::endl;
}


void testingComposite() 
{
    // 🌟 Start of Testing Composite Design Pattern
    printWithBorders("🌾 Testing Composite Design Pattern 🌾", "1;36");
    
    // 🌱 Create SoilState instances with meaningful soil types
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    cout << "\n🌍 Initializing Farmland Environment...\n";
    
    // 🌾 Create individual FarmUnit instances
    CropField wheatField("🌾 Wheat Field", 500, drySoil);
    CropField cornField("🌽 Corn Field", 300, fruitfulSoil);
    Barn storageBarn(1000); // 🏠 Barn with a capacity for 1000 units   

    cout << "🏡 Farm Units Initialized:\n";
    cout << "   - " << wheatField.getName() << " (Capacity: 500 units)\n";
    cout << "   - " << cornField.getName() << " (Capacity: 300 units)\n";
    cout << "   - " << storageBarn.getName() << " (Capacity: 1000 units)\n";

    cout << "\n🔗 Creating Composite Farmland...\n";

    // 🌿 Create composite Farmland
    Farmland mainFarmland;

    // ➕ Add CropFields and Barn to Farmland
    mainFarmland.add(&wheatField);
    mainFarmland.add(&cornField);
    mainFarmland.add(&storageBarn);

    cout << "🌱 Main Farmland contains:\n";
    cout << "   - " << wheatField.getName() << "\n";
    cout << "   - " << cornField.getName() << "\n";
    cout << "   - " << storageBarn.getName() << "\n";

    // 🌾 Add a nested Farmland to test hierarchy
    Farmland nestedFarmland;
    CropField riceField("🍚 Rice Field", 400, drySoil);
    nestedFarmland.add(&riceField);
    mainFarmland.add(&nestedFarmland);

    cout << "   - Nested Farmland contains:\n";
    cout << "     - " << riceField.getName() << " (Capacity: 400 units)\n";

    // 🧮 Test getTotalCapacity() for Farmland and individual units
    cout << "\n📊 Testing Capacity Calculations:\n";
    cout << "   🔹 Total Capacity of Main Farmland: " << mainFarmland.getTotalCapacity() << " units\n";
    cout << "   🔹 Total Capacity of " << wheatField.getName() << ": " << wheatField.getTotalCapacity() << " units\n";

    // 🌾 Test getCropType() for CropFields
    cout << "\n🌱 Testing Crop Types:\n";
    cout << "   🌾 Crop Type of " << wheatField.getName() << ": " << wheatField.getCropType() << "\n";
    cout << "   🌽 Crop Type of " << cornField.getName() << ": " << cornField.getCropType() << "\n";
    cout << "   🍚 Crop Type of " << riceField.getName() << ": " << riceField.getCropType() << "\n";

    // 🧑‍🌾 Test getSoilStateName() for CropFields
    cout << "\n🌍 Testing Soil States:\n";
    cout << "   🌾 Soil State of " << wheatField.getName() << ": " << wheatField.getSoilStateName() << "\n";
    cout << "   🌽 Soil State of " << cornField.getName() << ": " << cornField.getSoilStateName() << "\n";
    cout << "   🍚 Soil State of " << riceField.getName() << ": " << riceField.getSoilStateName() << "\n";

    // 📦 Test getCurrentAmount() and setCurrentAmount() for CropField
    cout << "\n📦 Testing Crop Amount Management:\n";
    cout << "   📦 Current Amount of " << wheatField.getName() << ": " << wheatField.getCurrentAmount() << " units\n";
    wheatField.setCurrentAmount(100); // Set new amount
    cout << "   ✅ Updated Amount of " << wheatField.getName() << ": " << wheatField.getCurrentAmount() << " units\n";

    // 🚜 Test removal and getTotalCapacity() after removal
    mainFarmland.remove(&cornField);
    cout << "\n🚜 Corn Field Removed! Testing Remaining Capacity:\n";
    cout << "   🔹 Total Capacity of Main Farmland after removing Corn Field: " << mainFarmland.getTotalCapacity() << " units\n";

    // 🔁 Test nested Farmland capacity
    cout << "\n🔁 Testing Nested Farmland Capacity:\n";
    cout << "   🔹 Total Capacity of Nested Farmland: " << nestedFarmland.getTotalCapacity() << " units\n";

    // 🚮 Clean up
    delete drySoil;
    delete fruitfulSoil;
    delete floodedSoil;

    cout << "\n🌟 Composite Design Pattern Test Completed! 🌟\n\n";
}

void testingState() //Nobuhle's Version 
{
    // 🌟 Start of Testing State Design Pattern
    printWithBorders("🌾 Testing State Design Pattern 🌾", "1;36");

    // 🌱 Initialize Soil States
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    SoilState* floodedSoil = new FloodedSoil();

    // 🧑‍🌾 Display Initial Soil State
    cout << "\n🌾 Initial Soil: " << endl;
    printColored("🌵 Dry Soil: " + drySoil->getName() + "\n", "1;33");

    // 🌾 Create a CropField with initial Dry Soil
    CropField wheatField("🌾 Wheat Field", 500, drySoil);
     printColored("🧑‍🌾 Current soil state of Wheat Field: " + wheatField.getSoilStateName() + "\n", "1;34");
     cout << endl;
    // 🌧️ Change Soil State to Fruitful
    cout << "\n🌧️ Changing Soil State to 🌱 Fruitful Soil..." << endl;
    wheatField.setSoilState(fruitfulSoil);
    printColored("🧑‍🌾 Current soil state of Wheat Field: " + wheatField.getSoilStateName() + "\n", "1;34");
    //rainEffect();
    cout << endl;

    // 🌧️🌧️ Simulate Heavy Rain and Change Soil State to Flooded
    cout << "\n🌧️🌧️🌧️ Simulating heavy rain... Flooding the soil..." << endl;
    wheatField.setSoilState(floodedSoil);
    printColored("🧑‍🌾 Current soil state of Wheat Field: " + wheatField.getSoilStateName() + "\n", "1;34");
    rainEffect();
    cout << endl;
    // 🚮 Clean up resources
    delete floodedSoil;
    cout << "\n🌟 State Design Pattern Test Completed! 🌟\n";
}

void testingDecorator() // Nobuhle's Version
{
    printWithBorders("🌾 Testing Decorator Design Pattern 🌾", "1;35");

    // 🌱 Initialize Soil States and Create Initial CropField
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    CropField* wheatField = new CropField("🌾 Wheat Field", 500, drySoil);

    // 🏡 Display Initial Field State
    cout << "\n🏡 Initial Field Setup: " << endl;
    cout << "  _______" << endl;
    cout << " |       |" << endl;
    cout << " | Field | 🌾 " << wheatField->getCropType() << endl;
    cout << " |_______|" << endl;
    printColored(" Soil state: " + wheatField->getSoilStateName() + "\n", "1;35");
    cout <<endl << endl;

    // 🌾 Apply Fertilizer Decorator
    printColored("🌾 Fertilizing the Wheat Field...", "1;36");
    cout<< endl;
    FertilizedField* fertilizedWheatField = new FertilizedField(wheatField);
    fertilizedWheatField->increaseProduction();
    cout <<endl;
    printColored(" 🌱 Soil state after fertilization: " + fertilizedWheatField->getSoilStateName(), "1;33" );
    
    cout << endl <<endl;

    // 🚜 Harvest after Fertilization
    printColored( "🚜 Harvesting after fertilization: ", "1;32");
    cout <<endl;
    fertilizedWheatField->harvest();
    cout << endl;

    // 🏚️ Apply Extra Barn Capacity Decorator
    printColored("\n🏚️ Enhancing Field with Extra Barn Capacity...", "1;33" );
    cout<< endl;
    ExtraBarn* barnEnhancedField = new ExtraBarn(wheatField, 200);
    cout << "📦 New storage capacity after adding ExtraBarn: " << barnEnhancedField->getTotalCapacity() << endl;

    cout << "📦 Remaining capacity: " << barnEnhancedField->getLeftoverCapacity() << endl;

    // 🚮 Clean up resources
    delete barnEnhancedField;
    delete fertilizedWheatField;
    delete fruitfulSoil;
    delete wheatField;

    cout << "\n🌟 Decorator Design Pattern Test Completed! 🌟\n";
}


void testingObserver() // Nobuhle Version
{
    // 🟨 Start of Testing Observer Design Pattern
    printWithBorders("🌟 Testing Observer Design Pattern 🌟", "1;33");

    // 🌱 Initialize Soil States and Create Initial CropField
    SoilState* drySoil = new DrySoil();
    SoilState* fruitfulSoil = new FruitfulSoil();
    CropField* wheatField = new CropField("🌾 Wheat Field", 500, drySoil);

    // 🚚 Initialize Trucks
    FertilizerTruck* fertilizerTruck = new FertilizerTruck();
    DeliveryTruck* deliveryTruck = new DeliveryTruck();

    // 🔄 Attach Observers to the Wheat Field
    cout << "\n🚜 Fertilizer Truck and Delivery Truck are on standby..." << endl;
    wheatField->addObserver(fertilizerTruck);
    wheatField->addObserver(deliveryTruck);

    // 🌾 Change Soil State to Fruitful and Notify Observers
    cout << "\n🌾 Fertilizing Wheat Field..." << endl;
    wheatField->setSoilState(new FruitfulSoil());
    printColored("🔔 Notifying all observers about the new soil state...", "1;32");
    cout <<endl<<endl;
    wheatField->notifyAll();

    // 🚚 Near-Capacity Field: Trigger Delivery Truck Notification
    cout << "\n🚚 Delivery Truck activated for near-capacity field..." << endl;
    wheatField->setCurrentAmount(480); // Near the capacity
    printColored("⚠️ Field nearing capacity: Delivering crops...", "1;31");
    cout <<endl <<endl;
    wheatField->notifyAll();

    // 🚛 Buying and Selling Truck Operations
    cout << "\n🚚 WheatField buys a Fertilizer Truck..." << endl;
    wheatField->buyTruck(fertilizerTruck);

    cout << "\n🚜 WheatField sells a Delivery Truck..." << endl;
    wheatField->sellTruck(deliveryTruck);

    // 🚛 Truck Engine Operations Simulation
    cout << "\n🔧 🚜 Fertilizer Truck Engine Starting..." << endl;
    fertilizerTruck->startEngine();

    cout << "\n🔧 🚚 Delivery Truck Engine Starting..." << endl;
    deliveryTruck->startEngine();

    // 🧹 Clean up resources
    delete fertilizerTruck;
    delete deliveryTruck;
    delete wheatField;
    delete fruitfulSoil;

    // 🟨 End of Testing Observer Design Pattern
    printWithBorders("🌟 Observer Design Pattern Test Completed! 🌟", "1;33");
}

// void testingIterator() Malaika's Version
//{
//     printWithBorders("Testing Iterator Design Pattern", "1;31");
//     // // Create some FarmUnit objects and a farmland
//     // Farmland* farm1 = new Farmland();
//     // Farmland* farm2 = new Farmland();
//     // Farmland* farm3 = new Farmland();
//     // FarmUnit* field1 = new CropField();
//     // FarmUnit* field2 = new CropField();

//     // // Build the farm hierarchy
//     // farm1->addFarmUnit(farm2);
//     // farm1->addFarmUnit(field1);
//     // farm2->addFarmUnit(farm3);
//     // farm2->addFarmUnit(field2);

//     // // Create and test BFS iterator
//     // FarmIterator* bfsIterator = farm1->createBFSIterator();
//     // while (!bfsIterator->isDone()) {
//     //     FarmUnit* currentFarm = bfsIterator->currentFarm();
//     //     cout << "Visiting farm/field in BFS: " << currentFarm->getName() << endl;
//     //     bfsIterator->next();
//     // }

//     // // Create and test DFS iterator
//     // FarmIterator* dfsIterator = farm1->createDFSIterator();
//     // while (!dfsIterator->isDone()) {
//     //     FarmUnit* currentFarm = dfsIterator->currentFarm();
//     //     cout << "Visiting farm/field in DFS: " << currentFarm->getName() << endl;
//     //     dfsIterator->next();
//     // }

//     // // Clean up
//     // delete bfsIterator;
//     // delete dfsIterator;
//     // delete farm1;
//     // delete farm2;
//     // delete farm3;
//     // delete field1;
//     // delete field2;
// }


// int main() {

//     cout << "\n========================== Component 1: Composite ===========================\n" << endl;
//     testingComposite();

//     cout << endl;

//     cout << "\n========================== Component 2: State ================================\n" << endl;
//     testingState();

//     cout << endl;

//     cout << "\n========================== Component 3: Decorator =============================\n" << endl;
//     testingDecorator();

//     cout << endl;

//     cout << "\n========================== Component 4: Observer ===============================\n" << endl;
//     testingObserver();

//     cout << endl;

//     cout << "\n========================== Component 5: Iterator ===============================\n" << endl;
//     testingIterator();

//     cout << endl;

    
//     return 0;
// }

