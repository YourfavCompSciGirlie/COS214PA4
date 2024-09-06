// Class defintion for Component 3 - Decorator (Decorator)

#ifndef CROPFIELDDECORATOR_H
#define CROPFIELDDECORATOR_H

#include "CropField.h"

class CropFieldDecorator : public FarmUnit {
    
    protected:
        CropField* field;  

        string name;
        vector<FarmUnit*> units; // Stores child FarmUnit objects

    public:
        CropFieldDecorator();
        CropFieldDecorator(CropField* field);
        virtual ~CropFieldDecorator();
        
        virtual void increaseProduction() = 0; 
        virtual void harvest() = 0;
        virtual int getLeftoverCapacity() = 0;

        virtual int getTotalCapacity() = 0;
        virtual string getCropType() = 0;
        virtual string getSoilStateName() = 0; 
        
        // Observer pattern methods
        virtual void buyTruck(Truck* truck) = 0;
        virtual void sellTruck(Truck* truck) = 0;

        virtual int getCurrentAmount() = 0;
        virtual void setCurrentAmount(int amount) = 0;

        // Composite pattern methods
        virtual void add(FarmUnit* unit) = 0;
        virtual void remove(FarmUnit* unit) = 0;

        // Iterator pattern methods
        virtual vector<FarmUnit*> getSubUnits() = 0;
        virtual FarmIterator* createBFSIterator() = 0;
        virtual FarmIterator* createDFSIterator() = 0;

        // Set and get the name of the farm unit
        virtual void setName(const string& unitName) = 0;
        virtual string getName() const = 0;

};

#endif // CROPFIELDDECORATOR_H
