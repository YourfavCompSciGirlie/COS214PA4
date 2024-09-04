// Class definition for Component 5 - Iterator (ConcreteIterator)

#ifndef DFFARMITERATOR_H
#define DFFARMITERATOR_H

#include "FarmIterator.h"
#include <stack>

class FarmUnit;

class DFFarmIterator : public FarmIterator {
    
    private:
        std::stack<FarmUnit*> farmStack;

    public:
        DFFarmIterator(FarmUnit* rootFarm);

        FarmUnit* firstFarm();
        FarmUnit* next();
        bool isDone();
        FarmUnit* currentFarm();
};

#endif // DFFARMITERATOR_H
