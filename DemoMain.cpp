#include <iostream>
#include "BasicCropField.h"
#include "FertilizedField.h"
#include "ExtraBarn.h"

void testBasicCropField() {
    BasicCropField basicField;
    std::cout << "Testing Basic Crop Field:\n";
    std::cout << "Initial storage capacity: " << basicField.getLeftoverCapacity() << "\n";
    
    basicField.increaseProduction();
    basicField.harvest();
    std::cout << "------------------------\n";
}

void testFertilizedField() {
    BasicCropField basicField;
    CropField* fertilizedField = new FertilizedField(&basicField);

    std::cout << "Testing Fertilized Field:\n";
    std::cout << "Storage capacity: " << fertilizedField->getLeftoverCapacity() << "\n";
    
    fertilizedField->increaseProduction();
    fertilizedField->harvest();
    std::cout << "------------------------\n";

    delete fertilizedField;
}

void testExtraBarn() {
    BasicCropField basicField;
    CropField* extraBarnField = new ExtraBarn(&basicField, 75);

    std::cout << "Testing Extra Barn:\n";
    std::cout << "Storage capacity with extra barn: " << extraBarnField->getLeftoverCapacity() << "\n";
    
    extraBarnField->increaseProduction();
    extraBarnField->harvest();
    std::cout << "------------------------\n";

    delete extraBarnField;
}

void testFertilizedFieldWithExtraBarn() {
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

void testMultipleDecorators() {
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

void testEmptyField() {
    // Create a CropField with default values
    BasicCropField emptyField;
    
    std::cout << "Testing Empty Crop Field:\n";
    std::cout << "Initial storage capacity: " << emptyField.getLeftoverCapacity() << "\n";
    
    emptyField.increaseProduction();
    emptyField.harvest();
    std::cout << "------------------------\n";
}

int main() {
    testBasicCropField();
    testFertilizedField();
    testExtraBarn();
    testFertilizedFieldWithExtraBarn();
    testMultipleDecorators();
    testEmptyField();

    return 0;
}
