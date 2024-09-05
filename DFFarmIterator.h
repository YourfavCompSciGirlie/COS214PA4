#ifndef DFFAMITERATOR_H
#define DFFAMITERATOR_H

#include "FarmIterator.h"
#include <stack>
#include <vector>

class DFFarmIterator : public FarmIterator {
private:
    std::stack<FarmUnit*> stack;
    FarmUnit* current = nullptr;

public:
    DFFarmIterator(FarmUnit* rootFarm) {
        if (rootFarm != nullptr) {
            stack.push(rootFarm);
        }
    }

    FarmUnit* firstFarm() override {
        if (!stack.empty()) {
            return stack.top();
        }
        return nullptr;
    }

    FarmUnit* next() override {
        // if (!isDone()) {
        //     current = stack.top();
        //     stack.pop();
        //     const std::vector<FarmUnit*>& subUnits = current->getSubUnits();
        //     for (auto it = subUnits.rbegin(); it != subUnits.rend(); ++it) {
        //         stack.push(*it);
        //     }
        // }
        // return current;
    }

    bool isDone() override {
        return stack.empty();
    }

    FarmUnit* currentFarm() override {
        return current;
    }
};
#endif