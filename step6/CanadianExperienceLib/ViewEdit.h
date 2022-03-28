/**
 * @file ViewEdit.h
 * @author Charles B. Owen
 * @author Jacob R. Stacy
 *
 * Basic edit view class for the Canadian Experience
 *
 * The window is a child of the main frame, which holds this
 * window, the menu bar, and the status bar.
 */

#ifndef CANADIANEXPERIENCE_VIEWEDIT_H
#define CANADIANEXPERIENCE_VIEWEDIT_H

#include "PictureObserver.h"

/**
 * Basic edit view class for the Canadian Experience
 */
class ViewEdit final : public wxScrolledCanvas, public PictureObserver {
private:
    void OnLeftDown(wxMouseEvent &event);
    void OnLeftUp(wxMouseEvent& event);
    void OnMouseMove(wxMouseEvent& event);
    void OnPaint(wxPaintEvent& event);

public:
    ViewEdit(wxFrame* parent);

    void UpdateObserver() override;
};

#endif //CANADIANEXPERIENCE_VIEWEDIT_H
