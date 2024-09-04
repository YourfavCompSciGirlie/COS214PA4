#ifndef CROP_FIELD_DECORATOR_H
#define CROP_FIELD_DECORATOR_H

#include "CropField.h"

class CropFieldDecorator : public FarmUnit {
protected:
    CropField* field;  

public:
    CropFieldDecorator() = default;
    CropFieldDecorator(CropField* field);
    
    virtual void increaseProduction() = 0; 
    virtual void harvest() = 0;
    virtual int getLeftoverCapacity() = 0; 
    
};

#endif // CROP_FIELD_DECORATOR_H
