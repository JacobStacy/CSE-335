/**
 * @file Item.cpp
 * @author Jacob Stacy
 */

#include "Item.h"
#include "pch.h"
#include "Aquarium.h"

/**
 * Constructor
 * @param aquarium The aquarium this item is a member of
 */
Item::Item(Aquarium *aquarium) : mAquarium(aquarium)
{
}