#ifndef DFFARMITERATOR_H
#define DFFARMITERATOR_H

#include <stack>
#include "FarmIterator.h"
#include "FarmUnit.h" // Assuming this header defines the FarmUnit class

class DFFarmIterator : public FarmIterator 
{
    private:
        FarmUnit* current;
        std::stack<FarmUnit*> stack;
        bool done;

   public:
        DFFarmIterator(FarmUnit* start);
        virtual FarmUnit* firstFarm() override;
        virtual FarmUnit* next() override;
        virtual bool isDone() override;
        virtual FarmUnit* currentFarm() override;

};

#endif // DFFARMITERATOR_H
