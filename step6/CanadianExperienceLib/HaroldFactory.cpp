/**
 * @file HaroldFactory.cpp
 * @author Jacob Stacy
 *
 * Implementation of HaroldFactory class
 *
 */

#include "pch.h"

#include "HaroldFactory.h"
#include "Actor.h"

using std::make_shared;

/**
 * This is a factory method that creates our Harold actor.
 * @param imagesDir Directory that contains the images for this application
 * @return Pointer to an actor object.
 */
std::shared_ptr<Actor> HaroldFactory::Create(std::wstring imagesDir)
{
    auto actor = make_shared<Actor>(L"Harold");

    return actor;
}