#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <vector>
#include <string>

#include "Truck.h"

using namespace std;

class FarmUnit {
    private:
        std::vector<Truck*> trucks;

<<<<<<< HEAD
public:
    
    virtual int getTotalCapacity() = 0;
    virtual string getCropType() = 0;
    virtual string getSoilStateName() = 0;
=======
    public:
        virtual void buyTruck(Truck* truck) = 0;
        virtual void sellTruck(Truck* truck) = 0;
        virtual void callTruck() = 0;

        virtual int getTotalCapacity() = 0;
        virtual string getCropType() = 0;
        virtual string getSoilStateName() = 0;
>>>>>>> 65170a403908ebc83eba818fe2a575f114c86ac7

        // Composite pattern methods
        virtual void add(FarmUnit* unit) {}
        virtual void remove(FarmUnit* unit) {}

        virtual int getCurrentAmount() = 0;
        virtual void setCurrentAmount(int amount) = 0;

        virtual ~FarmUnit();
        FarmUnit();

        // Nobuhle - Decorator functions
        virtual void increaseProduction() = 0;
        virtual void harvest() = 0;
        virtual int getLeftoverCapacity() = 0;
};

#endif // FARMUNIT_H