#include "FarmIterator.h"
#include "FarmUnit.h"
#include "DFFarmIterator.h"

DFFarmIterator::DFFarmIterator(FarmUnit* start) : current(start), done(false) 
{
        if (current) {
            stack.push(current);
        } else {
            done = true;
        }
}


FarmUnit* DFFarmIterator:: firstFarm()
{
        return current;
}

bool DFFarmIterator::isDone() 
{
        return done;
}

FarmUnit* DFFarmIterator::next() 
{
        
}

FarmUnit* DFFarmIterator::currentFarm()
{
        return stack.empty() ? nullptr : stack.top();
}

