// Class definition for Component 1 - Composite (Leaf)
// Class definition for Component 2 - State (Context)
// Class definition for Component 4 - Observer (ConcreteSubject)

#ifndef CROPFIELD_H
#define CROPFIELD_H

#include "FarmUnit.h"
#include "SoilState.h"
#include "NotificationSystem.h"
#include "Truck.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

#include <string>
#include <vector>

using namespace std;

/**
 * @class CropField
 * @brief Represents a crop field unit in the farm system.
 * 
 * This class acts as a leaf in the composite pattern, handles state transitions
 * using the state design pattern, and notifies observers about truck-related 
 * events via the observer pattern.
 */

class SoilState;

class CropField : public FarmUnit, public NotificationSystem {
    
    private:
        string cropType; ///< The type of crop grown in the field.
        int totalCapacity; ///< Total capacity of the crop field.
        int currentAmount; ///< Current amount of crops stored in the field.

        string name; ///< Name of the crop field.

        SoilState* soilState; ///< Current soil state of the crop field.

    public:
        /**
         * @brief Default constructor for CropField.
         */
        CropField() {};

        /**
         * @brief Parameterized constructor for CropField.
         * 
         * @param cropType Type of crop grown in the field.
         * @param totalCapacity Total capacity of the crop field.
         * @param initialState Initial soil state of the field.
         */
        CropField(const string& cropType, int totalCapacity, SoilState* initialState);

        /**
         * @brief Destructor for CropField.
         */
        virtual ~CropField();

        /**
         * @brief Gets the total capacity of the crop field.
         * 
         * @return The total capacity of the crop field.
         */
        int getTotalCapacity();

        /**
         * @brief Gets the type of crop grown in the field.
         * 
         * @return The type of crop.
         */
        string getCropType();

        /**
         * @brief Gets the name of the current soil state.
         * 
         * @return The name of the current soil state.
         */
        string getSoilStateName();

        /**
         * @brief Sets a new soil state for the crop field.
         * 
         * @param newState Pointer to the new soil state.
         */
        void setSoilState(SoilState* newState);

        /**
         * @brief Harvests the crops from the field.
         * 
         * @return The number of crops harvested.
         */
        int harvestCrops();

        /**
         * @brief Simulates rainfall and triggers soil state transitions.
         */
        void rain();

        // Composite pattern methods

        /**
         * @brief Adds a new farm unit to the crop field.
         * 
         * @param unit Pointer to the farm unit to be added.
         */
        void add(FarmUnit* unit);

        /**
         * @brief Removes a farm unit from the crop field.
         * 
         * @param unit Pointer to the farm unit to be removed.
         */
        void remove(FarmUnit* unit);

        /**
         * @brief Gets the current amount of crops in the field.
         * 
         * @return The current crop amount.
         */
        int getCurrentAmount();

        /**
         * @brief Sets the current amount of crops in the field.
         * 
         * @param amount The new current amount of crops.
         */
        void setCurrentAmount(int amount);

        // Provide accessors for soilState
        /**
         * @brief Provides access to the current soil state.
         * 
         * @return Pointer to the current soil state.
         */
        SoilState* getSoilState() const;

        // Observer pattern methods
        /**
         * @brief Purchases a truck for the crop field.
         * 
         * @param truck Pointer to the truck to be purchased.
         */
        void buyTruck(Truck* truck);

        /**
         * @brief Sells a truck from the crop field.
         * 
         * @param truck Pointer to the truck to be sold.
         */
        void sellTruck(Truck* truck);

        // Decorator pattern methods
        /**
         * @brief Increases the production of crops.
         */
        void increaseProduction();

        /**
         * @brief Harvests crops (decorator pattern method).
         */
        void harvest();

        /**
         * @brief Gets the leftover capacity of the crop field.
         * 
         * @return The leftover capacity.
         */
        int getLeftoverCapacity();  

        // Iterator pattern methods
        /**
         * @brief Gets the list of sub-units of the crop field.
         * 
         * @return A vector containing pointers to sub-units.
         */
        vector<FarmUnit*> getSubUnits();

        /**
         * @brief Creates a Breadth-First Search iterator for the crop field.
         * 
         * @return Pointer to the BFS iterator.
         */
        FarmIterator* createBFSIterator();
        /**
         * @brief Creates a Depth-First Search iterator for the crop field.
         * 
         * @return Pointer to the DFS iterator.
         */
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the crop field.
         * 
         * @param unitName The name to be set for the crop field.
         */
        void setName(const string& unitName);
        /**
         * @brief Gets the name of the crop field.
         * 
         * @return The name of the crop field.
         */
        string getName() const;
};

#endif // CROPFIELD_H
