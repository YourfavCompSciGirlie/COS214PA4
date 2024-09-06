// Class definition for Component 5 - Iterator (Iterator)

#ifndef FARMITERATOR_H
#define FARMITERATOR_H

class FarmUnit;

class FarmIterator {

    public:
        FarmIterator();
        
        virtual ~FarmIterator();
        virtual FarmUnit* firstFarm() = 0;
        virtual FarmUnit* next() = 0;
        virtual bool isDone() = 0;
        virtual FarmUnit* currentFarm() = 0;
};

#endif 
