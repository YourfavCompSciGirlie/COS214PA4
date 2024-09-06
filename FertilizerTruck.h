// Class definition for Component 4 - Observer (ConcreteObserver)

#ifndef FERTILIZER_TRUCK_H
#define FERTILIZER_TRUCK_H

#include "Truck.h"

class FertilizerTruck : public Truck
{
    public:
     void startEngine();
     void callTruck();

     FertilizerTruck();
     ~FertilizerTruck();   
};
#endif
