#ifndef EXTRA_BARN_H
#define EXTRA_BARN_H

#include "CropField.h"
#include "CropFieldDecorator.h"

class ExtraBarn : public CropFieldDecorator
{
private:
    CropField* field;
     int extraStorageCapacity;

public:
    ExtraBarn(CropField* field, int extraCapacity);
    void increaseProduction() override;
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
