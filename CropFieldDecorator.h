#ifndef CROP_FIELD_DECORATOR_H
#define CROP_FIELD_DECORATOR_H

#include "CropField.h"

class CropFieldDecorator : public FarmUnit 
{
protected:
    CropField* field;  

public:
    CropFieldDecorator();
    ~CropFieldDecorator();
    CropFieldDecorator(CropField* field);
    
    virtual void increaseProduction() = 0; 
    virtual void harvest() = 0;
    virtual int getLeftoverCapacity() = 0;

    virtual int getTotalCapacity() = 0;
    virtual string getCropType() = 0;
    virtual string getSoilStateName() = 0; 
    
    // Observer pattern methods
    virtual void buyTruck(Truck* truck) = 0;
    virtual void sellTruck(Truck* truck) = 0;

    virtual int getCurrentAmount() = 0;
    virtual void setCurrentAmount(int amount) = 0;
};

#endif // CROP_FIELD_DECORATOR_H
