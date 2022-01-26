/**
 * @file AquariumApp.h
 * @author Jacob R. Stacy
 *
 * Declaration of AquariumApp *
 */

#ifndef AQUARIUM_AQUARIUMAPP_H
#define AQUARIUM_AQUARIUMAPP_H

#include <wx/wx.h>

/**
 * Main Application class
 */

class AquariumApp : public wxApp {
private:

public:
    bool OnInit() override;

};

#endif //AQUARIUM_AQUARIUMAPP_H
