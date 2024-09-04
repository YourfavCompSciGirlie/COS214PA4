// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "NotificationSystem.h"
#include "Truck.h"

#include <string>
#include <vector>

using namespace std;

class SoilState;

class CropField : public FarmUnit, public NotificationSystem {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

        SoilState* soilState;

    public:
        CropField();
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

        // Observer pattern methods
        void buyTruck(Truck* truck) override;
        void sellTruck(Truck* truck) override;

        // Decorator pattern methods
        void increaseProduction() override;
        void harvest() override;
        int getLeftoverCapacity() override;  
};

#endif // CROPFIELD_H
