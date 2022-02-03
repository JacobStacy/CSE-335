#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <FishBeta.h>

using namespace std;

TEST(AquariumTest, Construct)
{
    Aquarium aquarium;
}

TEST(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<FishBeta> fish1 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish1);
    fish1->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";

    shared_ptr<FishBeta> fish2 = make_shared<FishBeta>(&aquarium);
    aquarium.Add(fish2);
    fish2->SetLocation(100, 200);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish2) << L"Testing two fish on top of each other";

    ASSERT_TRUE(aquarium.HitTest(100, 20000) == nullptr) << L"Testing hitting where there is no fish";
}