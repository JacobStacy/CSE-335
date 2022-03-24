/**
 * @file GameView.h
 * @author John Landers
 * View class for the game
 */

#ifndef PROJECT1_GAMEVIEW_H
#define PROJECT1_GAMEVIEW_H

#include "Game.h"

/**
 * View class for the game
 */
class GameView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);

    void OnKeyDown(wxKeyEvent& event);

    void OnTimer(wxTimerEvent& event);

    void LoadLevelZero(wxCommandEvent& event);
    void LoadLevelOne(wxCommandEvent& event);
    void LoadLevelTwo(wxCommandEvent& event);
    void LoadLevelThree(wxCommandEvent& event);

    /// Object that describes the main game object
    Game mGame;

    /// The timer that allows for animation
    wxTimer mTimer;

    /// Stopwatch used to measure elapsed time
    wxStopWatch mStopWatch;

    /// The last stopwatch time
    long mTime = 0;

public:
    void Initialize(wxFrame* parent);

    void OnKeyUp(wxKeyEvent& event);

    /**
     * Stop the timer so the window can close
     */
    void Stop() { mTimer.Stop(); }

};

#endif //PROJECT1_GAMEVIEW_H
