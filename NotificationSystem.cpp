// Class implementation for Component 4 - Observer (Subject)

/**
 * @file NotificationSystem.cpp
 * @brief Implementation of the NotificationSystem class (Subject in the Observer Pattern).
 */

#include "NotificationSystem.h"

using namespace std;

/**
 * @brief Constructor for the NotificationSystem class.
 * 
 * Initializes the NotificationSystem with a message indicating its readiness to manage notifications.
 */
NotificationSystem::NotificationSystem() {
    std::cout << "🔔 Notification System is up and running! Ready to keep the trucks in check! 🚛" << std::endl;
}

/**
 * @brief Destructor for the NotificationSystem class.
 * 
 * Cleans up the NotificationSystem with a message indicating its shutdown.
 */
NotificationSystem::~NotificationSystem() {
    std::cout << "🔕 Shutting down Notification System. All trucks have been notified of the closure. 🛑" << std::endl;
}

/**
 * @brief Adds a Truck to the notification system.
 * 
 * @param truck Pointer to the Truck object to be added as an observer.
 */
void NotificationSystem::addObserver(Truck* truck) 
{
    observers.push_back(truck);
    std::cout << "🚛 Truck added to notification system.\n";
}

/**
 * @brief Removes a Truck from the notification system.
 * 
 * @param truck Pointer to the Truck object to be removed from the observers list.
 */
void NotificationSystem::removeObserver(Truck* truck) 
{
    auto it = std::find(observers.begin(), observers.end(), truck);
    if (it != observers.end()) {
        observers.erase(it);
        std::cout << "🚚 Truck removed from notification system.\n";
    }
}

/**
 * @brief Notifies all registered Truck observers.
 * 
 * Calls the startEngine method on all Truck objects currently registered as observers.
 */
void NotificationSystem::notifyAll() 
{
    if (observers.empty()) {
        std::cout << "❌ No trucks available to notify.\n";
        return;
    }

    std::cout << "🔔 Notifying all trucks...\n";
    for (auto observer : observers) {
        observer->startEngine();
    }
}

/**
 * @brief Notifies all registered Truck observers that fertilizer is needed.
 * 
 * Calls the notifyAll method to alert all trucks that the soil is dry.
 */
void NotificationSystem::notifyFertilizerNeeded() 
{
    std::cout << "🌱 Notification: Soil is dry. Fertilizer trucks needed.\n";
    notifyAll();
}

/**
 * @brief Notifies all registered Truck observers that storage capacity is reached.
 * 
 * Calls the notifyAll method to alert all trucks that the storage capacity is nearing its limit.
 */
void NotificationSystem::notifyStorageCapacityReached() 
{
    std::cout << "🏗️ Notification: Storage capacity nearing limit. Delivery trucks needed.\n";
    notifyAll();
}
