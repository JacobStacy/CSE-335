/**
 * @file Platform.cpp
 * @author Jacob Stacy
 * Implementation of the Platform Class
 */

#include "pch.h"
#include "Item.h"
#include "Platform.h"

using namespace std;

/// Width of the platform images
const double PlatformImageWidth = 32;

/// Height of the platform images
const double PlatformImageHeight = 32;

/**
 * Constructor
 * @param game The game we are in
 * @param leftBitmap Bitmap for the bitmap we use for the left
 * @param centerBitmap Bitmap for the bitmap we use for the center
 * @param rightBitmap Bitmap for the bitmap we use for the right
 * @param height Actual height of the the platform
 * @param width Actual width of the platform
 */
Platform::Platform(Game* game,
        const std::shared_ptr<wxBitmap> leftBitmap,
        const std::shared_ptr<wxBitmap> centerBitmap,
        const std::shared_ptr<wxBitmap> rightBitmap,
        const int width,
        const int height) : Item(game, centerBitmap)
{

    mLeftBitmap = leftBitmap;

    mCenterBitmap = centerBitmap;

    mRightBitmap = rightBitmap;


    mWidth = width;
    mHeight = height;
}

/**
 * Draws the platform to the screen
 * @param gc Graphic Context the platform is drawn with
 */
void Platform::Draw(wxGraphicsContext* gc)
{
    int numberOfCenter = (mWidth - (PlatformImageWidth * 2)) / 32;

    if (numberOfCenter % 2 == 0)
    {
        int i = 0;
        for (; i < numberOfCenter / 2; i++)
        {
            // Left
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() - (PlatformImageWidth ) - (PlatformImageWidth * i),
                    GetY() - PlatformImageHeight / 2,
                    PlatformImageWidth + 1,
                    PlatformImageHeight);

            // Right
            gc->DrawBitmap(*mCenterBitmap,
                    GetX() + (PlatformImageWidth * i),
                    GetY() - PlatformImageHeight / 2,
                    PlatformImageWidth + 1,
                    PlatformImageHeight);

        }
        // Left
        gc->DrawBitmap(*mLeftBitmap,
                GetX() - (PlatformImageWidth ) - (PlatformImageWidth * i),
                GetY() - PlatformImageHeight / 2,
                PlatformImageWidth + 1,
                PlatformImageHeight);

        // Right
        gc->DrawBitmap(*mRightBitmap,
                GetX() + (PlatformImageWidth * i),
                GetY() - PlatformImageHeight / 2,
                PlatformImageWidth + 1,
                PlatformImageHeight);

    }
    else
    {
        gc->DrawBitmap(*mCenterBitmap,
                GetX() - (PlatformImageWidth / 2),
                GetY() - PlatformImageHeight / 2,
                PlatformImageWidth + 1,
                PlatformImageHeight);

        numberOfCenter--;

        int i = 0;
        for (; i <= numberOfCenter / 2; i++)
        {
            // Left
            gc->DrawBitmap(*mCenterBitmap,
                    (GetX() + PlatformImageWidth / 2) - (PlatformImageWidth ) - (PlatformImageWidth * i),
                    GetY() - PlatformImageHeight / 2,
                    PlatformImageWidth + 1,
                    PlatformImageHeight);

            // Right
            gc->DrawBitmap(*mCenterBitmap,
                    (GetX() - PlatformImageWidth / 2) + (PlatformImageWidth * i),
                    GetY() - PlatformImageHeight / 2,
                    PlatformImageWidth + 1,
                    PlatformImageHeight);

        }

        // Left
        gc->DrawBitmap(*mLeftBitmap,
                (GetX() + PlatformImageWidth / 2) - (PlatformImageWidth ) - (PlatformImageWidth * i),
                GetY() - PlatformImageHeight / 2,
                PlatformImageWidth + 1,
                PlatformImageHeight);

        // Right
        gc->DrawBitmap(*mRightBitmap,
                (GetX() - PlatformImageWidth / 2) + (PlatformImageWidth * i),
                GetY() - PlatformImageHeight / 2,
                PlatformImageWidth + 1,
                PlatformImageHeight);
    }
}

/**
 * Loads platform with its corresponding width and height position
 * @param node The parent node
 */
void Platform::XmlLoad(wxXmlNode* node)
{
    Item::XmlLoad(node);

    node->GetAttribute(L"width", L"32").ToDouble(&mWidth);
    node->GetAttribute(L"height", L"32").ToDouble(&mHeight);
}
