/**
 * @file AquariumApp.cpp
 * @author Jacob R. Stacy
 */

#include "AquariumApp.h"
#include "pch.h"
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