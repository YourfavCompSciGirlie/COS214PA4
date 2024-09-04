// Class implementation for Component 1 - Composite (Composite)

#ifndef FARMLAND_H
#define FARMLAND_H

#include "FarmUnit.h"

#include <vector>
#include <string>

using namespace std;

class Farmland : public FarmUnit {
    
    private:
        vector<FarmUnit*> units; // Stores child FarmUnit objects

    public:
        // Methods to manage child FarmUnit objects
        void add(FarmUnit* unit) override;
        void remove(FarmUnit* unit) override;

        // Methods to access information about the Farmland
        int getTotalCapacity() override;
        string getCropType() override;
        string getSoilStateName() override;

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        ~Farmland();
        Farmland();

        // Nobuhle - Decorator functions
        void increaseProduction() override;
        void harvest() override;
        int getLeftoverCapacity() override;

        void buyTruck(Truck* truck) override;
        void sellTruck(Truck* truck) override;
        void callTruck() override;
};

#endif // FARMLAND_H
