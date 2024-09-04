// Class definition for Component 2 - State (ConcreteState)

#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilState.h"

using namespace std;

class FloodedSoil : public SoilState {
    
    public:
        int harvestCrops() const override;
        void rain() override;
        string getName() const override;

        FloodedSoil();
        ~FloodedSoil();
};

#endif // FLOODEDSOIL_H
