/**
 * @file EquipmentRack.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_EQUIPMENTRACK_H
#define CANADIANEXPERIENCE_EQUIPMENTRACK_H

#include "Shape.h"

class EquipmentRack : public Shape{
private:
    
    /// Directory for images | !!!!! NOT IN UML !!!!!
    std::wstring mImagesDir;

public:

    EquipmentRack(const std::wstring &name, const std::wstring &imageDir);

    /// Copy Constructor (Disabled)
    EquipmentRack(const EquipmentRack &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const EquipmentRack &) = delete;

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

};

#endif //CANADIANEXPERIENCE_EQUIPMENTRACK_H
