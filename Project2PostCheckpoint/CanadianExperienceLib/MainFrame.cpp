/**
 * @file MainFrame.cpp
 * @author Charles B. Owen
 */
#include "pch.h"

#include <wx/xrc/xmlres.h>
#include <wx/stdpaths.h>
#include <laboratory-api.h>


#include "MainFrame.h"

#include "ViewEdit.h"
#include "ViewTimeline.h"
#include "Picture.h"
#include "PictureFactory.h"
#include "LaboratoryAdapter.h"

/// Directory within resources that contains the images.
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
    SetIcon(wxIcon(L"mainframe", wxBITMAP_TYPE_ICO_RESOURCE));
#endif

    auto sizer = new wxBoxSizer( wxVERTICAL );

    auto standardPaths = wxStandardPaths::Get();
    auto resourcesDir = standardPaths.GetResourcesDir().ToStdWstring();
    auto imagesDir = resourcesDir + ImagesDirectory;

    mViewEdit = new ViewEdit(this);
    mViewTimeline = new ViewTimeline(this, imagesDir);

    sizer->Add(mViewEdit,1, wxEXPAND | wxALL );
    sizer->Add(mViewTimeline, 0, wxEXPAND | wxALL);

    SetSizer( sizer );
    Layout();

    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_CLOSE_WINDOW, &MainFrame::OnClose, this);
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSetLaboratory, this, XRCID("SetLab"));
    Bind(wxEVT_COMMAND_MENU_SELECTED, &MainFrame::OnSetStartLabFrame, this, XRCID("SetLabStart"));




    // Create our picture
    PictureFactory factory;
    mPicture = factory.Create(resourcesDir);

    // Tell the views about the picture
    mViewEdit->SetPicture(mPicture);
    mViewTimeline->SetPicture(mPicture);
}



/**
 * Exit menu option handlers
 * @param event
 */
void MainFrame::OnExit(wxCommandEvent& event)
{
  Close(true);
}

/**
 * Application about box menu handler
 * @param event The menu command event
 */
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxDialog aboutDlg;
    wxXmlResource::Get()->LoadDialog(&aboutDlg, this, L"AboutDialog");
    aboutDlg.ShowModal();
}


/**
 * Handle a close event. Stop the animation and destroy this window.
 * @param event The Close event
 */
void MainFrame::OnClose(wxCloseEvent& event)
{
    mViewTimeline->Stop();
    Destroy();
}

void MainFrame::OnSetLaboratory(wxCommandEvent& event)
{
    if (mPicture->GetLaboratory()->GetDialog(this->GetParent()))
    {
        mPicture->UpdateObservers();
    }

    mPicture->GetTimeline()->SetLabNumber(mPicture->GetLaboratory()->GetLaboratoryNumber());
}

void MainFrame::OnSetStartLabFrame(wxCommandEvent& event)
{
    mPicture->GetLaboratory()->SetFrame(mPicture->GetTimeline()->GetCurrentFrame());
    mPicture->UpdateObservers();

    mPicture->GetTimeline()->SetLabStartFrame(mPicture->GetTimeline()->GetCurrentFrame());
}

