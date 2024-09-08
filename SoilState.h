// Class definition for Component 2 - State (State)

/**
 * @file SoilState.h
 * @brief Class definition for Component 2 - State (State)
 */

#ifndef SOILSTATE_H
#define SOILSTATE_H

#include <string>

using namespace std;

class CropField;

/**
 * @class SoilState
 * @brief Abstract base class for representing different states of soil.
 * 
 * This class serves as the base class for all concrete soil state classes. It defines the interface
 * for interacting with different soil states and provides a mechanism for transitioning between states.
 */

class SoilState {

    protected:
        CropField* context; ///< Pointer to the context (CropField) to manage state transitions
    
    public:
        /**
         * @brief Default constructor for SoilState.
         */
        SoilState();

        /**
         * @brief Virtual destructor for SoilState.
         */
        virtual ~SoilState();

        /**
         * @brief Harvests crops from the soil.
         * @return An integer representing the amount of crops harvested.
         */
        virtual int harvestCrops() const = 0; // Returns the amount of crops harvested

        /**
         * @brief Handles the rain event, which may affect the soil state.
         * This method may trigger a transition to a different soil state.
         */
        virtual void rain() = 0; // Simulates the effect of rain on the soil

        /**
         * @brief Gets the name of the soil state.
         * @return A string representing the name of the soil state.
         */
        virtual string getName() const = 0; // Returns the name of the soil state

        /**
         * @brief Sets the context for the soil state.
         * @param context Pointer to the CropField object that manages state transitions.
         */
        void setContext(class CropField* context);
};

#endif // SOILSTATE_H
