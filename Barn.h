// Class definition for Component 1 - Composite (Leaf)

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

#include <algorithm>

using namespace std;

class Barn : public FarmUnit {
    
    private:
        int totalCapacity;
        int currentAmount;

        string name;

    public:
        Barn(int totalCapacity);
        ~Barn();

        int getTotalCapacity();
        string getCropType();
        string getSoilStateName();

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Composite pattern methods (not applicable for Barn)
        void add(FarmUnit* unit);
        void remove(FarmUnit* unit);

        // Decorator pattern methods
        void increaseProduction();
        void harvest();
        int getLeftoverCapacity();

        // Observer pattern methods
        void buyTruck(Truck* truck);
        void sellTruck(Truck* truck);

        // Iterator pattern methods
        vector<FarmUnit*> getSubUnits();
        FarmIterator* createBFSIterator();
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        void setName(const string& unitName);
        string getName() const;
};

#endif // BARN_H
