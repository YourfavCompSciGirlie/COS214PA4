// Class defintion for Component 3 - Decorator (ConcreteDecorator)

#ifndef FERTILIZEDFIELD_H
#define FERTILIZEDFIELD_H

#include "CropField.h"
#include "CropFieldDecorator.h"
#include "FertilizedField.h"
#include "CropField.h"
#include "FruitfulSoil.h"
#include "FloodedSoil.h"

#include <algorithm>

/**
 * @class FertilizedField
 * @brief A concrete decorator for CropField that adds fertilization functionality.
 * 
 * The FertilizedField class enhances a CropField by increasing its production capacity and
 * providing additional methods for managing trucks, soil states, and harvesting.
 */

using namespace std;

class FertilizedField : public CropFieldDecorator {
    
    private:
        /**
         * @brief A pointer to the wrapped CropField object.
         */
        CropField* field;  // Wrapped CropField object

        /**
         * @brief The name of the fertilized field.
         */
        string name;

    public:
        /**
         * @brief Constructor for FertilizedField.
         * 
         * @param field A pointer to the CropField being decorated.
         */
        FertilizedField(CropField* field);

        /**
         * @brief Destructor for FertilizedField.
         */
        ~FertilizedField();

        /**
         * @brief Increases the production capacity of the fertilized field.
         */
        void increaseProduction();

        /**
         * @brief Harvests crops from the fertilized field.
         */
        void harvest();

        /**
         * @brief Gets the leftover capacity of the fertilized field.
         * 
         * @return The leftover capacity as an integer.
         */
        int getLeftoverCapacity();

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

        /**
         * @brief Gets the total capacity of the fertilized field.
         * 
         * @return The total capacity as an integer.
         */
        int getTotalCapacity();

        /**
         * @brief Gets the crop type of the fertilized field.
         * 
         * @return The crop type as a string.
         */
        string getCropType();

        /**
         * @brief Gets the soil state name of the fertilized field.
         * 
         * @return The soil state name as a string.
         */
        string getSoilStateName();

        /**
         * @brief Gets the current amount of resources in the fertilized field.
         * 
         * @return The current amount as an integer.
         */
        int getCurrentAmount();

        /**
         * @brief Sets the current amount of resources in the fertilized field.
         * 
         * @param amount The amount to set.
         */
        void setCurrentAmount(int amount);

        // Iterator pattern methods
        /**
         * @brief Gets the child FarmUnit objects contained within the fertilized field.
         * 
         * @return A vector of pointers to the child FarmUnit objects.
         */
        vector<FarmUnit*> getSubUnits();

        /**
         * @brief Creates a Breadth-First Search (BFS) iterator for the fertilized field.
         * 
         * @return A pointer to the BFS iterator.
         */
        FarmIterator* createBFSIterator();

        /**
         * @brief Creates a Depth-First Search (DFS) iterator for the fertilized field.
         * 
         * @return A pointer to the DFS iterator.
         */
        FarmIterator* createDFSIterator();

        // Set and get the name of the farm unit
        /**
         * @brief Sets the name of the fertilized field.
         * 
         * @param unitName The name to set.
         */
        void setName(const string& unitName);

        /**
         * @brief Gets the name of the FertilizedField.
         * 
         * @return The name of the FertilizedField.
         */
        string getName() const;

        // Composite pattern methods
        /**
         * @brief Adds a child FarmUnit to the FertilizedField.
         * 
         * This method is part of the Composite pattern but may not have an effect in FertilizedField.
         * 
         * @param unit A pointer to the FarmUnit to be added.
         */
        void add(FarmUnit* unit);

        /**
         * @brief Removes a child FarmUnit from the FertilizedField.
         * 
         * This method is part of the Composite pattern but may not have an effect in FertilizedField.
         * 
         * @param unit A pointer to the FarmUnit to be removed.
         */
        void remove(FarmUnit* unit);

};

#endif // FERTILIZEDFIELD_H
