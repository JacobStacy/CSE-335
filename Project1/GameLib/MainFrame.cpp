/**
 * @file MainFrame.cpp
 * @author John Landers
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
    mGameView = gameView;

    // Add it to the sizer
    sizer->Add(gameView, 1, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer(sizer);

    // Layout (place) the child windows
    Layout();

    // Create the menu bar.
    auto menuBar = new wxMenuBar( );

    auto fileMenu = new wxMenu();
    auto levelMenu = new wxMenu();
    auto helpMenu = new wxMenu();
    /// for testing objects
    auto testMenu = new wxMenu();

    menuBar->Append(fileMenu, L"&File" );
    menuBar->Append(levelMenu, L"&Level" );
    menuBar->Append(helpMenu, L"&Help" );
    ///testing objects, remove later
    menuBar->Append(testMenu, L"&Test Object");


    fileMenu->Append(wxID_EXIT, "E&xit\tAlt-X", "Quit the game");

    levelMenu->Append(IDM_LEVELZERO, L"&Level 0", L"&Switch to level 0");
    levelMenu->Append(IDM_LEVELONE, L"&Level 1", L"&Switch to level 1");
    levelMenu->Append(IDM_LEVELTWO, L"&Level 2", L"&Switch to level 2");
    levelMenu->Append(IDM_LEVELTHREE, L"&Level 3", L"&Switch to level 3");

    helpMenu->Append(wxID_ABOUT, "&About\tF1", "About this game");

    testMenu->Append(IDM_ADDGNOME, "Gnome", L"Test Gnome Object");
    testMenu->Append(IDM_ADDPLATFORM, "Platform", L"Test Gnome Object");
    testMenu->Append(IDM_ADDVILLAIN, "Villain", L"Test Villain Object");

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::About, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);

    SetMenuBar( menuBar );
    CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );
}

/**
 * Exit menu option handlers
 * @param event Event from exiting on the menu
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}

/**
 * About menu option handlers
 * @param event Event for About on the menu
 */
void MainFrame::About(wxCommandEvent& event)
{
    wxMessageBox(L"Welcome to the Sparty Gnome Game! Good luck!",
            L"About Sparty Gnome Game",
            wxOK,
            this);
}

/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mGameView->Stop();
    Destroy();
}
