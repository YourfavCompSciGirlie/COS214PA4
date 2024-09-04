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
// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"

#include <string>

using namespace std;

class SoilState;

class CropField : public FarmUnit {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

        SoilState* soilState;

    public:
        CropField(const string& cropType, int totalCapacity, SoilState* initialState);
        virtual ~CropField();

        int getTotalCapacity() override;
        string getCropType() override;
        string getSoilStateName() override;

        void setSoilState(SoilState* newState);
        int harvestCrops();
        void rain();

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Provide accessors for soilState
        SoilState* getSoilState() const;
};

#endif // CROPFIELD_H
