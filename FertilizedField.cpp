#include "CropField.h"
#include <iostream>
#include "FertilizedField.h"
#include "CropFieldDecorator.h"

FertilizedField::FertilizedField(CropField* field) 
{
        this->field = field;
}

void FertilizedField::increaseProduction()  
{
        std::cout << "Applying premium fertilizer to the crop field...\n";
        
        field->increaseProduction();
        
        std::cout << "The soil is being enriched with extra nutrients.\n";
        
        if (field->getLeftoverCapacity() > 0) {
            field->increaseProduction();
            std::cout << "Crop yield has been supercharged! Additional increase in productivity.\n";
        } else {
            std::cout << "Field already has maximum production capacity.\n";
        }
}


void FertilizedField::harvest()
{
   std::cout << "Harvesting enhanced crops from the fertilized field...\n";
        
        
        field->harvest();
        
       
        if (rand() % 10 < 3) 
        { 
            std::cout << "Bonus harvest! Additional high-quality crops collected due to superior soil conditions.\n";
            int bonusYield = 10;
            int currentCapacity = field->getLeftoverCapacity();
            
            if (currentCapacity >= bonusYield) {
                std::cout << "Collected " << bonusYield << " extra units of premium crops.\n";
            } else if (currentCapacity > 0) {
                std::cout << "Storage almost full. Collected " << currentCapacity << " extra units of premium crops.\n";
            } else {
                std::cout << "Storage is full. No bonus crops could be stored.\n";
            }
        } else {
            std::cout << "No bonus crops this time. Regular harvest completed.\n";
        } 
}


 int FertilizedField::getLeftoverCapacity()
 {
        int baseCapacity = field->getLeftoverCapacity();
        int bonusCapacity = 10; // Additional capacity due to advanced storage management

        std::cout << "Enhanced field management provides " << bonusCapacity << " extra units of storage.\n";
        return baseCapacity + bonusCapacity;
}
    