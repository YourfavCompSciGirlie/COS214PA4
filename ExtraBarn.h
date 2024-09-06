// Class defintion for Component 3 - Decorator (ConcreteDecorator)

#ifndef EXTRABARN_H
#define EXTRABARN_H

#include "CropField.h"
#include "CropFieldDecorator.h"

#include <algorithm>

using namespace std;

class ExtraBarn : public CropFieldDecorator {
    
    private:
        CropField* field;
        int extraStorageCapacity;

        string name;

    public:
        ExtraBarn(CropField* field, int extraCapacity);
        ~ExtraBarn();

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

#endif // EXTRABARN_H
