//Class implementation for Component 5  - Iterator(ConcreteIterator)

#ifndef BFFARMITERATOR_H
#define BFFARMITERATOR_H


#include "FarmIterator.h"
#include "FarmUnit.h"

#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class BFFarmIterator : public FarmIterator {
    private:
        queue<FarmUnit*> unitQueue;
        FarmUnit* current = nullptr;
        unordered_set<FarmUnit*> visited; // Set to track visited nodes

    public:
        BFFarmIterator();
        ~BFFarmIterator();
        BFFarmIterator(FarmUnit* rootFarm);
        FarmUnit* firstFarm();
        FarmUnit* next();
        bool isDone();
        FarmUnit* currentFarm();
};

#endif // BFFARMITERATOR_H