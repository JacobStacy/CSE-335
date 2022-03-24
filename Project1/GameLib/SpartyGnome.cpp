/**
 * @file SpartyGnome.cpp
 * @author matty, Kurt LaBlanc
 * Implementation of SpartyGnome Class
 */

#include "pch.h"
#include "SpartyGnome.h"
#include "Game.h"
#include <string>
#include <sstream>

using namespace std;

///Gravity in virtual pixels per second
const double Gravity = 1000.00;
///Small value to ensure we do not stay in collision
const double Epsilon = 0.01;

/**
 * Constructor
 * @param game The game sparty is in
 * @param neutral The bitmap used for neutral sparty
 * @param leftOne The bitmap used for leftOne sparty
 * @param leftTwo The bitmap used for leftTwo sparty
 * @param rightOne The bitmap used for rightOne sparty
 * @param rightTwo The bitmap used for rightTwo sparty
 */
SpartyGnome::SpartyGnome(Game* game, std::shared_ptr<wxBitmap> neutral,
        std::shared_ptr<wxBitmap> leftOne,
        std::shared_ptr<wxBitmap> leftTwo,
        std::shared_ptr<wxBitmap> rightOne,
        std::shared_ptr<wxBitmap> rightTwo) : Item(game, neutral)
{

    mItemBitmap = neutral;
    mNeutralBitmap = neutral;
    mLeftOneBitmap = leftOne;
    mLeftTwoBitmap = leftTwo;
    mRightOneBitmap = rightOne;
    mRightTwoBitmap = rightTwo;

    mGame = game;
}

/**
 * Sets location of SpartyGnome
 * @param x X coordinate
 * @param y Y coordinate
 */
void SpartyGnome::SetLocation(double x, double y)
{
    Item::SetLocation(x, y);
    Vector p(x, y);
    SetP(p);
}

/**
 * Draw this item
 * @param gc Device context to draw on
 */
void SpartyGnome::Draw(wxGraphicsContext *gc)
{
    gc->DrawBitmap(*mItemBitmap,
            GetX() - (mItemBitmap->GetWidth() / 2),
            GetY() - mItemBitmap->GetHeight() / 2,
            mItemBitmap->GetWidth() + 1,
            mItemBitmap->GetHeight());
}

/**
 * Handle updates in time for the gnome.
 * @param elapsed Time elapsed since class call
 */
void SpartyGnome::Update(double elapsed)
{
    //Item::Update(elapsed);

    // The current position
    Vector p = GetP();

    //Check to see if Gnome fell off
    if (p.Y() < 1050 && mCanMove)
    {
        // Gravity
        // Compute a new velocity with gravity added in.
        Vector newV(mV.X(), mV.Y()+Gravity*elapsed);

        // Update position
        Vector newP = p+newV*elapsed;

        if (p.Y()!=newP.Y()) {
            //
            // Try updating the Y location.
            //
            SetLocation(p.X(), newP.Y());
            auto collided = mGame->CollisionTest(this);
            if (collided!=nullptr) {
                if (newV.Y()>0) {
                    // We are falling, stop at the collision point
                    newP.SetY(collided->GetY()-collided->GetHeight()/2-GetHeight()/2-Epsilon);
                    mLanded = true;
                }
                else {
                    // We are rising, stop at the collision point
                    newP.SetY(collided->GetY()+collided->GetHeight()/2+GetHeight()/2+Epsilon);

                }

                // If we collide, we cancel any velocity
                // in the Y direction
                newV.SetY(0);
            }
        }

        if (p.X()!=newP.X()) {

            //
            // Try updating the X location
            //
            SetLocation(newP.X(), p.Y());

            auto collided = mGame->CollisionTest(this);
            if (collided!=nullptr) {
                if (newV.X()>0) {
                    // We are moving to the right, stop at the collision point
                    newP.SetX(collided->GetX()-collided->GetWidth()/2-GetWidth()/2-Epsilon);
                }
                else {
                    // We are moving to the left, stop at the collision point
                    newP.SetX(collided->GetX()+collided->GetWidth()/2+GetWidth()/2+Epsilon);
                }


                // If we collide, we cancel any velocity
                // in the X direction
                newV.SetX(0);
            }
        }


        // Update the velocity and position
        mV = newV;
        SetLocation(newP.X(), newP.Y());
        if (mV.X()>0) {
            if (static_cast<int>(mP.X())%200<100 && mLanded) {
                mItemBitmap = mRightOneBitmap;
            }
            else {
                mItemBitmap = mRightTwoBitmap;
            }
        }
        else if (mV.X()<0) {
            if (static_cast<int>(mP.X())%200<100 && mLanded) {
                mItemBitmap = mLeftOneBitmap;
            }
            else {
                mItemBitmap = mLeftTwoBitmap;
            }
        }
        else {
            mItemBitmap = mNeutralBitmap;
        }
    }
    else// if (p.Y() >= 1050)
    {
        mGame->Restart();
        CanMove(true);
    }
}

/**
 * Detects if SpartyGnome has jumped
 * @param JumpSpeed
 */
void SpartyGnome::Jump(double JumpSpeed)
{
    if (mLanded)
    {
        GetV()->SetY(JumpSpeed);
        mLanded = false;
    }
}

