/**
 * @file MainFrame.h
 * @author Charles B. Owen
 * @author Jacob R. Stacy
 *
 * The top-level (main) frame of the application
 */
#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_

class ViewEdit;
class ViewTimeline;

/**
 * The top-level (main) frame of the application
 */
class MainFrame : public wxFrame
{
private:

    /// View class for our edit window
    ViewEdit *mViewEdit = nullptr;

    /// View class for the timeline
    ViewTimeline *mViewTimeline = nullptr;


public:
    MainFrame();
    void Initialize();

    void OnExit(wxCommandEvent& event);

    void OnAbout(wxCommandEvent& event);
};

#endif //_MAINFRAME_H_
