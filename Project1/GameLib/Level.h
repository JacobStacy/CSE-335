/**
 * @file Level.h
 * @author Jacob Stacy
 * Defines Level class
 */

#ifndef PROJECT1_LEVEL_H
#define PROJECT1_LEVEL_H

#include <vector>
#include <memory>
#include "Item.h"
#include "Vector.h"

/**
 * Creates Level class
 */
class Level {
private:
    /// All of the scrolling items to populate our game
    std::vector<std::shared_ptr<Item>> mItems;

    /// Sparty start location in the playing area
    double mSpartyStartX;

    /// Sparty start location in the playing area
    double mSpartyStartY;

public:

    void SetStart(double x, double y);

    /**
     * Getter for SpartyGnome position X
     * @return mSpartyStartX
     */
    double GetStartX() { return mSpartyStartX; }

    /**
     * Getter for SpartyGnome position Y
     * @return mSpartyStartY
     */
    double GetStartY() { return mSpartyStartY; }

    // Add item to mItems
    void Add(std::shared_ptr<Item> item);

    /**
     * Getter for Items in specific level
     * @return mItems
     */
    std::vector<std::shared_ptr<Item>> GetItems() { return mItems; }

};

#endif //PROJECT1_LEVEL_H
