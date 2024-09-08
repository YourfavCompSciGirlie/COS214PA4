//Class defintion for Component 5  - Iterator(ConcreteIterator)

/**
 * @file BFFarmIterator.h
 * @brief Class definition for Component 5  - Iterator(ConcreteIterator)
 */

#ifndef BFFARMITERATOR_H
#define BFFARMITERATOR_H


#include "FarmIterator.h"
#include "FarmUnit.h"

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

/**
 * @class BFFarmIterator
 * @brief Concrete iterator implementing Breadth-First Traversal for farm units.
 * 
 * This class provides the functionality to traverse a farm's structure using
 * the Breadth-First Search (BFS) algorithm. It maintains a queue to track the 
 * next farm units to visit and a set to track visited units.
 */

class BFFarmIterator : public FarmIterator {
    private:
        queue<FarmUnit*> unitQueue; ///< Queue to store the units to be visited.
        FarmUnit* current = nullptr; ///< Pointer to the current farm unit.
        unordered_set<FarmUnit*> visited; ///< Set to track visited farm units.

    public:
        /**
         * @brief Default constructor for BFFarmIterator.
         */
        BFFarmIterator();

        /**
         * @brief Destructor for BFFarmIterator.
         */
        ~BFFarmIterator();

        /**
         * @brief Constructor that initializes the iterator with the root farm unit.
         * 
         * @param rootFarm Pointer to the root farm unit for the BFS traversal.
         */
        BFFarmIterator(FarmUnit* rootFarm);

        /**
         * @brief Starts the BFS traversal and returns the first farm unit.
         * 
         * @return Pointer to the first farm unit in the traversal.
         */
        FarmUnit* firstFarm();

        /**
         * @brief Moves to the next farm unit in the BFS traversal.
         * 
         * @return Pointer to the next farm unit in the traversal.
         */
        FarmUnit* next();

        /**
         * @brief Checks if the traversal is complete.
         * 
         * @return true if there are no more farm units to visit, false otherwise.
         */
        bool isDone();

        /**
         * @brief Returns the current farm unit in the traversal.
         * 
         * @return Pointer to the current farm unit.
         */
        FarmUnit* currentFarm();
};

#endif // BFFARMITERATOR_H