/**
 * @file ViewTimeline.h
 * @author Charles B. Owen
 * @author Jacob R. Stacy
 *
 * View class for the timeline area of the screen.
 */

#ifndef CANADIANEXPERIENCE_VIEWTIMELINE_H
#define CANADIANEXPERIENCE_VIEWTIMELINE_H

#include "PictureObserver.h"

/**
 * View class for the timeline area of the screen.
 */
class ViewTimeline final : public wxScrolledCanvas, public PictureObserver {
private:

    /// Bitmap image for the pointer
    std::unique_ptr<wxImage> mPointerImage;

    /// Graphics bitmap to display
    wxGraphicsBitmap mPointerBitmap;

    /// Flag to indicate we are moving the pointer
    bool mMovingPointer = false;

    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

public:

    ViewTimeline(wxFrame* parent, std::wstring imagesDir);

    void UpdateObserver() override;

    void OnEditTimelineProperties(wxCommandEvent& event);

    void OnSetKeyframe(wxCommandEvent& event);

    void OnDeleteKeyframe(wxCommandEvent& event);
};


#endif //CANADIANEXPERIENCE_VIEWTIMELINE_H
