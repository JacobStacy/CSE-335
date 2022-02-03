/**
 * @file JacobRobertStacyApp.cpp
 * @author Jacob R. Stacy
 */

#include "pch.h"
#include "JacobRobertStacyApp.h"
#include "JacobRobertStacyLib/MainFrame.h"


/**
 * Initialize the application.
 * @return
 */
bool JacobRobertStacyApp::OnInit()
{
    if (!wxApp::OnInit())
        return false;

    auto frame = new MainFrame();
    frame->Initialize();
    frame->Show(true);

    return true;
}