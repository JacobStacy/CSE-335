/**
 * @file Door.h
 * @author Jacob Stacy
 * Defines Door class
 */

#ifndef PROJECT1_DOOR_H
#define PROJECT1_DOOR_H


#include "Item.h"
#include "Game.h"
#include <string>

/**
 * Creates door class inherited from Item
 */
class Door : public Item{
private:
    /// True if door is hit; false otherwise
    bool hit = false;

public:
    ///Default constructor
    Door() = delete;

    ///Copy constructor
    Door(const Door &) = delete;

    ///Assignment operator
    void operator=(const Door &) = delete;

    /**
     * Constructor
     * @param game
     * @param bitmap
     */
    Door(Game* game, std::shared_ptr<wxBitmap> bitmap);

    bool CollisionTest(Item *item) override;

};



#endif //PROJECT1_DOOR_H
