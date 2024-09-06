// Class implementation for Component 1 - Composite (Composite)
// Class implementation for Component 5 - Iterator (ConcreteAggregate)

#ifndef FARMLAND_H
#define FARMLAND_H

#include "FarmUnit.h"
#include "FarmIterator.h"

#include <vector>
#include <string>

using namespace std;

class Farmland : public FarmUnit {
    
    private:
        string name;
        vector<FarmUnit*> units; // Stores child FarmUnit objects

    public:
        Farmland();
        ~Farmland();

        // Methods to access information about the Farmland
        int getTotalCapacity();
        string getCropType();
        string getSoilStateName();

        // Methods to manage child FarmUnit objects
        void add(FarmUnit* unit);
        void remove(FarmUnit* unit);

        int getCurrentAmount();
        void setCurrentAmount(int amount);

        // Decorator pattern methods
        void increaseProduction();
        void harvest() override;
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

#endif // FARMLAND_H
