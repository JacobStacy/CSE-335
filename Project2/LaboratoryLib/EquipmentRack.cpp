/**
 * @file EquipmentRack.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "EquipmentRack.h"

EquipmentRack::EquipmentRack(const std::wstring& name, const std::wstring& imageDir) : Shape(name)
{
    mImagesDir = imageDir;

    GetPolygon()->SetImage(mImagesDir + L"/rack.png");
    GetPolygon()->Rectangle(-66, 0);
}

void EquipmentRack::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Shape::Draw(graphics);
}
