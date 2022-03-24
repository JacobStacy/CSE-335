/**
 * @file GameApp.cpp
 * @author matty
 *
 * Implementation of the GameApp Class
 */

#include "pch.h"
#include "GameApp.h"
#include <MainFrame.h>
/**
 * Game initializer
 * @return Whether the game was initialized or not
 */
bool GameApp::OnInit()
{
    if(!wxApp::OnInit())
    {
        return false;
    }

    // Add image type handlers
    wxInitAllImageHandlers();

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}
