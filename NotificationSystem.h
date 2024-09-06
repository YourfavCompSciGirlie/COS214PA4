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
        NotificationSystem();
        ~NotificationSystem();
        void addObserver(Truck* truck);
        void removeObserver(Truck* truck);
        void notifyAll();
        void notifyFertilizerNeeded();
        void notifyStorageCapacityReached();
};

#endif // NOTIFICATION_SYSTEM_H
