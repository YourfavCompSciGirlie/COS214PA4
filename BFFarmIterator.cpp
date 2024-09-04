// // Class definition for Component 5 - Iterator (ConcreteIterator)

// #include "FarmUnit.h"

// #include <queue>

// using namespace std;

// BFFarmIterator::BFFarmIterator(FarmUnit* rootFarm) {
//     if (rootFarm) {
//         farmQueue.push(rootFarm);
//     }
// }

// FarmUnit* BFFarmIterator::firstFarm() {
//     return farmQueue.empty() ? nullptr : farmQueue.front();
// }

// FarmUnit* BFFarmIterator::next() {
//     if (farmQueue.empty()) return nullptr;
    
//     FarmUnit* current = farmQueue.front();
//     farmQueue.pop();

//     // Add sub-units to the queue
//     std::vector<FarmUnit*> subUnits = current->getSubUnits();
//     for (FarmUnit* unit : subUnits) {
//         farmQueue.push(unit);
//     }

//     return current;
// }

// bool BFFarmIterator::isDone() {
//     return farmQueue.empty();
// }

// FarmUnit* BFFarmIterator::currentFarm() {
//     return farmQueue.empty() ? nullptr : farmQueue.front();
// }
