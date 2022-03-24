/**
 * @file Game.h
 * @author Aref Zeitoun, John Landers, Jacob Stacy, Kurt LaBlanc
 * Declaration of the Game class.
 */

#ifndef PROJECT1_GAME_H
#define PROJECT1_GAME_H

#include "Item.h"
#include "Level.h"
#include "ItemVisitor.h"
#include "SpartyGnome.h"
#include "Scoreboard.h"
#include "Clock.h"

#include <memory>
#include <random>
#include <string>
#include <list>
#include <map>
#include <chrono>
#include <thread>



/**
 * Class declaration for the Game Class
 */
class Game {
private:
    /// Used to parse XML
    void XmlItem(wxXmlNode *node);

    /// Gnome player
    std::shared_ptr<SpartyGnome> mGnome;

    /// Map used for collecting id's
    std::map<std::string, std::vector<std::shared_ptr<wxBitmap>>> mMap;

    /// Scoreboard for game
    std::shared_ptr<Scoreboard> mScoreboard;

    /// Clock for game time
    std::unique_ptr<Clock> mClock;

    /// Whether the game is running or not
    bool mPause = true;

    /// Level currently being displayed
    wxString mCurrentLevel;

    /// Vector Of Levels in order
    std::vector<wxString> mOrderedLevels;

    /// Map of Levels
    std::map<wxString, Level> mLevels;

    /// The amount tuition is multiplied by
    double mTuitionRate = 1;

    /// Boolean if begin message needs to appear on screen or not.
    bool mBeginTF = true;

    ///True of False if lose message needs to repair
    bool mRestartTF = false;

public:
    void OnDraw(wxGraphicsContext* graphics, int width, int height);

    /// constructor
    Game();

    /**
     * Adds items to game
     * @param item
     */
    void Add(std::shared_ptr<Item> item);

    void OnKeyDown(wxKeyEvent& event);

    void Update(double elapsed);

    void Accept(ItemVisitor* visitor);

    void Load(const wxString &filename);

    void OnKeyUp(wxKeyEvent& event);

    std::shared_ptr<Item> CollisionTest(Item *item);

    /**
     * Adds money to scoreboard
     * @param inMoney
     */
    void AddMoney(int inMoney) { mScoreboard->AddScore(inMoney); }

    void SetLevel(const wxString& level);

    void NextLevel();

    void Restart();

    void IncreaseSpeed();

    /**
     * Increases tuition rate by 1%
     */
    void UpTuition () { mTuitionRate = mTuitionRate + .1;}

    /**
     * Getter for tuition rate
     * @return mTuitionRate
     */
    double GetTuition () { return mTuitionRate; }

    /**
     * Pause the game
     * @param pause
     */
    void Pause(bool pause) { mPause = pause; }

    /**
     * Get the pause status for the game
     * @return true if game is paused
     */
    bool GetPause() { return mPause; }
};

#endif //PROJECT1_GAME_H
