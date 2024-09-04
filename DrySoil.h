// Class definition for Component 2 - State (ConcreteState)

#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilState.h"

using namespace std;

class DrySoil : public SoilState {

    public:
        int harvestCrops() const override;
        void rain() override;
        string getName() const override;

        DrySoil();
        ~DrySoil();
};

#endif // DRYSOIL_H
