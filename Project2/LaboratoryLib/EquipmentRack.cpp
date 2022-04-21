/**
 * @file EquipmentRack.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "EquipmentRack.h"

///// Where to start drawing racks
//double RackOffset = 15;


EquipmentRack::EquipmentRack(const std::wstring& name, const std::wstring& imageDir) : Shape(name)
{
    mImagesDir = imageDir;

    GetPolygon()->SetImage(mImagesDir + L"/rack.png");
    GetPolygon()->Rectangle(-66, 0);
}

void EquipmentRack::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
    Shape::Draw(graphics);

// The solution below is a much better solution but does not follow the UML
//    double stackHeight = RackOffset;
//
//    for (int rack : mRacks)
//    {
//        int addedHeight = 0;
//        cse335::Polygon rackPoly;
//        switch(rack)
//        {
//        case 1:
//            addedHeight = 10;
//            rackPoly.SetImage(mImagesDir+L"/1u.png");
//            break;
//        case 2:
//            addedHeight = 21;
//            rackPoly.SetImage(mImagesDir+L"/2u.png");
//            break;
//        case 5:
//            addedHeight = 52;
//            rackPoly.SetImage(mImagesDir+L"/5u.png");
//            break;
//        case 6:
//            addedHeight = 62;
//            rackPoly.SetImage(mImagesDir+L"/6u.png");
//            break;
//        case 10:
//            addedHeight = 104;
//            rackPoly.SetImage(mImagesDir+L"/10u.png");
//            break;
//        case 12:
//            addedHeight = 125;
//            rackPoly.SetImage(mImagesDir+L"/12u.png");
//            break;
//        }
//
//        rackPoly.Rectangle(-57, 0);
//        rackPoly.DrawPolygon(graphics, GetOrigin().x, GetOrigin().y - stackHeight);
//
//        stackHeight += addedHeight;
//
//
//    }
}

//void EquipmentRack::AddRack(int size)
//{
//    mRacks.push_back(size);
//}

