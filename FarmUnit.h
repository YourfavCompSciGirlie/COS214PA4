// Class definition for Component 1 - Composite (Component)
// Class definition for Component 5 - Iterator (Aggregate)

/**
 * @file FarmUnit.h
 * @brief Class definition for Component 1 - Composite (Component) and Component 5 - Iterator (Aggregate)
 */

#ifndef FARMUNIT_H
#define FARMUNIT_H

#include <vector>
#include <string>

#include "Truck.h"
#include "FarmIterator.h"

using namespace std;

class FarmIterator;

/**
 * @class FarmUnit
 * @brief Abstract class representing a unit in the farm.
 * 
 * The FarmUnit class is the base component for the Composite pattern, representing individual or 
 * composite farm units. It also serves as the aggregate for the Iterator pattern, enabling 
 * traversal through farm sub-units.
 */

class FarmUnit {
    
    private:
    string name; ///< Name of the farm unit.
    vector<FarmUnit*> units; ///< Collection of sub-units.

    public:
        /**
         * @brief Constructor for FarmUnit.
         */
        FarmUnit();

        /**
         * @brief Virtual destructor for FarmUnit.
         */
        virtual ~FarmUnit();

        /**
         * @brief Returns the total capacity of the farm unit.
         * @return The total capacity as an integer.
         */
        virtual int getTotalCapacity() = 0;

        /**
         * @brief Returns the crop type of the farm unit.
         * @return The crop type as a string.
         */
        virtual string getCropType() = 0;

        /**
         * @brief Returns the name of the soil state of the farm unit.
         * @return The soil state name as a string.
         */
        virtual string getSoilStateName() = 0;

        // Composite pattern methods
        /**
         * @brief Adds a sub-unit to the farm unit (Composite pattern).
         * @param unit A pointer to the FarmUnit to be added.
         */
        virtual void add(FarmUnit* unit) = 0;

        /**
         * @brief Removes a sub-unit from the farm unit (Composite pattern).
         * @param unit A pointer to the FarmUnit to be removed.
         */
        virtual void remove(FarmUnit* unit) = 0;

        /**
         * @brief Returns the current amount of crops or produce.
         * @return The current amount as an integer.
         */
        virtual int getCurrentAmount() = 0;

        /**
         * @brief Sets the current amount of crops or produce.
         * @param amount The amount to set.
         */
        virtual void setCurrentAmount(int amount) = 0;

        // Decorator pattern methods
        /**
         * @brief Increases production capacity (Decorator pattern).
         */
        virtual void increaseProduction() = 0;

        /**
         * @brief Harvests the crops or produce (Decorator pattern).
         */
        virtual void harvest() = 0;

        /**
         * @brief Returns the leftover capacity after harvest (Decorator pattern).
         * @return The leftover capacity as an integer.
         */
        virtual int getLeftoverCapacity() = 0;

        // Observer pattern methods
        /**
         * @brief Buys a truck for the farm unit (Observer pattern).
         * @param truck A pointer to the Truck object.
         */
        virtual void buyTruck(Truck* truck) = 0;

        /**
         * @brief Sells a truck from the farm unit (Observer pattern).
         * @param truck A pointer to the Truck object.
         */
        virtual void sellTruck(Truck* truck) = 0;

        // Create iterators for traversal
        // Iterator pattern methods
        /**
         * @brief Creates a BFS iterator for traversing the farm units (Iterator pattern).
         * @return A pointer to the BFS FarmIterator.
         */
        virtual FarmIterator* createBFSIterator() = 0;

        /**
         * @brief Creates a DFS iterator for traversing the farm units (Iterator pattern).
         * @return A pointer to the DFS FarmIterator.
         */
        virtual FarmIterator* createDFSIterator() = 0;

        // Return a list of sub-units (for composite)
        /**
         * @brief Returns a list of sub-units (for the Composite pattern).
         * @return A vector of pointers to sub-units.
         */
        virtual vector<FarmUnit*> getSubUnits() = 0;

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the farm unit.
         * @param unitName The name to set.
         */
        virtual void setName(const string& unitName) = 0;

        /**
         * @brief Returns the name of the farm unit.
         * @return The name as a string.
         */
        virtual string getName() const = 0;

};

#endif // FARMUNIT_H