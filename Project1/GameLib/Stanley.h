/**
 * @file Stanley.h
 * @author Kurt LaBlanc
 * Defines Stanley Class
 */

#ifndef PROJECT1_STANLEY_H
#define PROJECT1_STANLEY_H

#include "Item.h"

/**
 * Creates Stanley class inherited from Item
 */
class Stanley : public Item {
private:
    /// Velocity of stanley
    Vector mV;

    ///Vector to hold velocity of money
    Vector mV_S;

    /// Boolean to indicate if Text is active
    bool mText = false;

    ///position of text
    double mTP = 0;

    ///size of text
    double mTSize = 25;

    /// Boolean if Stanley is in contact
    bool hit = false;

public:
    ///Default constructor (disabled)
    Stanley() = delete;

    ///Copy constructor (disabled)
    Stanley(const Stanley&) = delete;

    ///Assignment operator (disabled)
    void operator = (const Stanley&) = delete;


    Stanley(Game* game, std::shared_ptr<wxBitmap> bitmap);

    /**
     * Accepts stanley as visitor
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override {visitor->VisitStanley(this);}

    bool CollisionTest(Item * item) override;

    void Update(double elapsed) override;

    void Draw(wxGraphicsContext* gc) override;
};

#endif //PROJECT1_STANLEY_H
