// Class definition for Component 5 - Iterator (ConcreteIterator)

/**
 * @file DFFarmIterator.h
 * @brief Class definition for Component 5 - Iterator (ConcreteIterator)
 */

#ifndef DFFAMITERATOR_H
#define DFFAMITERATOR_H

#include "FarmIterator.h"
#include "FarmUnit.h"

#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

/**
 * @class DFFarmIterator
 * @brief Implements the depth-first traversal iterator for farm units.
 * 
 * This class allows traversal of farm units using the depth-first search (DFS) strategy.
 * It maintains a stack to keep track of the current path during the traversal and an unordered set
 * to track visited farm units, ensuring that each unit is processed only once.
 */

class DFFarmIterator : public FarmIterator {
    
    private:
        stack<FarmUnit*> unitStack; ///< Stack to store farm units during DFS traversal
        FarmUnit* current = nullptr; ///< Pointer to the current farm unit being traversed
        unordered_set<FarmUnit*> visited; ///< Set to keep track of visited farm units

    public:
        /**
         * @brief Default constructor for DFFarmIterator.
         */
        DFFarmIterator(); 

        /**
         * @brief Destructor for DFFarmIterator.
         */
        ~DFFarmIterator();

        /**
         * @brief Constructor that initializes the DFS iterator with a root farm unit.
         * @param rootFarm The root farm unit for starting the DFS traversal.
         */
        DFFarmIterator(FarmUnit* rootFarm);

        /**
         * @brief Returns the first farm unit in the DFS traversal.
         * @return Pointer to the first farm unit in the traversal.
         */
        FarmUnit* firstFarm();

        /**
         * @brief Moves to the next farm unit in the DFS traversal.
         * @return Pointer to the next farm unit in the traversal.
         */
        FarmUnit* next();

        /**
         * @brief Checks if the DFS traversal is complete.
         * @return True if all farm units have been visited, false otherwise.
         */
        bool isDone();

        /**
         * @brief Returns the current farm unit in the DFS traversal.
         * @return Pointer to the current farm unit being traversed.
         */
        FarmUnit* currentFarm();
};

#endif // DFFAMITERATOR_H