/**
 * @file Clock.h
 * @author Jacob Stacy
 * Class declaration for the Clock Item
 */

#ifndef PROJECT1_CLOCK_H
#define PROJECT1_CLOCK_H

#include "Item.h"

/**
 * Class for the Clock Item
 */
class Clock : public Item {
private:
    /// The game this item is contained in
    Game *mGame;

    /// Score on the score board in seconds
    double mTime = 0;


protected:
    /**
     * Gets clock width to be used with collision
     * @return width of the clock
     */
    double GetWidth() override { return 0; }

    /**
     * Gets clock height to be used with collision
     * @return height of the clock
     */
    double GetHeight() override { return 0; }

public:
    Clock(Game* game);

    /// Default constructor (disabled)
    Clock() = delete;

    /// Copy constructor (disabled)
    Clock(const Clock &) = delete;

    /// Assignment operator
    void operator=(const Clock &) = delete;


    void Draw(wxGraphicsContext *gc) override;

    /// Updates clock with time elapsed
    void Update(double elapsed) override;

    /// Resets clock to 0
    void ResetClock() { mTime = 0; }
};

#endif //PROJECT1_CLOCK_H
