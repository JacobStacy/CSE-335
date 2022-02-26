/**
 * @file MainFrame.cpp
 * @author John Landers
 *
 * The implementation for the top level frame of the game application
 */

#include "pch.h"
#include "MainFrame.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include "ids.h"

/**
 * Initialization for the the main frame of the game
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Sparty Gnome Game", wxDefaultPosition, wxSize(1000, 800));

    // Create a sizer that will lay out child windows vertically, one above each other
    auto sizer = new wxBoxSizer(wxVERTICAL);

    // Create the view class object as a child of MainFrame
    auto gameView = new GameView();
    gameView->Initialize(this);

    // Add it to the sizer
    sizer->Add(gameView, 1, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer(sizer);

    // Layout (place) the child windows
    Layout();
}