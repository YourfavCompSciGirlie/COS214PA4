// Class defintion for Component 3 - Decorator (Decorator)

/**
 * @file CropFieldDecorator.h
 * @brief Class definition for Component 3 - Decorator (Decorator)
 */

#ifndef CROPFIELDDECORATOR_H
#define CROPFIELDDECORATOR_H

#include "CropField.h"

/**
 * @class CropFieldDecorator
 * @brief Abstract base class for CropField decorators that adds additional functionality to CropField objects.
 * 
 * This class implements the Decorator design pattern. It wraps a CropField object and allows for 
 * additional behavior to be added without modifying the CropField class itself.
 */

class CropFieldDecorator : public FarmUnit {
    
    protected:
        CropField* field;  ///< Wrapped CropField object

        string name;  ///< Name of the decorated farm unit
        vector<FarmUnit*> units; ///< Stores child FarmUnit objects (Composite pattern)

    public:
        /**
         * @brief Default constructor for CropFieldDecorator.
         */
        CropFieldDecorator();

        /**
         * @brief Constructor that accepts a CropField object to wrap.
         * @param field The CropField object to be decorated.
         */
        CropFieldDecorator(CropField* field);

        /**
         * @brief Virtual destructor for CropFieldDecorator.
         */
        virtual ~CropFieldDecorator();
        
        /**
         * @brief Abstract method to increase production capacity of the decorated CropField.
         */
        virtual void increaseProduction() = 0; 

        /**
         * @brief Abstract method to harvest crops from the decorated CropField.
         */
        virtual void harvest() = 0;

        /**
         * @brief Abstract method to get the leftover capacity of the decorated CropField.
         * @return The amount of remaining capacity in the decorated CropField.
         */
        virtual int getLeftoverCapacity() = 0;

        /**
         * @brief Abstract method to get the total capacity of the decorated CropField.
         * @return The total capacity of the decorated CropField.
         */
        virtual int getTotalCapacity() = 0;

        /**
         * @brief Abstract method to get the crop type of the decorated CropField.
         * @return The type of crops being grown in the decorated CropField.
         */
        virtual string getCropType() = 0;

        /**
         * @brief Abstract method to get the name of the soil state of the decorated CropField.
         * @return The name of the soil state.
         */
        virtual string getSoilStateName() = 0; 
        
        // Observer pattern methods
        /**
         * @brief Abstract method to add a truck for the decorated CropField (Observer pattern).
         * @param truck The truck to be added.
         */
        virtual void buyTruck(Truck* truck) = 0;

        /**
         * @brief Abstract method to remove a truck from the decorated CropField (Observer pattern).
         * @param truck The truck to be removed.
         */
        virtual void sellTruck(Truck* truck) = 0;

        /**
         * @brief Abstract method to get the current amount of crops in the decorated CropField.
         * @return The current amount of crops.
         */
        virtual int getCurrentAmount() = 0;

        /**
         * @brief Abstract method to set the current amount of crops in the decorated CropField.
         * @param amount The amount to set.
         */
        virtual void setCurrentAmount(int amount) = 0;

        // Composite pattern methods
        /**
         * @brief Abstract method to add a child FarmUnit (Composite pattern).
         * @param unit The FarmUnit to be added.
         */
        virtual void add(FarmUnit* unit) = 0;

        /**
         * @brief Abstract method to remove a child FarmUnit (Composite pattern).
         * @param unit The FarmUnit to be removed.
         */
        virtual void remove(FarmUnit* unit) = 0;

        // Iterator pattern methods
        /**
         * @brief Abstract method to get the subunits of the decorated CropField.
         * @return A vector of pointers to the subunits.
         */
        virtual vector<FarmUnit*> getSubUnits() = 0;

        /**
         * @brief Abstract method to create a BFS iterator for the decorated CropField.
         * @return A pointer to a BFS iterator.
         */
        virtual FarmIterator* createBFSIterator() = 0;

        /**
         * @brief Abstract method to create a DFS iterator for the decorated CropField.
         * @return A pointer to a DFS iterator.
         */
        virtual FarmIterator* createDFSIterator() = 0;

        // Set and get the name of the farm unit
        /**
         * @brief Abstract method to set the name of the decorated CropField.
         * @param unitName The name to set for the decorated CropField.
         */
        virtual void setName(const string& unitName) = 0;

        /**
         * @brief Abstract method to get the name of the decorated CropField.
         * @return The name of the decorated CropField.
         */
        virtual string getName() const = 0;

};

#endif // CROPFIELDDECORATOR_H
