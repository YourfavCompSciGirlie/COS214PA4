#ifndef CROP_FIELD_DECORATOR_H
#define CROP_FIELD_DECORATOR_H

#include "CropField.h"


class CropFieldDecorator : public CropField {
protected:
    CropField* field;  

public:
    CropFieldDecorator() = default;
    CropFieldDecorator(CropField* field) : field(field) {}

    
    virtual void increaseProduction() {
        field->increaseProduction();
    }

    void harvest() override {
        field->harvest();
    }

    int getLeftoverCapacity() override {
        return field->getLeftoverCapacity();
    }

    
    virtual ~CropFieldDecorator() {
        delete field;  
    }
};

#endif // CROP_FIELD_DECORATOR_H
