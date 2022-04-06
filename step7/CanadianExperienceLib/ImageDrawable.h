/**
 * @file ImageDrawable.h
 * @author Jacob Stacy
 *
 *  Header file for ImageDrawable
 *
 */

#ifndef CANADIANEXPERIENCE_IMAGEDRAWABLE_H
#define CANADIANEXPERIENCE_IMAGEDRAWABLE_H

#include "Drawable.h"

/**
 * The class for Drawables that are made up of images
 */
class ImageDrawable : public Drawable {
private:

    /// The center of the image
    wxPoint mCenter = wxPoint(0, 0);

protected:

    /// The image we are drawing
    std::unique_ptr<wxImage> mImage;

    /// The graphics bitmap we will use
    wxGraphicsBitmap mBitmap;

public:

    ImageDrawable(const std::wstring &name, const std::wstring &filename);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    /**
     * Set the drawable center
     * @param pos The new drawable center
     */
    void SetCenter(wxPoint pos) { mCenter = pos; }

    /**
     * Get the drawable center
     * @return The drawable center
     */
    wxPoint GetCenter() const { return mCenter; }
    
    
};

#endif //CANADIANEXPERIENCE_IMAGEDRAWABLE_H
