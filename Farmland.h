// Class implementation for Component 1 - Composite (Composite)
// Class implementation for Component 5 - Iterator (ConcreteAggregate)

/**
 * @file Farmland.h
 * @brief Class implementation for Component 1 - Composite (Composite) and Class implementation for Component 5 - Iterator (ConcreteAggregate)
 */

#ifndef FARMLAND_H
#define FARMLAND_H

#include "FarmUnit.h"
#include "FarmIterator.h"

#include <vector>
#include <string>

using namespace std;

/**
 * @class Farmland
 * @brief Represents a composite farm unit that can contain other farm units.
 * 
 * The Farmland class implements the Composite pattern to manage a collection of FarmUnit objects.
 * It also implements the Iterator pattern to provide access to its children elements.
 */

class Farmland : public FarmUnit {
    
    private:
        /**
         * @brief The name of the farmland.
         */
        string name;

        /**
         * @brief A vector of child FarmUnit objects contained within this Farmland.
         */
        vector<FarmUnit*> units; // Stores child FarmUnit objects

    public:
        /**
         * @brief Default constructor for Farmland.
         */
        Farmland();

        /**
         * @brief Destructor for Farmland.
         */
        ~Farmland();

        // Methods to access information about the Farmland
        /**
         * @brief Gets the total capacity of the farmland.
         * 
         * @return The total capacity of the farmland.
         */
        int getTotalCapacity();

        /**
         * @brief Gets the crop type of the farmland.
         * 
         * @return The crop type as a string.
         */
        string getCropType();

        /**
         * @brief Gets the name of the soil state of the farmland.
         * 
         * @return The soil state name as a string.
         */
        string getSoilStateName();

        // Methods to manage child FarmUnit objects
        /**
         * @brief Adds a child FarmUnit to the Farmland.
         * 
         * @param unit A pointer to the FarmUnit to be added.
         */
        void add(FarmUnit* unit);

        /**
         * @brief Removes a child FarmUnit from the Farmland.
         * 
         * @param unit A pointer to the FarmUnit to be removed.
         */
        void remove(FarmUnit* unit);

        /**
         * @brief Gets the current amount of resources in the Farmland.
         * 
         * @return The current amount as an integer.
         */
        int getCurrentAmount();

        /**
         * @brief Sets the current amount of resources in the Farmland.
         * 
         * @param amount The amount to set.
         */
        void setCurrentAmount(int amount);

        // Decorator pattern methods
        /**
         * @brief Increases production capacity for the Farmland.
         * 
         * This method is applicable to the Decorator pattern but may not have an effect in Farmland.
         */
        void increaseProduction();
        /**
         * @brief Harvests crops from the Farmland.
         * 
         * This method is applicable to the Decorator pattern but may not have an effect in Farmland.
         */
        void harvest();
        /**
         * @brief Gets the leftover capacity in the Farmland.
         * 
         * @return The leftover capacity as an integer.
         */
        int getLeftoverCapacity();

        // Observer pattern methods
        /**
         * @brief Adds a truck to the notification system.
         * 
         * @param truck A pointer to the Truck object to be added.
         */
        void buyTruck(Truck* truck);
        /**
         * @brief Removes a truck from the notification system.
         * 
         * @param truck A pointer to the Truck object to be removed.
         */
        void sellTruck(Truck* truck);

        // Iterator pattern methods
        /**
         * @brief Gets the child FarmUnit objects contained within this Farmland.
         * 
         * @return A vector of pointers to the child FarmUnit objects.
         */
        vector<FarmUnit*> getSubUnits();
        /**
         * @brief Creates a Breadth-First Search (BFS) iterator for the Farmland.
         * 
         * @return A pointer to the BFS iterator.
         */
        FarmIterator* createBFSIterator();
        /**
         * @brief Creates a Depth-First Search (DFS) iterator for the Farmland.
         * 
         * @return A pointer to the DFS iterator.
         */
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the Farmland.
         * 
         * @param unitName The name to set.
         */
        void setName(const string& unitName);
        /**
         * @brief Gets the name of the Farmland.
         * 
         * @return The name of the Farmland as a string.
         */
        string getName() const;
};

#endif // FARMLAND_H
