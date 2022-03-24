/**
 * @file Game.cpp
 * @author Aref Zeitoun, John Landers, Kurt LaBlanc, Matt Wright, Jacob Stacy
 */
#include "pch.h"
#include "Game.h"
#include "Food.h"
#include "Money.h"
#include "Platform.h"
#include "ItemBackground.h"
#include "Stanley.h"
#include "Scoreboard.h"
#include "Villain.h"
#include "Wall.h"
#include "Door.h"
#include <chrono>
#include <thread>

#include <wx/graphics.h>
#include <vector>

using namespace std;

/// Initial Gnome X location
const int InitialX = 300;

/// Initial Gnome Y location
const int InitialY = 900;

/// Game area height in virtual pixels
const static int VirtualHeight = 1024;

/// Horizontal character speed in pixels per second
double HorizontalSpeed = 500.00;

///Vertical character speed in pixels per second
const double JumpSpeed = -800;

/// Offset for score
const double ScoreOffset = 10;
/// Offset for score
const double ClockOffset = 10;


/// SpartyGnome's Neutral Image
const wstring SpartyGnomeNeutral = L"images/gnome.png";

/// SpartyGnome's LeftOne Image
const wstring SpartyGnomeLeftOne = L"images/gnome-walk-left-1.png";

/// SpartyGnome's LeftTwo Image
const wstring SpartyGnomeLeftTwo = L"images/gnome-walk-left-2.png";

/// SpartyGnome's RightOne Image
const wstring SpartyGnomeRightOne = L"images/gnome-walk-right-1.png";

/// SpartyGnome's RightTwo Image
const wstring SpartyGnomeRightTwo = L"images/gnome-walk-right-2.png";

/// Level 0
const wxString Level0 = L"levels/level0.xml";

/// Level 1
const wxString Level1 = L"levels/level1.xml";

/// Level 2
const wxString Level2 = L"levels/level2.xml";

/// Level 3
const wxString Level3 = L"levels/level3.xml";

/**
 * Game Constructor
 */
Game::Game()
{

    shared_ptr<wxImage> mItemImage = make_shared<wxImage>(SpartyGnomeNeutral, wxBITMAP_TYPE_ANY);
    shared_ptr<wxBitmap> mItemBitmap = make_shared<wxBitmap>(*mItemImage);

    shared_ptr<wxImage> mItemImage2 = make_shared<wxImage>(SpartyGnomeLeftOne, wxBITMAP_TYPE_ANY);
    shared_ptr<wxBitmap> mItemBitmap2 = make_shared<wxBitmap>(*mItemImage2);

    shared_ptr<wxImage> mItemImage3 = make_shared<wxImage>(SpartyGnomeLeftTwo, wxBITMAP_TYPE_ANY);
    shared_ptr<wxBitmap> mItemBitmap3 = make_shared<wxBitmap>(*mItemImage3);

    shared_ptr<wxImage> mItemImage4 = make_shared<wxImage>(SpartyGnomeRightOne, wxBITMAP_TYPE_ANY);
    shared_ptr<wxBitmap> mItemBitmap4 = make_shared<wxBitmap>(*mItemImage4);

    shared_ptr<wxImage> mItemImage5 = make_shared<wxImage>(SpartyGnomeRightTwo, wxBITMAP_TYPE_ANY);
    shared_ptr<wxBitmap> mItemBitmap5 = make_shared<wxBitmap>(*mItemImage5);

    mGnome = std::make_shared<SpartyGnome>(this, mItemBitmap, mItemBitmap2, mItemBitmap3, mItemBitmap4, mItemBitmap5);

    mScoreboard = make_shared<Scoreboard>(this);
    mClock = make_unique<Clock>(this);

    mOrderedLevels.push_back(Level0);
    mOrderedLevels.push_back(Level1);
    mOrderedLevels.push_back(Level2);
    mOrderedLevels.push_back(Level3);

    for (const auto& level : mOrderedLevels)
    {
        Load(level);
    }

    SetLevel(Level1);

}

/**
 * Draw the game area
 * @param graphics The wxWidgets graphics context on which to draw
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(wxGraphicsContext* graphics, int width, int height)
{
    // Automatic Scaling
    auto mScale = double(height) / double(VirtualHeight);
    graphics->Scale(mScale, mScale);


    auto virtualWidth = (double)width/mScale;
    graphics->PushState();

    // Compute the amount to scroll in the X dimension
    auto xOffset = (double)-mGnome->GetX() + virtualWidth / 2.0f;
    graphics->Translate(xOffset, 0);

    // Draws the scrolling game items
    for(const auto& item: mLevels[mCurrentLevel].GetItems())
    {
        item->Draw(graphics);
    }
    mGnome->Draw(graphics);
    graphics->PopState();

    mScoreboard->SetLocation(virtualWidth - ScoreOffset, ScoreOffset);
    mClock->SetLocation(ClockOffset, ScoreOffset);

    // Draws the scrolling game items
    mScoreboard->Draw(graphics);
    mClock->Draw(graphics);

    if (mBeginTF && mPause)//!mRestartTF)
    {
        wxFont font(wxSize(0, 100),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
        // Draw begin text
        graphics->SetFont(font, *wxBLUE);
        auto level = find(mOrderedLevels.begin(), mOrderedLevels.end(), mCurrentLevel);
        int current = level - mOrderedLevels.begin();
        auto beginText = L"Level " + to_string(current) + " Begin";
        graphics->DrawText(beginText, virtualWidth/4, VirtualHeight/2);

        //SetLevel(mCurrentLevel);
        //Load(mCurrentLevel);
        this_thread::sleep_for(chrono::milliseconds(1000));

        mBeginTF = false;
        SetLevel(mCurrentLevel);
        Load(mCurrentLevel);
        Pause(false);
    }

    if (mRestartTF && mPause)
    {
        wxFont font(wxSize(0, 100),
                wxFONTFAMILY_SWISS,
                wxFONTSTYLE_NORMAL,
                wxFONTWEIGHT_NORMAL);
        // Draw restart text
        graphics->SetFont(font, *wxBLUE);
        graphics->DrawText(L"You Lose!", virtualWidth/4, VirtualHeight/2);
        mRestartTF = false;
        this_thread::sleep_for(chrono::milliseconds(1000));

        mBeginTF = true;

    }
}

/**
 * Add an item to the game
 */
void Game::Add(std::shared_ptr<Item> item)
{
    item->SetLocation(InitialX, InitialY);
    mLevels[mCurrentLevel].Add(item);
}


/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
    if (!mPause) {
        for (auto item: mLevels[mCurrentLevel].GetItems()) {
            item->Update(elapsed);
        }
        mClock->Update(elapsed);
        mGnome->Update(elapsed);
    }
}

/**
 * Accept a visitor into
 * @param visitor
 */
void Game::Accept(ItemVisitor* visitor)
{
    for (auto item : mLevels[mCurrentLevel].GetItems())
    {
        item->Accept(visitor);
    }
}

/**
 * Load the game from the .game XML file
 * Opens the XML file and reads the nodes, creating items as appropriate.
 * @param filename The filename of the file to load the game from.
 */
void Game::Load(const wxString &filename)
{
    mCurrentLevel = filename;
    mLevels[filename] = Level();
    mScoreboard->ResetScore();
    mClock->ResetClock();

    wxXmlDocument xmlDoc;
    if(!xmlDoc.Load(filename))
    {
        wxMessageBox(L"Unable to load Game file");
        return;
    }


    // Get the XML document root node
    auto root = xmlDoc.GetRoot();

    // Gets Sparty's start location
    double startX;
    root->GetAttribute("start-x").ToDouble(&startX);
    double startY;
    root->GetAttribute("start-y").ToDouble(&startY);

    mLevels[mCurrentLevel].SetStart(startX, startY);

    //
    // Traverse the children of the root
    // node of the XML document in memory!!!!
    //
    auto child = root->GetChildren();


    // Temporary list for creating the map
    vector<shared_ptr<wxBitmap>> tempList;

    // We have an item. Which node?
    auto children = child->GetChildren();

    //First does the declarations to add items to a map
    while(child->GetName() == "declarations")
    {
        auto attributes = children->GetAttributes();

        //Check to see if next is null
        if (children->GetNext() == nullptr)
        {
            //if so, go to next node (tag)
            child = child->GetNext();
        }

        //background 1
        if (attributes->GetValue() == L"i001")
        {
            if (mMap.find("i001") == mMap.end())
            {
                auto image = make_unique<wxImage>("images/backgroundForest.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i001"] = tempList;
                tempList.clear();
            }
        }
        //background 2
        if (attributes->GetValue() == L"i002")
        {
            if (mMap.find("i002") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/backgroundColorGrass.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i002"] = tempList;
                tempList.clear();
            }
        }
        //Grass platform
        if (attributes->GetValue() == L"i003")
        {
            if (mMap.find("i003") == mMap.end())
            {

                auto image = make_shared<wxImage>("images/grassLeft.png", wxBITMAP_TYPE_ANY);
                auto image2 = make_shared<wxImage>("images/grassMid.png", wxBITMAP_TYPE_ANY);
                auto image3 = make_shared<wxImage>("images/grassRight.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                tempList.push_back(make_unique<wxBitmap>(*image2));
                tempList.push_back(make_unique<wxBitmap>(*image3));
                mMap["i003"] = tempList;
                tempList.clear();
            }
        }
        //Snow Platform
        if (attributes->GetValue() == L"i004")
        {
            if (mMap.find("i004") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/snowLeft.png", wxBITMAP_TYPE_ANY);
                auto image2 = make_shared<wxImage>("images/snowMid.png", wxBITMAP_TYPE_ANY);
                auto image3 = make_shared<wxImage>("images/snowRight.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                tempList.push_back(make_unique<wxBitmap>(*image2));
                tempList.push_back(make_unique<wxBitmap>(*image3));
                mMap["i004"] = tempList;
                tempList.clear();
            }
        }
        //Industrial Platform
        if (attributes->GetValue() == L"i005")
        {
            if (mMap.find("i005") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/platformIndustrial_059.png", wxBITMAP_TYPE_ANY);
                auto image2 = make_shared<wxImage>("images/platformIndustrial_060.png", wxBITMAP_TYPE_ANY);
                auto image3 = make_shared<wxImage>("images/platformIndustrial_061.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                tempList.push_back(make_unique<wxBitmap>(*image2));
                tempList.push_back(make_unique<wxBitmap>(*image3));
                mMap["i005"] = tempList;
                tempList.clear();
            }
        }
        //Wall1
        if (attributes->GetValue() == L"i006")
        {
            if (mMap.find("i006") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/wall1.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i006"] = tempList;
                tempList.clear();
            }
        }
        //Wall2
        if (attributes->GetValue() == L"i007")
        {
            if (mMap.find("i007") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/wall2.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i007"] = tempList;
                tempList.clear();
            }
        }
        //Schmoney 100
        if (attributes->GetValue() == L"i008")
        {
            if (mMap.find("i008") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/money100.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i008"] = tempList;
                tempList.clear();
            }
        }
        //Schmoney 1000
        if (attributes->GetValue() == L"i009")
        {
            if (mMap.find("i009") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/money1000.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i009"] = tempList;
                tempList.clear();
            }
        }
        //Stanley
        if (attributes->GetValue() == L"i010")
        {
            if (mMap.find("i010") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/stanley.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i010"] = tempList;
                tempList.clear();
            }
        }
        //Door
        if (attributes->GetValue() == L"i011")
        {
            if (mMap.find("i011") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/door.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i011"] = tempList;
                tempList.clear();
            }
        }
        //UofM Villian
        if (attributes->GetValue() == L"i012")
        {
            if (mMap.find("i012") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/UofM.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i012"] = tempList;
                tempList.clear();
            }
        }
        //Wisconsin Villain
        if (attributes->GetValue() == L"i013")
        {
            if (mMap.find("i013") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/wisc.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i013"] = tempList;
                tempList.clear();
            }
        }
        //Food item
        if (attributes->GetValue() == L"i014")
        {
            if(mMap.find("i014") == mMap.end())
            {
                auto image = make_shared<wxImage>("images/food.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i014"] = tempList;
                tempList.clear();
            }
        }
        //background 3
        if (attributes->GetValue() == L"i015") {
            if (mMap.find("i015")==mMap.end()) {
                auto image = make_unique<wxImage>("images/backgroundColorDesert.png", wxBITMAP_TYPE_ANY);
                tempList.push_back(make_unique<wxBitmap>(*image));
                mMap["i015"] = tempList;
                tempList.clear();
            }
        }
        //Go to next child in tree
        children = children->GetNext();
    }
    for( ; child; child=child->GetNext())
    {
        XmlItem(child);
    }

}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Game::XmlItem(wxXmlNode *node)
{

    // A pointer for the item we are loading
    shared_ptr<Item> item;

    // We have an item. Which node?
    auto children = node->GetChildren();

    //This traverses the items tags for location
    while (node->GetName() == "items")
    {
        auto attributes = children->GetAttributes();
        if (attributes->GetValue() == L"i001")
        {
            item = make_shared<ItemBackground>(this, mMap["i001"][0]);
        }
        else if(attributes->GetValue() == L"i002")
        {
            item = make_shared<ItemBackground>(this, mMap["i002"][0]);
        }
        else if (attributes->GetValue() == L"i003")
        {
            const int width = wxAtoi(children->GetAttribute(L"x"));
            const int height = wxAtoi(children->GetAttribute(L"y"));
            item = make_shared<Platform>(this,
                    mMap["i003"][0],
                    mMap["i003"][1],
                    mMap["i003"][2],
                    width, height);
        }

        else if (attributes->GetValue() == L"i004")
        {
            const int width = wxAtoi(children->GetAttribute(L"x"));
            const int height = wxAtoi(children->GetAttribute(L"y"));
            item = make_shared<Platform>(this,
                    mMap["i004"][0],
                    mMap["i004"][1],
                    mMap["i004"][2],
                    width, height);
        }
        else if (attributes->GetValue() == L"i005")
        {
            const int width = wxAtoi(children->GetAttribute(L"x"));
            const int height = wxAtoi(children->GetAttribute(L"y"));
            item = make_shared<Platform>(this,
                    mMap["i005"][0],
                    mMap["i005"][1],
                    mMap["i005"][2],
                    width, height);
        }
        else if (attributes->GetValue() == L"i006")
        {
            const int width = wxAtoi(children->GetAttribute(L"x"));
            const int height = wxAtoi(children->GetAttribute(L"y"));
            item = make_shared<Wall>(this, mMap["i006"][0], width, height);

        }
        else if (attributes->GetValue() == L"i007")
        {
            const int width = wxAtoi(children->GetAttribute(L"x"));
            const int height = wxAtoi(children->GetAttribute(L"y"));
            item = make_shared<Wall>(this, mMap["i007"][0], width, height);
        }
        else if (attributes->GetValue() == L"i008")
        {
            item = make_shared<Money>(this, mMap["i008"][0], 100);
        }
        else if (attributes->GetValue() == L"i009")
        {
            item = make_shared<Money>(this, mMap["i009"][0], 1000);
        }
        else if (attributes->GetValue() == L"i010")
        {
            item = make_shared<Stanley>(this, mMap["i010"][0]);
        }
        else if (attributes->GetValue() == L"i011")
        {
            item = make_shared<Door>(this, mMap["i011"][0]);
        }
        else if (attributes->GetValue() == L"i012")
        {
            // create michigan wolverine villain
            item = make_shared<Villain>(this, mMap["i012"][0]);
        }
        else if (attributes->GetValue() == L"i013")
        {
            // create wisconsin badger villain
            item = make_shared<Villain>(this, mMap["i013"][0]);
        }
        else if(attributes->GetValue() == L"i014")
        {
            //create food item
            item = make_shared<Food>(this, mMap["i014"][0]);
        }

        else if(attributes->GetValue() == L"i015")
        {
            // desert background
            item = make_shared<ItemBackground>(this, mMap["i015"][0]);
        }

        if (item != nullptr)
        {
            Add(item);
            item->XmlLoad(children);
        }
        //check to see if next node is null
        if (children->GetNext() == nullptr)
        {
            //if so, we're done
            break;
        }
        children = children->GetNext();

    }
}

/**
 * Keyboard press event handler
 * @param event key event
 */
void Game::OnKeyDown(wxKeyEvent& event)
{
    switch(event.GetKeyCode())
    {
        case WXK_RIGHT:
            mGnome->GetV()->SetX(HorizontalSpeed);
            break;
        case WXK_LEFT:
            mGnome->GetV()->SetX(-HorizontalSpeed);
            //left arrow pressed
            break;
        case WXK_SPACE:
            mGnome->Jump(JumpSpeed);
            //space bar pressed
            break;
    }
}


/**
 * On key up event handler
 * @param event
 */
void Game::OnKeyUp(wxKeyEvent& event)
{
    switch (event.GetKeyCode())
    {
        case WXK_RIGHT:
        case WXK_LEFT:
            mGnome->GetV()->SetX(0);
            break;
    }
}

/**
 * collision test for game
 * @param itemIn Item being checked
 * @return item collied with
 */
shared_ptr<Item> Game::CollisionTest(Item * itemIn)
{

    for (auto item : mLevels[mCurrentLevel].GetItems())
    {
        if (item->CollisionTest(itemIn))
        {
            return item;
        }
    }
    return nullptr;

}

/**
 * Sets the current level
 * @param level level being set to
 */
void Game::SetLevel(const wxString& level)
{
    //Level begin text
    //mBeginTF = true;
    mCurrentLevel = level;

    mGnome->SetLocation(mLevels[mCurrentLevel].GetStartX(), mLevels[mCurrentLevel].GetStartY());

    HorizontalSpeed = 500.00;
    //change to 2000
    //this_thread::sleep_for(chrono::milliseconds(200));
    //remove begin text
    //Pause(false);

    mScoreboard->ResetScore();
    mClock->ResetClock();
    //mBeginTF = false;
    //Pause(false);
}

/**
 * Changes to the next level
 */
void Game::NextLevel()
{
    auto iter = find(mOrderedLevels.begin(), mOrderedLevels.end(), mCurrentLevel);

    int current = iter - mOrderedLevels.begin();

    if (current < mOrderedLevels.size() - 1)
    {
        SetLevel(mOrderedLevels[current + 1]);
    }
    else
    {
        SetLevel(mOrderedLevels[current]);
    }
}

/**
 * Function restarts the level if Gnome falls or comes in contact with Villain
 */
void Game::Restart()
{
    if (!mPause) {
        mRestartTF = true;
        mGnome->CanMove(false);
        Pause(true);
        // You Lose text
        // Pause for 2 seconds (edit 200 to 2000)
        //this_thread::sleep_for(chrono::milliseconds(200));
        // Remove text
        //mRestartTF = false;
        // Resets level
        //SetLevel(mCurrentLevel);
        //Load(mCurrentLevel);
    }
}


/**
 * Increase spartygnome speed when he rip that hotdog
 */
void Game::IncreaseSpeed()
{
    HorizontalSpeed += 200;
}