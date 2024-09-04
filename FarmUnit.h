// Class definition for Component 1 - Composite (Component)

#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <vector>
#include <string>

#include "Truck.h"
#include "FarmIterator.h"

using namespace std;

class FarmIterator;

class FarmUnit {
    
    public:
        FarmUnit();
        virtual ~FarmUnit();

        virtual int getTotalCapacity() = 0;
        virtual string getCropType() = 0;
        virtual string getSoilStateName() = 0;
>>>>>>> 65170a403908ebc83eba818fe2a575f114c86ac7

        // Composite pattern methods
        virtual void add(FarmUnit* unit) {}
        virtual void remove(FarmUnit* unit) {}

        virtual int getCurrentAmount() = 0;
        virtual void setCurrentAmount(int amount) = 0;

        // Decorator pattern methods
        virtual void increaseProduction() = 0;
        virtual void harvest() = 0;
        virtual int getLeftoverCapacity() = 0;

        // Observer pattern methods
        virtual void buyTruck(Truck* truck) = 0;
        virtual void sellTruck(Truck* truck) = 0;

        // // Create iterators for traversal
        // // Iterator pattern methods
        // virtual FarmIterator* createBFSIterator() = 0;
        // virtual FarmIterator* createDFSIterator() = 0;

        // // Return a list of sub-units (for composite)
        // virtual vector<FarmUnit*> getSubUnits() = 0;
};

#endif // FARMUNIT_H