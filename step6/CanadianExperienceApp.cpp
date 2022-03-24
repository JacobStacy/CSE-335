/**
 * @file CanadianExperienceApp.cpp
 * @author Charles B. Owen
 */

#include "pch.h"

#include "CanadianExperienceApp.h"
#include "MainFrame.h"

/**
 * Initialize the application.
 * @return
 */
bool CanadianExperienceApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    // Add image type handlers
    wxInitAllImageHandlers();

    // Do not remove this line...
    wxSetWorkingDirectory(L"..");

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}
