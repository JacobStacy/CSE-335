/**
 * @file AquariumView.h
 * @author Jacob R. Stacy
 *
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
public:
    void Initialize(wxFrame*);
};

#endif //AQUARIUM_AQUARIUMVIEW_H
