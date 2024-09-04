#include "ExtraBarn.h"
#include <iostream>

ExtraBarn::ExtraBarn(CropField* field, int extraCapacity) 
    : CropFieldDecorator(field), extraStorageCapacity(extraCapacity) 
{
    this->field = field;
}

void ExtraBarn::increaseProduction()  
{
    std::cout << "Increasing production with extra barn capacity...\n";
    field->increaseProduction();
    std::cout << "Extra barn helps enhance production.\n";
}

void ExtraBarn::harvest()
{
    std::cout << "Harvesting from the field with extra barn storage...\n";
    field->harvest();
    std::cout << "Extra barn provides additional storage for harvested crops.\n";
}

int ExtraBarn::getLeftoverCapacity()
{
    int baseCapacity = field->getLeftoverCapacity();
    std::cout << "Extra barn adds " << extraStorageCapacity << " units to the leftover capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

void ExtraBarn::buyTruck(Truck* truck)
{
    std::cout << "Adding a truck to the field with extra barn storage...\n";
    field->buyTruck(truck);
    std::cout << "Extra barn's enhanced storage can now be utilized with additional transportation.\n";
}

void ExtraBarn::sellTruck(Truck* truck)
{
    std::cout << "Removing a truck from the field with extra barn storage...\n";
    field->sellTruck(truck);
    std::cout << "Extra barn's transportation capacity adjusted.\n";
}

int ExtraBarn::getTotalCapacity()
{
    int baseCapacity = field->getTotalCapacity();
    std::cout << "Extra barn provides " << extraStorageCapacity << " units of additional total capacity.\n";
    return baseCapacity + extraStorageCapacity;
}

std::string ExtraBarn::getCropType()
{
    std::string baseCropType = field->getCropType();
    std::cout << "Crop type in the extra barn is: " << baseCropType << ".\n";
    return baseCropType;
}

std::string ExtraBarn::getSoilStateName()
{
    std::string baseSoilState = field->getSoilStateName();
    std::cout << "Soil state with extra barn: " << baseSoilState << ".\n";
    return baseSoilState;
}

int ExtraBarn::getCurrentAmount()
{
    int baseAmount = field->getCurrentAmount();
    std::cout << "Current amount in the field with extra barn: " << baseAmount << ".\n";
    return baseAmount;
}

void ExtraBarn::setCurrentAmount(int amount)
{
    std::cout << "Setting current amount in the field with extra barn to: " << amount << ".\n";
    field->setCurrentAmount(amount);
}
