// Class defintion for Component 3 - Decorator (ConcreteDecorator)

#ifndef FERTILIZEDFIELD_H
#define FERTILIZEDFIELD_H

#include "CropField.h"
#include "CropFieldDecorator.h"
#include "FertilizedField.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"

#include <algorithm>

using namespace std;

class FertilizedField : public CropFieldDecorator {
    
    private:
        CropField* field;  // Wrapped CropField object
        string name;

    public:
        FertilizedField(CropField* field);
        ~FertilizedField();

        void increaseProduction();
        void harvest();
        int getLeftoverCapacity();

        void buyTruck(Truck* truck);
        void sellTruck(Truck* truck);

        int getTotalCapacity();
        string getCropType();
        string getSoilStateName();

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Iterator pattern methods
        vector<FarmUnit*> getSubUnits();
        FarmIterator* createBFSIterator();
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        void setName(const string& unitName);
        string getName() const;

        // Composite pattern methods
        void add(FarmUnit* unit);
        void remove(FarmUnit* unit);

};

#endif // FERTILIZEDFIELD_H
