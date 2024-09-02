// CropField.h
#ifndef CROP_FIELD_H
#define CROP_FIELD_H

class CropField {
public:
    virtual ~CropField() {}
    virtual void increaseProduction() = 0;
    virtual void harvest() = 0;
    virtual int getLeftoverCapacity() = 0;
};

#endif // CROP_FIELD_H
