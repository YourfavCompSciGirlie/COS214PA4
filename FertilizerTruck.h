// Class definition for Component 4 - Observer (ConcreteObserver)

/**
 * @file FertilizerTruck.h
 * @brief Class definition for Component 4 - Observer (ConcreteObserver)
 */

#ifndef FERTILIZERTRUCK_H
#define FERTILIZERTRUCK_H

#include "Truck.h"

/**
 * @class FertilizerTruck
 * @brief Concrete observer class for the Observer pattern, representing a type of truck used for fertilizer.
 * 
 * This class inherits from Truck and represents a fertilizer truck in the farm management system. It 
 * includes methods for starting the engine and calling the truck, specific to its role in the system.
 */

class FertilizerTruck : public Truck
{
    public:
    /**
    * @brief Starts the engine of the fertilizer truck.
    */
    void startEngine();

    /**
    * @brief Calls the fertilizer truck for service or delivery.
    */
    void callTruck();
    
    /**
     * @brief Default constructor for FertilizerTruck.
    */
    FertilizerTruck();

    /**
    * @brief Destructor for FertilizerTruck.
    */ 
    ~FertilizerTruck();   
};

#endif
