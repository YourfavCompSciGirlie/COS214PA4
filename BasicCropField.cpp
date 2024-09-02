#include "CropField.h"
#include "BasicCropField.h"

#include <iostream>
#include <string>

BasicCropField::BasicCropField()
{
    this->soilState = 0;
    this->storageCapacity = 100;
    this->cropsYield = 0;
    this->harvestedCrops = 0;
}

void BasicCropField::increaseProduction()
{
    if(soilState == 0)
    {
        soilState = 1;
        cropsYield += 30;
        std::cout <<  "Fertilezer applied: Soil is now fruitful.";

    }
    else 
    {
        std::cout << "Soil is already fertilized.No further increase in production\n";
    }
}


void BasicCropField:: harvest()
{
    if (cropsYield > 0) {
            int harvestableCrops = std::min(cropsYield, storageCapacity);
            harvestedCrops += harvestableCrops;
            cropsYield -= harvestableCrops;
            storageCapacity -= harvestableCrops;
            std::cout << "Harvested " << harvestableCrops << " units of crops. "
                      << "Remaining crops in field: " << cropsYield << ". "
                      << "Remaining storage capacity: " << storageCapacity << ".\n";
        } else {
            std::cout << "No crops to harvest.\n";
        }
}

int BasicCropField::getLeftoverCapacity()
{
     std::cout << "Current storage capacity: " << storageCapacity << " units.\n";
        return storageCapacity;
}


 void BasicCropField::displayFieldStatus() 
 {
        std::string soil = (soilState == 0) ? "DrySoil" : "FruitfulSoil";
        std::cout << "Field Status:\n"
                  << "Soil State: " << soil << "\n"
                  << "Current Crop Yield: " << cropsYield << " units\n"
                  << "Harvested Crops: " << harvestedCrops << " units\n"
                  << "Available Storage Capacity: " << storageCapacity << " units\n";
}