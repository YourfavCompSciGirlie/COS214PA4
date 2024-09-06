// Class definition for Component 1 - Composite (Leaf)

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

using namespace std;

class Barn : public FarmUnit {
    
    private:
        int totalCapacity;
        int currentAmount;

        string name;
        vector<FarmUnit*> units; // Stores child FarmUnit objects

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

        // Iterator pattern methods
        vector<FarmUnit*> getSubUnits() override;
        FarmIterator* createBFSIterator() override;
        FarmIterator* createDFSIterator() override;

        // Set and get the name of the farm unit
        void setName(const string& unitName) override;
        string getName() const override;
};

#endif // BARN_H
