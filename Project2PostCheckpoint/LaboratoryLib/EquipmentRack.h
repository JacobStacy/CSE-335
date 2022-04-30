/**
 * @file EquipmentRack.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_EQUIPMENTRACK_H
#define CANADIANEXPERIENCE_EQUIPMENTRACK_H

#include "Shape.h"

/**
 * Equipment Rack Class
 */
class EquipmentRack : public Shape{
private:
    
    /// Directory for images | !!!!! NOT IN UML !!!!!
    std::wstring mImagesDir;

//    /// Vector of the fake racks | 1 = 1U,  2 = 2U | !!!!! NOT IN UML !!!!! | Can replace to not break uml
//    std::vector<int> mRacks;

public:

    EquipmentRack(const std::wstring &name, const std::wstring &imageDir);

    /// Copy Constructor (Disabled)
    EquipmentRack(const EquipmentRack &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const EquipmentRack &) = delete;

//    void AddRack(int size);
};

#endif //CANADIANEXPERIENCE_EQUIPMENTRACK_H
