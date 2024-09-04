#include <iostream>
#include "BasicCropField.h"
#include "FertilizedField.h"
#include "ExtraBarn.h"
#include "FarmUnit.h"
#include "FertilizerTruck.h"
#include "DeliveryTruck.h"
#include "NotificationSystem.h"

void testBasicCropField() 
{
    BasicCropField basicField;
    std::cout << "Testing Basic Crop Field:\n";
    std::cout << "Initial storage capacity: " << basicField.getLeftoverCapacity() << "\n";
    
    basicField.increaseProduction();
    basicField.harvest();
    std::cout << "------------------------\n";
}

void testFertilizedField() 
{
    BasicCropField basicField;
    CropField* fertilizedField = new FertilizedField(&basicField);

    std::cout << "Testing Fertilized Field:\n";
    std::cout << "Storage capacity: " << fertilizedField->getLeftoverCapacity() << "\n";
    
    fertilizedField->increaseProduction();
    fertilizedField->harvest();
    std::cout << "------------------------\n";

    delete fertilizedField;
}

void testExtraBarn() 
{
    BasicCropField basicField;
    CropField* extraBarnField = new ExtraBarn(&basicField, 75);

    std::cout << "Testing Extra Barn:\n";
    std::cout << "Storage capacity with extra barn: " << extraBarnField->getLeftoverCapacity() << "\n";
    
    extraBarnField->increaseProduction();
    extraBarnField->harvest();
    std::cout << "------------------------\n";

    delete extraBarnField;
}

void testFertilizedFieldWithExtraBarn() 
{
    BasicCropField basicField;
    CropField* fertilizedField = new FertilizedField(&basicField);
    CropField* extraBarnField = new ExtraBarn(fertilizedField, 75);

    std::cout << "Testing Fertilized Field with Extra Barn:\n";
    std::cout << "Storage capacity with fertilization and extra barn: " << extraBarnField->getLeftoverCapacity() << "\n";
    
    extraBarnField->increaseProduction();
    extraBarnField->harvest();
    std::cout << "------------------------\n";

    delete extraBarnField;
}

void testMultipleDecorators() 
{
    BasicCropField basicField;
    CropField* fertilizedField = new FertilizedField(&basicField);
    CropField* extraBarnField = new ExtraBarn(fertilizedField, 50);
    CropField* fullyDecoratedField = new ExtraBarn(extraBarnField, 25);

    std::cout << "Testing Multiple Decorators:\n";
    std::cout << "Storage capacity with multiple decorators: " << fullyDecoratedField->getLeftoverCapacity() << "\n";
    
    fullyDecoratedField->increaseProduction();
    fullyDecoratedField->harvest();
    std::cout << "------------------------\n";

    delete fullyDecoratedField;
}

void testEmptyField() 
{
   
    BasicCropField emptyField;
    
    std::cout << "Testing Empty Crop Field:\n";
    std::cout << "Initial storage capacity: " << emptyField.getLeftoverCapacity() << "\n";
    
    emptyField.increaseProduction();
    emptyField.harvest();
    std::cout << "------------------------\n";
}

void testTruckHierarchy() 
{
    std::cout << "=== Testing Truck Hierarchy ===" << std::endl;

    Truck* fertilizerTruck = new FertilizerTruck();
    Truck* deliveryTruck = new DeliveryTruck();

    std::cout << "Starting Fertilizer Truck:" << std::endl;
    fertilizerTruck->startEngine();

    std::cout << "Starting Delivery Truck:" << std::endl;
    deliveryTruck->startEngine();

    delete fertilizerTruck;
    delete deliveryTruck;

    std::cout << "=== Truck Hierarchy Test Complete ===\n" << std::endl;
}

void testNotificationSystem() 
{
    std::cout << "=== Testing NotificationSystem ===" << std::endl;

    NotificationSystem notificationSystem;
    Truck* fertilizerTruck = new FertilizerTruck();
    Truck* deliveryTruck = new DeliveryTruck();

    notificationSystem.addObserver(fertilizerTruck);
    notificationSystem.addObserver(deliveryTruck);

    std::cout << "Notifying all trucks:" << std::endl;
    notificationSystem.notifyAll();  // Should notify both trucks to start their engines

    notificationSystem.removeObserver(fertilizerTruck);
    std::cout << "Notifying after removing FertilizerTruck:" << std::endl;
    notificationSystem.notifyAll();  // Should only notify the delivery truck

    delete fertilizerTruck;  // Cleanup
    delete deliveryTruck;

    std::cout << "=== NotificationSystem Test Complete ===\n" << std::endl;
}

void testCompleteIntegration() 
{
    std::cout << "=== Testing Complete Integration ===\n";

    FarmUnit farm;
    NotificationSystem notificationSystem;

    Truck* fertilizerTruck = new FertilizerTruck();
    Truck* deliveryTruck = new DeliveryTruck();

    
    farm.buyTruck(fertilizerTruck);
    farm.buyTruck(deliveryTruck);

    notificationSystem.addObserver(fertilizerTruck);
    notificationSystem.addObserver(deliveryTruck);

    
    std::cout << "FarmUnit calling trucks...\n";
    farm.callTruck(); 

    
    std::cout << "Notifying trucks from NotificationSystem...\n";
    notificationSystem.notifyAll();

    
    farm.sellTruck(fertilizerTruck);
    notificationSystem.removeObserver(fertilizerTruck);

    std::cout << "Final notification after removing FertilizerTruck...\n";
    notificationSystem.notifyAll();  

   
    delete fertilizerTruck;  
    delete deliveryTruck;

    std::cout << "=== Complete Integration Testing Complete ===\n\n";
}


int main() 
{
    testBasicCropField();
    testFertilizedField();
    testExtraBarn();
    testFertilizedFieldWithExtraBarn();
    testMultipleDecorators();
    testEmptyField();

    testNotificationSystem();
    testTruckHierarchy();
    testCompleteIntegration();
    return 0;
}
