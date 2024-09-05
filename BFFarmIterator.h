#ifndef BFFARMITERATOR_H
#define BFFARMITERATOR_H

#include <queue>
#include "FarmIterator.h"
#include "FarmUnit.h" // Assuming this header defines the FarmUnit class

class BFFarmIterator : public FarmIterator 
{
    private:
    FarmUnit* current;
    int currentFarm;
    std::queue<FarmUnit> queueFarm;
    bool done;
    

   public:
    BFFarmIterator(FarmUnit* start);
    FarmUnit* firstFarm();
    bool hasNext();
    virtual FarmUnit* next() override; //need to implement
    virtual bool isDone() override;
    virtual FarmUnit* currentFarm() override; 
    
};

#endif 
