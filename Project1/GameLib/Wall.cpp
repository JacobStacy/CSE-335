/**
 * @file Wall.cpp
 * @author Jacob Stacy
 * Implementation of the Wall Class
 */

#include "pch.h"
#include "Item.h"
#include "Wall.h"

using namespace std;

/// length of the side of a image
const double WallImageDimension = 32;

/**
 * Constructor
 * @param game The game we are in
 * @param bitmap Bitmap we use for the wall
 * @param width Actual width of the Wall
 * @param height Actual height of the the Wall
 */
Wall::Wall(Game* game,
        std::shared_ptr<wxBitmap> bitmap,
        const int width,
        const int height) : Item(game, bitmap)
{
    mCenterBitmap = bitmap;

    mWidth = width;
    mHeight = height;
}

/**
 * Draws the Wall to the screen
 * @param gc Graphic Context the Wall is drawn with
 */
void Wall::Draw(wxGraphicsContext* gc)
{
    int numberOfCenter = (mHeight - (WallImageDimension * 2)) / 32;

    if (numberOfCenter % 2 == 0)
    {
        int i = 0;
        for (; i < numberOfCenter / 2; i++)
        {
            // Top
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() - WallImageDimension / 2,
                    GetY() - (WallImageDimension ) - (WallImageDimension * i),
                    WallImageDimension + 1,
                    WallImageDimension);

            // Bottom
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() - WallImageDimension / 2,
                    GetY() + (WallImageDimension * i),
                    WallImageDimension + 1,
                    WallImageDimension);

        }
        // Top
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - WallImageDimension / 2,
                GetY() - (WallImageDimension ) - (WallImageDimension * i),
                WallImageDimension + 1,
                WallImageDimension);

        // Bottom
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - WallImageDimension / 2,
                GetY() + (WallImageDimension * i),
                WallImageDimension + 1,
                WallImageDimension);

    } else
    {
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - WallImageDimension / 2,
                GetY() - (WallImageDimension / 2),
                WallImageDimension + 1,
                WallImageDimension);

        numberOfCenter--;

        int i = 0;
        for (; i <= numberOfCenter / 2; i++)
        {
            // Top
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() - WallImageDimension / 2,
                    (GetY() + WallImageDimension / 2) - (WallImageDimension ) - (WallImageDimension * i),
                    WallImageDimension + 1,
                    WallImageDimension);

            // Bottom
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() - WallImageDimension / 2,
                    (GetY() - WallImageDimension / 2) + (WallImageDimension * i),
                    WallImageDimension + 1,
                    WallImageDimension);

        }

        // Top
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - WallImageDimension / 2,
                (GetY() + WallImageDimension / 2) - (WallImageDimension ) - (WallImageDimension * i),
                WallImageDimension + 1,
                WallImageDimension);

        // Bottom
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - WallImageDimension / 2,
                (GetY() - WallImageDimension / 2) + (WallImageDimension * i),
                WallImageDimension + 1,
                WallImageDimension);
    }
}

void Wall::XmlLoad(wxXmlNode* node)
{
    Item::XmlLoad(node);

    node->GetAttribute(L"width", L"32").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"32").ToDouble(&mHeight);
}
