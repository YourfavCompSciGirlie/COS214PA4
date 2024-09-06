// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)
// Class definition for Component 4 - Observer (ConcreteSubject)

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "NotificationSystem.h"
#include "Truck.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

#include <string>
#include <vector>

using namespace std;

class SoilState;

class CropField : public FarmUnit, public NotificationSystem {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

        string name;

        SoilState* soilState;

    public:
        CropField() {};
        CropField(const string& cropType, int totalCapacity, SoilState* initialState);
        virtual ~CropField();

        int getTotalCapacity();
        string getCropType();
        string getSoilStateName();

        void setSoilState(SoilState* newState);
        int harvestCrops();
        void rain();

        // Composite pattern methods
        void add(FarmUnit* unit);
        void remove(FarmUnit* unit);

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Provide accessors for soilState
        SoilState* getSoilState() const;

        // Observer pattern methods
        void buyTruck(Truck* truck);
        void sellTruck(Truck* truck);

        // Decorator pattern methods
        void increaseProduction();
        void harvest();
        int getLeftoverCapacity();  

        // Iterator pattern methods
        vector<FarmUnit*> getSubUnits();
        FarmIterator* createBFSIterator();
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        void setName(const string& unitName);
        string getName() const;
};

#endif // CROPFIELD_H
