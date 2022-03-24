/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 * @author Jacob Stacy
 */
#include "pch.h"

#include "MainFrame.h"

#include <wx/xrc/xmlres.h>

/// Directory within the resources that contains the images.
const std::wstring ImagesDirectory = L"/images";

/**
 * Constructor
 */
MainFrame::MainFrame()
{

}



/**
 * Initialize the MainFrame window.
 */
void MainFrame::Initialize()
{
    wxXmlResource::Get()->LoadFrame(this, nullptr, L"MainFrame");

#ifdef WIN32
    // This sets the frame icon on Windows systems
    SetIcon(wxIcon(L"mainframe", wxBITMAP_TYPE_ICO_RESOURCE));
#endif


}


