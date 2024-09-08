// Class definition for Component 4 - Observer (ConcreteObserver)

/**
 * @file DeliveryTruck.h
 * @brief Class definition for Component 4 - Observer (ConcreteObserver)
 */

#ifndef DELIVERY_TRUCK_H
#define DELIVERY_TRUCK_H

#include "Truck.h"
#include <string>

/**
 * @class DeliveryTruck
 * @brief Represents a delivery truck used in farm logistics.
 * 
 * This class is a concrete observer in the observer pattern, responsible for managing deliveries
 * and observing notifications about transportation needs.
 */
class DeliveryTruck  : public Truck
{
    private:
      //variables needed
      std::string soilTexture; ///< Soil texture where the truck will be used.
      int storageCapacity; ///< Storage capacity of the delivery truck.

    public:
      /**
      * @brief Default constructor for DeliveryTruck.
      */
      DeliveryTruck();

      /**
      * @brief Destructor for DeliveryTruck.
      */
      ~DeliveryTruck();

      /**
      * @brief Starts the engine of the delivery truck.
      * 
      * Simulates the action of starting the truck's engine.
      */
      void startEngine();

      /**
       * @brief Calls the delivery truck for transportation.
       * 
      * Simulates the action of dispatching the truck to transport crops or goods.
      */
      void callTruck();       
};
#endif