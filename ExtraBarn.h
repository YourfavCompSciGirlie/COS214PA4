// Class defintion for Component 3 - Decorator (ConcreteDecorator)

/**
 * @file ExtraBarn.h
 * @brief Class definition for Component 3 - Decorator (ConcreteDecorator)
 */

#ifndef EXTRABARN_H
#define EXTRABARN_H

#include "CropField.h"
#include "CropFieldDecorator.h"

#include <algorithm>

using namespace std;

/**
 * @class ExtraBarn
 * @brief A decorator class that adds extra storage capacity to a CropField.
 * 
 * The ExtraBarn class extends the functionality of a CropField by adding additional
 * storage capacity, allowing for increased production and resource storage.
 */

class ExtraBarn : public CropFieldDecorator {
    
    private:
        CropField* field; ///< The wrapped CropField object
        int extraStorageCapacity; ///< Additional storage capacity provided by the ExtraBarn

        string name;  ///< Name of the ExtraBarn

    public:
        /**
         * @brief Constructor for ExtraBarn.
         * @param field The CropField to be decorated with extra storage.
         * @param extraCapacity The additional storage capacity provided by the ExtraBarn.
         */
        ExtraBarn(CropField* field, int extraCapacity);

        /**
         * @brief Destructor for ExtraBarn.
         */
        ~ExtraBarn();

        /**
         * @brief Increases the production capacity of the decorated CropField.
         */
        void increaseProduction();

        /**
         * @brief Harvests crops from the decorated CropField.
         */
        void harvest();

        /**
         * @brief Gets the leftover capacity after harvest.
         * @return The remaining storage capacity.
         */
        int getLeftoverCapacity();

        /**
         * @brief Buys a truck and associates it with the CropField.
         * @param truck The truck to be added.
         */
        void buyTruck(Truck* truck);

        /**
         * @brief Sells a truck associated with the CropField.
         * @param truck The truck to be sold.
         */
        void sellTruck(Truck* truck);

        /**
         * @brief Gets the total capacity of the decorated CropField.
         * @return The total capacity including the extra storage capacity.
         */
        int getTotalCapacity();

        /**
         * @brief Gets the crop type grown in the decorated CropField.
         * @return The type of crop.
         */
        string getCropType();

        /**
         * @brief Gets the current soil state of the decorated CropField.
         * @return The name of the current soil state.
         */
        string getSoilStateName();

        /**
         * @brief Gets the current amount of crops stored in the decorated CropField.
         * @return The current amount of crops.
         */
        int getCurrentAmount();

        /**
         * @brief Sets the current amount of crops stored in the decorated CropField.
         * @param amount The new current amount.
         */
        void setCurrentAmount(int amount);

        // Iterator pattern methods
        /**
         * @brief Retrieves the sub-units of the CropField for iteration.
         * @return A vector of FarmUnit pointers representing sub-units.
         */
        vector<FarmUnit*> getSubUnits();

        /**
         * @brief Creates a breadth-first search (BFS) iterator for traversing the CropField.
         * @return A pointer to a FarmIterator for BFS traversal.
         */
        FarmIterator* createBFSIterator();

        /**
         * @brief Creates a depth-first search (DFS) iterator for traversing the CropField.
         * @return A pointer to a FarmIterator for DFS traversal.
         */
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the ExtraBarn.
         * @param unitName The name to assign to the ExtraBarn.
         */
        void setName(const string& unitName);

        /**
         * @brief Gets the name of the ExtraBarn.
         * @return The name of the ExtraBarn.
         */
        string getName() const;

        // Composite pattern methods
        /**
         * @brief Adds a sub-unit to the CropField (part of the Composite pattern).
         * @param unit The FarmUnit to be added.
         */
        void add(FarmUnit* unit);

        /**
         * @brief Removes a sub-unit from the CropField (part of the Composite pattern).
         * @param unit The FarmUnit to be removed.
         */
        void remove(FarmUnit* unit);
};

#endif // EXTRABARN_H
