/**
 * @file Clock.cpp
 * @author Jacob Stacy
 * Implementation of the Clock Class
 */

#include "pch.h"
#include "Item.h"
#include "Clock.h"
#include "Game.h"
#include <sstream>
#include <iomanip>

/// Offset for the x
const static int XOffset = 100;
using namespace std;

/**
 * Constructor
 * @param game The game we are in
 */
Clock::Clock(Game* game)
{
    mGame = game;
}

/**
 * Draws the clock to the screen
 * @param gc Graphic Context the clock is drawn with
 */
void Clock::Draw(wxGraphicsContext* gc)
{

    wxFont font(wxSize(0, 50),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    ostringstream oss;

    int minutes = static_cast<int>(mTime) / 60;
    int seconds = static_cast<int>(mTime) % 60;

    oss << minutes << ":" << setfill('0') << setw(2) << seconds;

    gc->SetFont(font, *wxBLUE);
    gc->DrawText(oss.str(), GetX() + XOffset , GetY());

}

/**
 * Updates clock with elapsed time
 * @param elapsed
 */
void Clock::Update(double elapsed)
{
    mTime += elapsed;
}


