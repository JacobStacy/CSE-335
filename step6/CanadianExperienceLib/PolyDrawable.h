/**
 * @file PolyDrawable.h
 * @author Jacob R. Stacy
 *
 *  Class for Polygon Drawable
 *
 */

#ifndef CANADIANEXPERIENCE_POLYDRAWABLE_H
#define CANADIANEXPERIENCE_POLYDRAWABLE_H

#include "Drawable.h"

/**
 * A drawable based on polygon images.
 *
 * This class has a list of points and draws a polygon
 * drawable based on those points.
 */
class PolyDrawable : public Drawable{
private:

    /// The polygon color
    wxColour mColor = *wxBLACK;

    /// All points
    std::vector<wxPoint> mPoints;

    /// Graphics Path
    wxGraphicsPath mPath;

public:

    PolyDrawable(const std::wstring& name);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    bool HitTest(wxPoint pos) override;

    void AddPoint(wxPoint point);

    /**
     * Set the color of the PolyDrawable
     * @param color New color
     */
    void SetColor(wxColour color) {mColor = color; }

    /**
     * Get the color of the Poly Drawable
     * @return The color
     */
    wxColour GetColor() { return mColor; }

};

#endif //CANADIANEXPERIENCE_POLYDRAWABLE_H
