/**
 * @file MainFrame.h
 * @author John Landers
 * The top level frame of the game application
 */

#ifndef PROJECT1_MAINFRAME_H
#define PROJECT1_MAINFRAME_H

#include "GameView.h"

/**
 * The top level frame of the game application
 */
class MainFrame : public wxFrame {
private:
    void OnExit(wxCommandEvent& event);
    void About(wxCommandEvent& event);
    void OnClose(wxCloseEvent& event);

    /**
     * Constructor
     */
    GameView* mGameView;

public:
    void Initialize();
};

#endif //PROJECT1_MAINFRAME_H
