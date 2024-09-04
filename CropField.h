// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "NotificationSystem.h"

#include <string>
using namespace std;
class SoilState;

class CropField : public FarmUnit, public NotificationSystem
{
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

        SoilState* soilState;

    public:
        CropField();
        CropField(const string& cropType, int totalCapacity, SoilState* initialState);
        virtual ~CropField();

        int getTotalCapacity()override;
        string getCropType()override;
        string getSoilStateName()override;

        void setSoilState(SoilState* newState);
        int harvestCrops();
        void rain();

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Provide accessors for soilState
        SoilState* getSoilState() const;

        // Nobuhle - Decorator functions
        void buyTruck(Truck* truck);
        void sellTruck(Truck* truck);       
};

#endif // CROPFIELD_H
