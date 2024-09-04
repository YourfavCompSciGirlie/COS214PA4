// Class definition for Component 1 - Composite (Leaf)

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"

using namespace std;

class Barn : public FarmUnit {
    
    private:
        string cropType;
        int totalCapacity;
        int currentAmount;

    public:
        Barn(int totalCapacity);
        ~Barn();

        int getTotalCapacity() override;
        string getCropType() override;
        string getSoilStateName() override;

        int getCurrentAmount();
        void setCurrentAmount(int amount);
};

#endif // BARN_H
