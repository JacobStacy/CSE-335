/**
 * @file Money.h
 * @author matt wright, Jacob Stacy, Kurt LaBlanc
 * Class declaration for the Money Item
 */

#ifndef PROJECT1_MONEY_H
#define PROJECT1_MONEY_H

#include "Item.h"
#include "Game.h"
#include <string>
#include "Vector.h"


/**
 * Class declaration for the Money Item
 */
class Money : public Item {
private:
    ///Value of money
    int mValue = 0;

    ///Text of amount of money
    bool mText = false;

    ///Vector to hold velocity of money
    Vector mV;


public:
    /// Default constructor (disabled)
    Money() = delete;

    /// Copy constructor (disabled)
    Money(const Money &) = delete;

    /// Assignment operator
    void operator=(const Money &) = delete;


    Money(Game* game, std::shared_ptr<wxBitmap> bitmap, int value);

    /**
     * Accept a visitor
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override {visitor->VisitMoney(this);}

    bool CollisionTest(Item *item) override;

    void Update(double elapsed) override;

    void Draw(wxGraphicsContext* gc) override;

};

#endif //PROJECT1_MONEY_H
