// Class definition for Component 2 - State (ConcreteState)

#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilState.h"

using namespace std;

class DrySoil : public SoilState {

    public:
        DrySoil();
        ~DrySoil();

        int harvestCrops() const;
        void rain();
        string getName() const;
};

#endif // DRYSOIL_H
