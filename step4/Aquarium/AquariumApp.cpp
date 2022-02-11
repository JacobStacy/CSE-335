/**
 * @file AquariumApp.cpp
 * @author Jacob R. Stacy
 */

#include "pch.h"
#include "AquariumApp.h"
#include "AquariumLib/MainFrame.h"


/**
 * Initialize the application.
 * @return
 */
bool AquariumApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}