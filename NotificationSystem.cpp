// Class implementation for Component 4 - Observer (Subject)

#include "NotificationSystem.h"

using namespace std;

NotificationSystem::NotificationSystem() {
    std::cout << "🔔 Notification System is up and running! Ready to keep the trucks in check! 🚛" << std::endl;
}


NotificationSystem::~NotificationSystem() {
    std::cout << "🔕 Shutting down Notification System. All trucks have been notified of the closure. 🛑" << std::endl;
}


void NotificationSystem::addObserver(Truck* truck) 
{
    observers.push_back(truck);
    std::cout << "🚛 Truck added to notification system.\n";
}


void NotificationSystem::removeObserver(Truck* truck) 
{
    auto it = std::find(observers.begin(), observers.end(), truck);
    if (it != observers.end()) {
        observers.erase(it);
        std::cout << "🚚 Truck removed from notification system.\n";
    }
}


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


void NotificationSystem::notifyFertilizerNeeded() 
{
    std::cout << "🌱 Notification: Soil is dry. Fertilizer trucks needed.\n";
    notifyAll();
}


void NotificationSystem::notifyStorageCapacityReached() 
{
    std::cout << "🏗️ Notification: Storage capacity nearing limit. Delivery trucks needed.\n";
    notifyAll();
}
