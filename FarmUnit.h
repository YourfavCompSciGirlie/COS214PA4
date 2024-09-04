#ifndef FARM_UNIT_H
#define FARM_UNIT_H

#include <vector>
#include <string>
#include "Truck.h"

class FarmUnit {
private:
    std::vector<Truck*> trucks;

public:
    void buyTruck(Truck* truck);
    void sellTruck(Truck* truck);
    void callTruck();

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

    // Nobuhle - Decorator functions
    virtual void increaseProduction() = 0;
    virtual void harvest() = 0;
    virtual int getLeftoverCapacity() = 0;
};
#endif
