// Class definition for Component 2 - State (State)

#ifndef SOILSTATE_H
#define SOILSTATE_H

#include <string>

using namespace std;

class CropField;

class SoilState {

    protected:
        CropField* context; // Pointer to the context (CropField) to manage state transitions
    
    public:
        SoilState();
        virtual ~SoilState();

        virtual int harvestCrops() const = 0; // Returns the amount of crops harvested
        virtual void rain() = 0; // Simulates the effect of rain on the soil
        virtual string getName() const = 0; // Returns the name of the soil state

        void setContext(class CropField* context);
};

#endif // SOILSTATE_H
