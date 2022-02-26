/**
 * @file GameView.h
 * @author John Landers
 *
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

    /// Object that describes the main game object
    Game mGame;
public:
    void Initialize(wxFrame* parent);
};

#endif //PROJECT1_GAMEVIEW_H
