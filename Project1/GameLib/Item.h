/**
 * @file Item.h
 * @author Jacob Stacy
 *
 * Base class for items in our game.
 */

#ifndef PROJECT1_ITEM_H
#define PROJECT1_ITEM_H

class Game;

class Item {
private:
    /// The game this item is contained in
    Game *mGame;

    // Item Location game
    double mX = 0; ///< X location for the center of the item
    double mY = 0; ///< Y location for the center of the item

    /// The underlying item image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we display for the item
    std::unique_ptr<wxBitmap> mItemBitmap;

protected:
    /**
     * Gets Image width
     * @return image width
     */
    double GetImageWidth (){ return mItemBitmap->GetWidth();}

    /**
     * Gets Image height
     * @return image height
     */
    double GetImageHeight (){ return mItemBitmap->GetHeight();}

public:
    Item(Game *game, const std::wstring &filename);

    virtual  ~Item();

    /// Default constructor (disabled)
    Item() = delete;

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

    void Draw(wxDC *dc);



    /**
    * Handle updates for animation
    * @param elapsed The time since the last update
    */
    virtual void Update(double elapsed) {}

    /**
     * Get the pointer to the Game object
     * @return Pointer to Game object
     */
    Game *GetGame() { return mGame;  }

};

#endif //PROJECT1_ITEM_H
