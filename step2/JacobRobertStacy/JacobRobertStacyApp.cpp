/**
 * @file JacobRobertStacyApp.cpp
 * @author Jacob R. Stacy
 */

#include "JacobRobertStacyApp.h"
#include "pch.h"
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