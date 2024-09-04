#ifndef NOTIFICATION_SYSTEM_H
#define NOTIFICATION_SYSTEM_H

#include <vector>
#include <algorithm>
#include "Truck.h"
#include <iostream>

class NotificationSystem 
{
    private:
        std::vector<Truck*> observers;

    public:
        void addObserver(Truck* truck) 
        {
            observers.push_back(truck);
            std::cout << "Truck added to notification system.\n";
        }

        void removeObserver(Truck* truck) 
        {
            auto it = std::find(observers.begin(), observers.end(), truck);
            if (it != observers.end()) {
                observers.erase(it);
                std::cout << "Truck removed from notification system.\n";
            }
        }

        void notifyAll() 
        {
            if (observers.empty()) {
                std::cout << "No trucks available to notify.\n";
                return;
            }

            std::cout << "Notifying all trucks...\n";
            for (auto observer : observers) {
                observer->startEngine();
            }
        }
    
        void notifyFertilizerNeeded() 
        {
            std::cout << "Notification: Soil is dry. Fertilizer trucks needed.\n";
            notifyAll();
        }

        void notifyStorageCapacityReached() 
        {
            std::cout << "Notification: Storage capacity nearing limit. Delivery trucks needed.\n";
            notifyAll();
        }
};

#endif 
