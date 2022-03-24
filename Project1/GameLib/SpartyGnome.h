/**
 * @file SpartyGnome.h
 * @author matty, Kurt LaBlanc
 * Class declaration for the Platform Item
 */

#ifndef PROJECT1_SPARTYGNOME_H
#define PROJECT1_SPARTYGNOME_H
#include "Item.h"
#include <memory>
#include "Vector.h"

/**
 * Class for the SpartyGnome Item
 */
class SpartyGnome : public Item {
private:
    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mItemBitmap;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mNeutralBitmap;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mLeftOneBitmap;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mLeftTwoBitmap;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mRightOneBitmap;

    /// The bitmap we can display for this item
    std::shared_ptr<wxBitmap> mRightTwoBitmap;

    /// Vector of positions of SpartyGnome
    Vector mP;

    /// Vector of velocity of SpartyGnome
    Vector mV;

    /// If sparty has landed after a jump
    bool mLanded = true;

    /// The game that it is in
    Game *mGame;

    /// Whether we want the gnome to move or not
    bool mCanMove = true;

public:
    /// Default constructor (disabled)
    SpartyGnome() = delete;

    /// Copy constructor (disabled)
    SpartyGnome(const SpartyGnome &) = delete;

    /// Assignment operator
    void operator=(const SpartyGnome &) = delete;


    SpartyGnome(Game *game, std::shared_ptr<wxBitmap> neutral, std::shared_ptr<wxBitmap> leftOne, std::shared_ptr<wxBitmap> leftTwo, std::shared_ptr<wxBitmap> rightOne, std::shared_ptr<wxBitmap> rightTwo);

    void Draw(wxGraphicsContext* gc) override;
    /**
     * Accept for spartygnome class
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override { visitor->VisitGnome(this);}
    /**
     * setter
     * @param v
     */
    void SetP(Vector v) {mP = v;}
    /**
     * getter
     * @return
     */
    Vector GetP() {return mP;}

    /**
     * setter
     * @param v
     */
    void SetV(Vector v) {mV = v;}

    /**
     * Sets location of SpartyGnome
     * @param x X coordinate
     * @param y Y coordinate
     */
    void SetLocation(double x, double y) override;

    /**
     * getter
     * @return
     */
    Vector* GetV() {return &mV;}

    void Update(double elapsed) override;

    void Jump(double);

    /**
     * Sets whether the gnome is able to move
     * @param move true if we want the gnome to move.
     */
    void CanMove(bool move) { mCanMove = move; }
};

#endif //PROJECT1_SPARTYGNOME_H
