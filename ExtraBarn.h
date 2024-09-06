#ifndef EXTRA_BARN_H
#define EXTRA_BARN_H

#include "CropField.h"
#include "CropFieldDecorator.h"

class ExtraBarn : public CropFieldDecorator
{
private:
    CropField* field;
    int extraStorageCapacity;

    string name;
    vector<FarmUnit*> units; // Stores child FarmUnit objects


public:
    ExtraBarn(CropField* field, int extraCapacity);
    void increaseProduction() override;
    void harvest()override;
    int getLeftoverCapacity()override;

    void buyTruck(Truck* truck)override;
    void sellTruck(Truck* truck)override;

    int getTotalCapacity()override;
    string getCropType()override;
    string getSoilStateName()override;

    int getCurrentAmount()override;
    void setCurrentAmount(int amount)override;

    // Iterator pattern methods
    vector<FarmUnit*> getSubUnits() override;
    FarmIterator* createBFSIterator() override;
    FarmIterator* createDFSIterator() override;

    // Set and get the name of the farm unit
    void setName(const string& unitName) override;
    string getName() const override;

};

#endif 
