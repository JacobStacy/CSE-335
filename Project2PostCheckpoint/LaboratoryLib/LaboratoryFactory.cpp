/**
 * @file LaboratoryFactory.cpp
 *
 * @author Charles Owen
 *
 * You are allowed to change this file.
 */

#include "pch.h"

#include "LaboratoryFactory.h"

#include "Laboratory.h"
#include "FakeLaboratory.h"

/**
 * Constructor
 * @param resourcesDir Directory to load images from
 */
LaboratoryFactory::LaboratoryFactory(std::wstring resourcesDir) :mResourcesDir(resourcesDir)
{
}


/**
 * Create a laboratory object
 *
 * Do not change the return type of this function!
 *
 * @return Object of type Laboratory
 */
std::shared_ptr<Laboratory> LaboratoryFactory::CreateLaboratory()
{
    return std::make_shared<FakeLaboratory>(mResourcesDir);
}


