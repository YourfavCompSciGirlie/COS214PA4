// Class definition for Component 1 - Composite (Leaf)

/**
 * @file Barn.h
 * @brief Class definition for Component 1 - Composite (Leaf)
 */

#ifndef BARN_H
#define BARN_H

#include "FarmUnit.h"
#include "BFFarmIterator.h"
#include "DFFarmIterator.h"

#include <algorithm>

using namespace std;

/**
 * @class Barn
 * @brief Represents a storage facility for farm produce.
 * 
 * The Barn class manages the storage of farm produce. It does not handle crops directly or 
 * participate in the production process. Implements Iterator and Observer patterns for logistics.
 */

class Barn : public FarmUnit {
    
    private:
        int totalCapacity; ///< Total storage capacity of the barn.
        int currentAmount; ///< Current amount of produce stored in the barn.

        string name; ///< Name of the barn.

    public:
        /**
         * @brief Constructs a new Barn object with a given capacity.
         * 
         * @param totalCapacity The total storage capacity of the barn.
         */
        Barn(int totalCapacity);
        /**
         * @brief Destructor for the Barn object.
         */
        ~Barn();

        /**
         * @brief Gets the total storage capacity of the barn.
         * 
         * @return int The total capacity of the barn.
         */
        int getTotalCapacity();
        /**
         * @brief Returns the crop type for this farm unit. Always returns "N/A" for a barn.
         * 
         * @return std::string "N/A" since barns do not store crops directly.
         */
        string getCropType();
        /**
         * @brief Returns the soil state for this farm unit. Always returns "N/A" for a barn.
         * 
         * @return std::string "N/A" since barns do not manage soil.
         */
        string getSoilStateName();

        /**
         * @brief Gets the current amount of produce stored in the barn.
         * 
         * @return int The current amount stored in the barn.
         */
        int getCurrentAmount();
        /**
         * @brief Sets the current amount of produce in the barn.
         * 
         * @param amount The new amount of produce to set, must be within the barn's capacity.
         */
        void setCurrentAmount(int amount);

        // Composite pattern methods (not applicable for Barn)
        /**
         * @brief Adds a farm unit to the barn. Not applicable to barns.
         * 
         * @param unit Pointer to the FarmUnit being added.
         */
        void add(FarmUnit* unit);
        /**
         * @brief Removes a farm unit from the barn. Not applicable to barns.
         * 
         * @param unit Pointer to the FarmUnit being removed.
         */
        void remove(FarmUnit* unit);

        // Decorator pattern methods
        /**
         * @brief Increases production, not applicable for a barn.
         */
        void increaseProduction();
        /**
         * @brief Harvest crops, not applicable for a barn.
         */
        void harvest();
        /**
         * @brief Gets the remaining storage capacity in the barn.
         * 
         * @return int The remaining capacity available.
         */
        int getLeftoverCapacity();

        // Observer pattern methods
        /**
         * @brief Buys a truck for logistics purposes. Generally not applicable for barns.
         * 
         * @param truck Pointer to the Truck object being purchased.
         */
        void buyTruck(Truck* truck);
        /**
         * @brief Sells a truck. Generally not applicable for barns.
         * 
         * @param truck Pointer to the Truck object being sold.
         */
        void sellTruck(Truck* truck);

        // Iterator pattern methods
        /**
         * @brief Returns the sub-units of the farm. Not applicable for barns.
         * 
         * @return std::vector<FarmUnit*> An empty vector as barns do not have sub-units.
         */
        vector<FarmUnit*> getSubUnits();
        /**
         * @brief Creates a breadth-first search iterator for the farm.
         * 
         * @return FarmIterator* Pointer to the BFS iterator.
         */
        FarmIterator* createBFSIterator();
        /**
         * @brief Creates a depth-first search iterator for the farm.
         * 
         * @return FarmIterator* Pointer to the DFS iterator.
         */
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the barn.
         * 
         * @param unitName The name to set for the barn.
         */
        void setName(const string& unitName);
        /**
         * @brief Gets the name of the barn.
         * 
         * @return std::string The name of the barn.
         */
        string getName() const;
};

#endif // BARN_H
