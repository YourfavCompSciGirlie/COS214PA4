#ifndef FARM_UNIT_H
#define FARM_UNIT_H

#include <vector>
#include "Truck.h"

class FarmUnit {
private:
    std::vector<Truck*> trucks;

public:
    void buyTruck(Truck* truck);
    void sellTruck(Truck* truck);
    void callTruck();
};

#endif 
// Class definition for Component 1 - Composite (Component)

#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <string>

using namespace std;

class FarmUnit {
    
    public:
        // Common interface methods for the Composite pattern
        virtual int getTotalCapacity() = 0;
        virtual string getCropType() = 0;
        virtual string getSoilStateName() = 0;

        // Composite pattern methods
        virtual void add(FarmUnit* unit) {}
        virtual void remove(FarmUnit* unit) {}

        virtual int getCurrentAmount() = 0;
        virtual void setCurrentAmount(int amount) = 0;

        virtual ~FarmUnit();
        FarmUnit();
};

#endif // FARMUNIT_H
