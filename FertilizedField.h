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
    void increaseProduction() override;
    void harvest() override;
    int getLeftoverCapacity() override;
};

#endif // FERTILIZED_FIELD_H
