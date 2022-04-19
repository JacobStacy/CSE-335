/**
 * @file LaboratoryFactoryOne.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "LaboratoryFactoryOne.h"
#include "ActualLaboratory.h"
#include "Shape.h"

using namespace std;

/**
 * Constructor
 * @param resourcesDir The directory that resources can be found in | probably need to make a member variable
 */
LaboratoryFactoryOne::LaboratoryFactoryOne(std::wstring resourcesDir) : mResourcesDir(resourcesDir)
{

}


/**
 * Creates Laboratory 1
 * @return
 */
std::shared_ptr<ActualLaboratory> LaboratoryFactoryOne::CreateLaboratory()
{
    auto labOne = make_shared<ActualLaboratory>();

    // The laboratory background image
    auto background = make_shared<Shape>(L"Background");
    background->GetPolygon()->SetImage(mResourcesDir + L"/images/laboratory.jpg");
    background->GetPolygon()->Rectangle(-600, 0);
    labOne->AddComponent(background);


    return labOne;
}
