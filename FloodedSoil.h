// Class definition for Component 2 - State (ConcreteState)

#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilState.h"

using namespace std;

class FloodedSoil : public SoilState {
    
    public:
        FloodedSoil();
        ~FloodedSoil();

        int harvestCrops() const;
        void rain();
        string getName() const;
};

#endif // FLOODEDSOIL_H
