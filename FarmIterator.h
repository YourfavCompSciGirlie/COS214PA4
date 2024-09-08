// Class definition for Component 5 - Iterator (Iterator)

/**
 * @file FarmIterator.h
 * @brief Class definition for Component 5 - Iterator (Iterator)
 */

#ifndef FARMITERATOR_H
#define FARMITERATOR_H

class FarmUnit;

/**
 * @class FarmIterator
 * @brief Abstract class representing the Iterator for traversing FarmUnits.
 * 
 * The FarmIterator class provides the interface for implementing iterators to traverse
 * farm units using various traversal strategies, such as BFS or DFS.
 */

class FarmIterator {

    public:
        /**
         * @brief Constructor for FarmIterator.
         */
        FarmIterator();
        
        /**
         * @brief Virtual destructor for FarmIterator.
         */
        virtual ~FarmIterator();

        /**
         * @brief Returns the first FarmUnit in the traversal.
         * @return A pointer to the first FarmUnit.
         */
        virtual FarmUnit* firstFarm() = 0;

        /**
         * @brief Moves the iterator to the next FarmUnit in the traversal.
         * @return A pointer to the next FarmUnit.
         */
        virtual FarmUnit* next() = 0;

        /**
         * @brief Checks if the iterator has finished traversing all FarmUnits.
         * @return True if traversal is complete, otherwise false.
         */
        virtual bool isDone() = 0;

        /**
         * @brief Returns the current FarmUnit being traversed.
         * @return A pointer to the current FarmUnit.
         */
        virtual FarmUnit* currentFarm() = 0;
};

#endif 
