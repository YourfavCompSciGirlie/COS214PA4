// Class definition for Component 1 - Composite (Leaf)

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"

using namespace std;

class Barn : public FarmUnit {
    
    private:
        int totalCapacity;
        int currentAmount;

    public:
        Barn(int totalCapacity);
        ~Barn();

        int getTotalCapacity();
        string getCropType();
        string getSoilStateName();

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Decorator pattern methods
        void increaseProduction() override;
        void harvest() override;
        int getLeftoverCapacity() override;

        // Observer pattern methods
        void buyTruck(Truck* truck) override;
        void sellTruck(Truck* truck) override;
};

#endif // BARN_H
