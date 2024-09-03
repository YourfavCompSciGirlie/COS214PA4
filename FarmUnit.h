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
