/**
 * @file AquariumView.h
 * @author Jacob R. Stacy
 *
 * Declaration of the AquariumView class.
 *
 */

#ifndef AQUARIUM_AQUARIUMVIEW_H
#define AQUARIUM_AQUARIUMVIEW_H

#include "Aquarium.h"

/**
 * View class for our aquarium
 */
class AquariumView : public wxWindow {
private:
    /// An object that describes our aquarium
    Aquarium  mAquarium;
    void OnPaint(wxPaintEvent& event);

    /// Any item we are currently dragging
    std::shared_ptr<Item> mGrabbedItem;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

public:
    void Initialize(wxFrame*);

    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishCarpFish(wxCommandEvent& event);
    void OnAddFishNemoFish(wxCommandEvent& event);

    void OnMouseMove(wxMouseEvent& event);

    void OnLeftUp(wxMouseEvent& event);

    void OnLeftDown(wxMouseEvent& event);

    void OnAddDecorCastleDecor(wxCommandEvent& event);

    void OnFileSaveAs(wxCommandEvent& event);

    void OnFileOpen(wxCommandEvent& event);

    void OnTimer(wxTimerEvent& event);
};

#endif //AQUARIUM_AQUARIUMVIEW_H
