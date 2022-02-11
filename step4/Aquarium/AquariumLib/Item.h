/**
 * @file Item.h
 * @author Jacob Stacy
 *
 * Base class for any item in our aquarium.
 */

#ifndef AQUARIUM_ITEM_H
#define AQUARIUM_ITEM_H


class Aquarium;

/**
 * Base class for any item in our aquarium.
 */
class Item {
private:
    /// The aquarium this item is contained in
    Aquarium   *mAquarium;

    // Item location in the aquarium
    double  mX = 0;     ///< X location for the center of the item
    double  mY = 0;     ///< Y location for the center of the item

    /// The underlying fish image
    std::unique_ptr<wxImage> mItemImage;

    /// The bitmap we can display for this item
    std::unique_ptr<wxBitmap> mItemBitmap;

    bool mMirror = false;   ///< True mirrors the item image

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
    Item(Aquarium *aquarium, const std::wstring &filename);

    virtual ~Item();

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


    bool HitTest(int x, int y);

    /**
     * Breeds Item with other item
     * @param mate the item breading with the item
     * @return
     */
    virtual bool Breed (std::shared_ptr<Item> mate) { return false; }

    /**
     * Spawns a copy of the fish
     * @param aquarium The aquarium the copy is added to
     */
    virtual void Spawn(Aquarium* aquarium) {}

    double DistanceTo(std::shared_ptr<Item> item);

    virtual wxXmlNode* XmlSave(wxXmlNode* node);

    virtual void XmlLoad(wxXmlNode* node);

    /**
    * Handle updates for animation
    * @param elapsed The time since the last update
    */
    virtual void Update(double elapsed) {}

    /**
     * Get the pointer to the Aquarium object
     * @return Pointer to Aquarium object
     */
    Aquarium *GetAquarium() { return mAquarium;  }

    void SetMirror(bool m);

};

#endif //AQUARIUM_ITEM_H
