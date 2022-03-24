/**
 * @file Level.cpp
 * @author Jacob Stacy, Kurt LaBlanc
 */

#include "pch.h"
#include "Level.h"
#include <sstream>

/// Offset for the x
const static int XOffset = 100;

using namespace std;


/**
 * Add an item to the level
 * @param item New item to add
 */
void Level::Add(std::shared_ptr<Item> item)
{
    mItems.push_back(item);
}

/**
 * Sets the position of SpartyGnome when level starts
 * @param x X coordinate
 * @param y Y coordinate
 */
void Level::SetStart(double x, double y)
{
    mSpartyStartX = x;
    mSpartyStartY = y;
}
