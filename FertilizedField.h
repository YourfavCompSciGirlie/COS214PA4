// FertilizedField.h
#ifndef FERTILIZED_FIELD_H
#define FERTILIZED_FIELD_H

#include "CropField.h"
#include "CropFieldDecorator.h"
#include "FertilizedField.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"

#include "algorithm"

class FertilizedField : public CropFieldDecorator
{
private:
    CropField* field;

    string name;
    vector<FarmUnit*> units; // Stores child FarmUnit objects


public:
    ~FertilizedField();
    FertilizedField(CropField* field);
    void increaseProduction()override;
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

    // Composite pattern methods
    void add(FarmUnit* unit);
    void remove(FarmUnit* unit);

};
#endif 
