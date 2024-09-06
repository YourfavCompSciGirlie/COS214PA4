#ifndef DFFAMITERATOR_H
#define DFFAMITERATOR_H

#include "FarmIterator.h"
#include "FarmUnit.h"

#include <stack>
#include <vector>
#include <unordered_set>

using namespace std;

class DFFarmIterator : public FarmIterator {
    
    private:
        stack<FarmUnit*> unitStack;
        FarmUnit* current = nullptr;
        unordered_set<FarmUnit*> visited; // To keep track of visited nodes

    public:
        DFFarmIterator(); 
        ~DFFarmIterator();

        DFFarmIterator(FarmUnit* rootFarm);

        FarmUnit* firstFarm() override;

        FarmUnit* next() override;

        bool isDone() override;

        FarmUnit* currentFarm() override;
};

#endif // DFFAMITERATOR_H