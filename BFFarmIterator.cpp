// Class defintion for Component 5 - Iterator (ConcreteIterator)

#include "FarmIterator.h"
#include "FarmUnit.h"
#include "BFFarmIterator.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for BFFarmIterator.
 */
BFFarmIterator::BFFarmIterator() {
    cout << "🚜 A new BFFarmIterator is ready to traverse the farm, one row at a time! 🌾" << endl;
}

/**
 * @brief Destructor for BFFarmIterator.
 */
BFFarmIterator::~BFFarmIterator() {
    cout << "🏁 The BFFarmIterator has finished its journey across the farm. Time to rest! 🐑" << endl;
}

/**
 * @brief Parameterized constructor for BFFarmIterator.
 * 
 * @param rootFarm The root farm unit to start the BFS from.
 */
BFFarmIterator::BFFarmIterator(FarmUnit* rootFarm) {
    cout << "🌻 Starting a new breadth-first farm exploration from the root unit! 🚶‍♂️" << endl;
    if (rootFarm) {
        unitQueue.push(rootFarm);
        current = rootFarm;
    }
}

/**
 * @brief Returns the first farm unit in the BFS.
 * 
 * @return FarmUnit* The first farm unit.
 */
FarmUnit* BFFarmIterator::firstFarm() {
    if (!unitQueue.empty()) {
        current = unitQueue.front();
        return current;
    }
    return nullptr;
}

/**
 * @brief Moves to the next farm unit in the BFS.
 * 
 * @return FarmUnit* The next farm unit.
 */
FarmUnit* BFFarmIterator::next() {
    if (!isDone()) {
        current = unitQueue.front();
        unitQueue.pop();

        FarmUnit* composite = dynamic_cast<FarmUnit*>(current);
        if (composite != nullptr) {
            const vector<FarmUnit*>& subUnits = composite->getSubUnits();
            for (FarmUnit* unit : subUnits) {
                if (unit != nullptr && visited.find(unit) == visited.end()) {
                    unitQueue.push(unit);
                    visited.insert(unit);
                }
            }
        }
    }
    return current;
}

/**
 * @brief Checks if the BFS is done.
 * 
 * @return bool True if the BFS is done, false otherwise.
 */
bool BFFarmIterator::isDone() {
    return unitQueue.empty();
}

/**
 * @brief Returns the current farm unit in the BFS.
 * 
 * @return FarmUnit* The current farm unit.
 */
FarmUnit* BFFarmIterator::currentFarm() {
    return current;
}
