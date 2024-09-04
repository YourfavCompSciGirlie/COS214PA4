// Class definition for Component 2 - State (ConcreteState)

#ifndef FRUITFULSOIL_H
#define FRUITFULSOIL_H

#include "SoilState.h"

using namespace std;

class FruitfulSoil : public SoilState {

    public:
        FruitfulSoil();
        ~FruitfulSoil();

        int harvestCrops() const;
        void rain();
        string getName() const;
};

#endif // FRUITFULSOIL_H
