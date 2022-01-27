/**
 * @file AquariumView.cpp
 * @author Jacob Stacy
 */

#include "AquariumView.h"
#include "pch.h"


/**
 * Initialize the aquarium view class.
 * @param parent The parent window for this class
 */
void AquariumView::Initialize(wxFrame* parent)
{
    Create(parent, wxID_ANY);
    SetBackgroundColour(*wxWHITE);

}
