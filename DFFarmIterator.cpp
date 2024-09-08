// Class implementation for Component 5 - Iterator (ConcreteIterator)

/**
 * @file DFFarmIterator.cpp
 * @brief Implementation of the DFFarmIterator class.
 */

#include "FarmIterator.h"
#include "FarmUnit.h"
#include "DFFarmIterator.h"

#include <stack>
#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

/**
 * @brief Default constructor. Initializes the depth-first farm iterator.
 */
DFFarmIterator::DFFarmIterator() {
    cout << "🌱 A new DFFarmIterator is born, ready to explore the farm's depths! 🌾" << endl;
}

/**
 * @brief Destructor. Cleans up resources used by the depth-first farm iterator.
 */
DFFarmIterator::~DFFarmIterator() {
    cout << "🌾 The DFFarmIterator has finished its journey through the farm. Farewell! 🐄" << endl;
}

/**
 * @brief Constructor that initializes the iterator starting from the given root farm unit.
 * @param rootFarm Pointer to the root FarmUnit to start the depth-first search.
 */
DFFarmIterator::DFFarmIterator(FarmUnit* rootFarm) : current(nullptr) {
    cout << "🚜 Starting a new depth-first farm exploration from the root unit!" << endl;
    if (rootFarm) {
        unitStack.push(rootFarm);
        current = rootFarm;
    }
}

/**
 * @brief Returns the first FarmUnit in the depth-first traversal.
 * @return Pointer to the first FarmUnit, or nullptr if the farm is empty.
 */
FarmUnit* DFFarmIterator::firstFarm() {
    if (!unitStack.empty()) {
        current = unitStack.top();
        return current;
    }
    return nullptr;
}

/**
 * @brief Advances the iterator to the next FarmUnit in the depth-first traversal.
 * @return Pointer to the next FarmUnit, or nullptr if traversal is complete.
 */
FarmUnit* DFFarmIterator::next() {
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

/**
 * @brief Checks if the traversal is complete.
 * @return true if there are no more FarmUnits to traverse, false otherwise.
 */
bool DFFarmIterator::isDone() {
    return unitStack.empty();
}

/**
 * @brief Returns the current FarmUnit in the traversal.
 * @return Pointer to the current FarmUnit.
 */
FarmUnit* DFFarmIterator::currentFarm() {
    return current;
}
