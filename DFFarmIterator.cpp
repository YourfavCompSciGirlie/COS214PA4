// #include "DFFarmIterator.h"
// #include "FarmUnit.h"

// #include <stack>

// using namespace std;

// DFFarmIterator::DFFarmIterator(FarmUnit* rootFarm) {
//     if (rootFarm) {
//         farmStack.push(rootFarm);
//     }
// }

// FarmUnit* DFFarmIterator::firstFarm() {
//     return farmStack.empty() ? nullptr : farmStack.top();
// }

// FarmUnit* DFFarmIterator::next() {
//     if (farmStack.empty()) return nullptr;
    
//     FarmUnit* current = farmStack.top();
//     farmStack.pop();

//     // Add sub-units to the stack (reverse order to ensure proper DFS order)
//     std::vector<FarmUnit*> subUnits = current->getSubUnits();
//     for (auto it = subUnits.rbegin(); it != subUnits.rend(); ++it) {
//         farmStack.push(*it);
//     }

//     return current;
// }

// bool DFFarmIterator::isDone() {
//     return farmStack.empty();
// }

// FarmUnit* DFFarmIterator::currentFarm() {
//     return farmStack.empty() ? nullptr : farmStack.top();
// }
