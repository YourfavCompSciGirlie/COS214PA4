#ifndef DFFAMITERATOR_H
#define DFFAMITERATOR_H

#include "FarmIterator.h"
#include "FarmUnit.h"

#include <stack>
#include <vector>

using namespace std;

class DFFarmIterator : public FarmIterator {
    
    private:
        stack<FarmUnit*> unitStack;
        FarmUnit* current = nullptr;

    public:
        DFFarmIterator(FarmUnit* rootFarm) {
            if (rootFarm != nullptr) {
                unitStack.push(rootFarm);
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
                    unitStack.push(*it);
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