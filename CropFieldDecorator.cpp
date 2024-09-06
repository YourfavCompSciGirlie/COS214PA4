#include "CropFieldDecorator.h"
#include <iostream>


CropFieldDecorator::CropFieldDecorator() : field(nullptr) 
{
    std::cout << "🌱 CropFieldDecorator created, no crop field attached yet.\n";
}


CropFieldDecorator::~CropFieldDecorator() 
{
    std::cout << "🌾 CropFieldDecorator destroyed, releasing attached crop field.\n";
    delete field; // Clean up the attached CropField if necessary
}


CropFieldDecorator::CropFieldDecorator(CropField* field) : field(field) {
    std::cout << "🌿 CropFieldDecorator created, decorating a crop field.\n";
}