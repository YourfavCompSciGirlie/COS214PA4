#ifndef TRUCK_H
#define TRUCK_H

class NotificationSystem;

class Truck
{
    public:
    virtual ~Truck() {}
    virtual void startEngine() = 0;


};
#endif