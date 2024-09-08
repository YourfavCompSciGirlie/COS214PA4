// Class definition for Component 2 - State (ConcreteState)

/**
 * @file DrySoil.h
 * @brief Class definition for Component 2 - State (ConcreteState)
 */

#ifndef DRYSOIL_H
#define DRYSOIL_H

#include "SoilState.h"

using namespace std;

/**
 * @class DrySoil
 * @brief Represents the dry soil state in the State design pattern.
 * 
 * This class is a concrete state that defines the behavior of a crop field when the soil is dry.
 */

class DrySoil : public SoilState {

    public:
        /**
         * @brief Constructs a DrySoil object.
         */
        DrySoil();
        /**
         * @brief Destructor for DrySoil.
         */
        ~DrySoil();

        /**
         * @brief Harvest crops from the field when the soil is dry.
         * 
         * @return The number of crops harvested from dry soil (usually low or zero).
         */
        int harvestCrops() const;
        /**
         * @brief Simulates rain and transitions the soil state from DrySoil to FruitfulSoil.
         */
        void rain();
        /**
         * @brief Get the name of the soil state.
         * 
         * @return A string representing the current soil state ("Dry").
         */
        string getName() const;
};

#endif // DRYSOIL_H
