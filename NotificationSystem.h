// Class definition for Component 4 - Observer (Subject)

/**
 * @file NotificationSystem.h
 * @brief Class definition for Component 4 - Observer (Subject)
 */

#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include <vector>
#include <algorithm>
#include "Truck.h"
#include <iostream>

/**
 * @class NotificationSystem
 * @brief Implements the Subject role in the Observer design pattern.
 * 
 * The NotificationSystem class maintains a list of observers (trucks) and notifies them
 * of important events such as fertilizer requirements or when storage capacity is reached.
 */

class NotificationSystem 
{
    private:
        /**
         * @brief A list of observers (trucks) to be notified.
         */
        std::vector<Truck*> observers;

    public:
        /**
         * @brief Constructs a NotificationSystem object.
         */
        NotificationSystem();

        /**
         * @brief Destructor for NotificationSystem.
         */
        ~NotificationSystem();

        /**
         * @brief Adds an observer to the notification system.
         * 
         * @param truck A pointer to a Truck object to be added to the observer list.
         */
        void addObserver(Truck* truck);

        /**
         * @brief Removes an observer from the notification system.
         * 
         * @param truck A pointer to a Truck object to be removed from the observer list.
         */
        void removeObserver(Truck* truck);

        /**
         * @brief Notifies all observers of a general event.
         * 
         * This method calls the `callTruck()` method of all registered Truck observers.
         */

        void notifyAll();

        /**
         * @brief Notifies all observers when fertilizer is needed.
         * 
         * This method is used to alert trucks that fertilization is required on the farm.
         */
        void notifyFertilizerNeeded();

        /**
         * @brief Notifies all observers when storage capacity is reached.
         * 
         * This method alerts trucks when the farm's storage capacity is full and crops need to be transported.
         */
        void notifyStorageCapacityReached();
};

#endif // NOTIFICATION_SYSTEM_H
