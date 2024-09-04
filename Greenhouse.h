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
};

#endif // GREENHOUSE_H
