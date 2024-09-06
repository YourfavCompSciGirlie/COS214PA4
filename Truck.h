// Class definition for Component 4 - Observer (Observer)

#ifndef TRUCK_H
#define TRUCK_H

class NotificationSystem;

class Truck
{
    public:
    virtual ~Truck();
    Truck();
    //These ARE GOING TO BE IMPLEMENTED inside the trucks classes
    virtual void startEngine() = 0;
    virtual void callTruck ()= 0;
};
#endif