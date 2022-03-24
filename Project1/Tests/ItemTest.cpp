/**
 * @file ItemTest.cpp
 * @author Jacob Stacy
 *
 * Test file for the Item Class
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Item.h>
#include <Game.h>
#include <Platform.h>

const std::wstring ItemImageName = L"images/platformIndustrial_057.png";
/** Mock class for testing the class Item */
class ItemMock : public Item {
public:
    ItemMock(Game *game, std::shared_ptr<wxBitmap> bitmap) : Item(game,  bitmap) {}

    void Draw(wxDC *dc){}
};

TEST(ItemTest, Construct) {
    auto image = std::make_shared<wxImage>(ItemImageName, wxBITMAP_TYPE_ANY);
    auto bitmap = std::make_shared<wxBitmap>(*image);

    Game game;
    ItemMock item(&game, bitmap);

    // Test initial values
    ASSERT_NEAR(0, item.GetX(), 0.0001);
    ASSERT_NEAR(0, item.GetY(), 0.0001);

    // Test SetLocation, GetX, and GetY
    item.SetLocation(10.5, 17.2);
    ASSERT_NEAR(10.5, item.GetX(), 0.0001);
    ASSERT_NEAR(17.2, item.GetY(), 0.0001);

    // Test a second with different values
    item.SetLocation(-72, -107);
    ASSERT_NEAR(-72, item.GetX(), 0.0001);
    ASSERT_NEAR(-107, item.GetY(), 0.0001);
}

TEST(ItemTest, Collision) {
    auto image = std::make_shared<wxImage>(ItemImageName, wxBITMAP_TYPE_ANY);
    auto bitmap = std::make_shared<wxBitmap>(*image);

    Game game;
    std::shared_ptr<Item> us = std::make_shared<Item>(&game, bitmap);
    Item other(&game, bitmap);



    other.SetLocation(100, 100);

    // Test top collide
    us->SetLocation(100, 67);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(100, 68);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(100, 69);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test right collide
    us->SetLocation(133, 100);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(132, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(131, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test bottom collide
    us->SetLocation(100, 133);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(100, 132);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(100, 131);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test left collide
    us->SetLocation(67, 100);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(68, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(69, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));

    //Test not colliding
    us->SetLocation(3000, 3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(-3000, 3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(3000, -3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(-3000, -3000);
    ASSERT_EQ(false, us->CollisionTest(&other));

}

TEST(ItemTest, PlatformCollision) {
    auto image = std::make_shared<wxImage>(ItemImageName, wxBITMAP_TYPE_ANY);
    auto bitmap = std::make_shared<wxBitmap>(*image);

    Game game;
    std::shared_ptr<Item> us = std::make_shared<Item>(&game, bitmap);
    Item other(&game, bitmap);

    other.SetLocation(100, 100);

    // Test top collide
    us->SetLocation(100, 67);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(100, 68);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(100, 69);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test right collide
    us->SetLocation(133, 100);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(132, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(131, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test bottom collide
    us->SetLocation(100, 133);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(100, 132);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(100, 131);
    ASSERT_EQ(true, us->CollisionTest(&other));

    // Test left collide
    us->SetLocation(67, 100);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(68, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));
    us->SetLocation(69, 100);
    ASSERT_EQ(true, us->CollisionTest(&other));

    //Test not colliding
    us->SetLocation(3000, 3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(-3000, 3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(3000, -3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
    us->SetLocation(-3000, -3000);
    ASSERT_EQ(false, us->CollisionTest(&other));
}