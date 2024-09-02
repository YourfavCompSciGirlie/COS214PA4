// BasicCropField.h
#ifndef BASIC_CROP_FIELD_H
#define BASIC_CROP_FIELD_H

#include "CropField.h"

class BasicCropField : public CropField 
{
protected:
    int soilState; // 0: DrySoil, 1: FruitfulSoil
    int storageCapacity;  //this is for total stiorage capacity
    int cropsYield;       // Amount of crops produced
    int harvestedCrops;   // Amount of crops harvested

public:
    BasicCropField(); // default capacity

    void increaseProduction() override; 
    void harvest() override;

    int getLeftoverCapacity() override;
    void displayFieldStatus();
};

#endif // BASIC_CROP_FIELD_H
