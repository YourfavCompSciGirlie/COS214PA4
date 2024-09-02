#include "CropField.h"
#include "ExtraBarn.h"
#include "CropFieldDecorator.h"

#include <iostream>

ExtraBarn::ExtraBarn(CropField* field, int extraCapacity)
{
     this->field= field;
     this->extraStorageCapacity = extraCapacity;
     std::cout << "Extra barn constructed with additional capacity of " << extraCapacity << " units.\n";
    
}

 void ExtraBarn:: increaseProduction()
{
        std::cout << "Optimizing production with enhanced storage management...\n";
        
        field->increaseProduction();
        
        if (extraStorageCapacity > 0) {
            std::cout << "The extra storage enables more efficient handling, slightly increasing productivity.\n";
            field->increaseProduction(); 
        } 
        else {
            std::cout << "No significant impact on production as storage is not extended.\n";
        }
}


void ExtraBarn::harvest() 
{
        std::cout << "Harvesting crops with enhanced storage capacity...\n";
        
        field->harvest();
        
        if (extraStorageCapacity > 0) {
            std::cout << "The extra barn allows for collecting a greater amount of harvested crops.\n";
        } else {
            std::cout << "Harvested crops, but no additional storage was available.\n";
        }
}


int ExtraBarn::getLeftoverCapacity() 
{
        int baseCapacity = field->getLeftoverCapacity();
        
        // Log the current state of storage
        std::cout << "Base storage capacity: " << baseCapacity << " units.\n";
        std::cout << "Additional capacity from extra barn: " << extraStorageCapacity << " units.\n";
        
        // Total available capacity after adding extra storage
        int totalCapacity = baseCapacity + extraStorageCapacity;
        std::cout << "Total leftover storage capacity: " << totalCapacity << " units.\n";
        
        return totalCapacity;
}