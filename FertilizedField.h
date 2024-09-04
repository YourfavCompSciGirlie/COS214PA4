// FertilizedField.h
#ifndef FERTILIZED_FIELD_H
#define FERTILIZED_FIELD_H

#include "CropField.h"
#include "CropFieldDecorator.h"

class FertilizedField : public CropFieldDecorator
{
private:
    CropField* field;

public:
    FertilizedField(CropField* field);
    void increaseProduction()override;
    void harvest()override;
    int getLeftoverCapacity()override;

    void buyTruck(Truck* truck)override;
    void sellTruck(Truck* truck)override;

    int getTotalCapacity()override;
    string getCropType()override;
    string getSoilStateName()override;

    int getCurrentAmount()override;
    void setCurrentAmount(int amount)override;
};
#endif 
