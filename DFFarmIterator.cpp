#include "FarmIterator.h"
#include "FarmUnit.h"
#include "DFFarmIterator.h"

#include <stack>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

DFFarmIterator::DFFarmIterator()
{
    cout << "🌱 A new DFFarmIterator is born, ready to explore the farm's depths! 🌾" << endl;
}

// Destructor
DFFarmIterator::~DFFarmIterator()
{
    cout << "🌾 The DFFarmIterator has finished its journey through the farm. Farewell! 🐄" << endl;
}

DFFarmIterator::DFFarmIterator(FarmUnit *rootFarm) : current(nullptr)
{
    cout << "🚜 Starting a new depth-first farm exploration from the root unit!" << endl;
    if (rootFarm)
    {
        unitStack.push(rootFarm);
        current = rootFarm;
    }
}

FarmUnit *DFFarmIterator::firstFarm()
{
    if (!unitStack.empty())
    {
        current = unitStack.top();
        return current;
    }
    return nullptr;
}

FarmUnit *DFFarmIterator::next()
{
    if (!isDone())
    {
        current = unitStack.top();
        unitStack.pop();

        const vector<FarmUnit *> &subUnits = current->getSubUnits();
        // Push children in reverse order to process the leftmost child first
        for (auto it = subUnits.rbegin(); it != subUnits.rend(); ++it)
        {
            if (visited.find(*it) == visited.end())
            { // Check if the unit has been visited
                unitStack.push(*it);
                visited.insert(*it);
            }
        }
        return current;
    }
    return nullptr;
}

bool DFFarmIterator::isDone()
{
    return unitStack.empty();
}

FarmUnit *DFFarmIterator::currentFarm()
{
    return current;
}