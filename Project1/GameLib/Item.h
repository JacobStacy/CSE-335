/**
 * @file Item.h
 * @author Jacob Stacy
 * Base class for items in our game.
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

#include <wx/graphics.h>
#include "ItemVisitor.h"
#include "Vector.h"

class Game;

class wxXmlNode;

/**
 * The Item Class
 */
class Item {
private:
    /// The game this item is contained in
    Game *mGame;

    // Item Location game
    double mX = 0; ///< X location for the center of the item
    double mY = 0; ///< Y location for the center of the item
    /// The bitmap we display for the item
    std::shared_ptr<wxBitmap> mItemBitmap;

public:
    /**
     * Gets width to be used with collision
     * @return width
     */
    virtual double GetWidth (){ return mItemBitmap->GetWidth();}

    /**
     * Gets height to be used with collision
     * @return height
     */
    virtual double GetHeight (){ return mItemBitmap->GetHeight();}

    virtual  ~Item();

    /// Default constructor (disabled)
    Item() = default;

    /// Copy constructor (disabled)
    Item(const Item &) = delete;

    /// Assignment operator
    void operator=(const Item &) = delete;

    /**
     * The X location of the item
     * @return X location in pixels
     */
    double GetX() const { return mX; }

    /**
     * The Y location of the item
     * @return Y location in pixels
     */
    double GetY() const { return mY; }

    /**
     * Set the item location
     * @param x X location in pixels
     * @param y Y location in pixels
     */
    virtual void SetLocation(double x, double y) { mX = x; mY = y; }

    virtual void Draw(wxGraphicsContext *gc);

    virtual bool CollisionTest(Item *item);


    /**
    * Handle updates for animation
    * @param elapsed The time since the last update
    */
    virtual void Update(double elapsed) {}

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game *GetGame() { return mGame; }

    /**
     * Accepts the visitor as Item
     * @param visitor
     */
    virtual void Accept(ItemVisitor* visitor) {}

    /**
     * Load this item to an XML node
     * @param node
     */
    virtual void XmlLoad(wxXmlNode *node);

    /**
     * Constructor
     * @param game The game this item is a member of
     * @param bitmap The bitmap of the item
     */
    Item(Game *game, std::shared_ptr<wxBitmap> bitmap);
};

#endif //PROJECT1_ITEM_H
