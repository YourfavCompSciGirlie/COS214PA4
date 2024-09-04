// Class definition for Component 1 - Composite (Leaf)

#ifndef GREENHOUSE_H
#define GREENHOUSE_H

#include "FarmUnit.h"
#include "SoilState.h"

using namespace std;

class Greenhouse : public FarmUnit {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

    public:
        Greenhouse(int totalCapacity);
        ~Greenhouse();
        
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

#endif // GREENHOUSE_H
