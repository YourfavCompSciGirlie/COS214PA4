#ifndef BFFARMITERATOR_H
#define BFFARMITERATOR_H


#include "FarmIterator.h"
#include <queue>

class BFFarmIterator : public FarmIterator {
private:
    std::queue<FarmUnit*> queue;
    FarmUnit* current = nullptr;

public:
    BFFarmIterator(FarmUnit* rootFarm) {
        if (rootFarm != nullptr) {
            queue.push(rootFarm);
        }
    }

    FarmUnit* firstFarm() override {
        if (!queue.empty()) {
            return queue.front();
        }
        return nullptr;
    }

    FarmUnit* next() override {
        if (!isDone()) {
            current = queue.front();
            queue.pop();
            for (FarmUnit* subUnit : current->getSubUnits()) {
                queue.push(subUnit);
            }
        }
        return current;
    }

    bool isDone() override {
        return queue.empty();
    }

    FarmUnit* currentFarm() override {
        return current;
    }
};
#endif