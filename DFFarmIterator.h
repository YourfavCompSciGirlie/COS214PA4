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
        DFFarmIterator() {};
        ~DFFarmIterator() {};

        DFFarmIterator(FarmUnit* rootFarm) : current(nullptr) {
            if (rootFarm != nullptr) {
                unitStack.push(rootFarm);
                visited.insert(rootFarm);
            }
        }

        FarmUnit* firstFarm() override {
            if (!unitStack.empty()) {
                current = unitStack.top();
                return current;
            }
            return nullptr;
        }

        FarmUnit* next() override {
            if (!isDone()) {
                current = unitStack.top();
                unitStack.pop();

                const vector<FarmUnit*>& subUnits = current->getSubUnits();
                // Push children in reverse order to process the leftmost child first
                for (auto it = subUnits.rbegin(); it != subUnits.rend(); ++it) {
                    if (visited.find(*it) == visited.end()) { // Check if the unit has been visited
                        unitStack.push(*it);
                        visited.insert(*it);
                    }
                }
                return current;
            }
            return nullptr;
        }

        bool isDone() override {
            return unitStack.empty();
        }

        FarmUnit* currentFarm() override {
            return current;
        }

};

#endif // DFFAMITERATOR_H