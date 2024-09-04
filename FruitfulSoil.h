// Class definition for Component 2 - State (ConcreteState)

#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H

#include "SoilState.h"

using namespace std;

class FruitfulSoil : public SoilState {

    public:
        int harvestCrops() const override;
        void rain() override;
        string getName() const override;

        FruitfulSoil();
        ~FruitfulSoil();
};

#endif // FRUITFULSOIL_H
