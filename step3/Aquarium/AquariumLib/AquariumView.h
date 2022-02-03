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

public:
    void Initialize(wxFrame*);

    void OnAddFishBetaFish(wxCommandEvent& event);
    void OnAddFishCarpFish(wxCommandEvent& event);
    void OnAddFishNemoFish(wxCommandEvent& event);
    void OnAddFishMosquitoFish(wxCommandEvent& event);

    void OnMouseMove(wxMouseEvent& event);

    void OnLeftUp(wxMouseEvent& event);

    void OnLeftDown(wxMouseEvent& event);

};

#endif //AQUARIUM_AQUARIUMVIEW_H
