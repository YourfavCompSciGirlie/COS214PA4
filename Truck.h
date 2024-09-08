// Class definition for Component 4 - Observer (Observer)

/**
 * @file Truck.h
 * @brief Class definition for Component 4 - Observer (Observer)
 */

#ifndef TRUCK_H
#define TRUCK_H

class NotificationSystem;

/**
 * @class Truck
 * @brief Abstract base class for trucks.
 * 
 * This class defines the interface for different types of trucks. It provides methods for starting
 * the engine and calling the truck, which will be implemented in derived classes.
 */

class Truck
{
    public:
    /**
    * @brief Virtual destructor for Truck.
    */
    virtual ~Truck();

    /**
    * @brief Default constructor for Truck.
    */
    Truck();
    //These ARE GOING TO BE IMPLEMENTED inside the trucks classes
    /**
    * @brief Starts the truck's engine.
    * This method must be implemented in derived classes to provide specific engine start functionality.
    */
    virtual void startEngine() = 0;

    /**
    * @brief Calls the truck.
    * This method must be implemented in derived classes to provide specific call functionality.
    */
    virtual void callTruck ()= 0;
};
#endif