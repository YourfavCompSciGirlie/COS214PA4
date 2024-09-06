

#include "FarmIterator.h"
#include "FarmUnit.h"
#include "BFFarmIterator.h"

#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

BFFarmIterator::BFFarmIterator() {
    cout << "🚜 A new BFFarmIterator is ready to traverse the farm, one row at a time! 🌾" << endl;
}

// Destructor
BFFarmIterator::~BFFarmIterator() {
    cout << "🏁 The BFFarmIterator has finished its journey across the farm. Time to rest! 🐑" << endl;
}

// Parameterized constructor
BFFarmIterator::BFFarmIterator(FarmUnit* rootFarm) {
    cout << "🌻 Starting a new breadth-first farm exploration from the root unit! 🚶‍♂️" << endl;
    if (rootFarm) {
        unitQueue.push(rootFarm);
        current = rootFarm;
    }
}

FarmUnit *BFFarmIterator::firstFarm()
{
    if (!unitQueue.empty())
    {
        current = unitQueue.front();
        return current;
    }
    return nullptr;
}

FarmUnit *BFFarmIterator::next()
{
    if (!isDone())
    {
        // Dequeue the front element
        current = unitQueue.front();
        unitQueue.pop();

        // Check if the current node is a CompositeFarm and handle its sub-units
        FarmUnit *composite = dynamic_cast<FarmUnit *>(current);
        if (composite != nullptr)
        {
            const vector<FarmUnit *> &subUnits = composite->getSubUnits(); // Assuming this method exists
            for (FarmUnit *unit : subUnits)
            {
                if (unit != nullptr && visited.find(unit) == visited.end())
                { // Check if not visited
                    unitQueue.push(unit);
                    visited.insert(unit); // Mark as visited
                }
            }
        }
    }
    return current;
}

bool BFFarmIterator::isDone()
{
    return unitQueue.empty();
}

FarmUnit *BFFarmIterator::currentFarm()
{
    return current;
}