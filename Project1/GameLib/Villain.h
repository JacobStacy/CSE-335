/**
 * @file Villain.h
 * @author Aref Zeitoun
 * Representation of a Villain
 */

#include "Game.h"
#include "Item.h"
#include <memory>
#include <string>

#ifndef PROJECT1_VILLAIN_H
#define PROJECT1_VILLAIN_H

/**
 * Representation of a Villain
 */
class Villain : public Item {
private:

    /// Top of the motion
    double mTop;

    /// Bottom of the motion
    double mBottom;

//    /// Vertical position when moving up/down
//    double mBounceY = 300;

    /// Movement speed, in pixels per second. Positive = move down; negative = move up
    double mSpeed = -240;

protected:
    //Villain(Game *game, const std::wstring& image);

public:
    /// Default constructor (disabled)
    Villain() = delete;

    /// Copy constructor (disabled)
    Villain(const Villain &) = delete;

    /// Assignment operator
    void operator=(const Villain &) = delete;

    /**
     * Constructor
     * @param game
     * @param bitmap
     */
    Villain(Game *game, std::shared_ptr<wxBitmap> bitmap);

    /**
     * Accepts villain as visitor
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitVillain(this);}


    bool CollisionTest(Item *item) override;

    void Update(double elapsed) override;

    void XmlLoad(wxXmlNode* node) override;
};

#endif //PROJECT1_VILLAIN_H
