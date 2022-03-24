/**
 * @file ItemBackground.cpp
 * @author matty
 */

#include "pch.h"
#include "ItemBackground.h"
#include <string>

using namespace std;


/**
 * Constructor
 * @param game The game we are in
 * @param bitmap The bitmap we use for the background
 */
ItemBackground::ItemBackground(Game* game, std::shared_ptr<wxBitmap> bitmap) : Item(game, bitmap)
{
    mItemBitmap = bitmap;
}

/**
* Draw this item
* @param gc Device context to draw on
*/
void ItemBackground::Draw(wxGraphicsContext *gc)
{
    double wid = mItemBitmap->GetWidth();
    double hit = mItemBitmap->GetHeight();
    gc->DrawBitmap(*mItemBitmap,
                   (GetX() - wid / 2),
                   int(GetY() - hit / 2),
                   int(wid), int(hit));
}

/**
 * Loads background
 * @param node The parent node
 */
void ItemBackground::XmlLoad(wxXmlNode* node)
{
    Item::XmlLoad(node);

}

