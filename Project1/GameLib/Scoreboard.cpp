/**
 * @file Scoreboard.cpp
 * @author Jacob Stacy
 * Implementation of the Scoreboard Class
 */

#include "pch.h"
#include "Item.h"
#include "Scoreboard.h"
#include "Game.h"
#include <sstream>



/// Offset for the x
const static int XOffset = 200;

using namespace std;

/**
 * Constructor
 * @param game The game we are in
 */
Scoreboard::Scoreboard(Game* game)
{
    mGame = game;
}

/**
 * Draws the scoreboard to the screen
 * @param gc Graphic Context the scoreboard is drawn with
 */
void Scoreboard::Draw(wxGraphicsContext* gc)
{

    wxFont font(wxSize(0, 50),
            wxFONTFAMILY_SWISS,
            wxFONTSTYLE_NORMAL,
            wxFONTWEIGHT_NORMAL);

    ostringstream oss;
    oss << "$" << mScore;

    gc->SetFont(font, *wxBLUE);
    gc->DrawText(oss.str(), GetX() - XOffset , GetY());

}


