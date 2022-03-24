/**
 * @file Scoreboard.h
 * @author Jacob Stacy
 * Class declaration for the Scoreboard Item
 */

#ifndef PROJECT1_SCOREBOARD_H
#define PROJECT1_SCOREBOARD_H

#include "Item.h"

/**
 * Class for the Scoreboard Item
 */
class Scoreboard : public Item {
private:
    /// The game this item is contained in
    Game *mGame;

    /// Score on the score board
    int mScore = 0;


protected:
    /**
     * Gets scoreboard width to be used with collision
     * @return width of the scoreboard
     */
    double GetWidth() override { return 0; }

    /**
     * Gets scoreboard height to be used with collision
     * @return height of the scoreboard
     */
    double GetHeight() override { return 0; }

public:
    Scoreboard(Game* game);

    /// Default constructor (disabled)
    Scoreboard() = delete;

    /// Copy constructor (disabled)
    Scoreboard(const Scoreboard &) = delete;

    /// Assignment operator
    void operator=(const Scoreboard &) = delete;

    void Draw(wxGraphicsContext *gc) override;

    /**
     * Resets scoreboard
     */
    void ResetScore() { mScore = 0; }

    /**
     * Adds money value to scoreboard
     * @param inScore
     */
    void AddScore(int inScore) { mScore += (inScore / 2); }

};

#endif //PROJECT1_SCOREBOARD_H
