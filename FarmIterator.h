// Class definition for Component 5 - Iterator (Iterator)

#ifndef FARMITERATOR_H
#define FARMITERATOR_H

class FarmUnit;

class FarmIterator {

    public:
        virtual ~FarmIterator() {};

        // Return the first farm/unit for traversal
        virtual FarmUnit* firstFarm() = 0;

        // Move to the next farm/unit in the traversal
        virtual FarmUnit* next() = 0;

        // Check if traversal is complete
        virtual bool isDone() = 0;

        // Return the current farm/unit being visited
        virtual FarmUnit* currentFarm() = 0;
};

#endif 
