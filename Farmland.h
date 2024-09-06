// Class implementation for Component 1 - Composite (Composite)

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

        // Methods to manage child FarmUnit objects
        void add(FarmUnit* unit);
        void remove(FarmUnit* unit);

        // Methods to access information about the Farmland
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

#endif // FARMLAND_H
