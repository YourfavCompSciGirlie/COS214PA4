#include "BFFarmIterator.h"
#include <queue>
#include "FarmUnit.h" 

#include <queue>
#include <unordered_set>
#include <vector>
#include "FarmIterator.h"
#include "FarmUnit.h"

BFFarmIterator::BFFarmIterator(FarmUnit* start) : current(start), done(false) 
{
        if (start) {
            queueFarm.push(start);
            visited.insert(start);
        } else {
            done = true;
        }
}

FarmUnit* BFFarmIterator::firstFarm()  
{
        return current;
}

FarmUnit* BFFarmIterator :: next() 
{
     
}

bool BFFarmIterator::isDone() 
{
        return done;
}

bool BFFarmIterator::hasNext()
{
    return currentFarm < queueFarm.size();
}

FarmUnit* BFFarmIterator::next()
{
    if(!hasNext())
    {
        throw new NoSuchElementException();
    }
}

FarmUnit* BFFarmIterator::currentFarm()  
{
        return queueFarm.empty() ? nullptr : queueFarm.front();
}

