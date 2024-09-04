// Class definition for Component 1 - Composite (Leaf)

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"

using namespace std;

class Barn : public FarmUnit {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

    public:
        Barn(int totalCapacity);
        ~Barn();

        int getTotalCapacity() override;
        string getCropType() override;
        string getSoilStateName() override;

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Nobuhle - Decorator functions
        void increaseProduction() override;
        void harvest() override;
        int getLeftoverCapacity() override;

        void buyTruck(Truck* truck) override;
        void sellTruck(Truck* truck) override;
        void callTruck() override;
};

#endif // BARN_H
