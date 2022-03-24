/**
 * @file Platform.h
 * @author Jacob Stacy
 * Class declaration for the Platform Item
 */

#ifndef PROJECT1_PLATFORM_H
#define PROJECT1_PLATFORM_H

#include "Item.h"

/**
 * Class for the Platform Item
 */
class Platform : public Item {
private:

    /// The underlying item Bitmap for the left side
    std::shared_ptr<wxBitmap>mLeftBitmap;

    /// The underlying item Bitmap for the center pieces
    std::shared_ptr<wxBitmap>mCenterBitmap;

    /// The underlying item Bitmap for the right side
    std::shared_ptr<wxBitmap>mRightBitmap;

    /// width of the platform
    double mWidth = 32;

    /// height of the platform
    double mHeight = 32;

protected:
    /**
     * Gets platform width to be used with collision
     * @return width of the platform
     */
    double GetWidth() override { return mWidth; }

    /**
     * Gets platform height to be used with collision
     * @return height of the platform
     */
    double GetHeight() override { return mHeight; }

public:
   
    Platform(Game* game,
            const std::shared_ptr<wxBitmap> leftBitmap,
            const std::shared_ptr<wxBitmap> centerBitmap,
            const std::shared_ptr<wxBitmap> rightBitmap,
            int width,
            int height);

    /// Default constructor (disabled)
    Platform() = delete;

    /// Copy constructor (disabled)
    Platform(const Platform &) = delete;

    /// Assignment operator
    void operator=(const Platform &) = delete;

    void Draw(wxGraphicsContext *gc) override;

    /**
     * Accept a visitor
     * @param visitor
     */
    void Accept(ItemVisitor* visitor) override {visitor->VisitPlatform(this);}

    void XmlLoad(wxXmlNode* node) override;
};

#endif //PROJECT1_PLATFORM_H
