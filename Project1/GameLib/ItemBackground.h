/**
 * @file ItemBackground.h
 * @author matty
 * Defines ItemBackground class
 */

#ifndef PROJECT1_ITEMBACKGROUND_H
#define PROJECT1_ITEMBACKGROUND_H

#include "Item.h"
#include <memory>
#include "Vector.h"

/**
 * Creates ItemBackgrouond class inherited from Item
 */
class ItemBackground : public Item {
private:

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

public:
    /// Default constructor (disabled)
    ItemBackground() = delete;

    /// Copy constructor (disabled)
    ItemBackground(const ItemBackground &) = delete;

    /// Assignment operator
    void operator=(const ItemBackground &) = delete;

    ///Draw background
    void Draw(wxGraphicsContext* gc) override;


    ItemBackground(Game* game, std::shared_ptr<wxBitmap>);

    /**
     * Accepts background as visitor
     * @param visitor Visitor
     */
    void Accept(ItemVisitor* visitor) override {visitor->VisitItemBackground(this);}

    void XmlLoad(wxXmlNode* node) override;

    /**
     * Stops background from colliding with anything
     * @param item item being checked
     * @return false
     */
    bool CollisionTest(Item *item) override { return false; }
};

#endif //PROJECT1_ITEMBACKGROUND_H
