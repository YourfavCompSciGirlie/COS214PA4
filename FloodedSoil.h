// Class definition for Component 2 - State (ConcreteState)

/**
 * @file FloodedSoil.h
 * @brief Class definition for Component 2 - State (ConcreteState)
 */

#ifndef FLOODEDSOIL_H
#define FLOODEDSOIL_H

#include "SoilState.h"

using namespace std;

/**
 * @class FloodedSoil
 * @brief Concrete state class representing a flooded soil state.
 * 
 * This class inherits from SoilState and represents a state where the soil is flooded. It provides
 * implementations for harvesting crops and handling rain events specific to this state.
 */

class FloodedSoil : public SoilState {
    
    public:
        /**
         * @brief Default constructor for FloodedSoil.
         */
        FloodedSoil();

        /**
         * @brief Destructor for FloodedSoil.
         */
        ~FloodedSoil();

        /**
         * @brief Harvests crops from the soil.
         * @return An integer representing the amount of crops harvested.
         */
        int harvestCrops() const;

        /**
         * @brief Handles the rain event, which may affect the soil state.
         * This method may transition the soil to a different state depending on the system's rules.
         */
        void rain();

        /**
         * @brief Gets the name of the soil state.
         * @return A string representing the name of the soil state.
         */
        string getName() const;
};

#endif // FLOODEDSOIL_H
