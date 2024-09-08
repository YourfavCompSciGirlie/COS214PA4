// Class implementation for Component 5 - Iterator (Iterator))


#include "FarmIterator.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructs a new FarmIterator object.
 * 
 * Initializes the FarmIterator, preparing it for traversal of farm units.
 */
FarmIterator::FarmIterator() {
    std::cout << "🚜 FarmIterator created. Ready for traversal!\n";
}

/**
 * @brief Destroys the FarmIterator object.
 * 
 * Cleans up resources associated with the FarmIterator and ends the traversal.
 */
FarmIterator::~FarmIterator() {
    std::cout << "🛠 FarmIterator destroyed. Traversal ended.\n";
}
