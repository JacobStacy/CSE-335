/**
 * @file MainFrame.cpp
 * @author Jacob Stacy
 */

#include "pch.h"
#include "MainFrame.h"
#include "JacobRobertStacyView.h"
#include "LeftView.h"

/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    Create(nullptr, wxID_ANY, L"Jacob Robert Stacy", wxDefaultPosition,  wxSize( 1000,600 ));

    // Create a sizer that will lay out child windows vertically
    // one above each other
    auto sizer = new wxBoxSizer( wxHORIZONTAL );

    // Create the view class object as a child of MainFrame
    auto jacobRobertStacyView = new JacobRobertStacyView();
    jacobRobertStacyView->Initialize(this);

    // Create the view class object as a child of MainFrame
    auto leftView = new LeftView();
    leftView->Initialize(this);

    // Add it to the sizer
    sizer->Add(leftView,1, wxEXPAND | wxALL);
    sizer->Add(jacobRobertStacyView,3, wxEXPAND | wxALL);

    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();
}
