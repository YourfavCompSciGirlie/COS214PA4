#ifndef BFFARMITERATOR_H
#define BFFARMITERATOR_H


#include "FarmIterator.h"
#include "FarmUnit.h"

#include <vector>
#include <queue>

using namespace std;

class BFFarmIterator : public FarmIterator {
    private:
        queue<FarmUnit*> unitQueue;
        FarmUnit* current = nullptr;

    public:
        BFFarmIterator(FarmUnit* rootFarm) {
            if (rootFarm != nullptr) {
                unitQueue.push(rootFarm);
            }
        }

        FarmUnit* firstFarm() override {
            if (!unitQueue.empty()) {
                current = unitQueue.front();
                return current;
            }
            return nullptr;
        }

        FarmUnit* next() override {
            if (!isDone()) {
                current = unitQueue.front();
                unitQueue.pop();
                const vector<FarmUnit*>& subUnits = current->getSubUnits();  // Assuming FarmUnit has getSubUnits() method.
                for (FarmUnit* unit : subUnits) {
                    unitQueue.push(unit);
                }
            }
            return current;
        }

        bool isDone() override {
            return unitQueue.empty();
        }

        FarmUnit* currentFarm() override {
            return current;
        }

};

#endif // BFFARMITERATOR_H