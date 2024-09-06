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
        BFFarmIterator() {};
        ~BFFarmIterator() {};
        
        BFFarmIterator(FarmUnit* rootFarm) : current(nullptr) {
            if (rootFarm != nullptr) {
                unitQueue.push(rootFarm);
                visited.insert(rootFarm); // Mark root as visited
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
                // Dequeue the front element
                current = unitQueue.front();
                unitQueue.pop();

                // Check if the current node is a CompositeFarm and handle its sub-units
                FarmUnit* composite = dynamic_cast<FarmUnit*>(current);
                if (composite != nullptr) {
                    const vector<FarmUnit*>& subUnits = composite->getSubUnits(); // Assuming this method exists
                    for (FarmUnit* unit : subUnits) {
                        if (unit != nullptr && visited.find(unit) == visited.end()) { // Check if not visited
                            unitQueue.push(unit);
                            visited.insert(unit); // Mark as visited
                        }
                    }
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