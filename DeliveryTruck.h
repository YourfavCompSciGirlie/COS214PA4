#ifndef DELIVERY_TRUCK_H
#define DELIVERY_TRUCK_H

#include "Truck.h"
#include <string>

class DeliveryTruck  : public Truck
{
    private:
      //variables needed
      std::string soilTexture;
      int storageCapacity;

    public:
      void startEngine()override;
      void callTruck() override;       
};
#endif